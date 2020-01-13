#pragma once

#include "CGuiWidget.hh"

namespace CGui
{
  class Headerbar : public widget
  {
    public:
      Headerbar(const gchar *title = "", const gchar *subtitle = "");
      template<typename addtype> void Add(BoxAddType type, addtype &w);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      GtkWidget *GetWidget();

    private:
      GtkWidget *headerbar;
  };

  Headerbar::Headerbar(const gchar *title, const gchar *subtitle)
  {
    headerbar = gtk_header_bar_new();
    gtk_header_bar_set_title(GTK_HEADER_BAR(headerbar), title);
    gtk_header_bar_set_subtitle(GTK_HEADER_BAR(headerbar), subtitle);
  }

  template<typename addtype> void Headerbar::Add(BoxAddType type, addtype &w)
  {
    switch (type)
    {
      case START:
        gtk_header_bar_pack_start(GTK_HEADER_BAR(headerbar), w.GetWidget());
        break;
      case END:
        gtk_header_bar_pack_end(GTK_HEADER_BAR(headerbar), w.GetWidget());
        break;
    }
  }

  void Headerbar::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(headerbar), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(headerbar), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Headerbar::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(headerbar), x, y); }

  void Headerbar::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(headerbar))), classname); }

  GtkWidget *Headerbar::GetWidget()
  { return headerbar; }
}
