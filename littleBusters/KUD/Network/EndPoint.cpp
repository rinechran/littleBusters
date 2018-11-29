#include "EndPoint.hpp"

KUD::Addrinfo::Addrinfo() {
	memset(&info, 0, sizeof(addrinfo));
}

KUD::EndPoint::EndPoint(const EndPoint & oth) {
	mIp = oth.mIp;
	mPort = oth.mPort;
}
