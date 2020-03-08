#pragma once

#include <gtk/gtk.h>
#include "./Widgets/Button/Button.hh"
#include "./Widgets/Image/Image.hh"
#include "./Widgets/Label/Label.hh"
#include "./Widgets/Entry/Entry.hh"
#include "./Widgets/Box/Box.hh"
#include "./Widgets/Window/Window.hh"
#include "./CssProvider/CssProvider.hh"
#include "./Widgets/Headerbar/Headerbar.hh"
#include "./Widgets/CheckButton/CheckButton.hh"
#include "./Widgets/Progressbar/Progressbar.hh"
#include "./Widgets/Revealer/Revealer.hh"
#include "./Widgets/Infobar/Infobar.hh"

namespace CGui
{
  struct Init
  {
    public:
      Init(int argc, char *argv[])
      { gtk_init(&argc, &argv); }
      ~Init()
      { gtk_main(); }
  };

  static void UpdateUI()
  {
    while(gtk_events_pending())
      gtk_main_iteration();
  }
};
