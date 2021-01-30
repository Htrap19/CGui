#include "./Switch.hh"

namespace CGui
{
	Switch::Switch()
	{
		widget = gtk_switch_new();
		this->SetContext(widget);
	}

	Switch::Switch(GtkSwitch* Switch)
	{
		widget = GTK_WIDGET(Switch);
		this->SetContext(widget);
	}

	void Switch::Active(bool active)
	{
		gtk_switch_set_active(GTK_SWITCH(widget), active);
	}

	bool Switch::Active()
	{
		return gtk_switch_get_active(GTK_SWITCH(widget));
	}

	void Switch::SwitchState(bool state)
	{
		gtk_switch_set_state(GTK_SWITCH(widget), state);
	}

	bool Switch::SwitchState()
	{
		return gtk_switch_get_state(GTK_SWITCH(widget));
	}

	bool Switch::IsSwitch()
	{
		return GTK_IS_SWITCH(widget);
	}

}