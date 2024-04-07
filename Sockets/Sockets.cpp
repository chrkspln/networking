#include "Sockets.h"

bool winsock_init()
{
	// Initialize Winsock
	WSAData wsa_data;
	if (WSAStartup(MAKEWORD(2, 2), &wsa_data) != 0)
	{
		std::cerr << "WSAStartup failed\n";
		return false;
	}
	return true;
}
