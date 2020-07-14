#pragma once

#include "../Widget.hh"

namespace CGui
{
	class Switch : public Widget
	{
	public:
		Switch();
		void Active(bool active);
		bool Active();
		void SwitchState(bool state);
		bool SwitchState();
	};
}