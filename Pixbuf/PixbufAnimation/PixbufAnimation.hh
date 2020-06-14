#pragma once

#include <gtk/gtk.h>
#include "../PixbufSimpleAnim/PixbufSimpleAnim.hh"

namespace CGui
{
	class PixbufAnimation
	{
	public:
		PixbufAnimation(PixbufSimpleAnim& animation);
		PixbufAnimation(const char* filename);
		bool IsStaticImage();
		Pixbuf StaticImage();
		int Width();
		int Height();
		GdkPixbufAnimation* GetWidget();

	protected:
		GdkPixbufAnimation* animation;
	};
}