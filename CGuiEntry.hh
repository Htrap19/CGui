#pragma once

#include "CGuiWidget.hh"

namespace CGui
{
  class Entry : public widget
  {
    public:
      Entry();
      Entry(const gchar *placeholdertext);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      void SetText(const char *text);
      const char *GetText();
      GtkWidget *GetWidget();

    private:
      GtkWidget *entry;
  };

  Entry::Entry()
  { entry = gtk_entry_new(); }

  Entry::Entry(const gchar *placeholdertext)
  {
    entry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(entry), placeholdertext);
  }

  void Entry::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(entry), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(entry), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Entry::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(entry), x, y); }

  void Entry::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(entry))), classname); }

  void Entry::SetText(const char *text)
  { gtk_entry_set_text(GTK_ENTRY(entry), text); }

  const char *Entry::GetText()
  { return gtk_entry_get_text(GTK_ENTRY(entry)); }

  GtkWidget *Entry::GetWidget()
  { return entry; }
}
