#include "./CheckButton.hh"

namespace CGui
{
	CheckButton::CheckButton() : Handler<CheckButton>::Handler(this)
	{
		widget = gtk_check_button_new();
		this->SetToggleButton(GTK_TOGGLE_BUTTON(widget));
	}

	CheckButton::CheckButton(const char* text) : Handler<CheckButton>::Handler(this)
	{
		widget = gtk_check_button_new_with_label(text);
		this->SetToggleButton(GTK_TOGGLE_BUTTON(widget));
	}

	long unsigned int CheckButton::Toggled(void(*func)())
	{
		return this->Handler<CheckButton>::SignalHandler(Signals::TOGGLED, func);
	}

	long unsigned int CheckButton::Toggled(void(*func)(CheckButton*))
	{
		return this->Handler<CheckButton>::SignalHandler(Signals::TOGGLED, func);
	}

	void CheckButton::SetCheckButton(GtkCheckButton* checkbutton)
	{
		this->widget = GTK_WIDGET(checkbutton);
		this->SetToggleButton(GTK_TOGGLE_BUTTON(widget));
	}
};
