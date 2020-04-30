#pragma once

#include "../Widget.hh"
#include "../EventHandler.hh"
#include "../Container.hh"

namespace CGui
{
  class Button : public widget, public EventHandler<Button>, public Container
  {
    public:
      Button();
      Button(const char *text);
      void Text(const char *text);
      const char *Text();
      long unsigned int Clicked(void(*func)());
      long unsigned int Clicked(void(*func)(Button*));
      template <typename ... Args> long unsigned int Clicked(void(*func)(Button*, Args*...), Args & ... args);
      template <typename ... Args> long unsigned int Clicked(void(*func)(Args*...), Args & ... args);
  };
}

#include "./Button.cc"
