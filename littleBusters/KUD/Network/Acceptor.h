#pragma once
#include "Socket.h"
namespace KUD {
	class Acceptor {
	public:

		Acceptor(KUD::Socket *othSocket, KUD::EndPoint &othEndpoint);
		//Server function	
		//server accept : bind -> listen -> accept
		void accept();

		typename KUD::Socket *s;
	};

	class Conector {
	public:
		Conector();
		//clinet : coennects
		void connect();

	};
}