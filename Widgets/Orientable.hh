#pragma once

#include <gtk/gtk.h>
#include "../Converter/Convert.hh"
#include "./Widget.hh"

namespace CGui
{
	class Orientable
	{
	public:
		Orientable(Widget *w);
		virtual void Orientation(CGui::Orientation orientation);
		virtual CGui::Orientation Orientation();

		bool IsOrientable();

	private:
		Widget* m_CGuiWidget;
	};
}