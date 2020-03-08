#pragma once

#include "../Widget.hh"
#include <vector>
#include <tuple>
#include <functional>

namespace CGui
{
  class Progressbar : public widget
  {
    public:
      static std::vector<std::tuple<Progressbar*, bool(*)(Progressbar*)>> singletimeoutmethods;
      template <typename Data, typename ... Rest> static std::vector<std::tuple<Progressbar*, unsigned int, bool(*)(Progressbar*, Data*, Rest*...), Data*, Rest*...>> timeoutmethods;
      Progressbar();
      Progressbar(const char *text);
      void Pulse();
      void Pulse(double fraction);
      void Fraction(double fraction);
      double Fraction();
      void ShowText(bool show);
      bool ShowText();
      void Text(const char *text);
      const char *Text();
      template <typename Data, typename ... Rest> void TimeoutAdd(unsigned int interval, bool(*func)(Progressbar*, Data*, Rest*...), Data &data, Rest & ... rest);
      void TimeoutAdd(unsigned int interval, bool(*func)(Progressbar*));
      void Increment(double fraction);
      void Increment();
      void Name(const char *name);
      const char *Name();
      void Align(Alignments halign, Alignments valign);
      void Sensitive(bool sensitive);
      void SizeRequest(guint x, guint y);
      void Tooltip(const char *text);
      const char *Tooltip();
      void StyleClass(const gchar *classname);
      void Hide();
      void Show();
      GtkWidget *GetWidget();
  };

  std::vector<std::tuple<Progressbar*, bool(*)(Progressbar*)>> Progressbar::singletimeoutmethods;
  template <typename Data, typename ... Rest> std::vector<std::tuple<Progressbar*, unsigned int, bool(*)(Progressbar*, Data*, Rest*...), Data*, Rest*...>> Progressbar::timeoutmethods;

  Progressbar::Progressbar()
  { widget = gtk_progress_bar_new(); }

  Progressbar::Progressbar(const char *text)
  {
    widget = gtk_progress_bar_new();
    gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(widget), true);
    gtk_progress_bar_set_text(GTK_PROGRESS_BAR(widget), text);
  }

  void Progressbar::Pulse()
  { gtk_progress_bar_pulse(GTK_PROGRESS_BAR(widget)); }

  void Progressbar::Pulse(double fraction)
  { gtk_progress_bar_set_pulse_step(GTK_PROGRESS_BAR(widget), fraction); }

  void Progressbar::Fraction(double fraction)
  {
    gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(widget), fraction);
    while(gtk_events_pending())
      gtk_main_iteration();
  }

  double Progressbar::Fraction()
  { return gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(widget)); }

  void Progressbar::ShowText(bool show)
  { gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(widget), show); }

  bool Progressbar::ShowText()
  { return gtk_progress_bar_get_show_text(GTK_PROGRESS_BAR(widget)); }

  void Progressbar::Text(const char *text)
  { gtk_progress_bar_set_text(GTK_PROGRESS_BAR(widget), text); }

  const char *Progressbar::Text()
  { return gtk_progress_bar_get_text(GTK_PROGRESS_BAR(widget)); }

  template <typename Data, typename ... Rest> void Progressbar::TimeoutAdd(unsigned int interval, bool(*func)(Progressbar*, Data*, Rest*...), Data &data, Rest & ... rest)
  {
    timeoutmethods<Data, Rest...>.push_back(std::make_tuple(this, interval, func, &data, &rest...));

    auto callback = +[](Progressbar *data) -> bool
    {
      typename std::vector<std::tuple<Progressbar*, unsigned int, bool(*)(Progressbar*, Data*, Rest*...), Data*, Rest*...>>::iterator it;
      for(it = timeoutmethods<Data, Rest...>.begin(); it != timeoutmethods<Data, Rest...>.end(); it++)
      {
        if(data == std::get<0>(*it))
        {
          return std::apply([](Progressbar* ins, unsigned int interval, bool(*func)(Progressbar*, Data*, Rest*...), Data *data, Rest * ... rest)
          {
            return func(ins, data, rest...);
          }, *it);
        }
      }
    };

    g_timeout_add(interval, (GSourceFunc) callback, this);
  }

  void Progressbar::TimeoutAdd(unsigned int interval, bool(*func)(Progressbar*))
  {
    singletimeoutmethods.push_back(std::make_tuple(this, func));

    auto callback = +[](Progressbar *data) -> gboolean
    {
      std::vector<std::tuple<Progressbar*, bool(*)(Progressbar*)>>::iterator it;
      for(it = singletimeoutmethods.begin(); it != singletimeoutmethods.end(); it++)
      {
        if(data == std::get<0>(*it))
        {
          return std::apply([](Progressbar *ins, bool(*func)(Progressbar*))
          {
            return func(ins);
          }, *it);
        }
      }

      return false;
    };

    g_timeout_add(interval, (GSourceFunc) callback, this);
  }

  void Progressbar::Increment(double fraction)
  { this->Fraction(this->Fraction() + fraction); }

  void Progressbar::Increment()
  { this->Fraction(this->Fraction() + this->Fraction()); }

  void Progressbar::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(widget), name); }

  const char *Progressbar::Name()
  { return gtk_widget_get_name(GTK_WIDGET(widget)); }

  void Progressbar::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Progressbar::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive); }

  void Progressbar::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(widget), x, y); }

  void Progressbar::Tooltip(const char *text)
  { gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text); }

  const char *Progressbar::Tooltip()
  { return gtk_widget_get_tooltip_text(GTK_WIDGET(widget)); }

  void Progressbar::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(widget))), classname); }

  void Progressbar::Hide()
  { gtk_widget_hide(GTK_WIDGET(widget)); }

  void Progressbar::Show()
  { gtk_widget_show(GTK_WIDGET(widget)); }

  GtkWidget *Progressbar::GetWidget()
  { return widget; }
}
