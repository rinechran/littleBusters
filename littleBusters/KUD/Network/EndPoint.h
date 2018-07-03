#pragma once

#include <WinSock2.h>
#include <string>
#include "Socket.h"

//http://www.winsocketdotnetworkprogramming.com/winsock2programming/winsock2advancediomethod5f.html

namespace KUD {
	// ip port
	struct _addrinfo {
		_addrinfo();

	public:
		SOCKADDR_IN info;
	};

	class EndPoint
	{
	public:
		// ipv , 
		EndPoint() = delete;

		//endpoint

		EndPoint(std::string othIp, u_char othPort) {
			ip = othIp;
			port = othPort;
		}
		EndPoint(const EndPoint& oth);

		EndPoint& operator=(const EndPoint& oth) {
			ip = oth.ip;
			port = oth.port;
			return *this;
		}
		

		virtual ~EndPoint() {}

	private:
		std::string ip;
		u_char port;

	};
	


	

}
