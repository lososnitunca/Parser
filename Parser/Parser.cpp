// Parser.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include "Class.h"

int myPlus(int a, int b) { 
	
	std::cout << "a = "<< a << std::endl;
	std::cout << "b = " << b << std::endl;

	return a + b; }

struct T {
	char name[128];
	char value[128];
	int res;
};

int main(int argc, char* argv[])
{
	std::vector<std::string> iniName(strlen(argv[0]));

	CConfig conf(CConfig::CreateIniName());

	WCHAR  lpF[260];

	GetModuleFileName(NULL, lpF, 260);

	std::wstring s = lpF;
	std::string ss(s.begin(), s.end());

	std::vector<T> s1;
	s1.push_back({ "Master", "1", 15 });
	s1.push_back({ "Slave", "2", 12 });

	char mas[128] = "Master";

	std::vector<T>::iterator i = std::find_if(
		s1.begin(), 
		s1.end(), 
		boost::bind(
			&boost::iequals<std::string, std::string>,
			boost::bind(&T::name, _1),
			mas,
			std::locale()
		));
	if (i == s1.end()) //|| //searching master account setting
	//	(std::find_if(s1.begin(), s1.end(), boost::bind(&T::name, _1) == "Slave")) == s1.end()) //searching slave account setting
		return(-14);

	ss.replace(ss.size() - 4, ss.size(), ".ini");

	std::string sgt;

	char ter[256] = "2321";

	sgt = ter;

	std::cout <<
		conf.MasterCfg.value << std::endl <<
		conf.SlaveCfg.name << std::endl <<
		argv[0] << std::endl <<
		ss << std::endl <<
		_pgmptr << std::endl <<
		__FILE__ << std::endl <<
		ter << std::endl <<
		sgt << std::endl <<
		s1[1].name << std::endl;

	std::function<int(int, int)> f(std::bind(myPlus, std::placeholders::_2, std::placeholders::_1));
	std::cout << f(10, 8) << std::endl;

	for (int i = 0; i < 3; i++)
	{
		switch (i) {
		case 0:
			std::cout << "0" << std::endl;
			break;
		case 1:
			std::cout << "1" << std::endl;
		case 2:
			std::cout << "2" << std::endl;
		}
	}
	system("pause");

	return 0;
}

