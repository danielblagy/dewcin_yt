#include "renderer.h"

namespace dewcin
{
	void Renderer::SetPixel(int x, int y, const RGBColor& color)
	{
		BitmapBuffer& buffer = getInstance().buffer;

		// clipping
		if (x < 0 || x > buffer.width || y < 0 || y > buffer.height)
			return;

		// convert (u8, u8, u8) rgb color to u32 representation
		uint32_t raw_color = (color.red << 16) | (color.green << 8) | (color.blue << 0);

		uint8_t* row = (uint8_t*)buffer.memory + x * bytes_per_pixel + y * buffer.pitch;
		uint32_t* pixel = (uint32_t*)row;
		*pixel = raw_color;
	}

	void Renderer::FillRectangle(const Rect& rect, const RGBColor& color)
	{
		BitmapBuffer& buffer = getInstance().buffer;

		int minX = rect.x;
		int minY = rect.y;
		int maxX = rect.x + rect.width;
		int maxY = rect.y + rect.height;

		// clipping
		if (minX < 0)				minX = 0;
		if (minY < 0)				minY = 0;
		if (maxX > buffer.width)	maxX = buffer.width;
		if (maxY > buffer.height)	maxY = buffer.height;

		// convert (u8, u8, u8) rgb color to u32 representation
		uint32_t raw_color = (color.red << 16) | (color.green << 8) | (color.blue << 0);

		uint8_t* row = (uint8_t*)buffer.memory + minX * bytes_per_pixel + minY * buffer.pitch;
		for (int y = minY; y < maxY; y++)
		{
			uint32_t* pixel = (uint32_t*)row;
			for (int x = minX; x < maxX; x++)
			{
				*pixel++ = raw_color;
			}
			row += buffer.pitch;
		}
	}

	void Renderer::getWindowDimensions(int* outWidth, int* outHeight)
	{
		RECT clientRect;
		GetClientRect(getInstance().windowHandle, &clientRect);

		*outWidth = clientRect.right - clientRect.left;
		*outHeight = clientRect.bottom - clientRect.top;
	}

	void Renderer::resizeFrameBuffer(int width, int height)
	{
		BitmapBuffer& buffer = getInstance().buffer;

		if (buffer.memory)
		{
			VirtualFree(buffer.memory, 0, MEM_RELEASE);
		}

		buffer.width = width;
		buffer.height = height;

		buffer.info.bmiHeader.biSize = sizeof(buffer.info.bmiHeader);
		buffer.info.bmiHeader.biWidth = buffer.width;
		buffer.info.bmiHeader.biHeight = -(buffer.height);
		buffer.info.bmiHeader.biPlanes = 1;
		buffer.info.bmiHeader.biBitCount = 32;
		buffer.info.bmiHeader.biCompression = BI_RGB;

		int bufferMemorySize = buffer.width * buffer.height * bytes_per_pixel;
		buffer.memory = VirtualAlloc(0, bufferMemorySize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		buffer.pitch = buffer.width * bytes_per_pixel;
	}

	void Renderer::copyBufferToWindow(HDC deviceContext, int windowWidth, int windowHeight)
	{
		BitmapBuffer& buffer = getInstance().buffer;

		StretchDIBits(
			deviceContext,
			0, 0, windowWidth, windowHeight,
			0, 0, buffer.width, buffer.height,
			buffer.memory,
			&(buffer.info),
			DIB_RGB_COLORS,
			SRCCOPY
		);
	}

	void Renderer::clear()
	{
		BitmapBuffer& buffer = getInstance().buffer;
		
		FillRectangle({ 0, 0, buffer.width, buffer.height }, getInstance().clearColor);
	}
}