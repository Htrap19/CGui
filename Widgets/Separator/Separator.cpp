#include "./Separator.hh"

namespace CGui
{
	Separator::Separator(CGui::Orientation orientation) : Orientable(this)
	{
		widget = gtk_separator_new((GtkOrientation)orientation);
		this->SetContext(widget);
	}

	Separator::Separator(GtkSeparator* separator) : Orientable(this)
	{
		widget = GTK_WIDGET(separator);
		this->SetContext(widget);
	}

	bool Separator::IsSeparator()
	{
		return GTK_IS_SEPARATOR(widget);
	}
}