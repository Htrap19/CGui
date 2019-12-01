#pragma once

#include "CGuiWidget.hh"

class Label : public widget
{
  public:
    Label(const gchar *text);
    void Align(Alignments halign, Alignments valign);
    void SizeRequest(guint x, guint y);
    void StyleClass(const gchar *classname);
    GtkWidget *GetWidget();

  private:
    GtkWidget *label;
};

Label::Label(const gchar *text)
{ label = gtk_label_new(text); }

void Label::Align(Alignments halign, Alignments valign)
{
  Converter::Convert convert;
  gtk_widget_set_halign(GTK_WIDGET(label), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
  gtk_widget_set_valign(GTK_WIDGET(label), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
}

void Label::SizeRequest(guint x, guint y)
{ gtk_widget_set_size_request(GTK_WIDGET(label), x, y); }

void Label::StyleClass(const gchar *classname)
{ gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(label))), classname); }

GtkWidget *Label::GetWidget()
{ return label; }
