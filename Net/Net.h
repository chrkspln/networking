#pragma once
#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <assert.h>

namespace Net {
	bool winsock_init();
	typedef SOCKET socket;

	enum IP_version {
		IPv4,
		IPv6
	};


}
