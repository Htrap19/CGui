#include "./ToggleButton.hh"

namespace CGui
{
	ToggleButton::ToggleButton() : Handler<ToggleButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		if (widget != nullptr)
			gtk_widget_destroy(widget);
		widget = gtk_toggle_button_new();
		this->SetContext(widget);
	}

	ToggleButton::ToggleButton(GtkToggleButton* toggle_button) : Handler<ToggleButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		if (widget != nullptr)
			gtk_widget_destroy(widget);
		this->SetToggleButton(toggle_button);
	}

	ToggleButton::ToggleButton(const char* label) : Handler<ToggleButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		widget = gtk_toggle_button_new_with_label(label);
		this->SetContext(widget);
	}

	void ToggleButton::Mode(bool draw_indicator)
	{
		gtk_toggle_button_set_mode(GTK_TOGGLE_BUTTON(widget), draw_indicator);
	}

	bool ToggleButton::Mode()
	{
		return gtk_toggle_button_get_mode(GTK_TOGGLE_BUTTON(widget));
	}

	void ToggleButton::Toggled()
	{
		gtk_toggle_button_toggled(GTK_TOGGLE_BUTTON(widget));
	}

	void ToggleButton::Active(bool active)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(widget), active);
	}

	bool ToggleButton::Active()
	{
		return gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget));
	}

	void ToggleButton::Inconsistant(bool inconsistant)
	{
		gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(widget), inconsistant);
	}

	bool ToggleButton::Inconsistant()
	{
		return gtk_toggle_button_get_inconsistent(GTK_TOGGLE_BUTTON(widget));
	}

	void ToggleButton::SetToggleButton(GtkToggleButton* togglebutton)
	{
		this->widget = GTK_WIDGET(togglebutton);
		this->SetContext(widget);
	}

	long unsigned int ToggleButton::Toggled(void(*func)())
	{
		return this->Handler<ToggleButton>::SignalHandler(Signals::TOGGLED, func);
	}

	long unsigned int ToggleButton::Toggled(void(*func)(ToggleButton*))
	{
		return this->Handler<ToggleButton>::SignalHandler(Signals::TOGGLED, func);
	}

	bool ToggleButton::IsToggleButton()
	{
		return GTK_IS_TOGGLE_BUTTON(widget);
	}
}