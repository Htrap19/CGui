#include "./LinkButton.hh"

namespace CGui
{
	LinkButton::LinkButton(GtkLinkButton* link_button) : Button::Container(this), Button::Handler(this)
	{
		if (widget != nullptr)
			gtk_widget_destroy(widget);
		widget = GTK_WIDGET(link_button);
		this->SetContext(widget);
	}

	LinkButton::LinkButton(const char* uri) : Button::Container(this), Handler<Button>::Handler(this)
	{
		if (widget != nullptr)
			gtk_widget_destroy(widget);
		widget = gtk_link_button_new(uri);
		this->SetContext(widget);
	}

	LinkButton::LinkButton(const char* uri, const char* label) : Button::Container(this), Button::Handler(this)
	{
		widget = gtk_link_button_new_with_label(uri, label);
		this->SetContext(widget);
	}

	void LinkButton::Uri(const char* uri)
	{
		gtk_link_button_set_uri(GTK_LINK_BUTTON(widget), uri);
	}

	const char* LinkButton::Uri()
	{
		return gtk_link_button_get_uri(GTK_LINK_BUTTON(widget));
	}

	void LinkButton::Visited(bool visited)
	{
		gtk_link_button_set_visited(GTK_LINK_BUTTON(widget), visited);
	}

	bool LinkButton::Visited()
	{
		return gtk_link_button_get_visited(GTK_LINK_BUTTON(widget));
	}

	bool LinkButton::IsLinkButton()
	{
		return GTK_IS_LINK_BUTTON(widget);
	}

}