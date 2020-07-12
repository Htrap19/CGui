#pragma once

#include "../CheckButton/CheckButton.hh"
#include "../../Custom/List/List.hh"

namespace CGui
{
	class RadioButton : public CheckButton, public Handler<RadioButton>
	{
	public:
		RadioButton();
		RadioButton(GtkRadioButton* radiobutton);
		RadioButton(Single::List<RadioButton>& group);
		RadioButton(RadioButton& radiobutton);
		RadioButton(Single::List<RadioButton>& group, const char* label);
		RadioButton(const char* label);
		RadioButton(RadioButton& radiobutton, const char* label);
		~RadioButton();
		void Group(Single::List<RadioButton>& group);
		Single::List<RadioButton*> Group();
		void JoinGroup(RadioButton& radiobutton);
		long unsigned int Toggled(void(*func)());
		long unsigned int Toggled(void(*func)(RadioButton*));
		template <typename ... Args> long unsigned int Toggled(void(*func)(RadioButton*, Args* ...), Args& ... args);
		template <typename ... Args> long unsigned int Toggled(void(*func)(Args* ...), Args& ... args);

	protected:
		Single::List<RadioButton*> group;
	};

	template <typename ... Args> long unsigned int RadioButton::Toggled(void(*func)(RadioButton*, Args* ...), Args& ... args)
	{
		return this->Handler<RadioButton>::SignalHandler(Signals::TOGGLED, func, args...);
	}

	template <typename ... Args> long unsigned int RadioButton::Toggled(void(*func)(Args* ...), Args& ... args)
	{
		return this->Handler<RadioButton>::SignalHandler(Signals::TOGGLED, func, args...);
	}
}