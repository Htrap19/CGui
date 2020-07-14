#include "./Infobar.hh"

namespace CGui
{
	Infobar::Infobar() : Orientable(this)
	{
		widget = gtk_info_bar_new();
		t_widget = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
		this->SetContext(widget);
	}

	Infobar::Infobar(CGui::MessageType messagetype, bool showclosebutton) : Orientable(this)
	{
		widget = gtk_info_bar_new();
		this->MessageType(messagetype);
		this->ShowCloseButton(showclosebutton);
		t_widget = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
		this->SetContext(widget);
	}

	void Infobar::MessageType(CGui::MessageType messagetype)
	{
		gtk_info_bar_set_message_type(GTK_INFO_BAR(widget), (GtkMessageType)messagetype);
	}

	CGui::MessageType Infobar::MessageType()
	{
		return (CGui::MessageType)gtk_info_bar_get_message_type(GTK_INFO_BAR(widget));
	}

	void Infobar::ShowCloseButton(bool showclosebutton)
	{
		gtk_info_bar_set_show_close_button(GTK_INFO_BAR(widget), showclosebutton);
	}

	bool Infobar::ShowCloseButton()
	{
		return gtk_info_bar_get_show_close_button(GTK_INFO_BAR(widget));
	}
};
