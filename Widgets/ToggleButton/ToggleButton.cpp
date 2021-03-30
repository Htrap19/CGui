#include "./ToggleButton.hh"

namespace CGui
{
	ToggleButton::ToggleButton() : Handler<ToggleButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = gtk_toggle_button_new();
		this->SetContext(m_Widget);
	}

	ToggleButton::ToggleButton(GtkToggleButton* toggle_button) : Handler<ToggleButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		this->SetToggleButton(toggle_button);
	}

	ToggleButton::ToggleButton(const char* label, bool mnemonic) : Handler<ToggleButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		if (mnemonic)
			m_Widget = gtk_toggle_button_new_with_mnemonic(label);
		else
			m_Widget = gtk_toggle_button_new_with_label(label);
		this->SetContext(m_Widget);
	}

	void ToggleButton::Mode(bool draw_indicator)
	{
		gtk_toggle_button_set_mode(GTK_TOGGLE_BUTTON(m_Widget), draw_indicator);
	}

	bool ToggleButton::Mode()
	{
		return gtk_toggle_button_get_mode(GTK_TOGGLE_BUTTON(m_Widget));
	}

	void ToggleButton::Toggled()
	{
		gtk_toggle_button_toggled(GTK_TOGGLE_BUTTON(m_Widget));
	}

	void ToggleButton::Active(bool active)
	{
		gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(m_Widget), active);
	}

	bool ToggleButton::Active()
	{
		return gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(m_Widget));
	}

	void ToggleButton::Inconsistant(bool inconsistant)
	{
		gtk_toggle_button_set_inconsistent(GTK_TOGGLE_BUTTON(m_Widget), inconsistant);
	}

	bool ToggleButton::Inconsistant()
	{
		return gtk_toggle_button_get_inconsistent(GTK_TOGGLE_BUTTON(m_Widget));
	}

	void ToggleButton::SetToggleButton(GtkToggleButton* togglebutton)
	{
		this->m_Widget = GTK_WIDGET(togglebutton);
		this->SetContext(m_Widget);
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
		return GTK_IS_TOGGLE_BUTTON(m_Widget);
	}
}