#pragma once

#include <WinSock2.h>
#include <string>

//http://www.winsocketdotnetworkprogramming.com/winsock2programming/winsock2advancediomethod5f.html

namespace KUD {
	// ip port
	struct _addrinfo {
		_addrinfo() {
			memset(&info, 0, sizeof(addrinfo));
		}

	public:
		SOCKADDR_IN info;
	};

	class EndPoint
	{
	public:
		// ipv , 
		EndPoint() = delete;
		//endpoint
		EndPoint(std::string ip,u_char port) {
//			_addrinfo.info.sin_addr.s_addr = inet_addr(ip.c_str());
			//_addrinfo.info.sin_family; v4 v6
//			_addrinfo.info.sin_port = htons(port);
		
		}

		virtual ~EndPoint() {}
	private:
		_addrinfo _addrinfo;

	};
	
}
