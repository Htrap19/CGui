#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
  class Box : public Widget, public Container<Box>
  {
    public:
      Box(BoxType type, int spacing);
      template <typename addtype> void Add(BoxAddType type, addtype &w, bool expand = false, bool fill = false, unsigned int padding = 0);
      template <typename addtype> void AddStart(addtype &w, bool expand = false, bool fill = false, unsigned int padding = 0);
      template <typename addtype> void AddEnd(addtype &w, bool expand = false, bool fill = false, unsigned int padding = 0);
      // template<typename addtype, typename ... restaddtype> void Add(BoxAddType, addtype &w, restaddtype & ... rw, bool expand = false, bool fill = false, unsigned int padding = 0);
      void Homogeneous(bool homogeneous);
      bool Homogeneous();
  };

  template<typename addtype> void Box::Add(BoxAddType type, addtype& w, bool expand, bool fill, unsigned int padding)
  {
	  auto func = Converter::Convert::GetInstance().BoxFuncPtr(type);
	  func(GTK_BOX(widget), w.GetWidget(), expand, fill, padding);
	  children.Insert((void*)& w);
  }

  template <typename addtype> void Box::AddStart(addtype& w, bool expand, bool fill, unsigned int padding)
  {
	  this->Add(BoxAddType::START, w, expand, fill, padding);
  }

  template <typename addtype> void Box::AddEnd(addtype& w, bool expand, bool fill, unsigned int padding)
  {
	  this->Add(BoxAddType::END, w, expand, fill, padding);
  }
}