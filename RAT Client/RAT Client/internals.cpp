#include "internals.h"


using namespace std;
#define BUFFER_SIZE 1024 
long fSize;
size_t result;
std::vector<char> buffer;
std::ifstream file("data.bmp");

PBITMAPFILEHEADER file_header;
PBITMAPINFOHEADER info_header;



std::string Internals::GetName()
{
	char username[UNLEN + 1];
	DWORD username_len = UNLEN + 1;

	
	

	//Get Username Simple
	GetUserNameA(username, &username_len);
	std::string user(username);
	return user;



	/*
	WHAT THE FUCK WHY DID I EVEN DO THIS SHIT AAAAH HELP
	DWORD dwSize = 0, dwResult = 0;
	PTOKEN_USER pTokenUser;
	HANDLE myProcess = GetCurrentProcess(); //Gets current process handle to feed into next
	HANDLE token;
	char lpName[256];
	char lpDomain[256];
	SID_NAME_USE SidType;
	
	//Open a token to this application
	OpenProcessToken(myProcess, TOKEN_QUERY, &token);

	//Preload our size variables for incoming token information
	GetTokenInformation(token, TokenUser, NULL, dwSize, &dwSize);

	//Allocate Memory for user token
	std::vector<BYTE> buffer;
	buffer.resize(dwSize);
	pTokenUser = reinterpret_cast<PTOKEN_USER>(&buffer[0]);

	//Get the SID from the process
	GetTokenInformation(token, TokenUser, pTokenUser,
		dwSize, &dwSize);

		if (!IsValidSid(pTokenUser->User.Sid))
		{
			_tprintf(_T("The owner SID is invalid.\n"));

			// Cleanup
			CloseHandle(token);
			token = NULL;
		}

		//Use SID to find Account, used ANSI Version to prevent casting errors
		LookupAccountSidA(NULL, pTokenUser->User.Sid,
			lpName, &dwSize, lpDomain, &dwSize, &SidType);
	
		//convert to a string
		std::string user(lpName);

	return user;
	*/
}



std::string Internals::GetTime()
{
	std::string strMessage;
	_SYSTEMTIME st;
	GetLocalTime(&st);
	
	char buffer[256];
	sprintf(buffer,
		"%d-%02d-%02d %02d:%02d",
		st.wYear,
		st.wMonth,
		st.wDay,
		st.wHour,
		st.wMinute
		);

	strMessage = buffer;

	return strMessage;


}

std::string Internals::GetProcessor()
{
	/*
	HKEY Key;
	LPSTR value = NULL;
	DWORD valuelen = 512;

	if (RegOpenKey(HKEY_LOCAL_MACHINE, TEXT("HARDWARE\\DESCRIPTION\\SYSTEM\\CENTRALPROCESSOR\\0"), &Key) != ERROR_SUCCESS)
	{
		std::cout << "Failed to open Reg key";
	}

	
	//This sucks
	RegQueryValueA(Key, "ProcessorNameString", value, NULL);
	
	RegCloseKey(Key);
	
	std::string Processor(value);
	*/

	return "No";
}

int Internals::CaptureKey()
{
	return 0;
}

int Internals::CaptureVid()
{
	return 0;
}

void makeFile()
{
	std::ifstream file("data.bmp");
		if (file) {
			file.seekg(0, std::ios::end);
			 std::streampos length = file.tellg();
			file.seekg(0, std::ios::beg);

			buffer.resize(length);
			file.read(&buffer[0], length);

			file_header = (PBITMAPFILEHEADER)(&buffer[0]);
			info_header = (PBITMAPINFOHEADER)(&buffer[0] + sizeof(BITMAPFILEHEADER));
		}
	}

long getSize(FILE *file)
{
	long lCurPos, lEndPos;
	lCurPos = ftell(file);
	fseek(file, 0, 2);
	lEndPos = ftell(file);
	fseek(file, lCurPos, 0);
	return lEndPos;
}

long Internals::fileSize()
{
	return fSize;
}

unsigned char* Internals::File(char* filename)
{
	
	typedef unsigned char BYTE; //8bits

	//BYTE *fileByUserInfoream;
	FILE *file = NULL;
	unsigned char* filebuffer;

if ((file = fopen(filename, "rb")) == NULL)
		cout << "Can't open this shit" << endl;
	else
		cout << "File opened" << endl;

	 fSize = getSize(file);

	filebuffer = new unsigned char[fSize];
	

	size_t result = fread(filebuffer, 1, fSize, file);

	

	// Print first 100 bytes in Hex
	for (int i = 0; i < 100; i++)
		printf("%X ", filebuffer[i]);
	
	
	fclose(file);   // Don't forget this dog
	
	return filebuffer;
}
char* Internals::Screenshot()
{

	/*

	POINT a, b;
	a.x = 0;
	a.y = 0;
	b.x = 1920;
	b.y = 1080;
	// copy screen to bitmap
	HDC     hScreen = GetDC(NULL);
	HDC     hDC = CreateCompatibleDC(hScreen);
	HBITMAP hBitmap = CreateCompatibleBitmap(hScreen, abs(b.x - a.x), abs(b.y - a.y));
	HGDIOBJ old_obj = SelectObject(hDC, hBitmap);
	BOOL    bRet = BitBlt(hDC, 0, 0, abs(b.x - a.x), abs(b.y - a.y), hScreen, a.x, a.y, SRCCOPY);


	BITMAPINFO MyBMInfo = { 0 };
	MyBMInfo.bmiHeader.biSize = sizeof(MyBMInfo.bmiHeader);
	BYTE* lpPixels = new BYTE[MyBMInfo.bmiHeader.biSizeImage];

	if (0 == GetDIBits(hDC, hBitmap, 0, 0, NULL, &MyBMInfo, DIB_RGB_COLORS)) {
		std::cout << "error" << std::endl;
	}


	GetDIBits(hDC, hBitmap, 0, 0, lpPixels, &MyBMInfo, DIB_RGB_COLORS);

	
	
	

	
	// save bitmap to clipboard
	/*
	OpenClipboard(NULL);
	EmptyClipboard();
	SetClipboardData(CF_BITMAP, hBitmap);
	CloseClipboard();

	// clean up
	SelectObject(hDC, old_obj);
	DeleteDC(hDC);
	ReleaseDC(NULL, hScreen);
	DeleteObject(hBitmap);

	return (char*)lpPixels;
	*/
	return NULL;
	
}
