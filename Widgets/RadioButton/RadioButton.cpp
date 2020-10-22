#include "./RadioButton.hh"

namespace CGui
{
	RadioButton::RadioButton() : Handler<RadioButton>::Handler(this)
	{
		widget = gtk_radio_button_new(NULL);
		this->SetCheckButton(GTK_CHECK_BUTTON(widget));
	}

	RadioButton::RadioButton(GtkRadioButton* radiobutton) : Handler<RadioButton>::Handler(this)
	{
		this->widget = GTK_WIDGET(radiobutton);
		this->SetCheckButton(GTK_CHECK_BUTTON(widget));
	}

	RadioButton::RadioButton(Single::List<RadioButton>& group) : Handler<RadioButton>::Handler(this)
	{
		GSList* g = NULL;

		for (unsigned int i = 0; i < group.Size(); i++)
		{
			g->data = GTK_RADIO_BUTTON(group[i].GetWidget());
			g = g->next;
		}

		widget = gtk_radio_button_new(g);
		this->SetCheckButton(GTK_CHECK_BUTTON(widget));

		g_slist_free(g);
	}

	RadioButton::RadioButton(RadioButton& radiobutton) : Handler<RadioButton>::Handler(this)
	{
		widget = gtk_radio_button_new_from_widget(GTK_RADIO_BUTTON(radiobutton.GetWidget()));
		this->SetCheckButton(GTK_CHECK_BUTTON(widget));
	}

	RadioButton::RadioButton(Single::List<RadioButton>& group, const char* label) : Handler<RadioButton>::Handler(this)
	{
		GSList* g = NULL;

		for (unsigned int i = 0; i < group.Size(); i++)
		{
			g->data = GTK_RADIO_BUTTON(group[i].GetWidget());
			g = g->next;
		}

		widget = gtk_radio_button_new_with_label(g, label);
		this->SetCheckButton(GTK_CHECK_BUTTON(widget));

		g_slist_free(g);
	}

	RadioButton::RadioButton(const char* label) : Handler<RadioButton>::Handler(this)
	{
		widget = gtk_radio_button_new_with_label(NULL, label);
		this->SetCheckButton(GTK_CHECK_BUTTON(widget));
	}

	RadioButton::RadioButton(RadioButton& radiobutton, const char* label) : Handler<RadioButton>::Handler(this)
	{
		widget = gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(radiobutton.GetWidget()), label);
		this->SetCheckButton(GTK_CHECK_BUTTON(widget));
	}

	RadioButton::~RadioButton()
	{
		group.ForEach([](RadioButton* data)
			{
				delete data;
			});
		group.DeleteAll();
	}

	void RadioButton::Group(Single::List<RadioButton>& group)
	{
		GSList* g = NULL;

		for (unsigned int i = 0; i < group.Size(); i++)
		{
			g->data = GTK_RADIO_BUTTON(group[i].GetWidget());
			g = g->next;
		}

		gtk_radio_button_set_group(GTK_RADIO_BUTTON(widget), g);

		g_slist_free(g);
	}

	Single::List<RadioButton*> RadioButton::Group()
	{
		GSList* g = gtk_radio_button_get_group(GTK_RADIO_BUTTON(widget));

		group.ForEach([](RadioButton* data)
			{
				delete data;
			});
		group.DeleteAll();

		for (GSList* it = g; it != NULL; it = it->next)
		{
			group.Insert(new RadioButton(GTK_RADIO_BUTTON(it->data)));
		}

		g_slist_free(g);

		return group;
	}

	void RadioButton::JoinGroup(RadioButton& radiobutton)
	{
		gtk_radio_button_join_group(GTK_RADIO_BUTTON(widget), GTK_RADIO_BUTTON(radiobutton.GetWidget()));
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
		return GTK_IS_RADIO_BUTTON(widget);
	}

}