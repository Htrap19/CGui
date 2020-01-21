#pragma once

#include "../Widget.hh"
#include <vector>
#include <tuple>
#include <functional>

namespace CGui
{
  class Button : public widget
  {
    typedef void(*FuncCallback)(Button*);
    public:
      static std::vector<std::tuple<Button*, void(*)(Button*)>> singlemethods;
      template<typename Data> static std::vector<std::tuple<Button*, void(*)(Button*, Data*), Data*>> doublemethods;
      template<typename Data, typename ... Rest> static std::vector<std::tuple<Button*, void(*)(Button*, Data*, Rest*...), Data*, Rest*...>> infinitemethods;
      Button();
      Button(const gchar *text);
      void Name(const char *name);
      const char *Name();
      template<typename addtype> void Add(addtype &w);
      void Sensitive(bool sensitive);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void Text(const char *text);
      const char *Text();
      template <typename Data> void SignalHandler(Events event, void(*func)(Button*, Data*), Data &data);
      template <typename Data, typename ... Rest> void SignalHandler(Events event, void(*func)(Button*, Data*, Rest*...), Data &data, Rest & ... rest);
      template <typename Data> void Clicked(void(*func)(Button*, Data*), Data &data);
      template <typename Data, typename ... Rest> void Clicked(void(*)(Button*, Data*, Rest*...), Data &data, Rest & ... rest);
      void Clicked(FuncCallback func);
      void StyleClass(const gchar *classname);
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *button;
  };

  std::vector<std::tuple<Button*, void(*)(Button*)>> Button::singlemethods;
  template<typename Data> std::vector<std::tuple<Button*, void(*)(Button*, Data*), Data*>> Button::doublemethods;
  template<typename Data, typename ... Rest> std::vector<std::tuple<Button*, void(*)(Button*, Data*, Rest*...), Data*, Rest*...>> Button::infinitemethods;

  bool operator==(Button &lhs, Button &rhs)
  {
    if(&lhs == &rhs)
      return true;
    else
      return false;
  }

  Button::Button()
  { button = gtk_button_new(); }

  Button::Button(const gchar *text)
  { button = gtk_button_new_with_label(text); }

  void Button::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(button), name); }

  const char *Button::Name()
  { return gtk_widget_get_name(GTK_WIDGET(button)); }

  template<typename addtype> void Button::Add(addtype &w)
  { gtk_container_add(GTK_CONTAINER(button), w.GetWidget()); }

  void Button::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(button), sensitive); }

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
    doublemethods<Data>.push_back(std::make_tuple(this, func, &data));
    auto callback = +[](GtkWidget *widget, Button *data) -> void
    {
      typename std::vector<std::tuple<Button*, void(*)(Button*, Data*), Data*>>::iterator it;
      for(it = doublemethods<Data>.begin(); it != doublemethods<Data>.end(); it++ )
      {
        if(data == std::get<0>(*it))
        {
          auto *userfunc = std::get<1>(*it);
          auto *argdata = std::get<2>(*it);
          userfunc(data, argdata);
        }
      }
    };

    g_signal_connect(G_OBJECT(button), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  template <typename Data, typename ... Rest> void Button::SignalHandler(Events event, void(*func)(Button*, Data*, Rest*...), Data &data, Rest & ... rest)
  {
    Converter::Convert convert;
    infinitemethods<Data, Rest...>.push_back(std::make_tuple(this, func, &data, &rest...));

    auto callback = +[](GtkWidget *widget, Button *data) -> void
    {
      typename std::vector<std::tuple<Button*, void(*)(Button*, Data*, Rest*...), Data*, Rest*...>>::iterator it;
      for(it = infinitemethods<Data, Rest...>.begin(); it != infinitemethods<Data, Rest...>.end(); it++)
      {
        if(data == std::get<0>(*it))
        {
          auto *userfunc = std::get<1>(*it);
          auto *argdata = std::get<2>(*it);

          userfunc(data, argdata, std::get<Rest*>(*it)...);
        }
      }
    };

    g_signal_connect(G_OBJECT(button), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  template <typename Data> void Button::Clicked(void(*func)(Button*, Data*), Data &data)
  { this->SignalHandler(CLICKED, func, data); }

  template <typename Data, typename ... Rest> void Button::Clicked(void(*func)(Button*, Data*, Rest*...), Data &data, Rest & ... rest)
  { this->SignalHandler(CLICKED, func, data, rest...); }

  void Button::Clicked(FuncCallback func)
  {
    Converter::Convert convert;
    singlemethods.push_back(std::make_tuple(this, func));
    auto callback = +[](GtkWidget *widget, Button *data) -> void
    {
      for(std::vector<std::tuple<Button*, void(*)(Button*)>>::iterator it = singlemethods.begin(); it != singlemethods.end(); it++ )
      {
        if(data == std::get<0>(*it))
        {
          auto *userfunc = std::get<1>(*it);
          userfunc(data);
        }
      }
    };
    g_signal_connect(G_OBJECT(button), std::get<char *>(convert.ConvertToGtkCode(CLICKED)), G_CALLBACK(callback), this);
  }

  void Button::Text(const char *text)
  { gtk_button_set_label(GTK_BUTTON(button), text); }

  const char *Button::Text()
  { return gtk_button_get_label(GTK_BUTTON(button)); }

  void Button::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(button))), classname); }

  void Button::Show()
  { gtk_widget_show(GTK_WIDGET(button)); }

  GtkWidget *Button::GetWidget()
  { return button; }
}
