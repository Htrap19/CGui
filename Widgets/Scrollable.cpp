#include "./Scrollable.hh"

namespace CGui
{

	Scrollable::Scrollable() : m_Scrollable(nullptr)
	{
	}

	Scrollable::Scrollable(Widget& w)
	{
		m_Scrollable = GTK_SCROLLABLE(w.GetWidget());
	}

	CGui::Adjustment Scrollable::HAdjustment()
	{
		return Adjustment(gtk_scrollable_get_hadjustment(m_Scrollable));
	}

	void Scrollable::HAdjustment(Adjustment adjustment)
	{
		gtk_scrollable_set_hadjustment(m_Scrollable, adjustment.GetAdjustment());
	}

	CGui::Adjustment Scrollable::VAdjustment()
	{
		return Adjustment(gtk_scrollable_get_vadjustment(m_Scrollable));
	}

	void Scrollable::VAdjustment(Adjustment adjustment)
	{
		gtk_scrollable_set_vadjustment(m_Scrollable, adjustment.GetAdjustment());
	}

	CGui::ScrollablePolicy Scrollable::HScrollPolicy()
	{
		return (ScrollablePolicy)gtk_scrollable_get_hscroll_policy(m_Scrollable);
	}

	void Scrollable::HScrollPolicy(ScrollablePolicy policy)
	{
		gtk_scrollable_set_hscroll_policy(m_Scrollable, (GtkScrollablePolicy)policy);
	}

	CGui::ScrollablePolicy Scrollable::VScrollPolicy()
	{
		return (ScrollablePolicy)gtk_scrollable_get_vscroll_policy(m_Scrollable);
	}

	void Scrollable::VScrollPolicy(ScrollablePolicy policy)
	{
		gtk_scrollable_set_vscroll_policy(m_Scrollable, (GtkScrollablePolicy)policy);
	}

	CGui::Border Scrollable::Border()
	{
		GtkBorder border;
		gtk_scrollable_get_border(m_Scrollable, &border);

		return { border.left, border.right, border.top, border.bottom };
	}

	bool Scrollable::IsScrollable()
	{
		return GTK_IS_SCROLLABLE(m_Scrollable);
	}

	void Scrollable::SetScrollable(GtkScrollable* scrollable)
	{
		this->m_Scrollable = scrollable;
	}

}