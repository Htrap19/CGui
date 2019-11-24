#include "CGuiImage.hh"

Image::Image(const gchar *filename)
{ image = gtk_image_new_from_file(filename); }

Image::Image(const gchar *filename, int width, int height, gboolean aspectRatio, GError **error)
{
  GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file_at_scale(filename, width, height, aspectRatio, error);
  image = gtk_image_new_from_pixbuf(pixbuf);
}

void Image::Align(Alignments halign, Alignments valign)
{
  Converter::Convert convert;
  gtk_widget_set_halign(GTK_WIDGET(image), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
  gtk_widget_set_valign(GTK_WIDGET(image), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
}

void Image::SizeRequest(guint x, guint y)
{ gtk_widget_set_size_request(GTK_WIDGET(image), x, y); }

GtkWidget *Image::GetWidget()
{ return image; }
