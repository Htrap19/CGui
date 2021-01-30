#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Orientable.hh"

namespace CGui
{
	class Paned : public virtual Widget, public virtual Container<Paned>, public virtual Orientable
	{
	public:
		Paned(CGui::Orientation orientation);
		Paned(GtkPaned* paned);
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
		bool IsPaned();
	};
}