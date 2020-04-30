#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Spinner : public widget
  {
    public:
      Spinner();
      void Start();
      void Stop();
  };
};

#include "./Spinner.cc"
