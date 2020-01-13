#pragma once

#include "CGuiWidget.hh"
#include "CGuiHeaderbar.hh"

namespace CGui
{
  class Window : public widget
  {
    public:
      Window(WindowType type, const gchar *title, WindowPos pos);
      void Icon(const gchar *iconpath);
      template<typename addtype> void Add(addtype &w);
      void InternalWidth(guint width);
      void DefaultSize(guint xsize, guint ysize);
      void NewHeaderbar(Headerbar &hb);
      void Quit();
      void ShowAll();
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      GtkWidget *GetWidget();

    private:
      GtkWidget *window;
  };

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

  template<typename addtype> void Window::Add(addtype &w)
  { gtk_container_add(GTK_CONTAINER(window), w.GetWidget()); }

  void Window::InternalWidth(guint width)
  { gtk_container_set_border_width(GTK_CONTAINER(window), width); }

  void Window::DefaultSize(guint xsize, guint ysize)
  { gtk_window_set_default_size(GTK_WINDOW(window), xsize, ysize); }

  void Window::NewHeaderbar(Headerbar &hb)
  { gtk_window_set_titlebar(GTK_WINDOW(window), hb.GetWidget()); }

  void Window::Quit()
  { gtk_main_quit(); }

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

  void Window::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(window))), classname); }

  GtkWidget *Window::GetWidget()
  { return window; }
}
