#pragma once

#include "../Widget.hh"
#include <vector>
#include <tuple>

namespace CGui
{
  class Box : public widget
  {
    public:
      Box(BoxType type, int spacing);
      template <typename addtype> void Add(BoxAddType type, addtype &w, bool expand = false, bool fill = false, unsigned int padding = 0);
      template <typename addtype> void AddStart(addtype &w, bool expand = false, bool fill = false, unsigned int padding = 0);
      template <typename addtype> void AddEnd(addtype &w, bool expand = false, bool fill = false, unsigned int padding = 0);
      template <typename removetype> void Remove(removetype &w);
      // template<typename addtype, typename ... restaddtype> void Add(BoxAddType, addtype &w, restaddtype & ... rw, bool expand = false, bool fill = false, unsigned int padding = 0);
      void Homogeneous(bool homogeneous);
      bool Homogeneous();
  };
}

#include "./Box.cc"
