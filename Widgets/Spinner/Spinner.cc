#pragma once

#include "./Spinner.hh"

namespace CGui
{
  Spinner::Spinner()
  { widget = gtk_spinner_new(); }

  void Spinner::Start()
  { gtk_spinner_start(GTK_SPINNER(widget)); }

  void Spinner::Stop()
  { gtk_spinner_stop(GTK_SPINNER(widget)); }
};
