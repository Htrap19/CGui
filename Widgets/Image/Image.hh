#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Image : public widget
  {
    public:
      Image(const char *filename);
      Image(const char *filename, int width, int height, bool aspectRatio = true, GError **error = NULL);
  };
}

#include "./Image.cc"
