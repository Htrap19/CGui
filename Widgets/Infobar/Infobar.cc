#pragma once

#include "./Infobar.hh"

namespace CGui
{
  Infobar::Infobar()
  {
    widget = gtk_info_bar_new();
    content_area = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
    this->SetContainer(content_area);
  }

  Infobar::Infobar(MessageType messagetype, bool showclosebutton)
  {
    widget = gtk_info_bar_new();
    content_area = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
    gtk_info_bar_set_message_type(GTK_INFO_BAR(widget), std::get<GtkMessageType>(Converter::Convert::GetInstance().ConvertToGtkCode(messagetype)));
    this->ShowCloseButton(showclosebutton);
    this->SetContainer(content_area);
  }

  void Infobar::Reveal(bool reveal)
  { gtk_info_bar_set_revealed(GTK_INFO_BAR(widget), reveal); }

  bool Infobar::Reveal()
  { return gtk_info_bar_get_revealed(GTK_INFO_BAR(widget)); }

  void Infobar::MessageBoxType(MessageType messagetype)
  { gtk_info_bar_set_message_type(GTK_INFO_BAR(widget), std::get<GtkMessageType>(Converter::Convert::GetInstance().ConvertToGtkCode(messagetype))); }

  void Infobar::ShowCloseButton(bool showclosebutton)
  { gtk_info_bar_set_show_close_button(GTK_INFO_BAR(widget), showclosebutton); }
};
