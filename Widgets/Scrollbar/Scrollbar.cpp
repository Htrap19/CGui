#include "./Scrollbar.hh"

namespace CGui
{
	Scrollbar::Scrollbar(CGui::Orientation orientation, CGui::Adjustment adjustment)
	{
		widget = gtk_scrollbar_new((GtkOrientation)orientation, adjustment.GetAdjustment());
		this->SetRange(GTK_RANGE(widget));
	}

	Scrollbar::Scrollbar(GtkScrollbar* scrollbar)
	{
		this->widget = GTK_WIDGET(scrollbar);
		this->SetContext(widget);
		this->SetRange(GTK_RANGE(widget));
	}
	bool Scrollbar::IsScrollbar()
	{
		return GTK_IS_SCROLLBAR(widget);
	}
}