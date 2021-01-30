#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Fixed : public virtual Widget, public virtual Container<Fixed>
	{
	public:
		Fixed();
		Fixed(GtkFixed* fixed);
		void Put(Widget& child, int x, int y);
		void Move(Widget& child, int x, int y);
		bool IsFixed();
	};
}