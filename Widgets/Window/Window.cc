#pragma once

#include "./Window.hh"

namespace CGui
{
  Window::Window(WindowType type, const char *title, WindowPos pos)
  {
    widget = gtk_window_new(std::get<GtkWindowType>(Converter::Convert::GetInstance().ConvertToGtkCode(type)));

    auto exit = +[](GtkWidget *widget, gpointer data)
    {
      auto f = +[](KeyValue::Node<const char *, Single::List<std::any>*> *node)
      {
        if(std::string(node->key) == "Instance")
          delete node->value;
      };

      Storage::GetInstance().ForEach<const char *, Single::List<std::any>*>(f, "allcallbacks");
      Storage::GetInstance().Free<const char *, Single::List<std::any>*>("allcallbacks");
      gtk_main_quit();
    };
    g_signal_connect(G_OBJECT(widget), "delete-event", G_CALLBACK(exit), NULL);
    this->Title(title);
    this->Position(pos);
    this->SetContainer(widget);
  }

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

  void Window::InternalWidth(unsigned int width)
  { gtk_container_set_border_width(GTK_CONTAINER(widget), width); }

  void Window::DefaultSize(unsigned int xsize, unsigned int ysize)
  { gtk_window_set_default_size(GTK_WINDOW(widget), xsize, ysize); }

  void Window::CustomHeaderbar(Headerbar &hb)
  { gtk_window_set_titlebar(GTK_WINDOW(widget), hb.GetWidget()); }

  void Window::Resizable(bool resizable)
  { gtk_window_set_resizable(GTK_WINDOW(widget), resizable); }

  void Window::Title(const char *title)
  { gtk_window_set_title(GTK_WINDOW(widget), title); }

  const char *Window::Title()
  { return gtk_window_get_title(GTK_WINDOW(widget)); }

  void Window::Maximize()
  { gtk_window_maximize(GTK_WINDOW(widget)); }

  void Window::Unmaximize()
  { gtk_window_unmaximize(GTK_WINDOW(widget)); }

  void Window::Fullscreen()
  { gtk_window_fullscreen(GTK_WINDOW(widget)); }

  void Window::Unfullscreen()
  { gtk_window_unfullscreen(GTK_WINDOW(widget)); }

  void Window::Position(WindowPos pos)
  { gtk_window_set_position(GTK_WINDOW(widget), std::get<GtkWindowPosition>(Converter::Convert::GetInstance().ConvertToGtkCode(pos))); }

  void Window::Quit()
  { gtk_main_quit(); }
};
