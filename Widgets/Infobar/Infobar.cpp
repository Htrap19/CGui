#include "./Infobar.hh"

namespace CGui
{
	Infobar::Infobar() : Box::Container(this), Box::Orientable(this)
	{
		m_Widget = gtk_info_bar_new();
		Container<Widget>::t_widget = gtk_info_bar_get_content_area(GTK_INFO_BAR(m_Widget));
		this->SetContext(m_Widget);
	}

	Infobar::Infobar(GtkInfoBar* infobar) : Box::Container(this), Box::Orientable(this)
	{
		m_Widget = GTK_WIDGET(infobar);
		Container<Widget>::t_widget = gtk_info_bar_get_content_area(GTK_INFO_BAR(m_Widget));
		this->SetContext(m_Widget);
	}

	Infobar::Infobar(CGui::MessageType messagetype, bool showclosebutton) : Box::Container(this), Box::Orientable(this)
	{
		m_Widget = gtk_info_bar_new();
		this->MessageType(messagetype);
		this->ShowCloseButton(showclosebutton);
		Container<Widget>::t_widget = gtk_info_bar_get_content_area(GTK_INFO_BAR(m_Widget));
		this->SetContext(m_Widget);
	}

	void Infobar::MessageType(CGui::MessageType messagetype)
	{
		gtk_info_bar_set_message_type(GTK_INFO_BAR(m_Widget), (GtkMessageType)messagetype);
	}

	CGui::MessageType Infobar::MessageType()
	{
		return (CGui::MessageType)gtk_info_bar_get_message_type(GTK_INFO_BAR(m_Widget));
	}

	void Infobar::ShowCloseButton(bool showclosebutton)
	{
		gtk_info_bar_set_show_close_button(GTK_INFO_BAR(m_Widget), showclosebutton);
	}

	bool Infobar::ShowCloseButton()
	{
		return gtk_info_bar_get_show_close_button(GTK_INFO_BAR(m_Widget));
	}

	void Infobar::ActionWidget(Widget& child, ResponseType res_id)
	{
		gtk_info_bar_add_action_widget(GTK_INFO_BAR(m_Widget), child.GetWidget(), (int)res_id);
	}

	Widget Infobar::AddButton(const char* button_text, ResponseType res_id)
	{
		return Widget(gtk_info_bar_add_button(GTK_INFO_BAR(m_Widget), button_text, (int)res_id));
	}

	void Infobar::ResponseSensitive(ResponseType res, bool sensitive)
	{
		gtk_info_bar_set_response_sensitive(GTK_INFO_BAR(m_Widget), (int)res, sensitive);
	}

	void Infobar::DefaultResponse(ResponseType res)
	{
		gtk_info_bar_set_default_response(GTK_INFO_BAR(m_Widget), (int)res);
	}

	void Infobar::Response(ResponseType res)
	{
		gtk_info_bar_response(GTK_INFO_BAR(m_Widget), (int)res);
	}

	Widget Infobar::ContentArea()
	{
		return Widget(gtk_info_bar_get_content_area(GTK_INFO_BAR(m_Widget)));
	}

	Widget Infobar::ActionArea()
	{
		return Widget(gtk_info_bar_get_action_area(GTK_INFO_BAR(m_Widget)));
	}

	bool Infobar::IsInfobar()
	{
		return GTK_IS_INFO_BAR(m_Widget);
	}

};
