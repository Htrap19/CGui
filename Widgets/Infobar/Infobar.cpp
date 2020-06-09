#include "./Infobar.hh"

namespace CGui
{
  Infobar::Infobar()
  {
    widget = gtk_info_bar_new();
	t_widget = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
	this->SetContext(widget);
  }

  Infobar::Infobar(MessageType messagetype, bool showclosebutton)
  {
    widget = gtk_info_bar_new();
    gtk_info_bar_set_message_type(GTK_INFO_BAR(widget), std::get<GtkMessageType>(Converter::Convert::GetInstance().ConvertToGtkCode(messagetype)));
    this->ShowCloseButton(showclosebutton);
	t_widget = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
	this->SetContext(widget);
  }

  void Infobar::Reveal(bool reveal)
  { gtk_revealer_set_reveal_child(GTK_REVEALER(widget), reveal); }

  bool Infobar::Reveal()
  { return gtk_revealer_get_reveal_child(GTK_REVEALER(widget)); }

  void Infobar::MessageBoxType(MessageType messagetype)
  { gtk_info_bar_set_message_type(GTK_INFO_BAR(widget), std::get<GtkMessageType>(Converter::Convert::GetInstance().ConvertToGtkCode(messagetype))); }

  void Infobar::ShowCloseButton(bool showclosebutton)
  { gtk_info_bar_set_show_close_button(GTK_INFO_BAR(widget), showclosebutton); }
};
