#include "./Progressbar.hh"

namespace CGui
{
  Progressbar::Progressbar()
  {
	  widget = gtk_progress_bar_new();
	  this->SetContext(widget);
  }

  Progressbar::Progressbar(const char *text)
  {
    widget = gtk_progress_bar_new();
    gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(widget), true);
    gtk_progress_bar_set_text(GTK_PROGRESS_BAR(widget), text);
	this->SetContext(widget);
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

  void Progressbar::Increment(double fraction)
  { this->Fraction(this->Fraction() + fraction); }

  void Progressbar::Increment()
  { this->Fraction(this->Fraction() + this->Fraction()); }
};
