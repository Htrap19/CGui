#pragma once

#include "../../Widget.hh"
#include "../Stack/Stack.hh"

namespace CGui
{
	class StackSidebar : public Widget
	{
	public:
		StackSidebar();
		void SidebarStack(Stack& stack);
		Stack SidebarStack();
	};
}