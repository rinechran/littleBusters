#pragma once
#include <WinSock2.h>
#include "EndPoint.h"
#include "Utility.h"
#pragma comment(lib, "Ws2_32.lib")




namespace KUD {
	//winsocket;

	enum class TRANSPORT_PROTOCAL {
		TCP = SOCK_STREAM,
		UDP = SOCK_DGRAM,
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
		void acceptor(EndPoint &endpoint) {
			_endPoint = &endpoint;
		}

		//Server function	
		//server accept : bind -> listen -> accept
		void accept() {

			//WSAAccept(_socket.socket)
		}

		//clinet : coennects
		void connect() {

		}
		virtual ~Socket() {}
	private:
		/*
		Not implement
		bool CreateSocket{
		
		}
		*/
		impleSocket _socket;
		EndPoint * _endPoint;
		INTERNET_PROTOCAL _internetProtocal;
		TRANSPORT_PROTOCAL _transportProtocal;
	};

	class acceptor {

	};

	class Conector {
		
	};
	 
}



