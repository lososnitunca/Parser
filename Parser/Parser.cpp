// Parser.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Class.h"


int main(int argc, char* argv[])
{
	std::vector<std::string> iniName(strlen(argv[0]));

	CConfig conf(CConfig::CreateIniName());

	WCHAR  lpF[260];

	GetModuleFileName(NULL, lpF, 260);

	std::wstring s = lpF;
	std::string ss(s.begin(), s.end());
	
	ss.replace(ss.size() - 4, ss.size(), ".ini");

	std::cout <<
		conf.MasterCfg.value << std::endl <<
		conf.SlaveCfg.name << std::endl <<
		argv[0] << std::endl <<
		ss << std::endl <<
		_pgmptr << std::endl <<
		__FILE__ << std::endl;

	system("pause");

	return 0;
}

