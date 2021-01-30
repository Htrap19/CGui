#pragma once

#include "../../Widget.hh"
#include "../Stack/Stack.hh"

namespace CGui
{
	class StackSidebar : public virtual Widget
	{
	public:
		StackSidebar();
		StackSidebar(GtkStackSidebar* stack_sidebar);
		void Stack(CGui::Stack& stack);
		CGui::Stack Stack();
		bool IsStackSidebar();
	};
}