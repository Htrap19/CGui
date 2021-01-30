#include "./Statusbar.hh"

namespace CGui
{
	Statusbar::Statusbar() : Box::Container(this), Box::Orientable(this)
	{
		widget = gtk_statusbar_new();
		this->SetContext(widget);
		Container<Widget>::t_widget = gtk_statusbar_get_message_area(GTK_STATUSBAR(widget));
	}

	Statusbar::Statusbar(GtkStatusbar* status_bar) : Box::Container(this), Box::Orientable(this)
	{
		widget = GTK_WIDGET(status_bar);
		this->SetContext(widget);
		Container<Widget>::t_widget = gtk_statusbar_get_message_area(GTK_STATUSBAR(widget));
	}

	void Statusbar::Add(Widget& child)
	{
		this->Container<Widget>::Add(child);
	}

	void Statusbar::Remove(Widget& child)
	{
		this->Container<Widget>::Remove(child);
	}

	int Statusbar::ContextID(const char* context_description)
	{
		return gtk_statusbar_get_context_id(GTK_STATUSBAR(widget), context_description);
	}

	int Statusbar::Push(int context_id, const char* text)
	{
		return gtk_statusbar_push(GTK_STATUSBAR(widget), context_id, text);
	}

	void Statusbar::Pop(int context_id)
	{
		gtk_statusbar_pop(GTK_STATUSBAR(widget), context_id);
	}

	void Statusbar::Remove(int context_id, int message_id)
	{
		gtk_statusbar_remove(GTK_STATUSBAR(widget), context_id, message_id);
	}

	void Statusbar::RemoveAll(int context_id)
	{
		gtk_statusbar_remove_all(GTK_STATUSBAR(widget), context_id);
	}

	bool Statusbar::IsStatusbar()
	{
		return GTK_IS_STATUSBAR(widget);
	}

}