#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Headerbar : public widget
  {
    public:
      Headerbar(const gchar *title = "", const gchar *subtitle = "");
      void Name(const char *name);
      const char *Name();
      template<typename addtype> void Add(BoxAddType type, addtype &w);
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

  Headerbar::Headerbar(const gchar *title, const gchar *subtitle)
  {
    widget = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(widget), title);
    gtk_header_bar_set_subtitle(GTK_HEADER_BAR(widget), subtitle);
  }

  void Headerbar::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(widget), name); }

  const char *Headerbar::Name()
  { return gtk_widget_get_name(GTK_WIDGET(widget)); }

  template<typename addtype> void Headerbar::Add(BoxAddType type, addtype &w)
  {
    switch (type)
    {
      case START:
        gtk_header_bar_pack_start(GTK_HEADER_BAR(widget), w.GetWidget());
        break;
      case END:
        gtk_header_bar_pack_end(GTK_HEADER_BAR(widget), w.GetWidget());
        break;
    }
  }

  void Headerbar::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive); }

  void Headerbar::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Headerbar::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(widget), x, y); }

  void Headerbar::Tooltip(const char *text)
  { gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text); }

  const char *Headerbar::Tooltip()
  { return gtk_widget_get_tooltip_text(GTK_WIDGET(widget)); }

  void Headerbar::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(widget))), classname); }

  void Headerbar::Hide()
  { gtk_widget_hide(GTK_WIDGET(widget)); }

  void Headerbar::Show()
  { gtk_widget_show(GTK_WIDGET(widget)); }

  GtkWidget *Headerbar::GetWidget()
  { return widget; }
}
