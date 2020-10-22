#pragma once

#include <gtk/gtk.h>
#include "../PixbufSimpleAnim/PixbufSimpleAnim.hh"

namespace CGui
{
	class PixbufAnimation
	{
	public:
		PixbufAnimation(GdkPixbufAnimation* animation);
		PixbufAnimation(PixbufSimpleAnim& animation);
		PixbufAnimation(const char* filename);
		bool IsStaticImage();
		Pixbuf StaticImage();
		int Width();
		int Height();
		bool IsPixbufAnimation();
		GdkPixbufAnimation* GetWidget();

	protected:
		GdkPixbufAnimation* animation;
	};
}