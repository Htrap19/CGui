#include "./Toolbar.hh"

namespace CGui
{
	Toolbar::Toolbar() : Container(this), Orientable(this)
	{
		widget = gtk_toolbar_new();
		this->SetContext(widget);
		this->SetToolShell(GTK_TOOL_SHELL(widget));
	}

	void Toolbar::Insert(ToolItem& item, int pos)
	{
		gtk_toolbar_insert(GTK_TOOLBAR(widget), GTK_TOOL_ITEM(item.GetWidget()), pos);
	}

	int Toolbar::ItemIndex(ToolItem& item)
	{
		return gtk_toolbar_get_item_index(GTK_TOOLBAR(widget), GTK_TOOL_ITEM(item.GetWidget()));
	}

	int Toolbar::NumItems()
	{
		return gtk_toolbar_get_n_items(GTK_TOOLBAR(widget));
	}

	ToolItem Toolbar::NthItem(int pos)
	{
		return ToolItem(gtk_toolbar_get_nth_item(GTK_TOOLBAR(widget), pos));
	}

	int Toolbar::DropIndex(int x, int y)
	{
		return gtk_toolbar_get_drop_index(GTK_TOOLBAR(widget), x, y);
	}

	void Toolbar::DropHighlightItem(ToolItem& item, int index)
	{
		gtk_toolbar_set_drop_highlight_item(GTK_TOOLBAR(widget), GTK_TOOL_ITEM(item.GetWidget()), index);
	}

	void Toolbar::ShowArrow(bool show)
	{
		gtk_toolbar_set_show_arrow(GTK_TOOLBAR(widget), show);
	}

	bool Toolbar::ShowArrow()
	{
		return gtk_toolbar_get_show_arrow(GTK_TOOLBAR(widget));
	}

	void Toolbar::UnsetIconSize()
	{
		gtk_toolbar_unset_icon_size(GTK_TOOLBAR(widget));
	}

	void Toolbar::IconSize(CGui::IconSize size)
	{
		gtk_toolbar_set_icon_size(GTK_TOOLBAR(widget), (GtkIconSize)size);
	}

	CGui::IconSize Toolbar::IconSize()
	{
		return (CGui::IconSize)gtk_toolbar_get_icon_size(GTK_TOOLBAR(widget));
	}

	void Toolbar::Style(ToolbarStyle style)
	{
		gtk_toolbar_set_style(GTK_TOOLBAR(widget), (GtkToolbarStyle)style);
	}

	void Toolbar::UnsetStyle()
	{
		gtk_toolbar_unset_style(GTK_TOOLBAR(widget));
	}

}