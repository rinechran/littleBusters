#pragma once
#include "Socket.h"
#include "EndPoint.h"


namespace KUD {

	class Acceptor {
	public:

		Acceptor(Socket & othSocket, EndPoint &othEndpoint);
		//Server function	
		//server accept : bind -> listen -> accept
		void accept();

		Socket &_socket;
	};

	class Conector {
	public:
		Conector();
		//clinet : coennects
		void connect();

	};
}