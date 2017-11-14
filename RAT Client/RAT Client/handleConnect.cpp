#include "handleConnect.h"
#include "internals.h"
#include <iostream>

Info::User UserInfo;
Info::File FileData;
char dataStream[1024];








static DWORD WINAPI readThread(LPVOID param)
{
	SOCKET s = (SOCKET)param;
	char Buffer[512];
	int iResult;

	do
	{
		iResult = recv(s, Buffer, 512, 0);
		if (iResult <= 0) break;
		Buffer[iResult] = '\0';
		std::cout << "Recv: " << Buffer << std::endl;
	} while (true);

	return 0;
}

int handleConnect::attemptConnection()
{
	Internals internalFunction;
	HANDLE readHandle;
	DWORD dwThreadID;
	WSADATA wsa;
	SOCKET s;

	internalFunction.Screenshot();

	struct sockaddr_in server;

	printf("\nInitialising Winsock...");
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		printf("Failed. Error Code : %d", WSAGetLastError());
		return 1;
	}

	printf("Initialised.\n");

	//Create a socket
	if ((s = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
	{
		printf("Could not create socket : %d", WSAGetLastError());
		return 1;
	}

	printf("Socket created.\n");


	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_family = AF_INET;
	server.sin_port = htons(8888);

	//Connect to remote server
	if (connect(s, (struct sockaddr *)&server, sizeof(server)) < 0)
	{
		puts("connect error");
		return 1;
	}


	//CREATE THREAD FUNCTION REFERENCE MUST BE STATIC.
	readHandle = CreateThread(NULL, 0, &readThread, (void*)s, 0, &dwThreadID);

	unsigned char* temp = internalFunction.File("C:\\Users\\Wilky\\Desktop\\CLmg\\Packetproto\\notepad.exe");


	//Handle File Data
	
	char fileStream[1000000];
	std::string fileBytes = std::string((char*)temp, internalFunction.fileSize());
	FileData.set_size(internalFunction.fileSize());
	FileData.set_buffer(fileBytes);
	
	//Handle User Data
	UserInfo.set_name(internalFunction.GetName());
	UserInfo.set_date(internalFunction.GetTime());
	UserInfo.set_processor("No");
	




	/*
	Retard ADHD NOTES
	1. Whole file is in fileBytes
	2. Take in whole file size
	3. Send some info 1024 of x bytes
	4. See what is left, continue to send till sent = size
	*/
		
	/*
	int remainder = internalFunction.fileSize() - FileData.ByteSize();
	printf("\n");
	std::cout << "Leftover bytes detected: " << remainder << std::endl;
	*/






	if (UserInfo.IsInitialized() && FileData.IsInitialized())
	{

		UserInfo.SerializeToArray(dataStream, sizeof(dataStream));
		FileData.SerializeToArray(fileStream, sizeof(fileStream));

		std::cout << "Serialization Success" << std::endl;

/*

		if (send(s, dataStream, UserInfo.ByteSize(), 0) == SOCKET_ERROR)
		{
			std::cout << "Error in sending" << std::endl;
		}

		*/

		puts("User Packet Sent! Starting File Send!");

		if (send(s, fileStream, FileData.ByteSize(), 0) == SOCKET_ERROR)
		{
			std::cout << "Error in sending" << std::endl;
		}
		puts("Both Sent Now!");


	}
	



	do
	{
		std::string message;
		if (!std::getline(std::cin, message))
			break;

		if (send(s, message.c_str(), message.length(), 0) == SOCKET_ERROR)
		{
			std::cout << "Error at send(): " << WSAGetLastError() << std::endl;
			break;
		}
	} while (true);

	return 0;
	

	
}




