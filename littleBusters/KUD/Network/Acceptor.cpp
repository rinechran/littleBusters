#include "Acceptor.h"
#include "Socket.h"

KUD::Acceptor::Acceptor(Socket & othSocket, EndPoint & othEndpoint) :_socket(othSocket){

}

//Server function	
//server accept : bind -> listen -> accept

void KUD::Acceptor::accept() {
}

//clinet : coennects


KUD::Conector::Conector() {

}

void KUD::Conector::connect() {

}
