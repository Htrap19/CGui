#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
  class Infobar : public Widget, public Container<Widget>
  {
    public:
      Infobar();
      Infobar(MessageType messagetype, bool showclosebutton);
      void Reveal(bool reveal);
      bool Reveal();
      void MessageBoxType(MessageType messagetype);
      void ShowCloseButton(bool showclosebutton);
  };
};
