#include "Sockets.h"

bool Net::winsock_init()
{
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
	this->m_socket = socket(IPv, type, protocol);
	if (this->m_socket == INVALID_SOCKET)
	{
		std::cerr << WSAGetLastError();
		return INVALID_SOCKET;
	}
	WSACleanup();
	return this->m_socket;
}

bool Socket::close_socket()
{
	if (this->get_socket() != INVALID_SOCKET)
	{
		const int result = closesocket(this->get_socket());
		if (result != 0)
		{
			std::cerr << WSAGetLastError();
			return false;
		}
	}
	this->m_socket = INVALID_SOCKET;
	WSACleanup();
	return true;
}
