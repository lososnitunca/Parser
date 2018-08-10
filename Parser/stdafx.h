// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN      // Exclude rarely-used stuff from Windows 

#include "targetver.h"

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <windows.h>
#include <vector>
#include <functional>
#include <MT4ServerAPI.h>
#include <boost/bind.hpp>
//#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/predicate.hpp>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/stream_translator.hpp>
#include <boost/property_tree/string_path.hpp>
#include <boost/property_tree/ini_parser.hpp>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time_types.hpp>
#include <boost/thread.hpp>
#include <boost/foreach.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>


//#pragma comment(lib, "Ws2_32.lib")

#define COPY_STR(dst,src) { strncpy(dst,src,sizeof(dst)-1); dst[sizeof(dst)-1]=0; }

// TODO: Установите здесь ссылки на дополнительные заголовки, требующиеся для программы
