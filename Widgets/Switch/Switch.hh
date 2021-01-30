#pragma once

#include "../Widget.hh"

namespace CGui
{
	class Switch : public virtual Widget
	{
	public:
		Switch();
		Switch(GtkSwitch* Switch);
		void Active(bool active);
		bool Active();
		void SwitchState(bool state);
		bool SwitchState();
		bool IsSwitch();
	};
}