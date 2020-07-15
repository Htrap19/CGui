#pragma once

#include "./Widget.hh"
#include "../Misc/Adjustment/Adjustment.hh"

namespace CGui
{
	class Scrollable
	{
	public:
		Scrollable(Widget& w)
		{
			scrollable = GTK_SCROLLABLE(w.GetWidget());
		}

		void HAdjustment(Adjustment adjustment)
		{
			gtk_scrollable_set_hadjustment(scrollable, adjustment.GetAdjustment());
		}

		Adjustment HAdjustment()
		{
			return Adjustment(gtk_scrollable_get_hadjustment(scrollable));
		}

		void VAdjustment(Adjustment adjustment)
		{
			gtk_scrollable_set_vadjustment(scrollable, adjustment.GetAdjustment());
		}

		Adjustment VAdjustment()
		{
			return Adjustment(gtk_scrollable_get_vadjustment(scrollable));
		}

		void HScrollPolicy(ScrollablePolicy policy)
		{
			gtk_scrollable_set_hscroll_policy(scrollable, (GtkScrollablePolicy)policy);
		}

		ScrollablePolicy HScrollPolicy()
		{
			return (ScrollablePolicy)gtk_scrollable_get_hscroll_policy(scrollable);
		}

		void VScrollPolicy(ScrollablePolicy policy)
		{
			gtk_scrollable_set_vscroll_policy(scrollable, (GtkScrollablePolicy)policy);
		}

		ScrollablePolicy VScrollPolicy()
		{
			return (ScrollablePolicy)gtk_scrollable_get_vscroll_policy(scrollable);
		}

		CGui::Border Border()
		{
			GtkBorder border;
			gtk_scrollable_get_border(scrollable, &border);

			return { border.left, border.right, border.top, border.bottom };
		}

	protected:
		Scrollable()
		{

		}

		void SetScrollable(GtkScrollable* scrollable)
		{
			this->scrollable = scrollable;
		}

		GtkScrollable* scrollable;
	};
}