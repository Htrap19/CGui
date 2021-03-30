#include "./LinkButton.hh"

namespace CGui
{
	LinkButton::LinkButton(GtkLinkButton* link_button) : Button::Container(this), Button::Handler(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = GTK_WIDGET(link_button);
		this->SetContext(m_Widget);
	}

	LinkButton::LinkButton(const char* uri) : Button::Container(this), Handler<Button>::Handler(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = gtk_link_button_new(uri);
		this->SetContext(m_Widget);
	}

	LinkButton::LinkButton(const char* uri, const char* label) : Button::Container(this), Button::Handler(this)
	{
		m_Widget = gtk_link_button_new_with_label(uri, label);
		this->SetContext(m_Widget);
	}

	void LinkButton::Uri(const char* uri)
	{
		gtk_link_button_set_uri(GTK_LINK_BUTTON(m_Widget), uri);
	}

	const char* LinkButton::Uri()
	{
		return gtk_link_button_get_uri(GTK_LINK_BUTTON(m_Widget));
	}

	void LinkButton::Visited(bool visited)
	{
		gtk_link_button_set_visited(GTK_LINK_BUTTON(m_Widget), visited);
	}

	bool LinkButton::Visited()
	{
		return gtk_link_button_get_visited(GTK_LINK_BUTTON(m_Widget));
	}

	bool LinkButton::IsLinkButton()
	{
		return GTK_IS_LINK_BUTTON(m_Widget);
	}

}