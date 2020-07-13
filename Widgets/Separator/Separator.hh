#pragma once

#include "../Widget.hh"
#include "../Orientable.hh"

namespace CGui
{
	class Separator : public Widget, public Orientable
	{
	public:
		Separator(Orientation orientation);
	};
}