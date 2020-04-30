#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
  class Infobar : public widget, public Container
  {
    public:
      Infobar();
      Infobar(MessageType messagetype, bool showclosebutton);
      void Reveal(bool reveal);
      bool Reveal();
      void MessageBoxType(MessageType messagetype);
      void ShowCloseButton(bool showclosebutton);

    private:
      GtkWidget *content_area;
  };
};

#include "./Infobar.cc"
