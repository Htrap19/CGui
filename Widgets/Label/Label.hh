#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Label : public widget
  {
    public:
      Label(const gchar *text);
      void Name(const char *name);
      const char *Name();
      void Text(const char *text);
      const char *Text();
      void Sensitive(bool sensitive);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *label;
  };

  Label::Label(const gchar *text)
  { label = gtk_label_new(text); }

  void Label::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(label), name); }

  const char *Label::Name()
  { return gtk_widget_get_name(GTK_WIDGET(label)); }

  void Label::Text(const char *text)
  { gtk_label_set_label(GTK_LABEL(label), text); }

  const char *Label::Text()
  { return gtk_label_get_text(GTK_LABEL(label)); }

  void Label::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(label), sensitive); }

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

  void Label::Show()
  { gtk_widget_show(GTK_WIDGET(label)); }

  GtkWidget *Label::GetWidget()
  { return label; }
}
