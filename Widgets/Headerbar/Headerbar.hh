#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
  class Headerbar : public Widget, public Container<Headerbar>
  {
    public:
      Headerbar(const char *title = "", const char *subtitle = "");
      template <typename addtype> void Add(BoxAddType type, addtype &w);
      template <typename addtype> void AddStart(addtype &w);
      template <typename addtype> void AddEnd(addtype &w);
  };

  template <typename addtype> void Headerbar::Add(BoxAddType type, addtype& w)
  {
	  auto func = Converter::Convert::GetInstance().HeaderbarFuncPtr(type);
	  func(GTK_HEADER_BAR(widget), w.GetWidget());
	  children.Insert((void*)& w);
  }

  template <typename addtype> void Headerbar::AddStart(addtype& w)
  {
	  this->Add(BoxAddType::START, w);
  }

  template <typename addtype> void Headerbar::AddEnd(addtype& w)
  {
	  this->Add(BoxAddType::END, w);
  }
}
