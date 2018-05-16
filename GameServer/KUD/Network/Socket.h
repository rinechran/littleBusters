#pragma once
#include "Utility/Utility.h"
#include <WinSock2.h>
#include "EndPoint.h"
#pragma comment(lib, "Ws2_32.lib")




namespace KUD {
	//winsocket;

	enum class TRANSPORT_PROTOCAL {
		TCP,
		UDP,
	};
	enum class INTERNET_PROTOCAL {
		ipv4,
		ipv6
	};

	struct impleSocket{
		SOCKET socket;
	};

	class Socket
	{

	public:
		Socket(INTERNET_PROTOCAL ipv, TRANSPORT_PROTOCAL transport) {
			_internetProtocal = ipv;
			_transportProtocal = transport;
		}
		void acceptor(EndPoint endpoint) {
			_endPoint = endpoint;
		}
		virtual ~Socket() {}
	private:
		/*
		Not implement
		bool CreateSocket{
		
		}
		*/
		impleSocket _socket;
		EndPoint _endPoint;
		INTERNET_PROTOCAL _internetProtocal;
		TRANSPORT_PROTOCAL _transportProtocal;
	};
	 
}



