#pragma once
#include <WinSock2.h>
#include <stdio.h>

#pragma comment (lib,"Ws2_32.lib")
#pragma warning (disable:4996)

#define MAX_STRSIZE 500
/*------------function prototypes-----------------------*/
void setupWSA(void);
SOCKET connectToServer(void);
void sendCaption(char szWinTitle, SOCKET socket);
void closeConnection(SOCKET socket);
/*-----------------------------------------------------*/

void setupWSA(void) {
	/*load the Winsock library*/
	WSADATA wsaData;
	WORD wsaVersion = MAKEWORD(2, 2);
	if (WSAStartup(wsaVersion, &wsaData) != 0) {
		perror("\nfailed: load winsock (2.2) library");
		exit(1);
	}
	//check if specified library version has loaded
	if (LOBYTE(wsaData.wVersion) < 2 || HIBYTE(wsaData.wVersion) < 2) {
		puts("\nfailed: specified winsock library");
		exit(1);
	}
	puts("\nWinsock library loaded...");
}

/*Create connection to the agent server */
SOCKET connectToServer(void) {
	//create the sockets
	SOCKET sockConnection = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	//create the address structure
	//struct hostent *host;
	//if (host = gethostbyname("localhost") == NULL) {
	//	puts("Failed to resolve hostname");
	//	WSACleanup();
	//	system("PAUSE");
	//	exit(1);
	//}

	SOCKADDR_IN serverAddrInfo;
	int addressSize = sizeof(serverAddrInfo);
	serverAddrInfo.sin_family = AF_INET;
	serverAddrInfo.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	serverAddrInfo.sin_port = htons(8080);

	//attempt connection to server
	puts("\nConnecting...");
	if (connect(sockConnection, (SOCKADDR*)&serverAddrInfo, addressSize) == SOCKET_ERROR) {
		printf("Fail: Connection to server: %ld",WSAGetLastError);
		WSACleanup();
		system("PAUSE");
		exit(1);
	}
	puts("\nConnected!");
	return sockConnection;
}

/*send current windo caption text to server*/
void sendCaption(char *szWinText, SOCKET socket) {
	//display message from the server	
	char urlStart[100] = "GET /tracker/trec?title=";
	char urlEnd[100] = " HTTP/1.1\r\nHost: 127.0.0.1:8080\r\n\r\n";
	char urlStringFull[MAX_STRSIZE];
	strcpy(urlStringFull, urlStart);
	strcat(urlStringFull, szWinText);
	strcat(urlStringFull, urlEnd);
	printf("\nText: %s\n", szWinText);
		printf("\nCurrent string size: %d", strlen(urlStringFull));
	char * requestStr = "GET /tracker/trec?title=test+the+data HTTP/1.1\r\nHost: 127.0.0.1:8080\r\n\r\n";
	//if (send(socket, requestStr, strlen(requestStr), 0) != strlen(requestStr)) {
	//	//if (send(socket, requestStr, strlen(requestStr), 0) != strlen(requestStr)) {
	//	puts("\nWindow caption text exceeds length ");
	//	system("PAUSE");
	//	exit(1);
	//}

	//char buffer[5000];
	//memset(buffer, 0, 4999);
	//int dataReceived = recv(socket, buffer, 4000, 0);
	//printf("\nserver responded with this message:\n %s\n", buffer);

}

/*do some cleanup*/
void cleanup(SOCKET socket) {
	if (socket != SOCKET_ERROR) {
		shutdown(socket, SD_SEND);
		closesocket(socket);
		puts("\nSuccess: socket closed ");
	}
	WSACleanup();
		puts("\nSuccess: wsa cleanup done");
		system("PAUSE");
		exit(0);
}