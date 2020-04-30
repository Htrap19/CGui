#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Headerbar : public widget
  {
    public:
      Headerbar(const gchar *title = "", const gchar *subtitle = "");
      template<typename addtype> void Add(BoxAddType type, addtype &w);
      template <typename addtype> void AddStart(addtype &w);
      template <typename addtype> void AddEnd(addtype &w);
  };
}

#include "./Headerbar.cc"
