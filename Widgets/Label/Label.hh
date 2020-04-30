#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Label : public widget
  {
    public:
      Label(const gchar *text);
      void Text(const char *text);
      const char *Text();
  };
};

#include "./Label.cc"
