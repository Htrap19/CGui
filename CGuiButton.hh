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
    void StyleClass(const gchar *classname);
    GtkWidget *GetWidget();

  private:
    GtkWidget *button;
};

Button::Button()
{ button = gtk_button_new(); }

Button::Button(const gchar *text)
{ button = gtk_button_new_with_label(text); }


template<typename addtype> void Button::Add(addtype &w)
{ gtk_container_add(GTK_CONTAINER(button), w.GetWidget()); }

void Button::Align(Alignments halign, Alignments valign)
{
  Converter::Convert convert;
  gtk_widget_set_halign(GTK_WIDGET(button), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
  gtk_widget_set_valign(GTK_WIDGET(button), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
}

void Button::SizeRequest(guint x, guint y)
{ gtk_widget_set_size_request(GTK_WIDGET(button), x, y); }

void Button::SignalHandler(Events event, GCallback callbackFunction, gpointer data)
{
  Converter::Convert convert;
  g_signal_connect(G_OBJECT(button), std::get<char *>(convert.ConvertToGtkCode(event)), callbackFunction, data);
}

void Button::StyleClass(const gchar *classname)
{ gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(button))), classname); }

GtkWidget *Button::GetWidget()
{ return button; }
