#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Image : public widget
  {
    public:
      Image(const gchar *filename);
      Image(const gchar *filename, int width, int height, gboolean aspectRatio = true, GError **error = NULL);
      void Name(const char *name);
      const char *Name();
      void Sensitive(bool sensitive);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *image;
  };

  Image::Image(const gchar *filename)
  { image = gtk_image_new_from_file(filename); }

  Image::Image(const gchar *filename, int width, int height, gboolean aspectRatio, GError **error)
  {
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file_at_scale(filename, width, height, aspectRatio, error);
    image = gtk_image_new_from_pixbuf(pixbuf);
  }

  void Image::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(image), name); }

  const char *Image::Name()
  { return gtk_widget_get_name(GTK_WIDGET(image)); }

  void Image::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(image), sensitive); }

  void Image::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(image), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(image), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Image::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(image), x, y); }

  void Image::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(image))), classname); }

  void Image::Show()
  { gtk_widget_show(GTK_WIDGET(image)); }

  GtkWidget *Image::GetWidget()
  { return image; }
}
