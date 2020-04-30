#pragma once

#include "./Image.hh"

namespace CGui
{
  Image::Image(const char *filename)
  { widget = gtk_image_new_from_file(filename); }

  Image::Image(const char *filename, int width, int height, bool aspectRatio, GError **error)
  { widget = gtk_image_new_from_pixbuf(gdk_pixbuf_new_from_file_at_scale(filename, width, height, aspectRatio, error)); }
};
