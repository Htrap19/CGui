#pragma once

#include "./Widget.hh"
#include "../Misc/Adjustment/Adjustment.hh"

namespace CGui
{
	class Scrollable
	{
	public:
		Scrollable(Widget& w);
		virtual void HAdjustment(Adjustment adjustment);
		virtual Adjustment HAdjustment();
		virtual void VAdjustment(Adjustment adjustment);
		virtual Adjustment VAdjustment();
		virtual void HScrollPolicy(ScrollablePolicy policy);
		virtual ScrollablePolicy HScrollPolicy();
		virtual void VScrollPolicy(ScrollablePolicy policy);
		virtual ScrollablePolicy VScrollPolicy();
		virtual CGui::Border Border();

		bool IsScrollable();

	protected:
		Scrollable();
		void SetScrollable(GtkScrollable* scrollable);

		GtkScrollable* m_Scrollable;
	};
}