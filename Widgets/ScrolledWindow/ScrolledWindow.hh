#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../../Misc/Adjustment/Adjustment.hh"

namespace CGui
{
	class ScrolledWindow : public virtual Widget, public virtual Container<ScrolledWindow>
	{
	public:
		ScrolledWindow(GtkScrolledWindow* scrolled_window);
		ScrolledWindow(Policy hpolicy, Policy vpolicy);
		ScrolledWindow(Adjustment hadjustment, Adjustment vadjustment);
		ScrolledWindow(Adjustment hadjustment, Policy hpolicy, Adjustment vadjustment, Policy vpolicy);
		void HAdjustment(Adjustment hadjustment);
		Adjustment HAdjustment();
		void VAdjustment(Adjustment vadjustment);
		Adjustment VAdjustment();
		Widget VScrollbar();
		Widget HScrollbar();
		void Policy(CGui::Policy hpolicy, CGui::Policy vpolicy);
		PolicyInfo Policy();
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
		bool IsScrolledWindow();
	};
};
