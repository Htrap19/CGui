#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Headerbar : public Widget, public Container<Headerbar>
	{
	public:
		Headerbar(const char* title = "", const char* subtitle = "");
		void Add(BoxPackType type, Widget& w);
		void AddStart(Widget& w);
		void AddEnd(Widget& w);
	};
}
