
#include <stdio.h>
#include <stdlib.h>
//#include "modProcessTrack.h"
//#include "Tests.h"
//#include "TestWindow.h"
#include "Dispatch.h"

int main(int argc, char *argv[]) {

	printf("Run at: %s\n--------------------------------------------\n", __TIME__);
	//getProcessInfo();
	//getProcesses();
	//createMyProcess();
	//EnumWindows(TestEnumWindowsProc, NULL);
	//getCurrentWin();

	WSADATA wsaLib;
	SOCKET connectedSocket;
	if (initWSA(&wsaLib) != 0) {
		puts("\nError occured initializing the winsock api");
		printf("\n\nPress enter to continue...");
		getchar();
		//exit(1);
	}
	else {
		if (connectedSocket = socketConnect()!=INVALID_SOCKET) {
			postData(connectedSocket);
			printf("\n\nPress enter to continue...");
			getchar();
		}
		else {
		puts("\nError occured connecting socket to server");
		}
	}
	return 0;
}

