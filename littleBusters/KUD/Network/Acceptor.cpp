#include "Acceptor.h"
#include "Socket.h"

KUD::Acceptor::Acceptor(Socket & othSocket, EndPoint & othEndpoint) :_socket(othSocket),endpoint(othEndpoint){

}

//Server function	
//server run : bind -> listen -> accept

void KUD::Acceptor::run() {


	if (this->_socket.CreateSocket())
		throw std::runtime_error("Socket Invalid");

	

	/*
	

	*/
	
}

//clinet : coennects


KUD::Conector::Conector() {

}

void KUD::Conector::connect() {

}
