#include "dewcin.h"

dewcin_app_entry_point
{
	// game init code

	int x = 250, y = 250;
	
	dewcin::Game::setGameUpdate([&](float delta)
	{
		wchar_t charBuffer[256];
		swprintf(charBuffer, 256, L"delta: %f\n", delta);
		OutputDebugString(charBuffer);

		dewcin::Renderer::SetPixel(10, 10, { 0, 0, 255 });
		
		dewcin::Renderer::FillRectangle({ x, y, 320, 180 }, { 0, 255, 0 });

		if (dewcin::Input::isKeyPressed(DC_UP))
			y -= 10;
		else if (dewcin::Input::isKeyPressed(DC_DOWN))
			y += 10;

		if (dewcin::Input::isKeyPressed(DC_LEFT))
			x -= 10;
		else if (dewcin::Input::isKeyPressed(DC_RIGHT))
			x += 10;
	}
	);

	dewcin::Renderer::SetClearColor({ 200, 120, 45 });

	dewcin::Game::start();

	// game destroy code

	return 0;
}