#pragma once

#include <WinSock2.h>
#include <string>
#include "Socket.h"
#include "Acceptor.h"

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
		template <class T>
		EndPoint(T othIp, u_char othPort);
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
	

	//endpoint

	template<class T>
	EndPoint::EndPoint(T othIp, u_char othPort) {
		ip = std::forward<T>(othIp);
		port = _othPort;
	}

}
