#include "./ToolItemGroup.hh"

namespace CGui
{
	ToolItemGroup::ToolItemGroup(GtkToolItemGroup* group) : Container(this)
	{
		this->widget = GTK_WIDGET(group);
		this->SetContext(widget);
	}

	ToolItemGroup::ToolItemGroup(const char* label) : Container(this)
	{
		widget = gtk_tool_item_group_new(label);
		this->SetContext(widget);
	}

	void ToolItemGroup::Collapsed(bool collapsed)
	{
		gtk_tool_item_group_set_collapsed(GTK_TOOL_ITEM_GROUP(widget), collapsed);
	}

	bool ToolItemGroup::Collapsed()
	{
		return gtk_tool_item_group_get_collapsed(GTK_TOOL_ITEM_GROUP(widget));
	}

	void ToolItemGroup::EllipsizeMode(CGui::EllipsizeMode mode)
	{
		gtk_tool_item_group_set_ellipsize(GTK_TOOL_ITEM_GROUP(widget), (PangoEllipsizeMode)mode);
	}

	CGui::EllipsizeMode ToolItemGroup::EllipsizeMode()
	{
		return (CGui::EllipsizeMode)gtk_tool_item_group_get_ellipsize(GTK_TOOL_ITEM_GROUP(widget));
	}

	void ToolItemGroup::ItemPosition(ToolItem& item, int pos)
	{
		gtk_tool_item_group_set_item_position(GTK_TOOL_ITEM_GROUP(widget), GTK_TOOL_ITEM(item.GetWidget()), pos);
	}

	int ToolItemGroup::ItemPosition(ToolItem& item)
	{
		return gtk_tool_item_group_get_item_position(GTK_TOOL_ITEM_GROUP(widget), GTK_TOOL_ITEM(item.GetWidget()));
	}

	void ToolItemGroup::Label(const char* label)
	{
		gtk_tool_item_group_set_label(GTK_TOOL_ITEM_GROUP(widget), label);
	}

	const char* ToolItemGroup::Label()
	{
		return gtk_tool_item_group_get_label(GTK_TOOL_ITEM_GROUP(widget));
	}

	void ToolItemGroup::LabelWidget(Widget& label)
	{
		gtk_tool_item_group_set_label_widget(GTK_TOOL_ITEM_GROUP(widget), label.GetWidget());
	}

	Widget ToolItemGroup::LabelWidget()
	{
		return Widget(gtk_tool_item_group_get_label_widget(GTK_TOOL_ITEM_GROUP(widget)));
	}

	void ToolItemGroup::HeaderRelief(CGui::ReliefStyle style)
	{
		gtk_tool_item_group_set_header_relief(GTK_TOOL_ITEM_GROUP(widget), (GtkReliefStyle)style);
	}

	CGui::ReliefStyle ToolItemGroup::HeaderRelief()
	{
		return (CGui::ReliefStyle)gtk_tool_item_group_get_header_relief(GTK_TOOL_ITEM_GROUP(widget));
	}

	unsigned int ToolItemGroup::NumItems()
	{
		return gtk_tool_item_group_get_n_items(GTK_TOOL_ITEM_GROUP(widget));
	}

	ToolItem ToolItemGroup::NthItem(int index)
	{
		return ToolItem(gtk_tool_item_group_get_nth_item(GTK_TOOL_ITEM_GROUP(widget), index));
	}

	void ToolItemGroup::Insert(ToolItem& item, int pos)
	{
		gtk_tool_item_group_insert(GTK_TOOL_ITEM_GROUP(widget), GTK_TOOL_ITEM(item.GetWidget()), pos);
	}

}