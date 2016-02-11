#ifndef DISPATCH_H
#define DISPATCH_H
#define WINSOCK_DEPRECATED_NO_WARNINGS

/*To prevent windows.h from including the WSA 1.1 automatically (would cause confilict with winsock2.h), 
the macro below is defined. It prevents winsock.h from being included by the windows.h header. */
//#ifndef WIN32_LEAN_AND_MEAN
//#define WIN32_LEAN_AND_MEAN
//#endif
#define PORT "8080"
//includes winsock.h automatically i.e WSA 1.1
//automatically includes core elements from windows.h
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>

#pragma comment(lib,"Ws2_32.lib") 
//tell linker that winsock2 library is needed.

//create client socket 
SOCKET socketConnect(void) {
	
	SOCKET sock = INVALID_SOCKET;
	struct sockaddr_in sockAddr;
	sockAddr.sin_family = AF_INET;
	sockAddr.sin_addr.S_un.S_addr = inet_pton(AF_INET,"127.0.0.1",0);
	sockAddr.sin_port = htons(8080); //glassfish server

	if (connect(sock, (struct sockaddr*)(&sockAddr), sizeof(sockAddr) == INVALID_SOCKET)) {
		printf("Error connecting to socket\nError: %d", WSAGetLastError());
		exit(1);
	}
		puts("Connected to glassfish server");
		return sock; //return  a socket connected to server IP and port 8080
}

//initialize winsock
int initWSA(WSADATA *wsaData){
	WSADATA wsaDataChk;
	wsaDataChk = *wsaData;
	DWORD dwErr;
	//start/iniitalize the winsock library
	WORD version = MAKEWORD(2, 2); //create a 16 bit word using high-order and low-order bits
	dwErr = WSAStartup(version,wsaData);
	if (dwErr != 0) {
		printf("WSA startup failed (Error Code): %d\n", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	/*check for correct version of WSA*/
	if (LOBYTE(wsaDataChk.wVersion) != 2 || HIBYTE(wsaDataChk.wVersion) != 2) {
		printf("Version of WSA not correct!\nError: %d", WSAGetLastError());
		WSACleanup();
		return 1;
	}
	puts("WSA Initialized\n");
	return 0;
}

void postData(SOCKET sock) {
	char httpStr[2048];
	char * host = "127.0.0.1:8080";
	char  data[] = "?title=How to Get Moving - Mozilla Firefox";
	//craft HTML query string and put in buffer (httpStr)
	sprintf_s(httpStr, sizeof(httpStr), "GET /ptrack/trec?title=How to Get Moving - Mozilla Firefox HTTP/1.1\r\n"
		"Host: %s\r\n"
		//"Content-type: application/x-www-form-url-encoded\r\n"
		"Accept-charset: utf-8\r\n"
		"Content-length: %d\r\n\r\n", host,sizeof(httpStr));
	puts(httpStr);

	int bytesSent = send(sock, httpStr, strlen(httpStr), 0);
	if (bytesSent == SOCKET_ERROR) {
		printf("Error sending data: %ld",WSAGetLastError());
	}
	printf("Total Bytes sent: %d bytes\n", bytesSent);
	/*pull down the tents ;)*/
	closesocket(sock);
	WSACleanup();
}
#endif /*DISPATCH_H*/
