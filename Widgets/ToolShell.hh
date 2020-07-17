#pragma once

#include <gtk/gtk.h>
#include "./Widget.hh"
#include "../Misc/SizeGroup/SizeGroup.hh"

namespace CGui
{
	class ToolShell
	{
	public:
		ToolShell(Widget& w)
		{
			this->m_tool_shell = GTK_TOOL_SHELL(w.GetWidget());
		}

		virtual CGui::EllipsizeMode EllipsizeMode()
		{
			return (CGui::EllipsizeMode)gtk_tool_shell_get_ellipsize_mode(m_tool_shell);
		}

		virtual CGui::IconSize IconSize()
		{
			return (CGui::IconSize)gtk_tool_shell_get_icon_size(m_tool_shell);
		}

		virtual CGui::Orientation Orientation()
		{
			return (CGui::Orientation)gtk_tool_shell_get_orientation(m_tool_shell);
		}

		virtual CGui::ReliefStyle ReliefStyle()
		{
			return (CGui::ReliefStyle)gtk_tool_shell_get_relief_style(m_tool_shell);
		}

		virtual CGui::ToolbarStyle Style()
		{
			return (CGui::ToolbarStyle)gtk_tool_shell_get_style(m_tool_shell);
		}

		virtual float TextAlignment()
		{
			return gtk_tool_shell_get_text_alignment(m_tool_shell);
		}

		virtual CGui::Orientation TextOrientation()
		{
			return (CGui::Orientation)gtk_tool_shell_get_text_orientation(m_tool_shell);
		}

		virtual void RebuildMenu()
		{
			gtk_tool_shell_rebuild_menu(m_tool_shell);
		}

		virtual SizeGroup TextSizeGroup()
		{
			return SizeGroup(gtk_tool_shell_get_text_size_group(m_tool_shell));
		}

	protected:
		GtkToolShell* m_tool_shell;
		ToolShell()
		{
		}

		void SetToolShell(GtkToolShell* toolshell)
		{
			this->m_tool_shell = toolshell;
		}
	};
}