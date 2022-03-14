#include "dewcin.h"

dewcin_app_entry_point
{
	// game init code

	dewcin::Game::setGameUpdate([&](float delta)
	{
		wchar_t charBuffer[256];
		swprintf(charBuffer, 256, L"delta: %f\n", delta);
		OutputDebugString(charBuffer);
	}
	);

	dewcin::Game::start();

	// game destroy code

	return 0;
}