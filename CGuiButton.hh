#pragma once

#include "CGuiWidget.hh"

class Button : public widget
{
  public:
    Button();
    Button(const gchar *text);
    template<typename addtype> void Add(addtype &w);
    void Align(Alignments halign, Alignments valign);
    void SizeRequest(guint x, guint y);
    void SignalHandler(Events event, GCallback callbackFunction, gpointer data = NULL);
    GtkWidget *GetWidget();

  private:
    GtkWidget *button;
};

template<typename addtype> void Button::Add(addtype &w)
{ gtk_container_add(GTK_CONTAINER(button), w.GetWidget()); }
