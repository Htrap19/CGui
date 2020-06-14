#include "Pixbuf.hh"

namespace CGui
{
	Pixbuf::Pixbuf(GdkPixbuf* pixbuf) : pixbuf{pixbuf}
	{
	}

	Pixbuf::Pixbuf(const char* filename)
	{
		pixbuf = gdk_pixbuf_new_from_file(filename, nullptr);
	}

	Pixbuf::Pixbuf(const char* filename, int width, int height, bool aspactRatio)
	{
		pixbuf = gdk_pixbuf_new_from_file_at_scale(filename, width, height, aspactRatio, nullptr);
	}

	Pixbuf::Pixbuf(const char* filename, int width, int height)
	{
		pixbuf = gdk_pixbuf_new_from_file_at_size(filename, width, height, nullptr);
	}

	void Pixbuf::SimpleScale(int dest_width, int dest_height, InterpType type)
	{
		this->pixbuf = gdk_pixbuf_scale_simple(this->pixbuf, dest_width, dest_height, (GdkInterpType)type);
	}

	void Pixbuf::Scale(int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, InterpType type)
	{
		gdk_pixbuf_scale(this->pixbuf, this->pixbuf, dest_x, dest_y, dest_width, dest_height, offset_x, offset_y, scale_x, scale_y, (GdkInterpType)type);
	}

	void Pixbuf::CompositeColorSimple(int dest_width, int dest_height, InterpType type, int overall_alpha, int check_size, int color1, int color2)
	{
		this->pixbuf = gdk_pixbuf_composite_color_simple(this->pixbuf, dest_width, dest_height, (GdkInterpType)type, overall_alpha, check_size, color1, color2);
	}

	void Pixbuf::Composite(int dest_x, int dest_y, int dest_width, int dest_height, double offset_x, double offset_y, double scale_x, double scale_y, InterpType type, bool overall_alpha)
	{
		gdk_pixbuf_composite(this->pixbuf, this->pixbuf, dest_x, dest_y, dest_width, dest_height, offset_x, offset_y, scale_x, scale_y, (GdkInterpType)type, overall_alpha);
	}

	void Pixbuf::Rotate(PixbufRotation rotation)
	{
		this->pixbuf = gdk_pixbuf_rotate_simple(pixbuf, (GdkPixbufRotation)rotation);
	}

	void Pixbuf::Flip(bool horizontal)
	{
		this->pixbuf = gdk_pixbuf_flip(this->pixbuf, horizontal);
	}

	GdkPixbuf* Pixbuf::GetWidget()
	{
		return pixbuf;
	}
}