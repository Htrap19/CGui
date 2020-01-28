#pragma once

#include "../Widget.hh"
#include <vector>
#include <tuple>
#include <functional>

namespace CGui
{
  class Entry : public widget
  {
    public:
      static std::vector<std::tuple<Entry*, void(*)()>> emptymethods;
      static std::vector<std::tuple<Entry*, void(*)(Entry*)>> singlemethods;
      template <typename Data> static std::vector<std::tuple<Entry*, void(*)(Entry*, Data*), Data*>> doublemethods;
      template <typename Data, typename ... Rest> static std::vector<std::tuple<Entry*, void(*)(Entry*, Data*, Rest*...), Data*, Rest*...>> infinitemethods;
      Entry();
      Entry(const gchar *placeholdertext);
      void Name(const char *name);
      const char *Name();
      void Editable(bool editable);
      bool Editable();
      void Visibility(bool visibility);
      bool Visibility();
      void Sensitive(bool sensitive);
      void SignalHandler(Events event, void(*func)());
      void SignalHandler(Events event, void(*func)(Entry*));
      template <typename Data> void SignalHandler(Events event, void(*func)(Entry*, Data*), Data &data);
      template <typename Data, typename ... Rest> void SignalHandler(Events event, void(*func)(Entry*, Data*, Rest*...), Data &data, Rest & ... rest);
      template <typename Data, typename ... Rest> void Changed(void(*func)(Entry*, Data*, Rest*...), Data &data, Rest & ... rest);
      template <typename Data> void Changed(void(*func)(Entry*, Data*), Data &data);
      void Changed(void(*func)(Entry*));
      void Changed(void(*func)());
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      void Text(const char *text);
      const char *Text();
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *entry;
  };

  std::vector<std::tuple<Entry*, void(*)()>> Entry::emptymethods;
  std::vector<std::tuple<Entry*, void(*)(Entry*)>> Entry::singlemethods;
  template<typename Data> std::vector<std::tuple<Entry*, void(*)(Entry*, Data*), Data*>> Entry::doublemethods;
  template<typename Data, typename ... Rest> std::vector<std::tuple<Entry*, void(*)(Entry*, Data*, Rest*...), Data*, Rest*...>> Entry::infinitemethods;

  Entry::Entry()
  { entry = gtk_entry_new(); }

  Entry::Entry(const gchar *placeholdertext)
  {
    entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), placeholdertext);
  }

  void Entry::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(entry), name); }

  const char *Entry::Name()
  { return gtk_widget_get_name(GTK_WIDGET(entry)); }

  void Entry::Editable(bool editable)
  { gtk_editable_set_editable(GTK_EDITABLE(entry), editable); }

  bool Entry::Editable()
  { return gtk_editable_get_editable(GTK_EDITABLE(entry)); }

  void Entry::Visibility(bool visibility)
  { gtk_entry_set_visibility(GTK_ENTRY(entry), visibility); }

  bool Entry::Visibility()
  { return gtk_entry_get_visibility(GTK_ENTRY(entry)); }

  void Entry::SignalHandler(Events event, void(*func)())
  {
    Converter::Convert convert;
    emptymethods.push_back(std::make_tuple(this, func));
    auto callback = +[](GtkWidget *widget, Entry *data) -> void
    {
      for(std::vector<std::tuple<Entry*, void(*)()>>::iterator it = emptymethods.begin(); it != emptymethods.end(); it++ )
      {
        if(data == std::get<0>(*it))
        {
          auto *userfunc = std::get<1>(*it);
          userfunc();
        }
      }
    };
    g_signal_connect(G_OBJECT(entry), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  void Entry::SignalHandler(Events event, void(*func)(Entry*))
  {
    Converter::Convert convert;
    singlemethods.push_back(std::make_tuple(this, func));
    auto callback = +[](GtkWidget *widget, Entry *data) -> void
    {
      for(std::vector<std::tuple<Entry*, void(*)(Entry*)>>::iterator it = singlemethods.begin(); it != singlemethods.end(); it++ )
      {
        if(data == std::get<0>(*it))
        {
          auto *userfunc = std::get<1>(*it);
          userfunc(data);
        }
      }
    };
    g_signal_connect(G_OBJECT(entry), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  template <typename Data> void Entry::SignalHandler(Events event, void(*func)(Entry*, Data*), Data &data)
  {
    Converter::Convert convert;
    doublemethods<Data>.push_back(std::make_tuple(this, func, &data));
    auto callback = +[](GtkWidget *widget, Entry *data) -> void
    {
      typename std::vector<std::tuple<Entry*, void(*)(Entry*, Data*), Data*>>::iterator it;
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

    g_signal_connect(G_OBJECT(entry), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  template <typename Data, typename ... Rest> void Entry::SignalHandler(Events event, void(*func)(Entry*, Data*, Rest*...), Data &data, Rest & ... rest)
  {
    Converter::Convert convert;
    infinitemethods<Data, Rest...>.push_back(std::make_tuple(this, func, &data, &rest...));

    auto callback = +[](GtkWidget *widget, Entry *data) -> void
    {
      typename std::vector<std::tuple<Entry*, void(*)(Entry*, Data*, Rest*...), Data*, Rest*...>>::iterator it;
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

    g_signal_connect(G_OBJECT(entry), std::get<char *>(convert.ConvertToGtkCode(event)), G_CALLBACK(callback), this);
  }

  void Entry::Changed(void(*func)())
  { this->SignalHandler(CHANGED, func); }

  void Entry::Changed(void(*func)(Entry*))
  { this->SignalHandler(CHANGED, func); }

  template <typename Data> void Entry::Changed(void(*func)(Entry*, Data*), Data &data)
  { this->SignalHandler(CHANGED, func, data); }

  template <typename Data, typename ... Rest> void Entry::Changed(void(*func)(Entry*, Data*, Rest*...), Data &data, Rest & ... rest)
  { this->SignalHandler(CHANGED, func, data, rest...); }

  void Entry::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(entry), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(entry), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Entry::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(entry), sensitive); }

  void Entry::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(entry), x, y); }

  void Entry::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(entry))), classname); }

  void Entry::Text(const char *text)
  { gtk_entry_set_text(GTK_ENTRY(entry), text); }

  const char *Entry::Text()
  { return gtk_entry_get_text(GTK_ENTRY(entry)); }

  void Entry::Show()
  { gtk_widget_show(GTK_WIDGET(entry)); }

  GtkWidget *Entry::GetWidget()
  { return entry; }
}
