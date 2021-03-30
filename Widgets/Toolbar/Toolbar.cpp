#include "./Toolbar.hh"

namespace CGui
{
	Toolbar::Toolbar() : Container(this), Orientable(this)
	{
		m_Widget = gtk_toolbar_new();
		this->SetContext(m_Widget);
		this->SetToolShell(GTK_TOOL_SHELL(m_Widget));
	}

	Toolbar::Toolbar(GtkToolbar* tool_bar) : Container(this), Orientable(this)
	{
		m_Widget = GTK_WIDGET(tool_bar);
		this->SetContext(m_Widget);
		this->SetToolShell(GTK_TOOL_SHELL(m_Widget));
	}

	void Toolbar::Insert(ToolItem& item, int pos)
	{
		gtk_toolbar_insert(GTK_TOOLBAR(m_Widget), GTK_TOOL_ITEM(item.GetWidget()), pos);
	}

	int Toolbar::ItemIndex(ToolItem& item)
	{
		return gtk_toolbar_get_item_index(GTK_TOOLBAR(m_Widget), GTK_TOOL_ITEM(item.GetWidget()));
	}

	int Toolbar::NumItems()
	{
		return gtk_toolbar_get_n_items(GTK_TOOLBAR(m_Widget));
	}

	ToolItem Toolbar::NthItem(int pos)
	{
		return ToolItem(gtk_toolbar_get_nth_item(GTK_TOOLBAR(m_Widget), pos));
	}

	int Toolbar::DropIndex(int x, int y)
	{
		return gtk_toolbar_get_drop_index(GTK_TOOLBAR(m_Widget), x, y);
	}

	void Toolbar::DropHighlightItem(ToolItem& item, int index)
	{
		gtk_toolbar_set_drop_highlight_item(GTK_TOOLBAR(m_Widget), GTK_TOOL_ITEM(item.GetWidget()), index);
	}

	void Toolbar::ShowArrow(bool show)
	{
		gtk_toolbar_set_show_arrow(GTK_TOOLBAR(m_Widget), show);
	}

	bool Toolbar::ShowArrow()
	{
		return gtk_toolbar_get_show_arrow(GTK_TOOLBAR(m_Widget));
	}

	void Toolbar::UnsetIconSize()
	{
		gtk_toolbar_unset_icon_size(GTK_TOOLBAR(m_Widget));
	}

	void Toolbar::IconSize(CGui::IconSize size)
	{
		gtk_toolbar_set_icon_size(GTK_TOOLBAR(m_Widget), (GtkIconSize)size);
	}

	CGui::IconSize Toolbar::IconSize()
	{
		return (CGui::IconSize)gtk_toolbar_get_icon_size(GTK_TOOLBAR(m_Widget));
	}

	void Toolbar::Style(ToolbarStyle style)
	{
		gtk_toolbar_set_style(GTK_TOOLBAR(m_Widget), (GtkToolbarStyle)style);
	}

	void Toolbar::UnsetStyle()
	{
		gtk_toolbar_unset_style(GTK_TOOLBAR(m_Widget));
	}

	bool Toolbar::IsToolbar()
	{
		return GTK_IS_TOOLBAR(m_Widget);
	}

}