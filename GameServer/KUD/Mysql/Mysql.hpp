#pragma once

#include <my_global.h>
#include <mysql.h>
#include <string>
#include <unordered_map>

#pragma comment(lib, "libmysql")
#pragma comment(lib, "mysqlclient")


namespace KUD {
	namespace MYSQL {
		struct ImPort
		{
			ImPort() : port(3306){}
		
			ImPort(unsigned int othPort) : port(othPort){}
			operator int() { return port; }
		private:
			unsigned int port;
		};

		struct ImFlog
		{
			ImFlog() : flog(0){}
			ImFlog(unsigned int othFlog) : flog(othFlog) {}
			operator unsigned int() { return flog; }
		private:
			unsigned long flog;
		};
		struct ImSocket
		{
			ImSocket() : sock(nullptr) {}
			ImSocket(const char * othFlog) : sock(othFlog) {}
			operator const char*() { return sock; }
		private:
			const char * sock;
		};

		struct ConnetSetting
		{
			std::string host;
			std::string id;
			std::string passwd;
			std::string database;
			ImPort port;
			ImSocket socket;
			ImFlog flog;
			
			ConnetSetting() {
			}
			ConnetSetting(ConnetSetting const & oth) {
				this->host = oth.host;
				this->id = oth.id;
				this->passwd = oth.passwd;
				//other implement 
				// ImPort, ImFlog
				// socket
			}


		};
		class Mysql {
			public:
				Mysql() : _IsSetting(false) {
					if (!_IsSetting) {
						_IsSetting = mysql_init(nullptr);
					}
				}
				ErrorCode connect(ConnetSetting setting) {
					
					if (!_IsSetting) {
						return ErrorCode::NOT_CONNECT;
					}
					auto isResult = mysql_real_connect(_Connector, setting.host.c_str(), setting.id.c_str()
						, setting.passwd.c_str(), setting.database.c_str(), setting.port
						, setting.socket, setting.flog);

					if (!isResult) {
						return ErrorCode::CONNERCT_ERROR;
					}
					return ErrorCode::CONNECTED;
				}
				virtual ~Mysql() {
					if (_IsSetting) {
						mysql_close(_Connector);
					}
				}
			::MYSQL * _Connector;
			bool _IsSetting;
			ConnetSetting _Setting;
		};

		enum class ErrorCode
		{
			CONNECTED,
			NOT_CONNECT,
			CONNERCT_ERROR,
		};
		const std::unordered_map<ErrorCode, std::wstring> ErrorCodeStringMapping = {
			{ ErrorCode::CONNECTED ,L"CONNECTED"},
			{ ErrorCode::NOT_CONNECT ,L"NOT_CONNECT" },
			{ ErrorCode::CONNERCT_ERROR ,L"CONNERCT_ERROR" },
		};
		std::wstring to_string(ErrorCode code){
			auto it = ErrorCodeStringMapping.find(code);
			if (it != ErrorCodeStringMapping.end()) {
				return it->second;
			}
			return L"";
		}
		
	}
}