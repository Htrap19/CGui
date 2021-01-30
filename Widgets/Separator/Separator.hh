#pragma once

#include "../Widget.hh"
#include "../Orientable.hh"

namespace CGui
{
	class Separator : public virtual Widget, public virtual Orientable
	{
	public:
		Separator(CGui::Orientation orientation);
		Separator(GtkSeparator* separator);
		bool IsSeparator();
	};
}