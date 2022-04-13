#include "dewcin.h"

dewcin_app_entry_point
{
	// game init code

	float x = 250.0f, y = 250.0f;
	
	dewcin::Game::setGameUpdate([&](float delta)
	{
		wchar_t charBuffer[256];
		//swprintf(charBuffer, 256, L"delta: %f\n", delta);
		//OutputDebugString(charBuffer);

		static int frames = 0;
		static float timePassed = 0.0f;

		frames++;
		timePassed += delta;

		if (timePassed >= 1.0f)
		{
			swprintf(charBuffer, 256, L"FPS: %d\n", frames);
			OutputDebugString(charBuffer);

			timePassed -= 1.0f;
			frames = 0;
		}

		dewcin::Renderer::SetPixel(10, 10, { 0, 0, 255 });
		
		// x = 3.4 = 3	x = 3.4 + 0.5 = 3.9 -> 3
		// x = 3.8 = 3  x = 3.8 ) 0.5 = 4.3 -> 4
		dewcin::Renderer::FillRectangle({ int(x + 0.5f), int(y + 0.5f), 320, 180 }, { 0, 255, 0 });

		if (dewcin::Input::isKeyPressed(DC_W))
			y -= 100.0f * delta;
		else if (dewcin::Input::isKeyPressed(DC_S))
			y += 100.0f * delta;

		if (dewcin::Input::isKeyPressed(DC_A))
			x -= 100.0f * delta;
		else if (dewcin::Input::isKeyPressed(DC_D))
			x += 100.0f * delta;
	}
	);

	dewcin::Renderer::SetClearColor({ 200, 120, 45 });

	dewcin::Game::start();

	// game destroy code

	return 0;
}