#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
  class Revealer : public widget, public Container
  {
    public:
      Revealer(Transition transition, unsigned int duration);
      void Reveal(bool reveal);
      bool Reveal();
  };
};

#include "./Revealer.cc"
