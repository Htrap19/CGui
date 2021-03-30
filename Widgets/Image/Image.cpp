#include "./Image.hh"

namespace CGui
{
	Image::Image()
	{
		m_Widget = gtk_image_new();
		this->SetContext(m_Widget);
	}

	Image::Image(GtkImage* image)
	{
		this->m_Widget = GTK_WIDGET(image);
		this->SetContext(m_Widget);
	}

	Image::Image(const char* filename)
	{
		m_Widget = gtk_image_new_from_file(filename);
		this->SetContext(m_Widget);
	}

	Image::Image(CGui::Pixbuf& pixbuf)
	{
		m_Widget = gtk_image_new_from_pixbuf(pixbuf.GetWidget());
		this->SetContext(m_Widget);
	}

	Image::Image(PixbufAnimation& pixbuf_animation)
	{
		m_Widget = gtk_image_new_from_animation(pixbuf_animation.GetWidget());
		this->SetContext(m_Widget);
	}

	Image::Image(const char* icon_name, IconSize size)
	{
		m_Widget = gtk_image_new_from_icon_name(icon_name, (GtkIconSize)size);
		this->SetContext(m_Widget);
	}

	void Image::File(const char* filename)
	{
		gtk_image_set_from_file(GTK_IMAGE(m_Widget), filename);
	}

	void Image::Pixbuf(CGui::Pixbuf& pixbuf)
	{
		gtk_image_set_from_pixbuf(GTK_IMAGE(m_Widget), pixbuf.GetWidget());
	}

	CGui::Pixbuf Image::Pixbuf()
	{
		return CGui::Pixbuf(gtk_image_get_pixbuf(GTK_IMAGE(m_Widget)));
	}

	void Image::Animation(PixbufAnimation& pixbuf_animation)
	{
		gtk_image_set_from_animation(GTK_IMAGE(m_Widget), pixbuf_animation.GetWidget());
	}

	PixbufAnimation Image::Animation()
	{
		return PixbufAnimation(gtk_image_get_animation(GTK_IMAGE(m_Widget)));
	}

	void Image::Iconname(const char* icon_name, IconSize size)
	{
		gtk_image_set_from_icon_name(GTK_IMAGE(m_Widget), icon_name, (GtkIconSize)size);
	}

	IconInfo Image::Iconname()
	{
		const char* icon_name;
		GtkIconSize size;
		gtk_image_get_icon_name(GTK_IMAGE(m_Widget), &icon_name, &size);

		return { icon_name, (IconSize)size };
	}

	void Image::Resource(const char* resource_path)
	{
		gtk_image_set_from_resource(GTK_IMAGE(m_Widget), resource_path);
	}

	ImageType Image::StorageType()
	{
		return (ImageType)gtk_image_get_storage_type(GTK_IMAGE(m_Widget));
	}

	void Image::Clear()
	{
		gtk_image_clear(GTK_IMAGE(m_Widget));
	}

	void Image::PixelSize(int pixel_size)
	{
		gtk_image_set_pixel_size(GTK_IMAGE(m_Widget), pixel_size);
	}

	int Image::PixelSize()
	{
		return gtk_image_get_pixel_size(GTK_IMAGE(m_Widget));
	}

	bool Image::IsImage()
	{
		return GTK_IS_IMAGE(m_Widget);
	}
};
