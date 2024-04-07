// Sockets.h : Include file for standard system include files,
// or project specific include files.

// Path: Sockets/Sockets.cpp

#pragma once
#pragma comment(lib, "ws2_32.lib")

#define WIN32_LEAN_AND_MEAN
#include <WinSock2.h>
#include <iostream>

bool winsock_init();
