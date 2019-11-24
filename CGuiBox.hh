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

Box::Box(BoxType type, gint spacing)
{
  Converter::Convert convert;
  box = gtk_box_new(std::get<GtkOrientation>(convert.ConvertToGtkCode(type)), spacing);
}

template<typename addtype> void Box::Add(BoxAddType type, addtype &w, gboolean expand, gboolean fill, guint padding)
{
  Converter::Convert convert;
  convert.AddIntoBox(box, w, type, expand, fill, padding);
}

void Box::Align(Alignments halign, Alignments valign)
{
  Converter::Convert convert;
  gtk_widget_set_halign(GTK_WIDGET(box), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
  gtk_widget_set_valign(GTK_WIDGET(box), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
}

void Box::SizeRequest(guint x, guint y)
{ gtk_widget_set_size_request(GTK_WIDGET(box), x, y); }

GtkWidget *Box::GetWidget()
{ return box; }
