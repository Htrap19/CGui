#pragma once

#include "../Widget.hh"
#include "../Window/Window.hh"
#include "../Container.hh"

namespace CGui
{
  class Dialog : public widget, public Container
  {
    public:
      Dialog(Window &window, bool modal, const char *title = "");
      void InternalWidth(unsigned int width);
      void Resizable(bool resizable);
      void DefaultSize(unsigned int xsize, unsigned int ysize);
      void CustomHeaderbar(Headerbar &hb);
      void Title(const char *title);
      const char *Title();
      void Modal(bool modal);
      bool Modal();
      void Parent(Window &window);
      void Parent(Window *window);

    protected:
      GtkWidget *content_area;
  };
};

#include "./Dialog.cc"
