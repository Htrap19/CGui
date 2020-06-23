#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class ScrolledWindow : public Widget, public Container<ScrolledWindow>
	{
	public:
		ScrolledWindow(Policy hpolicy, Policy vpolicy);
		~ScrolledWindow();
		Widget& VScrollbar();
		Widget& HScrollbar();
		void ScrollPolicy(Policy hpolicy, Policy vpolicy);
		PolicyInfo ScrollPolicy();
		void Placement(CornerType type);
		CornerType Placement();
		void UnsetPlacement();
		void Shadow(ShadowType type);
		ShadowType Shadow();
		void KineticScrolling(bool scrolling);
		bool KineticScrolling();
		void CaptureButtonPress(bool capture_button_press);
		bool CaptureButtonPress();
		void OverlayScrolling(bool overlay_scrolling);
		bool OverlayScrolling();
		void MinContentWidth(int width);
		int MinContentWidth();
		void MinContentHeight(int height);
		int MinContentHeight();
		void MaxContentWidth(int width);
		int MaxContentWidth();
		void MaxContentHeight(int height);
		int MaxContentHeight();
		void PropagateNaturalWidth(bool propagate_width);
		bool PropagateNaturalWidth();
		void PropagateNaturalHeight(bool propagate_height);
		bool PropagateNaturalHeight();

	private:
		Widget* m_HScrollbar;
		Widget* m_VScrollbar;
	};
};
