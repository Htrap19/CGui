#pragma once

#include "../Widget.hh"

namespace CGui
{
  class CheckButton : public widget
  {
    public:
      CheckButton();
      CheckButton(const char *text);
      template <typename Data> void SignalHandler(Events event, void(*func)(CheckButton*, Data*), Data &data);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      GtkWidget *GetWidget();

    private:
      GtkWidget *checkbutton;
  };

  CheckButton::CheckButton()
  { checkbutton = gtk_check_button_new(); }

  CheckButton::CheckButton(const gchar *text)
  { checkbutton = gtk_check_button_new_with_label(text); }

  template <typename Data> void CheckButton::SignalHandler(Events event, void(*func)(CheckButton*, Data*), Data &data)
  {
    Converter::Convert convert;
    static auto *userfunc = func;
    static CheckButton *tempcheckbutton = this;
    static Data *tempdata = &data;
    auto callback = +[](GtkWidget *widget, gpointer data) -> void { userfunc(tempcheckbutton, tempdata); };

    g_signal_connect(G_OBJECT(checkbutton), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), &data);
  }

  void CheckButton::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(checkbutton), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(checkbutton), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void CheckButton::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(checkbutton), x, y); }

  void CheckButton::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(checkbutton))), classname); }

  GtkWidget *CheckButton::GetWidget()
  { return checkbutton; }
};
