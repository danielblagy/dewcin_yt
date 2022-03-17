#include "dewcin.h"

dewcin_app_entry_point
{
	// game init code

	dewcin::Game::setGameUpdate([&](float delta)
	{
		wchar_t charBuffer[256];
		swprintf(charBuffer, 256, L"delta: %f\n", delta);
		OutputDebugString(charBuffer);

		dewcin::Renderer::SetPixel(10, 10, { 0, 0, 255 });
		
		dewcin::Renderer::FillRectangle({ 250, 250, 320, 180 }, { 0, 255, 0 });
	}
	);

	dewcin::Renderer::SetClearColor({ 200, 120, 45 });

	dewcin::Game::start();

	// game destroy code

	return 0;
}