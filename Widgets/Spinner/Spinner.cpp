#include "./Spinner.hh"

namespace CGui
{
  Spinner::Spinner()
  {
	  widget = gtk_spinner_new();
	  this->SetContext(widget);
  }

  void Spinner::Start()
  { gtk_spinner_start(GTK_SPINNER(widget)); }

  void Spinner::Stop()
  { gtk_spinner_stop(GTK_SPINNER(widget)); }
};
