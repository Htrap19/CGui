#include "./FlowBox.hh"

namespace CGui
{
	FlowBox::Child::Child() : Container(this)
	{
		widget = gtk_flow_box_child_new();
		this->SetContext(widget);
	}

	FlowBox::Child::Child(GtkFlowBoxChild* child) : Container(this)
	{
		widget = GTK_WIDGET(child);
		this->SetContext(widget);
	}

	int FlowBox::Child::Index()
	{
		return gtk_flow_box_child_get_index(GTK_FLOW_BOX_CHILD(widget));
	}

	bool FlowBox::Child::IsSelected()
	{
		return gtk_flow_box_child_is_selected(GTK_FLOW_BOX_CHILD(widget));
	}

	void FlowBox::Child::Changed()
	{
		gtk_flow_box_child_changed(GTK_FLOW_BOX_CHILD(widget));
	}

	bool FlowBox::Child::IsChild()
	{
		return GTK_IS_FLOW_BOX_CHILD(widget);
	}

	FlowBox::FlowBox() : Container(this), Orientable(this)
	{
		widget = gtk_flow_box_new();
		this->SetContext(widget);
	}

	void FlowBox::Insert(Widget& child, int position)
	{
		gtk_flow_box_insert(GTK_FLOW_BOX(widget), child.GetWidget(), position);
	}

	FlowBox::Child FlowBox::ChildAtIndex(int index)
	{
		return FlowBox::Child(gtk_flow_box_get_child_at_index(GTK_FLOW_BOX(widget), index));
	}

	FlowBox::Child FlowBox::ChildAtPos(int x, int y)
	{
		return FlowBox::Child(gtk_flow_box_get_child_at_pos(GTK_FLOW_BOX(widget), x, y));
	}

	void FlowBox::HAdjustment(Adjustment adjustment)
	{
		gtk_flow_box_set_hadjustment(GTK_FLOW_BOX(widget), adjustment.GetAdjustment());
	}

	void FlowBox::VAdjustment(Adjustment adjustment)
	{
		gtk_flow_box_set_vadjustment(GTK_FLOW_BOX(widget), adjustment.GetAdjustment());
	}

	void FlowBox::Homogeneous(bool homogeneous)
	{
		gtk_flow_box_set_homogeneous(GTK_FLOW_BOX(widget), homogeneous);
	}

	bool FlowBox::Homogeneous()
	{
		return gtk_flow_box_get_homogeneous(GTK_FLOW_BOX(widget));
	}

	void FlowBox::RowSpacing(unsigned int spacing)
	{
		gtk_flow_box_set_row_spacing(GTK_FLOW_BOX(widget), spacing);
	}

	unsigned int FlowBox::RowSpacing()
	{
		return gtk_flow_box_get_row_spacing(GTK_FLOW_BOX(widget));
	}

	void FlowBox::ColumnSpacing(unsigned int spacing)
	{
		gtk_flow_box_set_column_spacing(GTK_FLOW_BOX(widget), spacing);
	}

	unsigned int FlowBox::ColumnSpacing()
	{
		return gtk_flow_box_get_column_spacing(GTK_FLOW_BOX(widget));
	}

	void FlowBox::MinChildrenPerLine(unsigned int n_children)
	{
		gtk_flow_box_set_min_children_per_line(GTK_FLOW_BOX(widget), n_children);
	}

	unsigned int FlowBox::MinChildrenPerLine()
	{
		return gtk_flow_box_get_min_children_per_line(GTK_FLOW_BOX(widget));
	}

	void FlowBox::MaxChildrenPerLine(unsigned int n_children)
	{
		gtk_flow_box_set_max_children_per_line(GTK_FLOW_BOX(widget), n_children);
	}

	unsigned int FlowBox::MaxChildrenPerLine()
	{
		return gtk_flow_box_get_max_children_per_line(GTK_FLOW_BOX(widget));
	}

	void FlowBox::ActivateOnSingleClick(bool activate)
	{
		gtk_flow_box_set_activate_on_single_click(GTK_FLOW_BOX(widget), activate);
	}

	bool FlowBox::ActivateOnSingleClick()
	{
		return gtk_flow_box_get_activate_on_single_click(GTK_FLOW_BOX(widget));
	}

	Single::List<Widget> FlowBox::SelectedChildren()
	{
		auto glist = gtk_flow_box_get_selected_children(GTK_FLOW_BOX(widget));
		Single::List<Widget> ret;

		for (GList* it = glist; it != NULL; it = it->next)
		{
			ret.Insert(Widget(GTK_WIDGET(it->data)));
		}
		g_list_free(glist);

		return ret;
	}

	void FlowBox::SelectChild(FlowBox::Child& child)
	{
		gtk_flow_box_select_child(GTK_FLOW_BOX(widget), GTK_FLOW_BOX_CHILD(child.GetWidget()));
	}

	void FlowBox::UnselectChild(FlowBox::Child& child)
	{
		gtk_flow_box_unselect_child(GTK_FLOW_BOX(widget), GTK_FLOW_BOX_CHILD(child.GetWidget()));
	}

	void FlowBox::SelectAll()
	{
		gtk_flow_box_select_all(GTK_FLOW_BOX(widget));
	}

	void FlowBox::UnselectAll()
	{
		gtk_flow_box_unselect_all(GTK_FLOW_BOX(widget));
	}

	void FlowBox::SelectionMode(CGui::SelectionMode mode)
	{
		gtk_flow_box_set_selection_mode(GTK_FLOW_BOX(widget), (GtkSelectionMode)mode);
	}

	CGui::SelectionMode FlowBox::SelectionMode()
	{
		return (CGui::SelectionMode)gtk_flow_box_get_selection_mode(GTK_FLOW_BOX(widget));
	}

	bool FlowBox::IsFlowBox()
	{
		return GTK_IS_FLOW_BOX(widget);
	}

}