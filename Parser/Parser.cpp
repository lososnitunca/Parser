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

int z = 0;
void timer() {
	++z;
	std::cout << "timer() fired! " << z << std::endl;
}

void server(boost::asio::io_service *io) {
	while (TRUE)
	{
		io->run();
		io->reset();
		std::cout << "NAVERNI GOVNA RAZOK" << std::endl;
	}
}

void server1(boost::asio::io_service *io) {
	io->run();
	io->reset();
	std::cout << "NAVERNI GOVNA DVAZOK" << z << std::endl;
}

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


	//system("pause");


	boost::asio::io_service io;
	
	//boost::thread server_thread(boost::bind(&server, &io));
	//server_thread.detach();
	
	boost::asio::deadline_timer keepalive_timer(io);
	boost::asio::deadline_timer keepalive_timer_2(io);
	keepalive_timer_2.expires_from_now(boost::posix_time::seconds(2));
	keepalive_timer.expires_from_now(boost::posix_time::seconds(1));
	keepalive_timer_2.async_wait(boost::bind(timer));
	keepalive_timer.async_wait(boost::bind(timer));

	boost::thread server_thread(boost::bind(&server1, &io));
	server_thread.detach();

	//keepalive_timer.cancel();
	//io.run();

	std::cout << "NAVERNI GOVNA" << std::endl;
	
	//io.stop();
	/*boost::asio::deadline_timer keepalive_timer_3(io);
	boost::asio::deadline_timer keepalive_timer_4(io);
	keepalive_timer_3.expires_from_now(boost::posix_time::seconds(6));
	keepalive_timer_4.expires_from_now(boost::posix_time::seconds(8));
	keepalive_timer_4.async_wait(boost::bind(timer));
	keepalive_timer_3.async_wait(boost::bind(timer));*/

	//boost::thread server_thread_1(boost::bind(&server1, &io));
	//server_thread_1.detach();

	system("pause");

	boost::asio::deadline_timer keepalive_timer_3(io);
	boost::asio::deadline_timer keepalive_timer_4(io);
	keepalive_timer_3.expires_from_now(boost::posix_time::seconds(1));
	keepalive_timer_4.expires_from_now(boost::posix_time::seconds(2));
	keepalive_timer_4.async_wait(boost::bind(timer));
	keepalive_timer_3.async_wait(boost::bind(timer));

	boost::thread server_thread_1(boost::bind(&server1, &io));
	server_thread_1.detach();

	system("pause");

	boost::asio::ip::tcp::iostream stream("www.yandex.ru", "http");
	stream << "GET /ip HTTP/1.1\r\nHost: www.yandex.ru\r\nConnection: close\r\n\r\n";
	
	boost::filesystem::ofstream http_parser("yaba.txt");
	
	//std::cout << stream.rdbuf();
	//http_parser << "111111\n";
	http_parser << stream.rdbuf();

	http_parser.close();

	system("pause");

	return 0;
}

