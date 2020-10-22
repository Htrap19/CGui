#include "./Infobar.hh"

namespace CGui
{
	Infobar::Infobar()
	{
		widget = gtk_info_bar_new();
		Container<Widget>::t_widget = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
		this->SetBox(GTK_BOX(widget));
	}

	Infobar::Infobar(GtkInfoBar* infobar)
	{
		this->widget = GTK_WIDGET(infobar);
		this->SetBox(GTK_BOX(widget));
		Container<Widget>::t_widget = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
	}

	Infobar::Infobar(CGui::MessageType messagetype, bool showclosebutton)
	{
		widget = gtk_info_bar_new();
		this->MessageType(messagetype);
		this->ShowCloseButton(showclosebutton);
		Container<Widget>::t_widget = gtk_info_bar_get_content_area(GTK_INFO_BAR(widget));
		this->SetBox(GTK_BOX(widget));
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

	void Infobar::ActionWidget(Widget& child, ResponseType res_id)
	{
		gtk_info_bar_add_action_widget(GTK_INFO_BAR(widget), child.GetWidget(), (int)res_id);
	}

	Widget Infobar::AddButton(const char* button_text, ResponseType res_id)
	{
		return Widget(gtk_info_bar_add_button(GTK_INFO_BAR(widget), button_text, (int)res_id));
	}

	void Infobar::ResponseSensitive(ResponseType res, bool sensitive)
	{
		gtk_info_bar_set_response_sensitive(GTK_INFO_BAR(widget), (int)res, sensitive);
	}

	void Infobar::DefaultResponse(ResponseType res)
	{
		gtk_info_bar_set_default_response(GTK_INFO_BAR(widget), (int)res);
	}

	void Infobar::Response(ResponseType res)
	{
		gtk_info_bar_response(GTK_INFO_BAR(widget), (int)res);
	}

	Widget Infobar::ContentArea()
	{
		return Widget(gtk_info_bar_get_content_area(GTK_INFO_BAR(widget)));
	}

	Widget Infobar::ActionArea()
	{
		return Widget(gtk_info_bar_get_action_area(GTK_INFO_BAR(widget)));
	}

	bool Infobar::IsInfobar()
	{
		return GTK_IS_INFO_BAR(widget);
	}

};
