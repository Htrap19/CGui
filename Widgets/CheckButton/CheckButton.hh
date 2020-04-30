#pragma once

#include "../Widget.hh"
#include "../EventHandler.hh"

namespace CGui
{
  class CheckButton : public widget, public EventHandler<CheckButton>
  {
    public:
      CheckButton();
      CheckButton(const char *text);
      void Checked(bool active);
      bool Checked();
      long unsigned int Toggled(void(*func)());
      long unsigned int Toggled(void(*func)(CheckButton*));
      template <typename ... Args> long unsigned int Toggled(void(*func)(CheckButton*, Args*...), Args & ... args);
      template <typename ... Args> long unsigned int Toggled(void(*func)(Args*...), Args & ... args);
  };
};

#include "./CheckButton.cc"
