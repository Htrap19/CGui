#include "CGuiBox.hh"

Box::Box(BoxType type, gint spacing)
{
  Converter::Convert convert;
  box = gtk_box_new(std::get<GtkOrientation>(convert.ConvertToGtkCode(type)), spacing);
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
