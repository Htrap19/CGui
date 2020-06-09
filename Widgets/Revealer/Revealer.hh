#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
  class Revealer : public Widget, public Container<Revealer>
  {
    public:
      Revealer(Transition transition, unsigned int duration);
      void Reveal(bool reveal);
      bool Reveal();
  };
};
