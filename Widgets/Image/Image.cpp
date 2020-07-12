#include "./Image.hh"

namespace CGui
{
	Image::Image()
	{
		widget = gtk_image_new();
		this->SetContext(widget);
	}

	Image::Image(GtkImage* image)
	{
		this->widget = GTK_WIDGET(image);
		this->SetContext(widget);
	}

	Image::Image(const char* filename)
	{
		widget = gtk_image_new_from_file(filename);
		this->SetContext(widget);
	}

	Image::Image(Pixbuf& pixbuf)
	{
		widget = gtk_image_new_from_pixbuf(pixbuf.GetWidget());
		this->SetContext(widget);
	}

	Image::Image(PixbufAnimation& pixbuf_animation)
	{
		widget = gtk_image_new_from_animation(pixbuf_animation.GetWidget());
		this->SetContext(widget);
	}

	Image::Image(const char* icon_name, IconSize size)
	{
		widget = gtk_image_new_from_icon_name(icon_name, (GtkIconSize)size);
		this->SetContext(widget);
	}

	void Image::File(const char* filename)
	{
		gtk_image_set_from_file(GTK_IMAGE(widget), filename);
	}

	void Image::ImagePixbuf(Pixbuf& pixbuf)
	{
		gtk_image_set_from_pixbuf(GTK_IMAGE(widget), pixbuf.GetWidget());
		m_ImagePixbuf = &pixbuf;
	}

	Pixbuf& Image::ImagePixbuf()
	{
		return *m_ImagePixbuf;
	}

	void Image::Animation(PixbufAnimation& pixbuf_animation)
	{
		gtk_image_set_from_animation(GTK_IMAGE(widget), pixbuf_animation.GetWidget());
		m_PixbufAnimation = &pixbuf_animation;
	}

	PixbufAnimation& Image::Animation()
	{
		return *m_PixbufAnimation;
	}

	void Image::Iconname(const char* icon_name, IconSize size)
	{
		gtk_image_set_from_icon_name(GTK_IMAGE(widget), icon_name, (GtkIconSize)size);
	}

	IconInfo Image::Iconname()
	{
		const char* icon_name;
		GtkIconSize size;
		gtk_image_get_icon_name(GTK_IMAGE(widget), &icon_name, &size);

		return { icon_name, (IconSize)size };
	}

	void Image::Resource(const char* resource_path)
	{
		gtk_image_set_from_resource(GTK_IMAGE(widget), resource_path);
	}

	ImageType Image::StorageType()
	{
		return (ImageType)gtk_image_get_storage_type(GTK_IMAGE(widget));
	}

	void Image::Clear()
	{
		gtk_image_clear(GTK_IMAGE(widget));
	}

	void Image::PixelSize(int pixel_size)
	{
		gtk_image_set_pixel_size(GTK_IMAGE(widget), pixel_size);
	}

	int Image::PixelSize()
	{
		return gtk_image_get_pixel_size(GTK_IMAGE(widget));
	}
};
