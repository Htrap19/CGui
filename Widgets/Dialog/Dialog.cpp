#include "./Dialog.hh"

namespace CGui
{
	Dialog::Dialog(Window& window, bool modal, const char* title)
	{
		widget = gtk_dialog_new();
		Container<Widget>::t_widget = gtk_dialog_get_content_area(GTK_DIALOG(widget));
		this->TransientFor(window);
		this->Modal(modal);
		this->Title(title);
		this->SetWindow(GTK_WINDOW(widget));
	}

	ResponseType Dialog::Run()
	{
		return (ResponseType)gtk_dialog_run(GTK_DIALOG(widget));
	}

	void Dialog::ActionWidget(Widget& action_widget, ResponseType res_type)
	{
		gtk_dialog_add_action_widget(GTK_DIALOG(widget), action_widget.GetWidget(), (int)res_type);
	}

	Widget Dialog::AddButton(const char* button_text, ResponseType res_type)
	{
		return Widget(gtk_dialog_add_button(GTK_DIALOG(widget), button_text, (int)res_type));
	}

	void Dialog::DefaultResponse(ResponseType res_type)
	{
		gtk_dialog_set_default_response(GTK_DIALOG(widget), (int)res_type);
	}

	void Dialog::ResponseSensitive(ResponseType res_type, bool sensitive)
	{
		gtk_dialog_set_response_sensitive(GTK_DIALOG(widget), (int)res_type, sensitive);
	}

	ResponseType Dialog::ResponseForWidget(Widget& w)
	{
		return (ResponseType)gtk_dialog_get_response_for_widget(GTK_DIALOG(widget), w.GetWidget());
	}

	Widget Dialog::WidgetForResponse(ResponseType res_type)
	{
		return Widget(gtk_dialog_get_widget_for_response(GTK_DIALOG(widget), (int)res_type));
	}

	void Dialog::Add(Widget& child)
	{
		this->Container<Widget>::Add(child);
	}

	void Dialog::Remove(Widget& child)
	{
		this->Container<Widget>::Remove(child);
	}

	void Dialog::InternalWidth(unsigned int width)
	{
		this->Container<Widget>::InternalWidth(width);
	}

	unsigned int Dialog::InternalWidth()
	{
		return this->Container<Widget>::InternalWidth();
	}

	Single::List<void*>* Dialog::Children()
	{
		return this->Container<Widget>::Children();
	}

	Dialog::Dialog()
	{ }

	void Dialog::SetDialog(GtkDialog* dialog)
	{
		this->widget = GTK_WIDGET(dialog);
		this->SetWindow(GTK_WINDOW(widget));
		Container<Widget>::t_widget = gtk_dialog_get_content_area(GTK_DIALOG(widget));
	}

};
