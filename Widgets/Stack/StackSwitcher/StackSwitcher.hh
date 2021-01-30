#pragma once

#include "../../Box/Box.hh"
#include "../Stack/Stack.hh"

namespace CGui
{
	class StackSwitcher : public virtual Box
	{
	public:
		StackSwitcher();
		StackSwitcher(GtkStackSwitcher* stack_switcher);
		void Stack(CGui::Stack& stack);
		CGui::Stack Stack();
		bool IsStackSwitcher();
	};
}