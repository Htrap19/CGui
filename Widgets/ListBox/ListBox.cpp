#include "./ListBox.hh"
#include "../../Custom/VectorsUtilities/VectorUtilities.hh"

namespace CGui
{
	ListBox::Row::Row() : Container(this)
	{
		m_Widget = gtk_list_box_row_new();
		this->SetContext(m_Widget);
	}

	ListBox::Row::Row(GtkListBoxRow* row) : Container(this)
	{
		this->m_Widget = GTK_WIDGET(row);
		this->SetContext(m_Widget);
	}

	void ListBox::Row::Changed()
	{
		gtk_list_box_row_changed(GTK_LIST_BOX_ROW(m_Widget));
	}

	bool ListBox::Row::IsSelected()
	{
		return gtk_list_box_row_is_selected(GTK_LIST_BOX_ROW(m_Widget));
	}

	void ListBox::Row::Header(Widget& header)
	{
		gtk_list_box_row_set_header(GTK_LIST_BOX_ROW(m_Widget), header.GetWidget());
	}

	Widget ListBox::Row::Header()
	{
		return Widget(gtk_list_box_row_get_header(GTK_LIST_BOX_ROW(m_Widget)));
	}

	int ListBox::Row::Index()
	{
		return gtk_list_box_row_get_index(GTK_LIST_BOX_ROW(m_Widget));
	}

	void ListBox::Row::Activatable(bool activatable)
	{
		gtk_list_box_row_set_activatable(GTK_LIST_BOX_ROW(m_Widget), activatable);
	}

	bool ListBox::Row::Activatable()
	{
		return gtk_list_box_row_get_activatable(GTK_LIST_BOX_ROW(m_Widget));
	}

	void ListBox::Row::Selectable(bool selectable)
	{
		gtk_list_box_row_set_selectable(GTK_LIST_BOX_ROW(m_Widget), selectable);
	}

	bool ListBox::Row::Selectable()
	{
		return gtk_list_box_row_get_selectable(GTK_LIST_BOX_ROW(m_Widget));
	}

	bool ListBox::Row::IsRow()
	{
		return GTK_IS_LIST_BOX_ROW(m_Widget);
	}

	ListBox::ListBox() : Container(this)
	{
		m_Widget = gtk_list_box_new();
		this->SetContext(m_Widget);
	}

	ListBox::ListBox(GtkListBox* list_box) : Container(this)
	{
		m_Widget = GTK_WIDGET(list_box);
		this->SetContext(m_Widget);
	}

	void ListBox::Prepend(Widget& child)
	{
		gtk_list_box_prepend(GTK_LIST_BOX(m_Widget), child.GetWidget());
	}

	void ListBox::Insert(Widget& child, int pos)
	{
		gtk_list_box_insert(GTK_LIST_BOX(m_Widget), child.GetWidget(), pos);
	}

	void ListBox::SelectRow(Row& row)
	{
		gtk_list_box_select_row(GTK_LIST_BOX(m_Widget), GTK_LIST_BOX_ROW(row.GetWidget()));
	}

	void ListBox::UnselectRow(Row& row)
	{
		gtk_list_box_unselect_row(GTK_LIST_BOX(m_Widget), GTK_LIST_BOX_ROW(row.GetWidget()));
	}

	void ListBox::SelectAll()
	{
		gtk_list_box_select_all(GTK_LIST_BOX(m_Widget));
	}

	void ListBox::UnselectAll()
	{
		gtk_list_box_unselect_all(GTK_LIST_BOX(m_Widget));
	}

	ListBox::Row ListBox::SelectedRow()
	{
		return Row(gtk_list_box_get_selected_row(GTK_LIST_BOX(m_Widget)));
	}

	Vector<Widget> ListBox::SelectedRows()
	{
		auto glist = gtk_list_box_get_selected_rows(GTK_LIST_BOX(m_Widget));		
		Vector<Widget> selectedrows(std::move(GListToWidgetVector(glist)));
		g_list_free(glist);
		return std::move(selectedrows);
	}

	void ListBox::SelectionMode(CGui::SelectionMode mode)
	{
		gtk_list_box_set_selection_mode(GTK_LIST_BOX(m_Widget), (GtkSelectionMode)mode);
	}

	CGui::SelectionMode ListBox::SelectionMode()
	{
		return (CGui::SelectionMode)gtk_list_box_get_selection_mode(GTK_LIST_BOX(m_Widget));
	}

	void ListBox::ActivateOnSingleClick(bool activate)
	{
		gtk_list_box_set_activate_on_single_click(GTK_LIST_BOX(m_Widget), activate);
	}

	bool ListBox::ActivateOnSingleClick()
	{
		return gtk_list_box_get_activate_on_single_click(GTK_LIST_BOX(m_Widget));
	}

	void ListBox::Adjustment(CGui::Adjustment adjustment)
	{
		gtk_list_box_set_adjustment(GTK_LIST_BOX(m_Widget), adjustment.GetAdjustment());
	}

	CGui::Adjustment ListBox::Adjustment()
	{
		return CGui::Adjustment(gtk_list_box_get_adjustment(GTK_LIST_BOX(m_Widget)));
	}

	void ListBox::PlaceHolder(Widget& placeholder)
	{
		gtk_list_box_set_placeholder(GTK_LIST_BOX(m_Widget), placeholder.GetWidget());
	}

	ListBox::Row ListBox::RowAtIndex(int index)
	{
		return ListBox::Row(gtk_list_box_get_row_at_index(GTK_LIST_BOX(m_Widget), index));
	}

	ListBox::Row ListBox::RowAtY(int y)
	{
		return ListBox::Row(gtk_list_box_get_row_at_y(GTK_LIST_BOX(m_Widget), y));
	}

	void ListBox::InvalidateFilter()
	{
		gtk_list_box_invalidate_filter(GTK_LIST_BOX(m_Widget));
	}

	void ListBox::InvalidateHeader()
	{
		gtk_list_box_invalidate_headers(GTK_LIST_BOX(m_Widget));
	}

	void ListBox::InvalidateSort()
	{
		gtk_list_box_invalidate_sort(GTK_LIST_BOX(m_Widget));
	}

	void ListBox::DragHighlightRow(ListBox::Row& row)
	{
		gtk_list_box_drag_highlight_row(GTK_LIST_BOX(m_Widget), GTK_LIST_BOX_ROW(row.GetWidget()));
	}

	void ListBox::DragUnhighlightRow(ListBox::Row& row)
	{
		gtk_list_box_drag_unhighlight_row(GTK_LIST_BOX(m_Widget));
	}

	bool ListBox::IsListBox()
	{
		return GTK_IS_LIST_BOX(m_Widget);
	}

}