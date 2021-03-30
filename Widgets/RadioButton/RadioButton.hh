#pragma once

#include "../CheckButton/CheckButton.hh"
#include "../../Custom/List/List.hh"

namespace CGui
{
	class RadioButton : public virtual CheckButton, public virtual Handler<RadioButton>
	{
	public:
		RadioButton();
		RadioButton(RadioButton&& other); // Move constructor
		RadioButton(GtkRadioButton* radiobutton);
		RadioButton(Vector<RadioButton>& group);
		RadioButton(RadioButton& radiobutton); // If copy constructor is called if will create a new Radiobutton with 'radiobutton' added in group
		RadioButton(Vector<RadioButton>& group, const char* label, bool mnemonic = false);
		RadioButton(const char* label, bool mnemonic = false);
		RadioButton(RadioButton& radiobutton, const char* label, bool mnemonic = false);
		~RadioButton();
		void Group(Vector<RadioButton>& group);
		Vector<RadioButton> Group();
		void JoinGroup(RadioButton& radiobutton);
		long unsigned int Toggled(void(*func)());
		long unsigned int Toggled(void(*func)(RadioButton*));
		template <typename ... Args> long unsigned int Toggled(void(*func)(RadioButton*, Args* ...), Args& ... args);
		template <typename ... Args> long unsigned int Toggled(void(*func)(Args* ...), Args& ... args);
		bool IsRadioButton();
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