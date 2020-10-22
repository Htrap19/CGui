#pragma once

#include <gtk/gtk.h>
#include "../../Converter/Convert.hh"
#include "../../Widgets/Widget.hh"
#include "../../Custom/List/List.hh"

namespace CGui
{
	class SizeGroup
	{
	public:
		SizeGroup(SizeGroupMode mode);
		SizeGroup(GtkSizeGroup* group);
		void Mode(SizeGroupMode mode);
		SizeGroupMode Mode();
		void AddWidget(Widget& widget);
		void RemoveWidget(Widget& widget);
		Single::List<Widget> Widgets();
		bool IsSizeGroup();

	protected:
		GtkSizeGroup* m_sizegroup;
	};
}