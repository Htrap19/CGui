#include "./ToolShell.hh"

namespace CGui
{

	ToolShell::ToolShell() : m_ToolShell(nullptr)
	{
	}

	ToolShell::ToolShell(Widget& w)
	{
		m_ToolShell = GTK_TOOL_SHELL(w.GetWidget());
	}

	CGui::EllipsizeMode ToolShell::EllipsizeMode()
	{
		return (CGui::EllipsizeMode)gtk_tool_shell_get_ellipsize_mode(m_ToolShell);
	}

	CGui::IconSize ToolShell::IconSize()
	{
		return (CGui::IconSize)gtk_tool_shell_get_icon_size(m_ToolShell);
	}

	CGui::Orientation ToolShell::Orientation()
	{
		return (CGui::Orientation)gtk_tool_shell_get_orientation(m_ToolShell);
	}

	CGui::ReliefStyle ToolShell::ReliefStyle()
	{
		return (CGui::ReliefStyle)gtk_tool_shell_get_relief_style(m_ToolShell);
	}

	CGui::ToolbarStyle ToolShell::Style()
	{
		return (CGui::ToolbarStyle)gtk_tool_shell_get_style(m_ToolShell);
	}

	float ToolShell::TextAlignment()
	{
		return gtk_tool_shell_get_text_alignment(m_ToolShell);
	}

	CGui::Orientation ToolShell::TextOrientation()
	{
		return (CGui::Orientation)gtk_tool_shell_get_text_orientation(m_ToolShell);
	}

	void ToolShell::RebuildMenu()
	{
		gtk_tool_shell_rebuild_menu(m_ToolShell);
	}

	CGui::SizeGroup ToolShell::TextSizeGroup()
	{
		return SizeGroup(gtk_tool_shell_get_text_size_group(m_ToolShell));
	}

	bool ToolShell::IsToolShell()
	{
		return GTK_IS_TOOL_SHELL(m_ToolShell);
	}

	void ToolShell::SetToolShell(GtkToolShell* toolshell)
	{
		m_ToolShell = toolshell;
	}

}