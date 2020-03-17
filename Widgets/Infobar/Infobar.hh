#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Infobar : public widget
  {
    public:
      Infobar();
      Infobar(MessageType messagetype, bool showclosebutton);
      void Reveal(bool reveal);
      bool Reveal();
      void MessageBoxType(MessageType messagetype);
      void ShowCloseButton(bool showclosebutton);
      template <typename addtype> void Add(addtype &w);
      template <typename removetype> void Remove(removetype &w);
      void Name(const char *name);
      const char *Name();
      void Align(Alignments halign, Alignments valign);
      void Sensitive(bool sensitive);
      void SizeRequest(unsigned int x, unsigned int y);
      void Tooltip(const char *text);
      const char *Tooltip();
      void StyleClass(const char *classname);
      void Hide();
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *content_area;
  };

  Infobar::Infobar()
  {
    widget = gtk_info_bar_new();
    content_area = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
  }

  Infobar::Infobar(MessageType messagetype, bool showclosebutton)
  {
    widget = gtk_info_bar_new();
    Converter::Convert convert;
    content_area = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
    gtk_info_bar_set_message_type(GTK_INFO_BAR(widget), std::get<GtkMessageType>(convert.ConvertToGtkCode(messagetype)));
    gtk_info_bar_set_show_close_button(GTK_INFO_BAR(widget), showclosebutton);
  }

  void Infobar::Reveal(bool reveal)
  { gtk_info_bar_set_revealed(GTK_INFO_BAR(widget), reveal); }

  bool Infobar::Reveal()
  { return gtk_info_bar_get_revealed(GTK_INFO_BAR(widget)); }

  void Infobar::MessageBoxType(MessageType messagetype)
  {
    Converter::Convert convert;
    gtk_info_bar_set_message_type(GTK_INFO_BAR(widget), std::get<GtkMessageType>(convert.ConvertToGtkCode(messagetype)));
  }

  void Infobar::ShowCloseButton(bool showclosebutton)
  { gtk_info_bar_set_show_close_button(GTK_INFO_BAR(widget), showclosebutton); }

  template <typename addtype> void Infobar::Add(addtype &w)
  { gtk_container_add(GTK_CONTAINER(content_area), w.GetWidget()); }

  template <typename removetype> void Infobar::Remove(removetype &w)
  { gtk_container_remove(GTK_CONTAINER(content_area), w.GetWidget()); }

  void Infobar::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(widget), name); }

  const char *Infobar::Name()
  { return gtk_widget_get_name(GTK_WIDGET(widget)); }

  void Infobar::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Infobar::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive); }

  void Infobar::SizeRequest(unsigned int x, unsigned int y)
  { gtk_widget_set_size_request(GTK_WIDGET(widget), x, y); }

  void Infobar::Tooltip(const char *text)
  { gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text); }

  const char *Infobar::Tooltip()
  { return gtk_widget_get_tooltip_text(GTK_WIDGET(widget)); }

  void Infobar::StyleClass(const char *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(widget))), classname); }

  void Infobar::Hide()
  { gtk_widget_hide(GTK_WIDGET(widget)); }

  void Infobar::Show()
  { gtk_widget_show(GTK_WIDGET(widget)); }

  GtkWidget *Infobar::GetWidget()
  { return widget; }
};
