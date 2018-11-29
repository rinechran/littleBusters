#pragma once
#include <winsock2.h>
#include <Windows.h>
#include <exception>
#include "Socket.hpp"
#include "EndPoint.hpp"





namespace KUD {

	class Acceptor {
	public:

		Acceptor(Socket & othSocket, EndPoint &othEndpoint);
		//Server function	
		//server run : createSocket -> bind -> listen -> accept
		void run();
		bool accept() {
			return false;
		}
		bool bind(){
			::bind(this->_socket,)
			return false;

		}
		bool listen() {
			return false;

		}
		EndPoint &endpoint;
		Socket &_socket;
	};

	class Conector {
	public:
		Conector();
		//clinet : coennects
		void connect();

	};
}