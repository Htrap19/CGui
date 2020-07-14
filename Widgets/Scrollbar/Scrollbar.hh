#pragma once

#include "../Range/Range.hh"
#include "../../Misc/Adjustment/Adjustment.hh"

namespace CGui
{
	class Scrollbar : public Range
	{
	public:
		Scrollbar(CGui::Orientation orientation, CGui::Adjustment adjustment);
		Scrollbar(GtkScrollbar* scrollbar);
	};
}