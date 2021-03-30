#pragma once

#include <gtk/gtk.h>
#include "./Widget.hh"
#include "../Misc/SizeGroup/SizeGroup.hh"

namespace CGui
{
	class ToolShell
	{
	public:
		ToolShell(Widget& w);
		virtual CGui::EllipsizeMode EllipsizeMode();
		virtual CGui::IconSize IconSize();
		virtual CGui::Orientation Orientation();
		virtual CGui::ReliefStyle ReliefStyle();
		virtual CGui::ToolbarStyle Style();
		virtual float TextAlignment();
		virtual CGui::Orientation TextOrientation();
		virtual void RebuildMenu();
		virtual SizeGroup TextSizeGroup();

		bool IsToolShell();

	protected:
		GtkToolShell* m_ToolShell;
		ToolShell();
		void SetToolShell(GtkToolShell* toolshell);
	};
}