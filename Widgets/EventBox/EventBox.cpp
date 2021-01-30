#include "./EventBox.hh"

namespace CGui
{
	EventBox::EventBox() : Container(this), Handler(this)
	{
		widget = gtk_event_box_new();
		this->SetContext(widget);
	}

	EventBox::EventBox(Widget& w) : Container(this), Handler(this)
	{
		widget = gtk_event_box_new();
		this->SetContext(widget);
		this->Add(w);
	}

	EventBox::EventBox(GtkEventBox* event_box) : Container(this), Handler(this)
	{
		widget = GTK_WIDGET(event_box);
		this->SetContext(widget);
	}

	void EventBox::VisibleWindow(bool visible)
	{
		gtk_event_box_set_visible_window(GTK_EVENT_BOX(widget), visible);
	}

	bool EventBox::VisibleWindow()
	{
		return gtk_event_box_get_visible_window(GTK_EVENT_BOX(widget));
	}

	void EventBox::AboveChild(bool above)
	{
		gtk_event_box_set_above_child(GTK_EVENT_BOX(widget), above);
	}

	bool EventBox::AboveChild()
	{
		return gtk_event_box_get_above_child(GTK_EVENT_BOX(widget));
	}
	bool EventBox::IsEventBox()
	{
		return GTK_IS_EVENT_BOX(widget);
	}
}