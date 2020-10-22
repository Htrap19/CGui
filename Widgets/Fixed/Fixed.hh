#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Fixed : public Widget, public Container<Fixed>
	{
	public:
		Fixed();
		void Put(Widget& child, int x, int y);
		void Move(Widget& child, int x, int y);
		bool IsFixed();
	};
}