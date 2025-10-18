#include "buttons.h";


int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	// Create Window Class

	WNDCLASS window_class = {};
	window_class.style = CS_HREDRAW | CS_VREDRAW;
	window_class.lpszClassName = "Game Window Class";
	window_class.lpfnWndProc = window_callback;
    window_class.hInstance = hInstance;
    
	// Register Class
	RegisterClass(&window_class);

	// Initialize GDI+

    ULONG_PTR gdiplusToken;
    Gdiplus::GdiplusStartupInput gdiplusStartupInput;
    Gdiplus::GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);

	// Create Window
	HWND window = CreateWindowA(window_class.lpszClassName, "Mystic Assassins", WS_OVERLAPPED| WS_CAPTION| WS_SYSMENU| WS_MINIMIZEBOX | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 1024 + 16 + 36 + 36, 1024 + 40 + 36 + 36, 0, 0, hInstance, 0);

    MSG message = {};
    HDC hdc = GetDC(window);
    HDC backBufferDC = CreateCompatibleDC(hdc);
    HBITMAP backBufferBitmap = CreateCompatibleBitmap(hdc, 1096, 1096);//Adjust size
    SelectObject(backBufferDC, backBufferBitmap);
    createButtons(window, hInstance);

    auto lastTime = std::chrono::high_resolution_clock::now();

    player1.position.x = 100;
    player1.position.y = 910;
    player2.position.x = 940;
    player2.position.y = 910;

    arena.hight.max = 980;
    arena.hight.min = 36;
    arena.width.max = 1024;
    arena.hight.min = 36;

    player2.isLookingRight = false;


	// Game loop
    while (running) {
        auto currentTime = std::chrono::high_resolution_clock::now();
        std::chrono::duration<float> delta = currentTime - lastTime;
        float deltaTime = delta.count();
        lastTime = currentTime;

        for (int i = 0; i < BUTTON_COUNT; i++) {
            input.buttons[i].changed = false;
        }
        while (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
            if (message.message == WM_QUIT) {
                running = false;
                break;
            }

            TranslateMessage(&message);
            DispatchMessage(&message);
        }

        Update(deltaTime,hdc);

        Draw(backBufferDC);

        // Limit frame rate
        //std::this_thread::sleep_for(std::chrono::milliseconds(16)); // 60 FPS

        // Swap the back buffer with the front buffer
        BitBlt(hdc, 0, 0, 1096, 1096, backBufferDC, 0, 0, SRCCOPY);
    }

	
    DeleteObject(backBufferBitmap);
    DeleteDC(backBufferDC);
    ReleaseDC(window,hdc);
    Gdiplus::GdiplusShutdown(gdiplusToken);
	DestroyWindow(window);
	
	return 0;
}
