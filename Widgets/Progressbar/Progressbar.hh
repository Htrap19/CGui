#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Progressbar : public widget
  {
    public:
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
      void Name(const char *name);
      const char *Name();
      void Align(Alignments halign, Alignments valign);
      void Sensitive(bool sensitive);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *progressbar;
  };

  Progressbar::Progressbar()
  { progressbar = gtk_progress_bar_new(); }

  Progressbar::Progressbar(const char *text)
  {
    progressbar = gtk_progress_bar_new();
    gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar), true);
    gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progressbar), text);
  }

  void Progressbar::Pulse()
  { gtk_progress_bar_pulse(GTK_PROGRESS_BAR(progressbar)); }

  void Progressbar::Pulse(double fraction)
  { gtk_progress_bar_set_pulse_step(GTK_PROGRESS_BAR(progressbar), fraction); }

  void Progressbar::Fraction(double fraction)
  { gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(progressbar), fraction); }

  double Progressbar::Fraction()
  { return gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(progressbar)); }

  void Progressbar::ShowText(bool show)
  { gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(progressbar), show); }

  bool Progressbar::ShowText()
  { return gtk_progress_bar_get_show_text(GTK_PROGRESS_BAR(progressbar)); }

  void Progressbar::Text(const char *text)
  { gtk_progress_bar_set_text(GTK_PROGRESS_BAR(progressbar), text); }

  const char *Progressbar::Text()
  { return gtk_progress_bar_get_text(GTK_PROGRESS_BAR(progressbar)); }

  void Progressbar::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(progressbar), name); }

  const char *Progressbar::Name()
  { return gtk_widget_get_name(GTK_WIDGET(progressbar)); }

  void Progressbar::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(progressbar), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(progressbar), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Progressbar::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(progressbar), sensitive); }

  void Progressbar::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(progressbar), x, y); }

  void Progressbar::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(GTK_WIDGET(progressbar)), classname); }

  void Progressbar::Show()
  { gtk_widget_show(GTK_WIDGET(progressbar)); }

  GtkWidget *Progressbar::GetWidget()
  { return progressbar; }
}
