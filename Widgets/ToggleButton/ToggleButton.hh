#pragma once

#include "../Button/Button.hh"
#include "../Handler.hh"

namespace CGui
{
	class ToggleButton : public Button, public Handler<ToggleButton>
	{
	public:
		ToggleButton();
		ToggleButton(const char* label);
		void Mode(bool draw_indicator);
		bool Mode();
		void Toggled();
		void Active(bool active);
		bool Active();
		void Inconsistant(bool inconsistant);
		bool Inconsistant();
		long unsigned int Toggled(void(*func)());
		long unsigned int Toggled(void(*func)(ToggleButton*));
		template <typename ... Args> long unsigned int Toggled(void(*func)(ToggleButton*, Args* ...), Args& ... args);
		template <typename ... Args> long unsigned int Toggled(void(*func)(Args* ...), Args& ... args);

	protected:
		void SetToggleButton(GtkToggleButton* togglebutton);
	};

	template <typename ... Args> long unsigned int ToggleButton::Toggled(void(*func)(ToggleButton*, Args* ...), Args& ... args)
	{
		return this->Handler<ToggleButton>::SignalHandler(Signals::TOGGLED, func, args...);
	}

	template <typename ... Args> long unsigned int ToggleButton::Toggled(void(*func)(Args* ...), Args& ... args)
	{
		return this->Handler<ToggleButton>::SignalHandler(Signals::TOGGLED, func, args...);
	}
}