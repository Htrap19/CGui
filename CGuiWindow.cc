#include "CGuiWindow.hh"

Window::Window(WindowType type, const gchar *title, WindowPos pos)
{
  Converter::Convert convert;
  window = gtk_window_new(std::get<GtkWindowType>(convert.ConvertToGtkCode(type)));
  g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
  gtk_window_set_title(GTK_WINDOW(window), title);
  gtk_window_set_position(GTK_WINDOW(window), std::get<GtkWindowPosition>(convert.ConvertToGtkCode(pos)));
}

void Window::Icon(const gchar *iconpath)
{
  GError *error = NULL;
  GdkPixbuf *icon = gdk_pixbuf_new_from_file(iconpath, &error);
  if(!icon)
  {
    fprintf(stderr, "%s\n", error->message);
    g_error_free(error);
  }
  gtk_window_set_icon(GTK_WINDOW(window), icon);
}

void Window::InternalWidth(guint width)
{ gtk_container_set_border_width(GTK_CONTAINER(window), width); }

void Window::DefaultSize(guint xsize, guint ysize)
{ gtk_window_set_default_size(GTK_WINDOW(window), xsize, ysize); }

void Window::ShowAll()
{ gtk_widget_show_all(window); }

void Window::Align(Alignments halign, Alignments valign)
{
  Converter::Convert convert;
  gtk_widget_set_halign(GTK_WIDGET(window), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
  gtk_widget_set_valign(GTK_WIDGET(window), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
}

void Window::SizeRequest(guint x, guint y)
{ gtk_widget_set_size_request(GTK_WIDGET(window), x, y); }

GtkWidget *Window::GetWidget()
{ return window; }
