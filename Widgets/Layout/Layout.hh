#pragma once

#include "../Widget.hh"
#include "../Scrollable.hh"
#include "../../Misc/Adjustment/Adjustment.hh"

namespace CGui
{
	class Layout : public Widget, public Scrollable
	{
	public:
		Layout();
		Layout(Adjustment hadjustment, Adjustment vadjustment);
		void Put(Widget& child, int x, int y);
		void Move(Widget& child, int x, int y);
		void Size(unsigned int width, unsigned int height);
		Requisition Size();
	};
}