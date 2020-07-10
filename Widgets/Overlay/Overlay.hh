#pragma once

#include "../Widget.hh"

namespace CGui
{
	class Overlay : public Widget
	{
	public:
		Overlay();
		void AddOverlay(Widget& child);
		void ReorderOverlay(Widget& child, int position);
		void OverlayPassThrough(Widget& child, bool pass);
		bool OverlayPassThrough(Widget& child);
	};
}