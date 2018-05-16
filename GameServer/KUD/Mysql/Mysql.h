#pragma once

#include <my_global.h>
#include <mysql.h>
#include <string>
#include <unordered_map>

#pragma comment(lib, "libmysql")
#pragma comment(lib, "mysqlclient")

namespace KUD {
	namespace MYSQL {

		struct ImplePort
		{
			ImplePort();
		
			ImplePort(unsigned int othPort);
			operator int() { return port; }
		private:
			unsigned int port;
		};

		struct impleFlog
		{
			impleFlog();
			impleFlog(unsigned int othFlog);
			operator unsigned int() { return flog; }
		private:
			unsigned long flog;
		};
		struct impleSocket
		{
			impleSocket();
			impleSocket(const char * othFlog);
			operator const char*() { return sock; }
		private:
			const char * sock;
		};



		struct ConnectSetting
		{
			std::string host;
			std::string id;
			std::string passwd;
			std::string database;
			ImplePort port;
			impleSocket socket;
			impleFlog flog;
		};
		enum class ErrorCode
		{
			CONNECTED,
			NOT_CONNECT,
			CONNERCT_ERROR,
			QUERY_SUCCESS,
			QUERY_FAIL
		};

		class Mysql {
			public:
				Mysql();
				ErrorCode connect(ConnectSetting setting);
				ErrorCode mysql_query(std::string &query);
				virtual ~Mysql();
		private:
			void ConnectMove(ConnectSetting &&oth);
			::MYSQL * _connector;
			bool _isSetting;
			ConnectSetting _setting;
		};

		/*
		std::unordered_map<ErrorCode, std::string> ErrorCodeStringMapping = {
			{ ErrorCode::CONNECTED ,"CONNECTED"},
			{ ErrorCode::NOT_CONNECT ,"NOT_CONNECT" },
			{ ErrorCode::CONNERCT_ERROR ,"CONNERCT_ERROR" },
		};
		*/
		extern std::unordered_map<ErrorCode, std::string> ErrorCodeStringMapping;
		
		std::string to_string(ErrorCode code);
		
	}
}