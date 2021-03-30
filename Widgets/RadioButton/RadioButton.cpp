#include "./RadioButton.hh"
#include "../../Custom/VectorsUtilities/VectorUtilities.hh"

namespace CGui
{
	RadioButton::RadioButton() : Handler<RadioButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this), Handler<ToggleButton>::Handler(this), Handler<CheckButton>::Handler(this)
	{
		gtk_widget_destroy(m_Widget);
		m_Widget = gtk_radio_button_new(NULL);
		this->SetContext(m_Widget);
	}

	RadioButton::RadioButton(GtkRadioButton* radiobutton) : Handler<RadioButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this), Handler<ToggleButton>::Handler(this), Handler<CheckButton>::Handler(this)
	{
		gtk_widget_destroy(m_Widget);
		this->m_Widget = GTK_WIDGET(radiobutton);
		this->SetContext(m_Widget);
	}

	RadioButton::RadioButton(Vector<RadioButton>& group) : Handler<RadioButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this), Handler<ToggleButton>::Handler(this), Handler<CheckButton>::Handler(this)
	{
		GSList g;

		for (unsigned int i = 0; i < group.Size(); i++)
		{
			g.data = GTK_RADIO_BUTTON(group[i].GetWidget());
			g = *g.next;
		}

		m_Widget = gtk_radio_button_new(&g);
		this->SetContext(m_Widget);

		g_slist_free(&g);
	}

	RadioButton::RadioButton(RadioButton& radiobutton) : Handler<RadioButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this), Handler<ToggleButton>::Handler(this), Handler<CheckButton>::Handler(this)
	{
		m_Widget = gtk_radio_button_new_from_widget(GTK_RADIO_BUTTON(radiobutton.GetWidget()));
		this->SetContext(m_Widget);
	}

	RadioButton::RadioButton(Vector<RadioButton>& group, const char* label, bool mnemonic) : Handler<RadioButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this), Handler<ToggleButton>::Handler(this), Handler<CheckButton>::Handler(this)
	{
		GSList g;

		for (unsigned int i = 0; i < group.Size(); i++)
		{
			g.data = GTK_RADIO_BUTTON(group[i].GetWidget());
			g = *g.next;
		}

		if (mnemonic)
			m_Widget = gtk_radio_button_new_with_mnemonic(&g, label);
		else
			m_Widget = gtk_radio_button_new_with_label(&g, label);
		this->SetContext(m_Widget);

		g_slist_free(&g);
	}

	RadioButton::RadioButton(const char* label, bool mnemonic) : Handler<RadioButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this), Handler<ToggleButton>::Handler(this), Handler<CheckButton>::Handler(this)
	{
		if (mnemonic)
			m_Widget = gtk_radio_button_new_with_mnemonic(NULL, label);
		else
			m_Widget = gtk_radio_button_new_with_label(NULL, label);
		this->SetContext(m_Widget);
	}

	RadioButton::RadioButton(RadioButton& radiobutton, const char* label, bool mnemonic) : Handler<RadioButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this), Handler<ToggleButton>::Handler(this), Handler<CheckButton>::Handler(this)
	{
		if (mnemonic)
			m_Widget = gtk_radio_button_new_with_mnemonic_from_widget(GTK_RADIO_BUTTON(radiobutton.GetWidget()), label);
		else
			m_Widget = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radiobutton.GetWidget()), label);
		this->SetContext(m_Widget);
	}

	RadioButton::RadioButton(RadioButton&& radiobutton) : Handler<RadioButton>::Handler(this), Handler<Button>::Handler(this), Button::Container(this), Handler<ToggleButton>::Handler(this), Handler<CheckButton>::Handler(this)
	{
		m_Widget = radiobutton.m_Widget;
		radiobutton.m_Widget = nullptr;
	}

	RadioButton::~RadioButton()
	{
		/*group.ForEach([](RadioButton* data)
			{
				delete data;
			});
		group.DeleteAll();*/
	}

	void RadioButton::Group(Vector<RadioButton>& group)
	{
		GSList g;

		for (unsigned int i = 0; i < group.Size(); i++)
		{
			g.data = GTK_RADIO_BUTTON(group[i].GetWidget());
			g = *g.next;
		}

		gtk_radio_button_set_group(GTK_RADIO_BUTTON(m_Widget), &g);

		g_slist_free(&g);
	}

	Vector<RadioButton> RadioButton::Group()
	{
		GSList* g = gtk_radio_button_get_group(GTK_RADIO_BUTTON(m_Widget));
		Vector<RadioButton> group(std::move(WidgetVectorToRadioButton(std::move(GSListToWidgetVector(g)))));
		g_slist_free(g);
		return std::move(group);
	}

	void RadioButton::JoinGroup(RadioButton& radiobutton)
	{
		gtk_radio_button_join_group(GTK_RADIO_BUTTON(m_Widget), GTK_RADIO_BUTTON(radiobutton.GetWidget()));
	}

	long unsigned int RadioButton::Toggled(void(*func)())
	{
		return this->Handler<CheckButton>::SignalHandler(Signals::TOGGLED, func);
	}

	long unsigned int RadioButton::Toggled(void(*func)(RadioButton*))
	{
		return this->Handler<RadioButton>::SignalHandler(Signals::TOGGLED, func);
	}

	bool RadioButton::IsRadioButton()
	{
		return GTK_IS_RADIO_BUTTON(m_Widget);
	}

}