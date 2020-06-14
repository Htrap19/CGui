#include "PixbufAnimation.hh"

namespace CGui
{
	PixbufAnimation::PixbufAnimation(PixbufSimpleAnim& animation)
	{
		this->animation = GDK_PIXBUF_ANIMATION(animation.GetWidget());
	}

	PixbufAnimation::PixbufAnimation(const char* filename)
	{
		animation = gdk_pixbuf_animation_new_from_file(filename, nullptr);
	}

	bool PixbufAnimation::IsStaticImage()
	{
		return gdk_pixbuf_animation_is_static_image(animation);
	}

	Pixbuf PixbufAnimation::StaticImage()
	{
		return Pixbuf(gdk_pixbuf_animation_get_static_image(animation));
	}

	int PixbufAnimation::Width()
	{
		return gdk_pixbuf_animation_get_width(animation);
	}

	int PixbufAnimation::Height()
	{
		return gdk_pixbuf_animation_get_height(animation);
	}

	GdkPixbufAnimation* PixbufAnimation::GetWidget()
	{
		return animation;
	}
}