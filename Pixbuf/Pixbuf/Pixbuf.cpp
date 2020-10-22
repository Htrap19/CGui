#include "Pixbuf.hh"

namespace CGui
{
	Pixbuf::Pixbuf(GdkPixbuf* pixbuf, bool copy_options) : error{ nullptr }
	{
		if (copy_options)
			gdk_pixbuf_copy_options(pixbuf, this->pixbuf);
		else
			this->pixbuf = gdk_pixbuf_copy(pixbuf);
	}

	Pixbuf::Pixbuf(const char* filename) : error{ nullptr }
	{
		pixbuf = gdk_pixbuf_new_from_file(filename, &error);
		if (!pixbuf)
			fprintf(stderr, "%s\n", error->message);
	}

	Pixbuf::Pixbuf(const char* filename, int width, int height, bool aspactRatio) : error{ nullptr }
	{
		pixbuf = gdk_pixbuf_new_from_file_at_scale(filename, width, height, aspactRatio, &error);
		if (!pixbuf)
			fprintf(stderr, "%s\n", error->message);
	}

	Pixbuf::Pixbuf(const char* filename, int width, int height) : error{ nullptr }
	{
		pixbuf = gdk_pixbuf_new_from_file_at_size(filename, width, height, &error);
		if (!pixbuf)
			fprintf(stderr, "%s\n", error->message);
	}

	Pixbuf::~Pixbuf()
	{
		if (this->HasError())
			g_error_free(error);
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

	Pixbuf Pixbuf::SubPixbuf(int src_x, int src_y, int width, int height)
	{
		return Pixbuf(gdk_pixbuf_new_subpixbuf(this->pixbuf, src_x, src_y, width, height));
	}

	void Pixbuf::AddAlpha(bool substitute_color, unsigned char r, unsigned char g, unsigned int b)
	{
		this->pixbuf = gdk_pixbuf_add_alpha(this->pixbuf, substitute_color, r, g, b);
	}

	Pixbuf Pixbuf::CopyArea(int src_x, int src_y, int width, int height, int dest_x, int dest_y)
	{
		GdkPixbuf* buff = this->pixbuf;
		gdk_pixbuf_copy_area(this->pixbuf, src_x, src_y, width, height, buff, dest_x, dest_y);
		return Pixbuf(buff);
	}

	void Pixbuf::SaturateAndPixelate(float saturate, bool pixelate)
	{
		gdk_pixbuf_saturate_and_pixelate(this->pixbuf, this->pixbuf, saturate, pixelate);
	}

	void Pixbuf::ApplyEmbeddedOrientation()
	{
		this->pixbuf = gdk_pixbuf_apply_embedded_orientation(this->pixbuf);
	}

	void Pixbuf::Fill(unsigned int pixel)
	{
		gdk_pixbuf_fill(this->pixbuf, pixel);
	}

	bool Pixbuf::HasError()
	{
		return (error != nullptr);
	}

	const char* Pixbuf::ErrorMessage()
	{
		return error->message;
	}

	int Pixbuf::ErrorDomain()
	{
		return error->domain;
	}

	int Pixbuf::ErrorCode()
	{
		return error->code;
	}

	bool Pixbuf::IsPixbuf()
	{
		return GDK_IS_PIXBUF(pixbuf);
	}

	GdkPixbuf* Pixbuf::GetWidget()
	{
		return pixbuf;
	}
}