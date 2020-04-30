#pragma once

#include "../Widget.hh"

namespace CGui
{
  class FileChooser : public widget
  {
    public:
      FileChooser(Action action);
      void ChooseAction(Action action);
  };
};

#include "./FileChooser.cc"
