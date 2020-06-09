#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Progressbar : public Widget
  {
    public:
      Progressbar();
      Progressbar(const char *text);
      void Pulse();
      void Pulse(double fraction);
      void Fraction(double fraction);
      double Fraction();
      void ShowText(bool show);
      bool ShowText();
      void Text(const char *text);
      const char *Text();
      void Increment(double fraction);
      void Increment();
  };
}
