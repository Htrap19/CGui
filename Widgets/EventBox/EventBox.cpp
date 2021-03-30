#include "./EventBox.hh"

namespace CGui
{
	EventBox::EventBox() : Container(this), Handler(this)
	{
		m_Widget = gtk_event_box_new();
		this->SetContext(m_Widget);
	}

	EventBox::EventBox(Widget& w) : Container(this), Handler(this)
	{
		m_Widget = gtk_event_box_new();
		this->SetContext(m_Widget);
		this->Add(w);
	}

	EventBox::EventBox(GtkEventBox* event_box) : Container(this), Handler(this)
	{
		m_Widget = GTK_WIDGET(event_box);
		this->SetContext(m_Widget);
	}

	void EventBox::VisibleWindow(bool visible)
	{
		gtk_event_box_set_visible_window(GTK_EVENT_BOX(m_Widget), visible);
	}

	bool EventBox::VisibleWindow()
	{
		return gtk_event_box_get_visible_window(GTK_EVENT_BOX(m_Widget));
	}

	void EventBox::AboveChild(bool above)
	{
		gtk_event_box_set_above_child(GTK_EVENT_BOX(m_Widget), above);
	}

	bool EventBox::AboveChild()
	{
		return gtk_event_box_get_above_child(GTK_EVENT_BOX(m_Widget));
	}
	bool EventBox::IsEventBox()
	{
		return GTK_IS_EVENT_BOX(m_Widget);
	}
}