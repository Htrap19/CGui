#pragma once

#include "../../Widget.hh"
#include "../Stack/Stack.hh"

namespace CGui
{
	class StackSidebar : public Widget
	{
	public:
		StackSidebar();
		void Stack(CGui::Stack& stack);
		CGui::Stack Stack();
		bool IsStackSidebar();
	};
}