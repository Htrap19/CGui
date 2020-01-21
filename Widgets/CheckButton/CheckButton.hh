#pragma once

#include "../Widget.hh"
#include <vector>
#include <tuple>
#include <functional>

namespace CGui
{
  class CheckButton : public widget
  {
    public:
      static std::vector<std::tuple<CheckButton*, void(*)(CheckButton*)>> singlemethods;
      template <typename Data> static std::vector<std::tuple<CheckButton*, void(*)(CheckButton*, Data*), Data*>> doublemethods;
      CheckButton();
      CheckButton(const char *text);
      void Name(const char *name);
      const char *Name();
      template <typename Data> void SignalHandler(Events event, void(*func)(CheckButton*, Data*), Data &data);
      template <typename Data> void Toggled(void(*func)(CheckButton*, Data*), Data &data);
      void Toggled(void(*func)(CheckButton*));
      void Sensitive(bool sensitive);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *checkbutton;
  };

  std::vector<std::tuple<CheckButton*, void(*)(CheckButton*)>> CheckButton::singlemethods;
  template<typename Data> std::vector<std::tuple<CheckButton*, void(*)(CheckButton*, Data*), Data*>> CheckButton::doublemethods;

  bool operator==(CheckButton &lhs, CheckButton &rhs)
  {
    if(&lhs == &rhs)
      return true;
    else
      return false;
  }

  CheckButton::CheckButton()
  { checkbutton = gtk_check_button_new(); }

  CheckButton::CheckButton(const gchar *text)
  { checkbutton = gtk_check_button_new_with_label(text); }

  void CheckButton::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(checkbutton), name); }

  const char *CheckButton::Name()
  { return gtk_widget_get_name(GTK_WIDGET(checkbutton)); }

  template <typename Data> void CheckButton::SignalHandler(Events event, void(*func)(CheckButton*, Data*), Data &data)
  {
    Converter::Convert convert;
    doublemethods<Data>.push_back(std::make_tuple(this, func, &data));

    auto callback = +[](GtkWidget *widget, CheckButton *data) -> void
    {
      typename std::vector<std::tuple<CheckButton*, void(*)(CheckButton*, Data*), Data*>>::iterator it;
      for(it = doublemethods<Data>.begin(); it != doublemethods<Data>.end(); it++)
      {
        if(data == std::get<0>(*it))
        {
          auto *userfunc = std::get<1>(*it);
          auto *argdata = std::get<2>(*it);
          userfunc(data, argdata);
        }
      }
    };

    g_signal_connect(G_OBJECT(checkbutton), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  template<typename Data> void CheckButton::Toggled(void(*func)(CheckButton*, Data*), Data &data)
  { this->SignalHandler(TOGGLED, func, data); }

  void CheckButton::Toggled(void(*func)(CheckButton*))
  {
    Converter::Convert convert;
    singlemethods.push_back(std::make_tuple(this, func));

    auto callback = +[](GtkWidget *widget, CheckButton* data) -> void
    {
      for(std::vector<std::tuple<CheckButton*, void(*)(CheckButton*)>>::iterator it = singlemethods.begin(); it != singlemethods.end(); it++)
      {
        if(data == std::get<0>(*it))
        {
          auto *userfunc = std::get<1>(*it);
          userfunc(data);
        }
      }
    };

    g_signal_connect(G_OBJECT(checkbutton), std::get<char *>(convert.ConvertToGtkCode(TOGGLED)), G_CALLBACK(callback), this);
  }

  void CheckButton::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(checkbutton), sensitive); }

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

  void CheckButton::Show()
  { gtk_widget_show(GTK_WIDGET(checkbutton)); }

  GtkWidget *CheckButton::GetWidget()
  { return checkbutton; }
};
