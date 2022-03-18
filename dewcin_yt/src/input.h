#pragma once

#include <windows.h>

#include <stdint.h>

#define DC_MAX_KEYS 52

#define DC_A			0
#define DC_B			1
#define DC_C			2
#define DC_D			3
#define DC_E			4
#define DC_F			5
#define DC_G			6
#define DC_H			7
#define DC_I			8
#define DC_J			9
#define DC_K			10
#define DC_L			11
#define DC_M			12
#define DC_N			13
#define DC_O			14
#define DC_P			15
#define DC_Q			16
#define DC_R			17
#define DC_S			18
#define DC_T			19
#define DC_U			20
#define DC_V			21
#define DC_W			22
#define DC_X			23
#define DC_Y			24
#define DC_Z			25

#define DC_UP			26
#define DC_DOWN			27
#define DC_LEFT			28
#define DC_RIGHT		29

#define DC_0			30
#define DC_1			31
#define DC_2			32
#define DC_3			33
#define DC_4			34
#define DC_5			35
#define DC_6			36
#define DC_7			37
#define DC_8			38
#define DC_9			39
#define DC_MINUS		40
#define DC_PLUS			41

#define DC_SHIFT		42
#define DC_CONTROL		43
#define DC_ALT			44
#define DC_SPACE		45
#define DC_ESCAPE		46
#define DC_CAPSLOCK		47
#define DC_TAB			48
#define DC_ENTER		49
#define DC_BACKSPACE	50
#define DC_TILDE		51

namespace dewcin
{
	class Input
	{
		friend LRESULT CALLBACK WindowCallback(
			HWND windowHandle,
			UINT message,
			WPARAM wParam,
			LPARAM lParam
		);

	public:
		struct KeyState
		{
			bool wasDown, isDown;
		};

		struct KeyboardInputMap
		{
			KeyState keys[DC_MAX_KEYS];
		};

	private:
		static KeyboardInputMap keyboard;

	public:
		static KeyState getKeyState(uint32_t keycode);

		static bool isKeyPressed(uint32_t keycode);

		static bool isKeyReleased(uint32_t keycode);

		// returns true if the key has just been pressed
		static bool wasKeyHit(uint32_t keycode);
	
	private:
		static void processKeyboardInput(uint32_t VKCode, bool wasDown, bool isDown);
	};
}