#include "./Scrollbar.hh"

namespace CGui
{
	Scrollbar::Scrollbar(CGui::Orientation orientation, CGui::Adjustment adjustment) : Range::Orientable(this)
	{
		widget = gtk_scrollbar_new((GtkOrientation)orientation, adjustment.GetAdjustment());
		this->SetContext(widget);
	}

	Scrollbar::Scrollbar(GtkScrollbar* scrollbar) : Range::Orientable(this)
	{
		this->widget = GTK_WIDGET(scrollbar);
		this->SetContext(widget);
	}

	bool Scrollbar::IsScrollbar()
	{
		return GTK_IS_SCROLLBAR(widget);
	}
}