#include "./Separator.hh"

namespace CGui
{
	Separator::Separator(CGui::Orientation orientation) : Orientable(this)
	{
		m_Widget = gtk_separator_new((GtkOrientation)orientation);
		this->SetContext(m_Widget);
	}

	Separator::Separator(GtkSeparator* separator) : Orientable(this)
	{
		m_Widget = GTK_WIDGET(separator);
		this->SetContext(m_Widget);
	}

	bool Separator::IsSeparator()
	{
		return GTK_IS_SEPARATOR(m_Widget);
	}
}