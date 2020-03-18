#pragma once

#include "../Converter/Convert.hh"

namespace CGui
{
  class widget
  {
    public:
      virtual GtkWidget *GetWidget() = 0;
      virtual void Align(Alignments halign, Alignments valign) = 0;
      virtual void Name(const char *name) = 0;
      virtual const char *Name() = 0;
      virtual void Sensitive(bool sensitive) = 0;
      virtual void SizeRequest(unsigned int x, unsigned int y) = 0;
      virtual void Tooltip(const char *text) = 0;
      virtual const char *Tooltip() = 0;
      virtual void StyleClass(const char *classname) = 0;
      virtual void Hide() = 0;
      virtual void Show() = 0;
      // virtual ~widget()
      // {  }

    protected:
      GtkWidget *widget;
  };
}
