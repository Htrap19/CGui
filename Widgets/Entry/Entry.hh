#pragma once

#include "../Widget.hh"
#include "../EventHandler.hh"

namespace CGui
{
  class Entry : public Widget, public EventHandler<Entry>
  {
    public:
      Entry();
      Entry(const char *placeholdertext);
      void Editable(bool editable);
      bool Editable();
      void Visibility(bool visibility);
      bool Visibility();
      void Text(const char *text);
      const char *Text();
      long unsigned int Changed(void(*func)());
      long unsigned int Changed(void(*func)(Entry*));
      template <typename ... Args> long unsigned int Changed(void(*func)(Entry*, Args*...), Args & ... args);
      template <typename ... Args> long unsigned int Changed(void(*func)(Args*...), Args & ... args);
  };

  template <typename ... Args> long unsigned int Entry::Changed(void(*func)(Entry*, Args* ...), Args& ... args)
  {
	  return this->SignalHandler(Events::CHANGED, func, args...);
  }

  template <typename ... Args> long unsigned int Entry::Changed(void(*func)(Args* ...), Args& ... args)
  {
	  return this->SignalHandler(Events::CHANGED, func, args...);
  }
}