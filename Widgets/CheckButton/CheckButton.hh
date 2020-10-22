#pragma once

#include "../ToggleButton/ToggleButton.hh"
#include "../Handler.hh"

namespace CGui
{
	class CheckButton : public ToggleButton, public Handler<CheckButton>
	{
	public:
		CheckButton();
		CheckButton(const char* text);
		long unsigned int Toggled(void(*func)());
		long unsigned int Toggled(void(*func)(CheckButton*));
		template <typename ... Args> long unsigned int Toggled(void(*func)(CheckButton*, Args* ...), Args& ... args);
		template <typename ... Args> long unsigned int Toggled(void(*func)(Args* ...), Args& ... args);
		bool IsCheckButton();

	protected:
		void SetCheckButton(GtkCheckButton* checkbutton);
	};

	template <typename ... Args> long unsigned int CheckButton::Toggled(void(*func)(CheckButton*, Args* ...), Args& ... args)
	{
		return this->Handler<CheckButton>::SignalHandler(Signals::TOGGLED, func, args...);
	}

	template <typename ... Args> long unsigned int CheckButton::Toggled(void(*func)(Args* ...), Args& ... args)
	{
		return this->Handler<CheckButton>::SignalHandler(Signals::TOGGLED, func, args...);
	}
};