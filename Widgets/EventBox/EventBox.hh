#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Handler.hh"

namespace CGui
{
	class EventBox : public Widget, public Container<EventBox>, public Handler<EventBox>
	{
	public:
		EventBox();
		EventBox(Widget& w);
		void VisibleWindow(bool visible);
		bool VisibleWindow();
		void AboveChild(bool above);
		bool AboveChild();
	};
}