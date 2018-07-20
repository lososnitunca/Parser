#pragma once
#include "stdafx.h"

#define MAX_BUFF 260
#define MASTER_ACCOUNT "Master Account"
#define DEFAULT_MASTER 6
#define SLAVE_ACCOUNT "Slave Account"
#define DEFAULT_SLAVE 7

class CConfig
{
private:

	boost::property_tree::ptree iniData;

public:

	struct PlugCfg
	{
		std::string name;
		int value;
	};

	PlugCfg MasterCfg;
	PlugCfg SlaveCfg;

	PluginCfg config;

	CConfig(std::string fileName);
	~CConfig();

	int Set(PlugCfg cfg);

	static std::string CreateIniName();

};

