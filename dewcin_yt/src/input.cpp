#include "input.h"

namespace dewcin
{
	Input::KeyboardInputMap Input::keyboard;
	
	Input::KeyState Input::getKeyState(uint32_t keycode)
	{
		return keyboard.keys[keycode];
	}

	bool Input::isKeyPressed(uint32_t keycode)
	{
		return keyboard.keys[keycode].isDown;
	}

	bool Input::isKeyReleased(uint32_t keycode)
	{
		return !keyboard.keys[keycode].isDown;
	}

	// returns true if the key has just been pressed
	bool Input::wasKeyHit(uint32_t keycode)
	{
		return ((!keyboard.keys[keycode].wasDown) && keyboard.keys[keycode].isDown);
	}

	void Input::processKeyboardInput(uint32_t VKCode, bool wasDown, bool isDown)
	{
		if (wasDown != isDown)
		{
			if (VKCode >= 'A' && VKCode <= 'Z')
			{
				uint32_t dewcinKeycode = VKCode - 'A';
				keyboard.keys[dewcinKeycode].isDown = isDown;
				keyboard.keys[dewcinKeycode].wasDown = wasDown;
			}
			else if (VKCode == VK_UP)
			{
				keyboard.keys[DC_UP].isDown = isDown;
				keyboard.keys[DC_UP].wasDown = wasDown;
			}
			else if (VKCode == VK_DOWN)
			{
				keyboard.keys[DC_DOWN].isDown = isDown;
				keyboard.keys[DC_DOWN].wasDown = wasDown;
			}
			else if (VKCode == VK_LEFT)
			{
				keyboard.keys[DC_LEFT].isDown = isDown;
				keyboard.keys[DC_LEFT].wasDown = wasDown;
			}
			else if (VKCode == VK_RIGHT)
			{
				keyboard.keys[DC_RIGHT].isDown = isDown;
				keyboard.keys[DC_RIGHT].wasDown = wasDown;
			}
			else if (VKCode >= '0' && VKCode <= '9')
			{
				uint32_t dc_keycode = VKCode - '0' + DC_0;
				keyboard.keys[dc_keycode].isDown = isDown;
				keyboard.keys[dc_keycode].wasDown = wasDown;
			}
			else if (VKCode == VK_OEM_MINUS)
			{
				keyboard.keys[DC_MINUS].isDown = isDown;
				keyboard.keys[DC_MINUS].wasDown = wasDown;
			}
			else if (VKCode == VK_OEM_PLUS)
			{
				keyboard.keys[DC_PLUS].isDown = isDown;
				keyboard.keys[DC_PLUS].wasDown = wasDown;
			}
			else if (VKCode == VK_SHIFT)
			{
				keyboard.keys[DC_SHIFT].isDown = isDown;
				keyboard.keys[DC_SHIFT].wasDown = wasDown;
			}
			else if (VKCode == VK_CONTROL)
			{
				keyboard.keys[DC_CONTROL].isDown = isDown;
				keyboard.keys[DC_CONTROL].wasDown = wasDown;
			}
			else if (VKCode == VK_MENU)
			{
				keyboard.keys[DC_ALT].isDown = isDown;
				keyboard.keys[DC_ALT].wasDown = wasDown;
			}
			else if (VKCode == VK_SPACE)
			{
				keyboard.keys[DC_SPACE].isDown = isDown;
				keyboard.keys[DC_SPACE].wasDown = wasDown;
			}
			else if (VKCode == VK_ESCAPE)
			{
				keyboard.keys[DC_ESCAPE].isDown = isDown;
				keyboard.keys[DC_ESCAPE].wasDown = wasDown;
			}
			else if (VKCode == VK_CAPITAL)
			{
				keyboard.keys[DC_CAPSLOCK].isDown = isDown;
				keyboard.keys[DC_CAPSLOCK].wasDown = wasDown;
			}
			else if (VKCode == VK_TAB)
			{
				keyboard.keys[DC_TAB].isDown = isDown;
				keyboard.keys[DC_TAB].wasDown = wasDown;
			}
			else if (VKCode == VK_RETURN)
			{
				keyboard.keys[DC_ENTER].isDown = isDown;
				keyboard.keys[DC_ENTER].wasDown = wasDown;
			}
			else if (VKCode == VK_BACK)
			{
				keyboard.keys[DC_BACKSPACE].isDown = isDown;
				keyboard.keys[DC_BACKSPACE].wasDown = wasDown;
			}
			else if (VKCode == VK_OEM_3)
			{
				keyboard.keys[DC_TILDE].isDown = isDown;
				keyboard.keys[DC_TILDE].wasDown = wasDown;
			}
		}
	}
}