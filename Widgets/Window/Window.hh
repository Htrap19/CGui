#pragma once

#include "../Widget.hh"
#include "../Headerbar/Headerbar.hh"

namespace CGui
{
  class Window : public widget
  {
    public:
      Window(WindowType type, const char *title, WindowPos pos);
      void Name(const char *name);
      const char *Name();
      void Icon(const char *iconpath);
      template<typename addtype> void Add(addtype &w);
      template<typename removetype> void Remove(removetype &w);
      void InternalWidth(unsigned int width);
      void DefaultSize(unsigned int xsize, unsigned int ysize);
      void NewHeaderbar(Headerbar &hb);
      void Resizable(bool resizable);
      void Quit();
      void ShowAll();
      void Sensitive(bool sensitive);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(unsigned int x, unsigned int y);
      void Tooltip(const char *text);
      const char *Tooltip();
      void StyleClass(const char *classname);
      void Hide();
      void Show();
      GtkWidget *GetWidget();
  };

  Window::Window(WindowType type, const gchar *title, WindowPos pos)
  {
    Converter::Convert convert;
    widget = gtk_window_new(std::get<GtkWindowType>(convert.ConvertToGtkCode(type)));

    g_signal_connect(G_OBJECT(widget), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
    gtk_window_set_title(GTK_WINDOW(widget), title);
    gtk_window_set_position(GTK_WINDOW(widget), std::get<GtkWindowPosition>(convert.ConvertToGtkCode(pos)));
  }

  void Window::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(widget), name); }

  const char *Window::Name()
  { return gtk_widget_get_name(GTK_WIDGET(widget)); }

  void Window::Icon(const char *iconpath)
  {
    GError *error = NULL;
    GdkPixbuf *icon = gdk_pixbuf_new_from_file(iconpath, &error);
    if(!icon)
    {
      fprintf(stderr, "%s\n", error->message);
      g_error_free(error);
    }
    gtk_window_set_icon(GTK_WINDOW(widget), icon);
  }

  template<typename addtype> void Window::Add(addtype &w)
  { gtk_container_add(GTK_CONTAINER(widget), w.GetWidget()); }

  template<typename removetype> void Window::Remove(removetype &w)
  { gtk_container_remove(GTK_CONTAINER(widget), w.GetWidget()); }

  void Window::InternalWidth(unsigned int width)
  { gtk_container_set_border_width(GTK_CONTAINER(widget), width); }

  void Window::DefaultSize(unsigned int xsize, unsigned int ysize)
  { gtk_window_set_default_size(GTK_WINDOW(widget), xsize, ysize); }

  void Window::NewHeaderbar(Headerbar &hb)
  { gtk_window_set_titlebar(GTK_WINDOW(widget), hb.GetWidget()); }

  void Window::Resizable(bool resizable)
  { gtk_window_set_resizable(GTK_WINDOW(widget), resizable); }

  void Window::Quit()
  { gtk_main_quit(); }

  void Window::ShowAll()
  { gtk_widget_show_all(widget); }

  void Window::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive); }

  void Window::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Window::SizeRequest(unsigned int x, unsigned int y)
  { gtk_widget_set_size_request(GTK_WIDGET(widget), x, y); }

  void Window::Tooltip(const char *text)
  { gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text); }

  const char *Window::Tooltip()
  { return gtk_widget_get_tooltip_text(GTK_WIDGET(widget)); }

  void Window::StyleClass(const char *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(widget))), classname); }

  void Window::Hide()
  { gtk_widget_hide(GTK_WIDGET(widget)); }

  void Window::Show()
  { gtk_widget_show(GTK_WIDGET(widget)); }

  GtkWidget *Window::GetWidget()
  { return widget; }
}
