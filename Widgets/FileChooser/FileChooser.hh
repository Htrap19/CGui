#pragma once

#include "../Widget.hh"

namespace CGui
{
  class FileChooser : public Widget
  {
    public:
      FileChooser(Action action);
      void ChooseAction(Action action);
  };
};
