#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Popover : public virtual Widget, public virtual Container<Popover>
	{
	public:
		Popover();
		Popover(GtkPopover* popover);
		Popover(Widget& relative_to);
		void PopUp();
		void PopDown();
		void RelativeTo(Widget& relative_to);
		Widget RelativeTo();
		void PointingTo(Rectangle rect);
		PointingToData PointingTo();
		void Position(PositionType type);
		PositionType Position();
		void ConstrainTo(PopoverConstraint constrain_to);
		PopoverConstraint ConstrainTo();
		void Modal(bool modal);
		bool Modal();
		void DefaultWidget(Widget& default_widget);
		Widget DefaultWidget();

		bool IsPopover();
	};
}