#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Overlay : public virtual Widget, public virtual Container<Overlay>
	{
	public:
		Overlay();
		Overlay(GtkOverlay* overlay);
		void AddOverlay(Widget& child);
		void ReorderOverlay(Widget& child, int position);
		void OverlayPassThrough(Widget& child, bool pass);
		bool OverlayPassThrough(Widget& child);
		bool IsOverlay();
	};
}