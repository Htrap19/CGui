#pragma once

#include "./Button.hh"

namespace CGui
{
  Button::Button() : EventHandler(this)
  {
    widget = gtk_button_new();
    this->SetContainer(widget);
  }

  Button::Button(const char *text) : EventHandler(this)
  {
    widget = gtk_button_new_with_label(text);
    this->SetContainer(widget);
  }

  long unsigned int Button::Clicked(void(*func)())
  { return this->SignalHandler(CLICKED, func); }

  long unsigned int Button::Clicked(void(*func)(Button*))
  { return this->SignalHandler(CLICKED, func); }

  template <typename ... Args> long unsigned int Button::Clicked(void(*func)(Button*, Args*...), Args & ... args)
  { return this->SignalHandler(CLICKED, func, args...); }

  template <typename ... Args> long unsigned int Button::Clicked(void(*func)(Args*...), Args & ... args)
  { return this->SignalHandler(CLICKED, func, args...); }

  void Button::Text(const char *text)
  { gtk_button_set_label(GTK_BUTTON(widget), text); }

  const char *Button::Text()
  { return gtk_button_get_label(GTK_BUTTON(widget)); }
};
