#pragma once

#include "CGuiWidget.hh"

namespace CGui
{
  class Button : public widget
  {
    public:
      Button();
      Button(const gchar *text);
      template<typename addtype> void Add(addtype &w);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void SetText(const char *text);
      const char *GetText();
      template <typename Data> void SignalHandler(Events event, void(*func)(Button*, Data*), Data &data = NULL);
      template <typename Data> void Clicked(void(*func)(Button*, Data*), Data &data = NULL);
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

  template<typename Data> void Button::SignalHandler(Events event, void(*func)(Button*, Data*), Data &data)
  {
    Converter::Convert convert;
    static auto *userfunc = func;
    static Button *tempbutton = this;
    static Data *tempdata = &data;
    auto callback = +[](GtkWidget *widget, void* data) -> void { userfunc(tempbutton, tempdata); };

    g_signal_connect(G_OBJECT(button), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), G_OBJECT(data.GetWidget()));
  }

  template <typename Data> void Button::Clicked(void(*func)(Button*, Data*), Data &data)
  {
    Converter::Convert convert;
    static auto *userfunc = func;
    static Button *tempbutton = this;
    static Data *tempdata = &data;
    auto callback = +[](GtkWidget *widget, gpointer data) -> void { userfunc(tempbutton, tempdata); };

    g_signal_connect(G_OBJECT(button), std::get<char *>(convert.ConvertToGtkCode(CLICKED)), G_CALLBACK(callback), G_OBJECT(data.GetWidget()));
  }

  void Button::SetText(const char *text)
  { gtk_button_set_label(GTK_BUTTON(button), text); }

  const char *Button::GetText()
  { return gtk_button_get_label(GTK_BUTTON(button)); }

  void Button::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(button))), classname); }

  GtkWidget *Button::GetWidget()
  { return button; }
}
