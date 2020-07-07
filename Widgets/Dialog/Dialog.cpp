#include "./Dialog.hh"

namespace CGui
{
	Dialog::Dialog(Window& window, bool modal, const char* title)
	{
		widget = gtk_dialog_new();
		t_widget = gtk_dialog_get_content_area(GTK_DIALOG(widget));
		this->Parent(window);
		this->Modal(modal);
		this->Title(title);
		this->SetContext(widget);
	}

	void Dialog::Resizable(bool resizable)
	{
		gtk_window_set_resizable(GTK_WINDOW(widget), resizable);
	}

	void Dialog::DefaultSize(unsigned int xsize, unsigned int ysize)
	{
		gtk_window_set_default_size(GTK_WINDOW(widget), xsize, ysize);
	}

	void Dialog::CustomHeaderbar(Headerbar& hb)
	{
		gtk_window_set_titlebar(GTK_WINDOW(widget), hb.GetWidget());
	}

	void Dialog::Title(const char* title)
	{
		gtk_window_set_title(GTK_WINDOW(widget), title);
	}

	const char* Dialog::Title()
	{
		return gtk_window_get_title(GTK_WINDOW(widget));
	}

	void Dialog::Modal(bool modal)
	{
		gtk_window_set_modal(GTK_WINDOW(widget), modal);
	}

	bool Dialog::Modal()
	{
		return gtk_window_get_modal(GTK_WINDOW(widget));
	}

	void Dialog::Parent(Window& window)
	{
		gtk_window_set_transient_for(GTK_WINDOW(widget), GTK_WINDOW(window.GetWidget()));
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
};
