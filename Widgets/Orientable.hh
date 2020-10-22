#pragma once

#include <gtk/gtk.h>
#include "../Converter/Convert.hh"
#include "./Widget.hh"

namespace CGui
{
	class Orientable
	{
	public:
		Orientable(Widget *w)
		{
			this->m_widget = w;
		}

		virtual void Orientation(CGui::Orientation orientation)
		{
			gtk_orientable_set_orientation(GTK_ORIENTABLE(m_widget->GetWidget()), (GtkOrientation)orientation);
		}

		virtual CGui::Orientation Orientation()
		{
			return (CGui::Orientation)gtk_orientable_get_orientation(GTK_ORIENTABLE(m_widget->GetWidget()));
		}

		bool IsOrientable()
		{
			return GTK_IS_ORIENTABLE(m_widget->GetWidget());
		}

	private:
		Widget* m_widget;
	};
}