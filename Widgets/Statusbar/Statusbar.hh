#pragma once

#include "../Box/Box.hh"
#include "../Container.hh"

namespace CGui
{
	class Statusbar : public Box, public Container<Widget>
	{
	public:
		Statusbar();
		void Add(Widget& child) override;
		void Remove(Widget& child) override;
		int ContextID(const char* context_description);
		int Push(int context_id, const char* text);
		void Pop(int context_id);
		void Remove(int context_id, int message_id);
		void RemoveAll(int context_id);
		bool IsStatusbar();
	};
}