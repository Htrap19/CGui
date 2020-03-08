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
      void Tooltip(const char *text);
      const char *Tooltip();
      void StyleClass(const gchar *classname);
      void Hide();
      void Show();
      GtkWidget *GetWidget();
  };

  Label::Label(const gchar *text)
  { widget = gtk_label_new(text); }

  void Label::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(widget), name); }

  const char *Label::Name()
  { return gtk_widget_get_name(GTK_WIDGET(widget)); }

  void Label::Text(const char *text)
  { gtk_label_set_label(GTK_LABEL(widget), text); }

  const char *Label::Text()
  { return gtk_label_get_text(GTK_LABEL(widget)); }

  void Label::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive); }

  void Label::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Label::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(widget), x, y); }

  void Label::Tooltip(const char *text)
  { gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text); }

  const char *Label::Tooltip()
  { return gtk_widget_get_tooltip_text(GTK_WIDGET(widget)); }

  void Label::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(widget))), classname); }

  void Label::Hide()
  { gtk_widget_hide(GTK_WIDGET(widget)); }

  void Label::Show()
  { gtk_widget_show(GTK_WIDGET(widget)); }

  GtkWidget *Label::GetWidget()
  { return widget; }
}
