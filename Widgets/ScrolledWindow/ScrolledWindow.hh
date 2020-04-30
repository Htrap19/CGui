#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
  class ScrolledWindow : public widget, public Container
  {
    public:
      ScrolledWindow(Policy hpolicy, Policy vpolicy);
      void ScrollPolicy(Policy hpolicy, Policy vpolicy);
  };
};

#include "./ScrolledWindow.cc"
