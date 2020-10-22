#pragma once

#include "../Widget.hh"
#include "../../Pixbuf/Pixbuf/Pixbuf.hh"
#include "../../Pixbuf/PixbufAnimation/PixbufAnimation.hh"

namespace CGui
{
	class Image : public Widget
	{
	public:
		Image();
		Image(GtkImage* image);
		Image(const char* filename);
		Image(Pixbuf& pixbuf);
		Image(PixbufAnimation& pixbuf_animation);
		Image(const char* icon_name, IconSize size);
		void File(const char* filename);
		void Pixbuf(CGui::Pixbuf& pixbuf);
		CGui::Pixbuf Pixbuf();
		void Animation(PixbufAnimation& pixbuf_animation);
		PixbufAnimation Animation();
		void Iconname(const char* icon_name, IconSize size);
		IconInfo Iconname();
		void Resource(const char* resource_path);
		ImageType StorageType();
		void Clear();
		void PixelSize(int pixel_size);
		int PixelSize();
		bool IsImage();
	};
}
