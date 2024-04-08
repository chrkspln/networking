// Sockets.h : Include file for standard system include files,
// or project specific include files.

// Path: Sockets/Sockets.cpp

#pragma once
#pragma comment(lib, "ws2_32.lib")

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <iostream>
#include <assert.h>

namespace Net {
	bool winsock_init();
	typedef SOCKET socket;

	enum IP_version {
		IPv4,
		IPv6
	};
}

class Socket
{
private:
	Net::socket m_socket;
	Net::IP_version m_IP_version;

public:
	Socket();
	~Socket();
	Net::socket get_socket();
	Net::IP_version get_IP_version();
	SOCKET init_socket(Net::IP_version IP_version, int protocol);
	bool close_socket();
};