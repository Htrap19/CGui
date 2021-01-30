#include "./ListBox.hh"

namespace CGui
{
	ListBox::Row::Row() : Container(this)
	{
		widget = gtk_list_box_row_new();
		this->SetContext(widget);
	}

	ListBox::Row::Row(GtkListBoxRow* row) : Container(this)
	{
		this->widget = GTK_WIDGET(row);
		this->SetContext(widget);
	}

	void ListBox::Row::Changed()
	{
		gtk_list_box_row_changed(GTK_LIST_BOX_ROW(widget));
	}

	bool ListBox::Row::IsSelected()
	{
		return gtk_list_box_row_is_selected(GTK_LIST_BOX_ROW(widget));
	}

	void ListBox::Row::Header(Widget& header)
	{
		gtk_list_box_row_set_header(GTK_LIST_BOX_ROW(widget), header.GetWidget());
	}

	Widget ListBox::Row::Header()
	{
		return Widget(gtk_list_box_row_get_header(GTK_LIST_BOX_ROW(widget)));
	}

	int ListBox::Row::Index()
	{
		return gtk_list_box_row_get_index(GTK_LIST_BOX_ROW(widget));
	}

	void ListBox::Row::Activatable(bool activatable)
	{
		gtk_list_box_row_set_activatable(GTK_LIST_BOX_ROW(widget), activatable);
	}

	bool ListBox::Row::Activatable()
	{
		return gtk_list_box_row_get_activatable(GTK_LIST_BOX_ROW(widget));
	}

	void ListBox::Row::Selectable(bool selectable)
	{
		gtk_list_box_row_set_selectable(GTK_LIST_BOX_ROW(widget), selectable);
	}

	bool ListBox::Row::Selectable()
	{
		return gtk_list_box_row_get_selectable(GTK_LIST_BOX_ROW(widget));
	}

	bool ListBox::Row::IsRow()
	{
		return GTK_IS_LIST_BOX_ROW(widget);
	}

	ListBox::ListBox() : Container(this)
	{
		widget = gtk_list_box_new();
		this->SetContext(widget);
	}

	ListBox::ListBox(GtkListBox* list_box) : Container(this)
	{
		widget = GTK_WIDGET(list_box);
		this->SetContext(widget);
	}

	void ListBox::Prepend(Widget& child)
	{
		gtk_list_box_prepend(GTK_LIST_BOX(widget), child.GetWidget());
	}

	void ListBox::Insert(Widget& child, int pos)
	{
		gtk_list_box_insert(GTK_LIST_BOX(widget), child.GetWidget(), pos);
	}

	void ListBox::SelectRow(Row& row)
	{
		gtk_list_box_select_row(GTK_LIST_BOX(widget), GTK_LIST_BOX_ROW(row.GetWidget()));
	}

	void ListBox::UnselectRow(Row& row)
	{
		gtk_list_box_unselect_row(GTK_LIST_BOX(widget), GTK_LIST_BOX_ROW(row.GetWidget()));
	}

	void ListBox::SelectAll()
	{
		gtk_list_box_select_all(GTK_LIST_BOX(widget));
	}

	void ListBox::UnselectAll()
	{
		gtk_list_box_unselect_all(GTK_LIST_BOX(widget));
	}

	ListBox::Row ListBox::SelectedRow()
	{
		return Row(gtk_list_box_get_selected_row(GTK_LIST_BOX(widget)));
	}

	Single::List<Widget> ListBox::SelectedRows()
	{
		auto glist = gtk_list_box_get_selected_rows(GTK_LIST_BOX(widget));
		Single::List<Widget> ret;

		for (GList* it = glist; it != NULL; it = it->next)
		{
			ret.Insert(Widget(GTK_WIDGET(it->data)));
		}

		g_list_free(glist);

		return ret;
	}

	void ListBox::SelectionMode(CGui::SelectionMode mode)
	{
		gtk_list_box_set_selection_mode(GTK_LIST_BOX(widget), (GtkSelectionMode)mode);
	}

	CGui::SelectionMode ListBox::SelectionMode()
	{
		return (CGui::SelectionMode)gtk_list_box_get_selection_mode(GTK_LIST_BOX(widget));
	}

	void ListBox::ActivateOnSingleClick(bool activate)
	{
		gtk_list_box_set_activate_on_single_click(GTK_LIST_BOX(widget), activate);
	}

	bool ListBox::ActivateOnSingleClick()
	{
		return gtk_list_box_get_activate_on_single_click(GTK_LIST_BOX(widget));
	}

	void ListBox::Adjustment(CGui::Adjustment adjustment)
	{
		gtk_list_box_set_adjustment(GTK_LIST_BOX(widget), adjustment.GetAdjustment());
	}

	CGui::Adjustment ListBox::Adjustment()
	{
		return CGui::Adjustment(gtk_list_box_get_adjustment(GTK_LIST_BOX(widget)));
	}

	void ListBox::PlaceHolder(Widget& placeholder)
	{
		gtk_list_box_set_placeholder(GTK_LIST_BOX(widget), placeholder.GetWidget());
	}

	ListBox::Row ListBox::RowAtIndex(int index)
	{
		return ListBox::Row(gtk_list_box_get_row_at_index(GTK_LIST_BOX(widget), index));
	}

	ListBox::Row ListBox::RowAtY(int y)
	{
		return ListBox::Row(gtk_list_box_get_row_at_y(GTK_LIST_BOX(widget), y));
	}

	void ListBox::InvalidateFilter()
	{
		gtk_list_box_invalidate_filter(GTK_LIST_BOX(widget));
	}

	void ListBox::InvalidateHeader()
	{
		gtk_list_box_invalidate_headers(GTK_LIST_BOX(widget));
	}

	void ListBox::InvalidateSort()
	{
		gtk_list_box_invalidate_sort(GTK_LIST_BOX(widget));
	}

	void ListBox::DragHighlightRow(ListBox::Row& row)
	{
		gtk_list_box_drag_highlight_row(GTK_LIST_BOX(widget), GTK_LIST_BOX_ROW(row.GetWidget()));
	}

	void ListBox::DragUnhighlightRow(ListBox::Row& row)
	{
		gtk_list_box_drag_unhighlight_row(GTK_LIST_BOX(widget));
	}

	bool ListBox::IsListBox()
	{
		return GTK_IS_LIST_BOX(widget);
	}

}