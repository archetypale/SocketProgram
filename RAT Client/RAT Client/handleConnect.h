#pragma once
#include <WinSock2.h>
#include <string>
#pragma comment(lib,"ws2_32.lib")

class handleConnect
{
public:
	int attemptConnection();

};