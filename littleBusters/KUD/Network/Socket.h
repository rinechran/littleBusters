#pragma once
#include <WinSock2.h>
#include "EndPoint.h"
#include "Utility.h"
#pragma comment(lib, "Ws2_32.lib")



//https://github.com/pauldotknopf/WindowsSDK7-Samples/tree/master/netds/winsock/iocp

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
	private:
		SOCKET _socket;
	public:
		impleSocket() {
			_socket = INVALID_SOCKET;
		}
		operator SOCKET&() {
			return _socket;
		}
		
	};

	// socket 은 ipv4,ipv6 엔드포인트와 묶어주는 작업을 추가한다

	class Socket
	{

	public:
		Socket(INTERNET_PROTOCAL ipv, TRANSPORT_PROTOCAL transport) {
			_internetProtocal = ipv;
			_transportProtocal = transport;			
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

	class Acceptor {
	public:
		Acceptor(Socket,EndPoint) {

		}
		//Server function	
		//server accept : bind -> listen -> accept
		void accept() {

			//WSAAccept(_socket.socket)
		}
	};

	class Conector {
	public:
		Conector() {

		}
		//clinet : coennects
		void connect() {

		}
		
	};
	 
}



