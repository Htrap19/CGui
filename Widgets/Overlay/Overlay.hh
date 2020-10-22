#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Overlay : public Widget, public Container<Overlay>
	{
	public:
		Overlay();
		void AddOverlay(Widget& child);
		void ReorderOverlay(Widget& child, int position);
		void OverlayPassThrough(Widget& child, bool pass);
		bool OverlayPassThrough(Widget& child);
		bool IsOverlay();
	};
}