#include "Acceptor.hpp"
#include "Socket.hpp"

KUD::Acceptor::Acceptor(Socket & othSocket, EndPoint & othEndpoint) :_socket(othSocket),endpoint(othEndpoint){

}

//Server function	
//server run : bind -> listen -> accept

void KUD::Acceptor::run() {


	if (!this->_socket.CreateSocket())
		throw std::runtime_error("Socket Invalid");
	

	if (!this->bind())
		throw std::runtime_error("Bind Error");

	if (!this->listen())
		throw std::runtime_error("listen Error");
	
}

//clinet : coennects


KUD::Conector::Conector() {

}

void KUD::Conector::connect() {

}
