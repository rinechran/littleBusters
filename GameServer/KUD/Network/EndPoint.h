#pragma once

#include <WinSock2.h>
#include <string>

namespace KUD {
	// ip port
	struct _addrinfo {
		_addrinfo() {
			memset(&info, 0, sizeof(addrinfo));
		}

	public:
		addrinfo info;
	};

	class EndPoint
	{
	public:
		// ipv , 
		EndPoint() = default;
		EndPoint(std::string ip,std::string port) {
			
		}

		virtual ~EndPoint() {}
	private:
		_addrinfo _addrinfo;

	};
	
}
