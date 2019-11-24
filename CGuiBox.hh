#pragma once

#include "CGuiWidget.hh"

class Box : public widget
{
  public:
    Box(BoxType type, gint spacing);
    template<typename addtype> void Add(BoxAddType type, addtype &w, gboolean expand = false, gboolean fill = false, guint padding = 0);
    void Align(Alignments halign, Alignments valign);
    void SizeRequest(guint x, guint y);
    GtkWidget *GetWidget();

  private:
    GtkWidget *box;
};

template<typename addtype> void Box::Add(BoxAddType type, addtype &w, gboolean expand, gboolean fill, guint padding)
{
  Converter::Convert convert;
  convert.AddIntoBox(box, w, type, expand, fill, padding);
}
