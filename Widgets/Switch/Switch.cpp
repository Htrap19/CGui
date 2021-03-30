#include "./Switch.hh"

namespace CGui
{
	Switch::Switch()
	{
		m_Widget = gtk_switch_new();
		this->SetContext(m_Widget);
	}

	Switch::Switch(GtkSwitch* Switch)
	{
		m_Widget = GTK_WIDGET(Switch);
		this->SetContext(m_Widget);
	}

	void Switch::Active(bool active)
	{
		gtk_switch_set_active(GTK_SWITCH(m_Widget), active);
	}

	bool Switch::Active()
	{
		return gtk_switch_get_active(GTK_SWITCH(m_Widget));
	}

	void Switch::SwitchState(bool state)
	{
		gtk_switch_set_state(GTK_SWITCH(m_Widget), state);
	}

	bool Switch::SwitchState()
	{
		return gtk_switch_get_state(GTK_SWITCH(m_Widget));
	}

	bool Switch::IsSwitch()
	{
		return GTK_IS_SWITCH(m_Widget);
	}

}