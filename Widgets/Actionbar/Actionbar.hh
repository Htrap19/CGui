#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Actionbar : public Widget, public Container<Actionbar>
	{
	public:
		Actionbar();
		void Add(PackType type, Widget& child);
		void AddStart(Widget& child);
		void AddEnd(Widget& child);
		void CenterWidget(Widget& child);
		Widget CenterWidget();
	};
}