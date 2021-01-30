#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Handler.hh"

namespace CGui
{
	class EventBox : public virtual Widget, public virtual Container<EventBox>, public virtual Handler<EventBox>
	{
	public:
		EventBox();
		EventBox(Widget& w);
		EventBox(GtkEventBox* event_box);
		void VisibleWindow(bool visible);
		bool VisibleWindow();
		void AboveChild(bool above);
		bool AboveChild();
		bool IsEventBox();
	};
}