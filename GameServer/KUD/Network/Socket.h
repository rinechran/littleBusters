#pragma once
#include "Utility/Utility.h"
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")

namespace KUD {
	struct impleSocket{
		SOCKET socket;
	};
	enum class TRANSPORT_PROTOCAL {
		TCP,
		UDP,
	};
	enum class INTERNET_PROTOCAL {
		ipv4,
		ipv6
	};
	class Socket
	{

	public:
		Socket(TRANSPORT_PROTOCAL ) {}
		virtual ~Socket() {}
	private:
		/*
		Not implement
		bool CreateSocket{
		
		}
		impleSocket _socket;
		*/
	};
}



