#pragma once

#include <gtk/gtk.h>

namespace CGui
{
  class CssProvider
  {
    public:
      CssProvider(const gchar *cssfilepath);
      GtkCssProvider *GetWidget();

    protected:
      GtkCssProvider *cssProvider;
  };
};

#include "./CssProvider.cc"
