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
      static std::vector<std::tuple<CheckButton*, void(*)()>> emptymethods;
      static std::vector<std::tuple<CheckButton*, void(*)(CheckButton*)>> singlemethods;
      template<typename Data> static std::vector<std::tuple<CheckButton*, void(*)(Data*), Data*>> singledatamethods;
      template <typename Data> static std::vector<std::tuple<CheckButton*, void(*)(CheckButton*, Data*), Data*>> doublemethods;
      template<typename Data, typename ... Rest> static std::vector<std::tuple<CheckButton*, void(*)(Data*, Rest*...), Data*, Rest*...>> infinitedatamethods;
      template <typename Data, typename ... Rest> static std::vector<std::tuple<CheckButton*, void(*)(CheckButton*, Data*, Rest*...), Data*, Rest*...>> infinitemethods;
      CheckButton();
      CheckButton(const char *text);
      void Name(const char *name);
      const char *Name();
      void Checked(bool active);
      bool Checked();
      void SignalHandler(Events event, void(*func)());
      void SignalHandler(Events event, void(*func)(CheckButton*));
      template <typename Data> void SignalHandler(Events event, void(*func)(CheckButton*, Data*), Data &data);
      template <typename Data, typename ... Rest> void SignalHandler(Events event, void(*func)(CheckButton*, Data*, Rest*...), Data &data, Rest & ... rest);
      template <typename Data> void Toggled(void(*func)(CheckButton*, Data*), Data &data);
      template <typename Data, typename ... Rest> void Toggled(void(*func)(CheckButton*, Data*, Rest*...), Data &data, Rest & ... rest);
      template <typename Data> void SignalHandler(Events event, void(*func)(Data*), Data &data);
      template <typename Data, typename ... Rest> void SignalHandler(Events event, void(*func)(Data*, Rest*...), Data &data, Rest & ... rest);
      template <typename Data> void Toggled(void(*func)(Data*), Data &data);
      template <typename Data, typename ... Rest> void Toggled(void(*func)(Data*, Rest*...), Data &data, Rest & ... rest);
      void Toggled(void(*func)(CheckButton*));
      void Toggled(void(*func)());
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

  std::vector<std::tuple<CheckButton*, void(*)()>> CheckButton::emptymethods;
  std::vector<std::tuple<CheckButton*, void(*)(CheckButton*)>> CheckButton::singlemethods;
  template<typename Data> std::vector<std::tuple<CheckButton*, void(*)(Data*), Data*>> CheckButton::singledatamethods;
  template<typename Data, typename ... Rest> std::vector<std::tuple<CheckButton*, void(*)(Data*, Rest*...), Data*, Rest*...>> CheckButton::infinitedatamethods;
  template<typename Data> std::vector<std::tuple<CheckButton*, void(*)(CheckButton*, Data*), Data*>> CheckButton::doublemethods;
  template<typename Data, typename ... Rest> std::vector<std::tuple<CheckButton*, void(*)(CheckButton*, Data*, Rest*...), Data*, Rest*...>> CheckButton::infinitemethods;

  bool operator==(CheckButton &lhs, CheckButton &rhs)
  {
    if(&lhs == &rhs)
      return true;
    else
      return false;
  }

  CheckButton::CheckButton()
  { widget = gtk_check_button_new(); }

  CheckButton::CheckButton(const gchar *text)
  { widget = gtk_check_button_new_with_label(text); }

  void CheckButton::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(widget), name); }

  const char *CheckButton::Name()
  { return gtk_widget_get_name(GTK_WIDGET(widget)); }

  void CheckButton::Checked(bool active)
  { gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), active); }

  bool CheckButton::Checked()
  { return gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)); }

  void CheckButton::SignalHandler(Events event, void(*func)())
  {
    Converter::Convert convert;
    emptymethods.push_back(std::make_tuple(this, func));

    auto callback = +[](GtkWidget *widget, CheckButton* data) -> void
    {
      for(std::vector<std::tuple<CheckButton*, void(*)()>>::iterator it = emptymethods.begin(); it != emptymethods.end(); it++)
      {
        if(data == std::get<0>(*it))
        {
          std::apply([](CheckButton *ins, auto *func)
          {
            func();
          }, *it);
        }
      }
    };

    g_signal_connect(G_OBJECT(widget), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  void CheckButton::SignalHandler(Events event, void(*func)(CheckButton*))
  {
    Converter::Convert convert;
    singlemethods.push_back(std::make_tuple(this, func));

    auto callback = +[](GtkWidget *widget, CheckButton* data) -> void
    {
      for(std::vector<std::tuple<CheckButton*, void(*)(CheckButton*)>>::iterator it = singlemethods.begin(); it != singlemethods.end(); it++)
      {
        if(data == std::get<0>(*it))
        {
          std::apply([](CheckButton *ins, auto *func)
          {
            func(ins);
          }, *it);
        }
      }
    };

    g_signal_connect(G_OBJECT(widget), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

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
          std::apply([](CheckButton *ins, auto *func, Data *data)
          {
            func(ins, data);
          }, *it);
        }
      }
    };

    g_signal_connect(G_OBJECT(widget), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  template <typename Data> void CheckButton::SignalHandler(Events event, void(*func)(Data*), Data &data)
  {
    Converter::Convert convert;
    singledatamethods<Data>.push_back(std::make_tuple(this, func, &data));
    auto callback = +[](GtkWidget *widget, CheckButton *data) -> void
    {
      typename std::vector<std::tuple<CheckButton*, void(*)(Data*), Data*>>::iterator it;
      for(it = singledatamethods<Data>.begin(); it != singledatamethods<Data>.end(); it++ )
      {
        if(data == std::get<0>(*it))
        {
          std::apply([](CheckButton* ins, auto *func, Data *data)
          {
            func(data);
          }, *it);
        }
      }
    };

    g_signal_connect(G_OBJECT(widget), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  template <typename Data, typename ... Rest> void CheckButton::SignalHandler(Events event, void(*func)(CheckButton*, Data*, Rest*...), Data &data, Rest & ... rest)
  {
    Converter::Convert convert;
    infinitemethods<Data, Rest...>.push_back(std::make_tuple(this, func, &data, &rest...));

    auto callback = +[](GtkWidget *widget, CheckButton *data) -> void
    {
      typename std::vector<std::tuple<CheckButton*, void(*)(CheckButton*, Data*, Rest*...), Data*, Rest*...>>::iterator it;
      for(it = infinitemethods<Data, Rest...>.begin(); it != infinitemethods<Data, Rest...>.end(); it++)
      {
        if(data == std::get<0>(*it))
        {
          std::apply([](CheckButton* ins, auto *func, Data *data, Rest * ... rest)
          {
            func(ins, data, rest...);
          }, *it);
        }
      }
    };

    g_signal_connect(G_OBJECT(widget), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  template <typename Data, typename ... Rest> void CheckButton::SignalHandler(Events event, void(*func)(Data*, Rest*...), Data &data, Rest & ... rest)
  {
    Converter::Convert convert;
    infinitedatamethods<Data, Rest...>.push_back(std::make_tuple(this, func, &data, &rest...));

    auto callback = +[](GtkWidget *widget, CheckButton *data) -> void
    {
      typename std::vector<std::tuple<CheckButton*, void(*)(Data*, Rest*...), Data*, Rest*...>>::iterator it;
      for(it = infinitedatamethods<Data, Rest...>.begin(); it != infinitedatamethods<Data, Rest...>.end(); it++)
      {
        if(data == std::get<0>(*it))
        {
          std::apply([](CheckButton* ins, auto *func, Data *data, Rest * ... rest)
          {
            func(data, rest...);
          }, *it);
        }
      }
    };

    g_signal_connect(G_OBJECT(widget), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  template<typename Data> void CheckButton::Toggled(void(*func)(CheckButton*, Data*), Data &data)
  { this->SignalHandler(TOGGLED, func, data); }

  template <typename Data> void CheckButton::Toggled(void(*func)(Data*), Data &data)
  { this->SignalHandler(TOGGLED, func, data); }

  template <typename Data, typename ... Rest> void CheckButton::Toggled(void(*func)(CheckButton*, Data*, Rest*...), Data &data, Rest & ... rest)
  { this->SignalHandler(TOGGLED, func, data, rest...); }

  template <typename Data, typename ... Rest> void CheckButton::Toggled(void(*func)(Data*, Rest*...), Data &data, Rest & ... rest)
  { this->SignalHandler(TOGGLED, func, data, rest...); }

  void CheckButton::Toggled(void(*func)(CheckButton*))
  { this->SignalHandler(TOGGLED, func); }

  void CheckButton::Toggled(void(*func)())
  { this->SignalHandler(TOGGLED, func); }

  void CheckButton::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive); }

  void CheckButton::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void CheckButton::SizeRequest(unsigned int x, unsigned int y)
  { gtk_widget_set_size_request(GTK_WIDGET(widget), x, y); }

  void CheckButton::Tooltip(const char *text)
  { gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text); }

  const char *CheckButton::Tooltip()
  { return gtk_widget_get_tooltip_text(GTK_WIDGET(widget)); }

  void CheckButton::StyleClass(const char *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(widget))), classname); }

  void CheckButton::Hide()
  { gtk_widget_hide(GTK_WIDGET(widget)); }

  void CheckButton::Show()
  { gtk_widget_show(GTK_WIDGET(widget)); }

  GtkWidget *CheckButton::GetWidget()
  { return widget; }
};
