#pragma once

#include "stdafx.h"
#include "Class.h"


CConfig::CConfig(std::string fileName) : MasterCfg { MASTER_ACCOUNT, DEFAULT_MASTER }, SlaveCfg { SLAVE_ACCOUNT, DEFAULT_SLAVE } // we believe that we have Server, Manager, Timer, Logins sections in file
{
		try
		{
			boost::property_tree::read_ini(fileName, iniData);
			//boost::property_tree::ptree& iniChild = iniData.get_child("");

			//std::cout << iniData.size() << std::endl;
			//std::vector<std::string> sections(iniData.size());
			//std::vector<std::string>::iterator sCount = sections.begin();

			//BOOST_FOREACH(auto& v, iniData)
			//{
			//	*sCount = v.first;
			//	++sCount;
			//}

			//boost::property_tree::ptree& iniMain = iniData.get_child("Main");
			//boost::property_tree::ptree& iniManager = iniTree.get_child("Manager");
			//boost::property_tree::ptree& iniTimer = iniTree.get_child("Timer");
			//boost::property_tree::ptree& iniLogins = iniTree.get_child("Logins");

			//m_server = iniServer.get<std::string>("adress");
			//m_login = iniManager.get<int>("login");
			//m_password = iniManager.get<std::string>("password");
			//m_time = iniTimer.get<int>("time");

			//int counter = iniLogins.size(); // init list of logins opening orders
			//m_Logins.resize(counter);
			//counter = 0;
			//for (auto&i : iniLogins)
			//{
			//	m_Logins[counter] = i.second.get<int>("");
			//	++counter;
			//}
			//std::sort(m_Logins.begin(), m_Logins.end());

			//std::string str = sections[2] + '.' + "mAccount3";

			//mAccount = iniData.get<int>(str, 0);
			//sAccount = iniData.get<int>("SlaveAccount", 0);

			if (const boost::optional<int> key =
				iniData.get_optional<int>(MASTER_ACCOUNT))
			{
				MasterCfg.name = MASTER_ACCOUNT;
				MasterCfg.value = key.get();

				std::cout << "\t" << MasterCfg.value << '\n';
			}

			if (const boost::optional<int> key =
				iniData.get_optional<int>(SLAVE_ACCOUNT))
			{
				SlaveCfg.name = SLAVE_ACCOUNT;
				SlaveCfg.value = key.get();
				
				std::cout << "\t" << SlaveCfg.value << '\n';
			}
		}
		catch (boost::property_tree::ini_parser_error& error)
		{
			// if file is not found - creat default ini file
			MasterCfg = { MASTER_ACCOUNT, DEFAULT_MASTER };
			SlaveCfg = { SLAVE_ACCOUNT, DEFAULT_SLAVE };

			iniData.put(MasterCfg.name, MasterCfg.value); //default value
			iniData.put(SlaveCfg.name, SlaveCfg.value); //default value
			boost::property_tree::write_ini(fileName, iniData);
		}
}


CConfig::~CConfig()
{

}

int CConfig::Set(PlugCfg cfg)
{
	iniData.put(cfg.name, cfg.value); //default value
	boost::property_tree::write_ini(CreateIniName(), iniData);
	return(0);
}

std::string CConfig::CreateIniName()
{
	WCHAR  lpFilename[MAX_BUFF];
	GetModuleFileName(NULL, lpFilename, MAX_BUFF);
	std::wstring s = lpFilename;
	std::string stringFilemame(s.begin(), s.end());
	stringFilemame.replace(stringFilemame.size() - 4, stringFilemame.size(), ".ini");
	return stringFilemame;
}