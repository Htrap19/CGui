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
};
