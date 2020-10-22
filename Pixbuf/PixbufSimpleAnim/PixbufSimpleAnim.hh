#pragma once

#include <gtk/gtk.h>
#include "../Pixbuf/Pixbuf.hh"

namespace CGui
{
	class PixbufSimpleAnim
	{
	public:
		PixbufSimpleAnim(int width, int height, float rate);
		void AddFrame(Pixbuf& pixbuf);
		void Loop(bool loop);
		bool Loop();
		bool IsPixbufSimpleAnim();
		GdkPixbufSimpleAnim* GetWidget();

	protected:
		GdkPixbufSimpleAnim* animation;
	};
}