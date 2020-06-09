#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
  class Box : public Widget, public Container<Box>
  {
    public:
      Box(BoxType type, int spacing);
      void Add(BoxAddType type, Widget& w, bool expand = false, bool fill = false, unsigned int padding = 0);
      void AddStart(Widget& w, bool expand = false, bool fill = false, unsigned int padding = 0);
      void AddEnd(Widget& w, bool expand = false, bool fill = false, unsigned int padding = 0);
      // template<typename addtype, typename ... restaddtype> void Add(BoxAddType, addtype &w, restaddtype & ... rw, bool expand = false, bool fill = false, unsigned int padding = 0);
      void Homogeneous(bool homogeneous);
      bool Homogeneous();
  };
}