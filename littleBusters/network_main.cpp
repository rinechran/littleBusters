#include <iostream>
#include "KUD/Network\LittleBusters.h"
#include <string>

int main() {
	KUD::Socket socket(KUD::INTERNET_PROTOCAL::ipv4, KUD::TRANSPORT_PROTOCAL::TCP);
	KUD::EndPoint endPoint("127.0.0.1u", 8080u);
	KUD::Acceptor acceptor(socket,endPoint);
	acceptor.accept();




}