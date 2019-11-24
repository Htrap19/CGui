#pragma once

#include "CGuiWidget.hh"

class Window : public widget
{
  public:
    Window(WindowType type, const gchar *title, WindowPos pos);
    void Icon(const gchar *iconpath);
    template<typename addtype> void Add(addtype &w);
    void InternalWidth(guint width);
    void DefaultSize(guint xsize, guint ysize);
    void ShowAll();
    void Align(Alignments halign, Alignments valign);
    void SizeRequest(guint x, guint y);
    GtkWidget *GetWidget();

  private:
    GtkWidget *window;
};

template<typename addtype> void Window::Add(addtype &w)
{ gtk_container_add(GTK_CONTAINER(window), w.GetWidget()); }
