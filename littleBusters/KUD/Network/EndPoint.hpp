#pragma once

#include <WinSock2.h>
#include <string>
#include "Socket.hpp"

//http://www.winsocketdotnetworkprogramming.com/winsock2programming/winsock2advancediomethod5f.html

namespace KUD {
	// ip port
	struct Addrinfo {
		Addrinfo();

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
			mIp = othIp;
			mPort = othPort;
		}
		EndPoint(const EndPoint& oth);

		EndPoint& operator=(const EndPoint& oth) {
			mIp = oth.mIp;
			mPort = oth.mPort;
			return *this;
		}
		

		virtual ~EndPoint() {}  

	private:
		std::string mIp;
		u_char mPort;
		Addrinfo mAddrinfo;

	};
	


	

}
