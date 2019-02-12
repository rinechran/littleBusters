#pragma once

#include <WinSock2.h>
#include "EndPoint.hpp"
#include "Utility.hpp"
#pragma comment(lib, "Ws2_32.lib")



//https://github.com/pauldotknopf/WindowsSDK7-Samples/tree/master/netds/winsock/iocp

namespace KUD {
	//winsocket;
	class Acceptor;

	enum  TRANSPORT_PROTOCAL {
		TCP = SOCK_STREAM,
		UDP = SOCK_DGRAM,
	};
	enum  INTERNET_PROTOCAL {
		ipv4 = AF_INET,
		ipv6 = AF_INET6
	};

	struct impleSocket{
	private:
		SOCKET _socket;
	public:
		impleSocket();
		 

		operator SOCKET&();

		impleSocket& operator=(SOCKET oth) {
			_socket = oth;
			return *this;
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
		bool CreateSocket() {
			_socket = WSASocket(_internetProtocal, _transportProtocal, 0, nullptr, 0, WSA_FLAG_OVERLAPPED);
			
			if (_socket == INVALID_SOCKET) 
				return false;
			return true;
		}
		bool isSocket() {
			return _socket;
		}
		
		friend class Acceptor;

		SOCKADDR_IN _socketaddr_in;
		impleSocket _socket;
		class EndPoint * _endPoint;
		INTERNET_PROTOCAL _internetProtocal;
		TRANSPORT_PROTOCAL _transportProtocal;
	};


	 
}



