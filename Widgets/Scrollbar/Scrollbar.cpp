#include "./Scrollbar.hh"

namespace CGui
{
	Scrollbar::Scrollbar(CGui::Orientation orientation, CGui::Adjustment adjustment) : Range::Orientable(this)
	{
		m_Widget = gtk_scrollbar_new((GtkOrientation)orientation, adjustment.GetAdjustment());
		this->SetContext(m_Widget);
	}

	Scrollbar::Scrollbar(GtkScrollbar* scrollbar) : Range::Orientable(this)
	{
		this->m_Widget = GTK_WIDGET(scrollbar);
		this->SetContext(m_Widget);
	}

	bool Scrollbar::IsScrollbar()
	{
		return GTK_IS_SCROLLBAR(m_Widget);
	}
}