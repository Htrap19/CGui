#include "./Orientable.hh"

namespace CGui
{

	Orientable::Orientable(Widget* w) : m_CGuiWidget(w)
	{
	}

	CGui::Orientation Orientable::Orientation()
	{
		return (CGui::Orientation)gtk_orientable_get_orientation(GTK_ORIENTABLE(m_CGuiWidget->GetWidget()));
	}

	void Orientable::Orientation(CGui::Orientation orientation)
	{
		gtk_orientable_set_orientation(GTK_ORIENTABLE(m_CGuiWidget->GetWidget()), (GtkOrientation)orientation);
	}

	bool Orientable::IsOrientable()
	{
		return GTK_IS_ORIENTABLE(m_CGuiWidget->GetWidget());
	}

}