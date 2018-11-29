#include "Socket.hpp"

KUD::impleSocket::impleSocket() {
	_socket = INVALID_SOCKET;
}

KUD::impleSocket::operator SOCKET&() {
	return _socket;
}
