#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Headerbar/Headerbar.hh"
#include "../../Custom/Storage/Storage.hh"

namespace CGui
{
  class Window : public widget, public Container
  {
    public:
      Window(WindowType type, const char *title, WindowPos pos);
      void Icon(const char *iconpath);
      void InternalWidth(unsigned int width);
      void DefaultSize(unsigned int xsize, unsigned int ysize);
      void CustomHeaderbar(Headerbar &hb);
      void Resizable(bool resizable);
      void Title(const char *title);
      const char *Title();
      void Maximize();
      void Unmaximize();
      void Fullscreen();
      void Unfullscreen();
      void Position(WindowPos pos);
      void Quit();
  };
}

#include "./Window.cc"
