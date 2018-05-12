#pragma once

#include <my_global.h>
#include <mysql.h>
#include <string>

#pragma comment(lib, "libmysql")
#pragma comment(lib, "mysqlclient")
namespace KUD {
	namespace MYSQL {
		struct ConnetSetting
		{
			std::string host;
			std::string id;
			std::string passwd;
			std::string database;
			int port;
			std::string socket;
			unsigned long flog;


		};
		class Mysql {
			public:
				Mysql() {
					if (!_IsSetting) {
						_IsSetting = mysql_init(nullptr);
					}
				}
				ErrorCode connect(ConnetSetting setting) {
					
					/*
							if (mysql_real_connect(con, "kudwafter.moe", "rinechran", "dutajrdj!!1",
								NULL, 0, NULL, 0) == NULL)
							{
								fprintf(stderr, "%s\n", mysql_error(con));
								mysql_close(con);
								exit(1);
							}
					*/
					//mysql_real_connect
					if (!_IsSetting) {
						
					}
					
					mysql_real_connect(_Connector, setting.host.c_str(), setting.id.c_str()
						, setting.passwd.c_str(), setting.database.c_str(), setting.port
						, setting.socket.c_str(), setting.flog);
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

		enum ErrorCode
		{

		};
	}
}