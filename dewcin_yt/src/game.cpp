#include "game.h"

namespace dewcin
{
	Game::Game()
	{
		// init window properties to default values
		windowTitle = L"Dewcin App";
		windowWidth = 1280;
		windowHeight = 720;
	}

	// handles window events
	LRESULT CALLBACK WindowCallback(
		HWND windowHandle,
		UINT message,
		WPARAM wParam,
		LPARAM lParam
	)
	{
		LRESULT result = 0;

		switch (message)
		{
		case WM_CLOSE:
		{
			Game::getInstance().running = false;
			OutputDebugString(L"window close\n");
		}break;

		case WM_DESTROY:
		{
			Game::getInstance().running = false;
			OutputDebugString(L"window destroy\n");
		}break;

		case WM_PAINT:
		{
			OutputDebugString(L"window paint\n");
			
			PAINTSTRUCT paint;
			HDC device_context = BeginPaint(windowHandle, &paint);

			FillRect(device_context, &paint.rcPaint, (HBRUSH)(COLOR_WINDOW + 2));

			EndPaint(windowHandle, &paint);
		}break;

		default:
			result = DefWindowProc(windowHandle, message, wParam, lParam);
		}

		return result;
	}

	void Game::startWindow()
	{
		const wchar_t* className = L"dewcin_window";

		WNDCLASS windowClass = {};

		windowClass.style = CS_HREDRAW | CS_VREDRAW;
		windowClass.lpfnWndProc = WindowCallback;
		windowClass.hInstance = hInstance;
		windowClass.lpszClassName = className;

		if (!RegisterClass(&windowClass))
		{
			OutputDebugString(L"Failed to register window class\n");
			return;
		}

		windowHandle = CreateWindowEx(
			0,
			className,
			windowTitle.c_str(),
			WS_OVERLAPPEDWINDOW | WS_VISIBLE,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			windowWidth,
			windowHeight,
			0,
			0,
			hInstance,
			0
		);

		if (windowHandle)
		{
			OutputDebugString(L"GAME INIT\n");
			running = true;

			// init the clock
			LARGE_INTEGER cpu_frequency;
			QueryPerformanceFrequency(&cpu_frequency);

			LARGE_INTEGER last_counter;
			QueryPerformanceCounter(&last_counter);

			while (running)
			{
				LARGE_INTEGER current_counter;
				QueryPerformanceCounter(&current_counter);

				int64_t counter_elapsed = current_counter.QuadPart - last_counter.QuadPart;

				float delta = (float)counter_elapsed / (float)cpu_frequency.QuadPart;	// in seconds

				last_counter = current_counter;
				
				// process windows messages
				MSG message;
				while (PeekMessage(&message, 0, 0, 0, PM_REMOVE))
				{
					if (message.message == WM_QUIT)
						running = false;

					TranslateMessage(&message);
					DispatchMessage(&message);		// Send message to the WindowProc (WindowCallback)
				}

				// update & render

				getInstance().update(delta);
			}
		}
		else
		{
			OutputDebugString(L"Failed to create a window\n");
		}
	}
}