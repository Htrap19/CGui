#include "./CheckButton.hh"

namespace CGui
{
	CheckButton::CheckButton() : Handler(this)
	{
		widget = gtk_check_button_new();
		this->SetContext(widget);
	}

	CheckButton::CheckButton(const char* text) : Handler(this)
	{
		widget = gtk_check_button_new_with_label(text);
		this->SetContext(widget);
	}

	void CheckButton::Checked(bool active)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), active);
	}

	bool CheckButton::Checked()
	{
		return gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	}

	long unsigned int CheckButton::Toggled(void(*func)())
	{
		return this->SignalHandler(Signals::TOGGLED, func);
	}

	long unsigned int CheckButton::Toggled(void(*func)(CheckButton*))
	{
		return this->SignalHandler(Signals::TOGGLED, func);
	}
};
