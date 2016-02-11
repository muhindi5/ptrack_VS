//#include <Windows.h>
//
//	const char g_szClassName[] = "WinClassus";
//
//	//step 4: The window procedure
//	LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam) {
//		switch (msg) {
//		case WM_CLOSE:
//			DestroyWindow(hWnd);
//			break;
//		case WM_DESTROY:
//			PostQuitMessage(0);
//			break;
//		default:
//			return DefWindowProc(hWnd, msg, wParam, lParam);
//		}
//		return 0;
//	}
//
//int WINAPI WinMain(HINSTANCE hInst, //loading resources or other module task
//	HINSTANCE prevInst,//handle to prev run instance of prog. No longer in use
//	LPSTR lpCmdLine, //command line arguments as a single string
//	int cmdShow //an int which can be passed to showWindow
//	) {
//	WNDCLASSEX wc;
//	HWND hWnd;
//	MSG message;
//	//step 1: Register the Window class
//	wc.cbSize = sizeof(WNDCLASSEX);
//	wc.style = 0;
//	wc.lpfnWndProc = WndProc;
//	wc.cbClsExtra = 0;
//	wc.cbWndExtra = 0;
//	wc.hInstance = hInst;
//	wc.hIcon = NULL;
//	wc.hCursor = NULL;
//	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//	wc.lpszClassName = g_szClassName;
//	wc.hIconSm = NULL;
//
//	if (!RegisterClassEx(&wc)) {
//		MessageBox(NULL, "Window Class Registration Failed", "Error", MB_ICONEXCLAMATION | MB_OK);
//		return 0;
//	}
//	MessageBox(NULL, "Good Byres", "NOTE", MB_CANCELTRYCONTINUE);
//	//return 0;
//
//	//step 2: creating the window
//	hWnd = CreateWindowEx(WS_EX_CLIENTEDGE, g_szClassName, "Title of Window", WS_OVERLAPPEDWINDOW,
//		CW_USEDEFAULT, CW_USEDEFAULT, 240, 120, NULL, NULL, hInst, NULL);
//
//	if (hWnd == NULL) {
//		MessageBox(NULL, "Window Creation Failed", "Error", MB_ICONEXCLAMATION | MB_OK);
//		return 0;
//	}
//
//	ShowWindow(hWnd, cmdShow);
//	UpdateWindow(hWnd);
//
//	//step 3: the message loop
//	while (GetMessage(&message, NULL, 0, 0) > 0) {
//		TranslateMessage(&message);
//		DispatchMessage(&message);
//	}
//	return message.wParam;
//}
//
//
