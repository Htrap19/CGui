#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Actionbar : public virtual Widget, public virtual Container<Actionbar>
	{
	public:
		Actionbar();
		Actionbar(GtkActionBar* actionbar);
		void Add(PackType type, Widget& child);
		void AddStart(Widget& child);
		void AddEnd(Widget& child);
		void CenterWidget(Widget& child);
		Widget CenterWidget();
		bool IsActionbar();
	};
}