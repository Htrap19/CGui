#pragma once

#include "../../Box/Box.hh"
#include "../Stack/Stack.hh"

namespace CGui
{
	class StackSwitcher : public Box
	{
	public:
		StackSwitcher();
		void SwitcherStack(Stack& stack);
		Stack SwitcherStack();
	};
}