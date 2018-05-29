#include "EndPoint.h"

KUD::_addrinfo::_addrinfo() {
	memset(&info, 0, sizeof(addrinfo));
}

KUD::EndPoint::EndPoint(const EndPoint & oth) {
	ip = oth.ip;
	port = oth.port;
}
