#include "Update.h"


LRESULT CALLBACK window_callback(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
    RECT clientRect;
	LRESULT result = 0;

 
	switch (uMsg)
	{
	case WM_PAINT: {
        hdc = BeginPaint(hwnd, &ps);
		//draw
        GetClientRect(hwnd, &clientRect);
		EndPaint(hwnd, &ps);
		return 0;
	}      
	case WM_CLOSE:
	case WM_DESTROY:

        CleanupImages();
        CleanupGraphics();

		running = false;

		break;
	case WM_COMMAND:
		if (HIWORD(wParam) == BN_CLICKED)
		{
			switch (LOWORD(wParam))
			{
			case IDC_BUTTON1:
				currentTab = 2;
				break;
			case IDC_BUTTON2:
				running = false;
				break;
			case IDC_BUTTON3:
				currentTab = 1;
				break;
			case IDC_BUTTON4:
				currentTab = 0;
				break;
			case IDC_BUTTON5:
                handleButtonClick(button5,wizard);
				break;
			case IDC_BUTTON6:
                handleButtonClick(button6, knight);
				break;
			case IDC_BUTTON7:
                handleButtonClick(button7, thief);
				break;
			case IDC_BUTTON8:
                handleButtonClick(button8, vampire);
				break;
			case IDC_BUTTON9:
                handleButtonClick(button9, archer);
				break;
			case IDC_BUTTON10:
				currentTab = 3;
				break;
			}
			gameStarted = (currentTab == 0);

			ShowWindow(GetDlgItem(hwnd, IDC_BUTTON1), (currentTab == 0) ? SW_SHOW : SW_HIDE);
			ShowWindow(GetDlgItem(hwnd, IDC_BUTTON2), (currentTab == 0) ? SW_SHOW : SW_HIDE);
			ShowWindow(GetDlgItem(hwnd, IDC_BUTTON3), (currentTab == 0) ? SW_SHOW : SW_HIDE);
			ShowWindow(GetDlgItem(hwnd, IDC_BUTTON4), (currentTab == 1 || currentTab == 2) ? SW_SHOW : SW_HIDE);

			InvalidateRect(hwnd, NULL, TRUE);
		}
	break;
       case WM_KEYDOWN:
       case WM_KEYUP:
       case WM_SYSKEYUP:
       case WM_SYSKEYDOWN:
          {
           ProcessKeyEvent(wParam, lParam);
          }
     break;
	
	default: return result = DefWindowProc(hwnd, uMsg, wParam, lParam);

	}
}


