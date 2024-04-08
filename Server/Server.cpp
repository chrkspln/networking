#include "../Sockets/Sockets.h"
#include "Server.h"

int main()
{
	if (Net::winsock_init())
	{
		std::cout << "Winsock init is successful.\n";
		Socket socket;
		socket.init_socket(Net::IP_version::IPv4, IPPROTO_TCP);
		if (socket.get_socket() != INVALID_SOCKET)
		{
			std::cout << "socket has been created successfully!\n";
			if (socket.close_socket())
			{
				std::cout << "socket has been closed successfully.\n";
			}
		}
	}
	return 0;
}