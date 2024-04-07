#include "Sockets.h"

bool Net::winsock_init()
{
	// Initialize Winsock
	WSAData wsa_data;
	if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0)
	{
		std::cerr << "WSAStartup failed\n";
		WSACleanup();
		return false;
	}
	return true;
}

Socket::Socket()
{
	m_socket = INVALID_SOCKET;
	m_IP_version = Net::IP_version::IPv4;
}

Socket::~Socket() = default;

Net::socket Socket::get_socket()
{
	return m_socket;
}

Net::IP_version Socket::get_IP_version()
{
	return m_IP_version;
}

SOCKET Socket::init_socket(Net::IP_version IP_version, int protocol)
{
	int IPv = (IP_version == Net::IP_version::IPv4 ? AF_INET : AF_INET6);
	int type = (protocol == IPPROTO_TCP ? SOCK_STREAM : SOCK_DGRAM);
	return socket(IPv, type, protocol);
}

