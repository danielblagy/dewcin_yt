#include "input.h"

namespace dewcin
{
	Input::KeyboardInputMap Input::keyboard;
	Input::MouseInputMap Input::mouse;
	
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


	Input::Position Input::getMousePosition()
	{
		return mouse.position;
	}

	bool Input::isMouseButtonPressed(unsigned int buttonCode)
	{
		return mouse.buttons[buttonCode].isDown;
	}

	bool Input::isMouseButtonReleased(unsigned int buttonCode)
	{
		return !mouse.buttons[buttonCode].isDown;
	}

	// returns true if the mouse button has just been pressed
	bool Input::wasMouseButtonHit(unsigned int buttonCode)
	{
		return (!mouse.buttons[buttonCode].wasDown) && mouse.buttons[buttonCode].isDown;
	}

	void Input::processMouseInput(WPARAM wParam, LPARAM lParam)
	{
		mouse.buttons[DC_MOUSE_LEFT].wasDown = mouse.buttons[DC_MOUSE_LEFT].isDown;
		mouse.buttons[DC_MOUSE_RIGHT].wasDown = mouse.buttons[DC_MOUSE_RIGHT].isDown;
		mouse.buttons[DC_MOUSE_MIDDLE].wasDown = mouse.buttons[DC_MOUSE_MIDDLE].isDown;
		mouse.buttons[DC_MOUSE_X1].wasDown = mouse.buttons[DC_MOUSE_X1].isDown;
		mouse.buttons[DC_MOUSE_X2].wasDown = mouse.buttons[DC_MOUSE_X2].isDown;

		mouse.buttons[DC_MOUSE_LEFT].isDown = wParam & MK_LBUTTON;
		mouse.buttons[DC_MOUSE_RIGHT].isDown = wParam & MK_RBUTTON;
		mouse.buttons[DC_MOUSE_MIDDLE].isDown = wParam & MK_MBUTTON;
		mouse.buttons[DC_MOUSE_X1].isDown = wParam & MK_XBUTTON1;
		mouse.buttons[DC_MOUSE_X2].isDown = wParam & MK_XBUTTON2;

		updateMousePosition(lParam);
	}

	void Input::updateMousePosition(LPARAM lParam)
	{
		mouse.position.x = GET_X_LPARAM(lParam);
		mouse.position.y = GET_Y_LPARAM(lParam);
	}
}