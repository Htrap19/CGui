#include "./CheckButton.hh"

namespace CGui
{
	CheckButton::CheckButton() : Handler<CheckButton>::Handler(this), Handler<ToggleButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = gtk_check_button_new();
		this->SetContext(m_Widget);
	}

	CheckButton::CheckButton(const char* text, bool mnemonic) : Handler<CheckButton>::Handler(this), Handler<ToggleButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		if (mnemonic)
			m_Widget = gtk_check_button_new_with_mnemonic(text);
		else
			m_Widget = gtk_check_button_new_with_label(text);
		this->SetContext(m_Widget);
	}

	CheckButton::CheckButton(GtkCheckButton* checkbutton) : Handler<CheckButton>::Handler(this), Handler<ToggleButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		this->SetCheckButton(GTK_CHECK_BUTTON(m_Widget));
	}

	long unsigned int CheckButton::Toggled(void(*func)())
	{
		return this->Handler<CheckButton>::SignalHandler(Signals::TOGGLED, func);
	}

	long unsigned int CheckButton::Toggled(void(*func)(CheckButton*))
	{
		return this->Handler<CheckButton>::SignalHandler(Signals::TOGGLED, func);
	}

	bool CheckButton::IsCheckButton()
	{
		return GTK_IS_CHECK_BUTTON(m_Widget);
	}

	void CheckButton::SetCheckButton(GtkCheckButton* checkbutton)
	{
		this->m_Widget = GTK_WIDGET(checkbutton);
		this->SetContext(m_Widget);
	}
};
