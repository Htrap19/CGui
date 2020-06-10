#pragma once

#include "../Widget.hh"

namespace CGui
{
	class Image : public Widget
	{
	public:
		Image(const char* filename);
		Image(const char* filename, int width, int height, bool aspectRatio = true, GError** error = NULL);
	};
}
