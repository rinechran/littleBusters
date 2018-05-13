#pragma once
#include "Utility/Utility.h"
#include <WinSock2.h>
#pragma comment(lib, "Ws2_32.lib")

namespace KUD {
	struct impleSocket{
		SOCKET socket;
	};
	enum class SOCKET_TYPE {
		TCP,
		UDP
	};
	class Socket
	{

	public:
		Socket(SOCKET_TYPE ) {}
		virtual ~Socket() {}
	private:
		impleSocket _socket;
	};
}



