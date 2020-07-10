#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Orientable.hh"

namespace CGui
{
	class Paned : public Widget, public Container<Paned>, public Orientable
	{
	public:
		Paned(Orientation orientation);
		void Add1(Widget& child);
		void Add2(Widget& child);
		void Pack1(Widget& child, bool resize, bool shrink);
		void Pack2(Widget& child, bool resize, bool shrink);
		Widget Child1();
		Widget Child2();
		void Position(int position);
		int Position();
		void WideHandle(bool handle);
		bool WideHandle();
	};
}