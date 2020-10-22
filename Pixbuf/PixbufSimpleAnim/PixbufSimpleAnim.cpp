#include "PixbufSimpleAnim.hh"

namespace CGui
{
	PixbufSimpleAnim::PixbufSimpleAnim(int width, int height, float rate)
	{
		animation = gdk_pixbuf_simple_anim_new(width, height, rate);
	}

	void PixbufSimpleAnim::AddFrame(Pixbuf& pixbuf)
	{
		gdk_pixbuf_simple_anim_add_frame(animation, pixbuf.GetWidget());
	}

	void PixbufSimpleAnim::Loop(bool loop)
	{
		gdk_pixbuf_simple_anim_set_loop(animation, loop);
	}

	bool PixbufSimpleAnim::Loop()
	{
		return gdk_pixbuf_simple_anim_get_loop(animation);
	}

	bool PixbufSimpleAnim::IsPixbufSimpleAnim()
	{
		return GDK_IS_PIXBUF_SIMPLE_ANIM(animation);
	}

	GdkPixbufSimpleAnim* PixbufSimpleAnim::GetWidget()
	{
		return animation;
	}
}