#include "./ToolItem.hh"

namespace CGui
{
	ToolItem::ToolItem() : Container(this)
	{
		m_Widget = GTK_WIDGET(gtk_tool_item_new());
		this->SetContext(m_Widget);
	}

	ToolItem::ToolItem(GtkToolItem* item) : Container(this)
	{
		m_Widget = GTK_WIDGET(item);
		this->SetContext(m_Widget);
	}

	void ToolItem::Homogeneous(bool homogeneous)
	{
		gtk_tool_item_set_homogeneous(GTK_TOOL_ITEM(m_Widget), homogeneous);
	}

	bool ToolItem::Homogeneous()
	{
		return gtk_tool_item_get_homogeneous(GTK_TOOL_ITEM(m_Widget));
	}

	void ToolItem::ItemExpand(bool expand)
	{
		gtk_tool_item_set_expand(GTK_TOOL_ITEM(m_Widget), expand);
	}

	bool ToolItem::ItemExpand()
	{
		return gtk_tool_item_get_expand(GTK_TOOL_ITEM(m_Widget));
	}

	void ToolItem::TooltipText(const char* text)
	{
		gtk_tool_item_set_tooltip_text(GTK_TOOL_ITEM(m_Widget), text);
	}

	void ToolItem::TooltipMarkup(const char* markup)
	{
		gtk_tool_item_set_tooltip_markup(GTK_TOOL_ITEM(m_Widget), markup);
	}

	void ToolItem::UseDragWindow(bool use)
	{
		gtk_tool_item_set_use_drag_window(GTK_TOOL_ITEM(m_Widget), use);
	}

	bool ToolItem::UseDragWindow()
	{
		return gtk_tool_item_get_use_drag_window(GTK_TOOL_ITEM(m_Widget));
	}

	void ToolItem::VisibleHorizontal(bool visible)
	{
		gtk_tool_item_set_visible_horizontal(GTK_TOOL_ITEM(m_Widget), visible);
	}

	bool ToolItem::VisibleHorizontal()
	{
		return gtk_tool_item_get_visible_horizontal(GTK_TOOL_ITEM(m_Widget));
	}

	void ToolItem::VisibleVertical(bool visible)
	{
		gtk_tool_item_set_visible_vertical(GTK_TOOL_ITEM(m_Widget), visible);
	}

	bool ToolItem::VisibleVertical()
	{
		return gtk_tool_item_get_visible_vertical(GTK_TOOL_ITEM(m_Widget));
	}

	void ToolItem::IsImportant(bool is_important)
	{
		gtk_tool_item_set_is_important(GTK_TOOL_ITEM(m_Widget), is_important);
	}

	bool ToolItem::IsImportant()
	{
		return gtk_tool_item_get_is_important(GTK_TOOL_ITEM(m_Widget));
	}

	Widget ToolItem::RetrieveProxyMenuItem()
	{
		return Widget(gtk_tool_item_retrieve_proxy_menu_item(GTK_TOOL_ITEM(m_Widget)));
	}

	void ToolItem::ProxyMenuItem(const char* menu_id, Widget& child)
	{
		gtk_tool_item_set_proxy_menu_item(GTK_TOOL_ITEM(m_Widget), menu_id, child.GetWidget());
	}

	Widget ToolItem::ProxyMenuItem(const char* menu_id)
	{
		return Widget(gtk_tool_item_get_proxy_menu_item(GTK_TOOL_ITEM(m_Widget), menu_id));
	}

	void ToolItem::ToolbarReconfigured()
	{
		gtk_tool_item_toolbar_reconfigured(GTK_TOOL_ITEM(m_Widget));
	}

	bool ToolItem::IsToolItem()
	{
		return GTK_IS_TOOL_ITEM(m_Widget);
	}

}