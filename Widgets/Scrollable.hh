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

		virtual void HAdjustment(Adjustment adjustment)
		{
			gtk_scrollable_set_hadjustment(scrollable, adjustment.GetAdjustment());
		}

		virtual Adjustment HAdjustment()
		{
			return Adjustment(gtk_scrollable_get_hadjustment(scrollable));
		}

		virtual void VAdjustment(Adjustment adjustment)
		{
			gtk_scrollable_set_vadjustment(scrollable, adjustment.GetAdjustment());
		}

		virtual Adjustment VAdjustment()
		{
			return Adjustment(gtk_scrollable_get_vadjustment(scrollable));
		}

		virtual void HScrollPolicy(ScrollablePolicy policy)
		{
			gtk_scrollable_set_hscroll_policy(scrollable, (GtkScrollablePolicy)policy);
		}

		virtual ScrollablePolicy HScrollPolicy()
		{
			return (ScrollablePolicy)gtk_scrollable_get_hscroll_policy(scrollable);
		}

		virtual void VScrollPolicy(ScrollablePolicy policy)
		{
			gtk_scrollable_set_vscroll_policy(scrollable, (GtkScrollablePolicy)policy);
		}

		virtual ScrollablePolicy VScrollPolicy()
		{
			return (ScrollablePolicy)gtk_scrollable_get_vscroll_policy(scrollable);
		}

		virtual CGui::Border Border()
		{
			GtkBorder border;
			gtk_scrollable_get_border(scrollable, &border);

			return { border.left, border.right, border.top, border.bottom };
		}

		bool IsScrollable()
		{
			return GTK_IS_SCROLLABLE(scrollable);
		}

	protected:
		Scrollable() : scrollable{NULL}
		{

		}

		void SetScrollable(GtkScrollable* scrollable)
		{
			this->scrollable = scrollable;
		}

		GtkScrollable* scrollable;
	};
}