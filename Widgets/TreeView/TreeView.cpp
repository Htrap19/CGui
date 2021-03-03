#include "TreeView.hh"

namespace CGui
{

	TreeView::TreeView() : Container(*this)
	{
		widget = gtk_tree_view_new();
		this->SetContext(widget);
	}

	TreeView::TreeView(GtkTreeView* view) : Container(*this)
	{
		widget = GTK_WIDGET(view);
		this->SetContext(widget);
	}

	TreeView::TreeView(TreeModel& model) : Container(*this)
	{
		widget = gtk_tree_view_new_with_model(model.GetWidget());
		this->SetContext(widget);
	}

	void TreeView::LevelIndentation(int indentation)
	{
		gtk_tree_view_set_level_indentation(GTK_TREE_VIEW(widget), indentation);
	}

	int TreeView::LevelIndentation()
	{
		return gtk_tree_view_get_level_indentation(GTK_TREE_VIEW(widget));
	}

	void TreeView::ShowExpanders(bool show)
	{
		gtk_tree_view_set_show_expanders(GTK_TREE_VIEW(widget), show);
	}

	bool TreeView::ShowExpanders()
	{
		return gtk_tree_view_get_show_expanders(GTK_TREE_VIEW(widget));
	}

	void TreeView::Model(TreeModel& tree_model)
	{
		gtk_tree_view_set_model(GTK_TREE_VIEW(widget), tree_model.GetWidget());
	}

	CGui::TreeModel TreeView::Model()
	{
		return CGui::TreeModel(gtk_tree_view_get_model(GTK_TREE_VIEW(widget)));
	}

	CGui::TreeSelection TreeView::Selection()
	{
		return CGui::TreeSelection(gtk_tree_view_get_selection(GTK_TREE_VIEW(widget)));
	}

	void TreeView::HeadersVisible(bool visible)
	{
		gtk_tree_view_set_headers_visible(GTK_TREE_VIEW(widget), visible);
	}

	bool TreeView::HeadersVisible()
	{
		return gtk_tree_view_get_headers_visible(GTK_TREE_VIEW(widget));
	}

	void TreeView::ColumnsAutosize()
	{
		gtk_tree_view_columns_autosize(GTK_TREE_VIEW(widget));
	}

	void TreeView::HeadersClickable(bool clickable)
	{
		gtk_tree_view_set_headers_clickable(GTK_TREE_VIEW(widget), clickable);
	}

	bool TreeView::HeadersClickable()
	{
		return gtk_tree_view_get_headers_clickable(GTK_TREE_VIEW(widget));
	}

	void TreeView::ActivateOnSingleClick(bool activate)
	{
		gtk_tree_view_set_activate_on_single_click(GTK_TREE_VIEW(widget), activate);
	}

	bool TreeView::ActivateOnSingleClick()
	{
		return gtk_tree_view_get_activate_on_single_click(GTK_TREE_VIEW(widget));
	}

	void TreeView::AppendColumn(TreeViewColumn& column)
	{
		gtk_tree_view_append_column(GTK_TREE_VIEW(widget), column.GetWidget());
	}

	void TreeView::RemoveColumn(TreeViewColumn& column)
	{
		gtk_tree_view_remove_column(GTK_TREE_VIEW(widget), column.GetWidget());
	}

	void TreeView::InsertColumn(TreeViewColumn& column, int position)
	{
		gtk_tree_view_insert_column(GTK_TREE_VIEW(widget), column.GetWidget(), position);
	}

	unsigned int TreeView::NColumns()
	{
		return gtk_tree_view_get_n_columns(GTK_TREE_VIEW(widget));
	}

	CGui::TreeViewColumn TreeView::Column(int n)
	{
		return CGui::TreeViewColumn(gtk_tree_view_get_column(GTK_TREE_VIEW(widget), n));
	}

	CGui::Single::List<CGui::TreeViewColumn> TreeView::Columns()
	{
		auto g_list = gtk_tree_view_get_columns(GTK_TREE_VIEW(widget));
		Single::List<CGui::TreeViewColumn> retValue;

		for (GList* it = g_list; it != nullptr; it = g_list_next(it))
		{
			retValue.Insert(TreeViewColumn(GTK_TREE_VIEW_COLUMN(it->data)));
		}

		g_list_free(g_list);

		return retValue;
	}

	void TreeView::MoveColumnAfter(TreeViewColumn& column, TreeViewColumn& base_column)
	{
		gtk_tree_view_move_column_after(GTK_TREE_VIEW(widget), column.GetWidget(), base_column.GetWidget());
	}

	void TreeView::ExpanderColumn(TreeViewColumn& column)
	{
		gtk_tree_view_set_expander_column(GTK_TREE_VIEW(widget), column.GetWidget());
	}

	CGui::TreeViewColumn TreeView::ExpanderColumn()
	{
		return CGui::TreeViewColumn(gtk_tree_view_get_expander_column(GTK_TREE_VIEW(widget)));
	}

	void TreeView::ScrollToPoint(int tree_x, int tree_y)
	{
		gtk_tree_view_scroll_to_point(GTK_TREE_VIEW(widget), tree_x, tree_y);
	}

	void TreeView::ScrollToCell(TreeModel::TreePath& path, TreeViewColumn& column, bool use_align, float row_align, float col_align)
	{
		gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW(widget), path.GetWidget(), column.GetWidget(), use_align, row_align, col_align);
	}

	void TreeView::Cursor(TreeModel::TreePath& path, TreeViewColumn& focus_column, bool start_editing)
	{
		gtk_tree_view_set_cursor(GTK_TREE_VIEW(widget), path.GetWidget(), focus_column.GetWidget(), start_editing);
	}

	CGui::TreeView::CursorData TreeView::Cursor()
	{
		GtkTreePath* path;
		GtkTreeViewColumn* column;

		gtk_tree_view_get_cursor(GTK_TREE_VIEW(widget), &path, &column);

		return { TreeModel::TreePath(path), TreeViewColumn(column) };
	}

	void TreeView::CursorOnCell(TreeModel::TreePath& path, TreeViewColumn& focus_column, CellRenderer& focus_cell, bool start_editing)
	{
		gtk_tree_view_set_cursor_on_cell(GTK_TREE_VIEW(widget), path.GetWidget(), focus_column.GetWidget(), focus_cell.GetCellRenderer(), start_editing);
	}

	void TreeView::RowActivated(TreeModel::TreePath& path, TreeViewColumn& column)
	{
		gtk_tree_view_row_activated(GTK_TREE_VIEW(widget), path.GetWidget(), column.GetWidget());
	}

	void TreeView::ExpandAll()
	{
		gtk_tree_view_expand_all(GTK_TREE_VIEW(widget));
	}

	void TreeView::CollapseAll()
	{
		gtk_tree_view_collapse_all(GTK_TREE_VIEW(widget));
	}

	void TreeView::ExpandToPath(TreeModel::TreePath& path)
	{
		gtk_tree_view_expand_to_path(GTK_TREE_VIEW(widget), path.GetWidget());
	}

	bool TreeView::ExpandRow(TreeModel::TreePath& path, bool open_all)
	{
		gtk_tree_view_expand_row(GTK_TREE_VIEW(widget), path.GetWidget(), open_all);
	}

	bool TreeView::CollapseRow(TreeModel::TreePath& path)
	{
		gtk_tree_view_collapse_row(GTK_TREE_VIEW(widget), path.GetWidget());
	}

	bool TreeView::RowExpanded(TreeModel::TreePath& path)
	{
		return gtk_tree_view_row_expanded(GTK_TREE_VIEW(widget), path.GetWidget());
	}

	void TreeView::Reorderable(bool reorderable)
	{
		gtk_tree_view_set_reorderable(GTK_TREE_VIEW(widget), reorderable);
	}

	bool TreeView::Reorderable()
	{
		return gtk_tree_view_get_reorderable(GTK_TREE_VIEW(widget));
	}

	CGui::TreeView::PathFromPosData TreeView::PathAtPos(int x, int y)
	{
		GtkTreePath* path;
		GtkTreeViewColumn* column;
		gint cell_x, cell_y;
		bool row_exists;

		row_exists = gtk_tree_view_get_path_at_pos(GTK_TREE_VIEW(widget), x, y, &path, &column, &cell_x, &cell_y);

		return { TreeModel::TreePath(path), TreeViewColumn(column), cell_x, cell_y, row_exists };
	}

	CGui::TreeView::PathFromPosData TreeView::IsBlankAtPos(int x, int y)
	{
		GtkTreePath* path;
		GtkTreeViewColumn* column;
		gint cell_x, cell_y;
		bool row_exists;

		row_exists = gtk_tree_view_is_blank_at_pos(GTK_TREE_VIEW(widget), x, y, &path, &column, &cell_x, &cell_y);

		return { TreeModel::TreePath(path), TreeViewColumn(column), cell_x, cell_y, row_exists };
	}

	Rectangle TreeView::CellArea(TreeModel::TreePath& path, TreeViewColumn& column)
	{
		GdkRectangle rect;

		gtk_tree_view_get_cell_area(GTK_TREE_VIEW(widget), path.GetWidget(), column.GetWidget(), &rect);

		return { { rect.x, rect.y }, { rect.width, rect.height } };
	}

	Rectangle TreeView::BackgroundArea(TreeModel::TreePath& path, TreeViewColumn& column)
	{
		GdkRectangle rect;

		gtk_tree_view_get_background_area(GTK_TREE_VIEW(widget), path.GetWidget(), column.GetWidget(), &rect);

		return { { rect.x, rect.y }, { rect.width, rect.height } };
	}

	CGui::TreeView::VisibleRangeData TreeView::VisibleRange()
	{
		GtkTreePath* start_path,* end_path;
		bool valid_paths;

		valid_paths = gtk_tree_view_get_visible_range(GTK_TREE_VIEW(widget), &start_path, &end_path);

		return { TreeModel::TreePath(start_path), TreeModel::TreePath(end_path), valid_paths };
	}

	CGui::CoordinatesInfo TreeView::ConvertBinWindowToTreeCoords(int bx, int by)
	{
		gint tx, ty;

		gtk_tree_view_convert_bin_window_to_tree_coords(GTK_TREE_VIEW(widget), bx, by, &tx, &ty);

		return { tx, ty };
	}

	CGui::CoordinatesInfo TreeView::ConvertBinWindowToWidgetCoords(int bx, int by)
	{
		gint wx, wy;

		gtk_tree_view_convert_bin_window_to_widget_coords(GTK_TREE_VIEW(widget), bx, by, &wx, &wy);

		return { wx, wy };
	}

	CGui::CoordinatesInfo TreeView::ConvertTreeToBinWindowCoords(int tx, int ty)
	{
		gint bx, by;

		gtk_tree_view_convert_tree_to_bin_window_coords(GTK_TREE_VIEW(widget), tx, ty, &bx, &by);

		return { bx, by };
	}

	CGui::CoordinatesInfo TreeView::ConvertTreeToWidgetCoords(int tx, int ty)
	{
		gint wx, wy;

		gtk_tree_view_convert_tree_to_widget_coords(GTK_TREE_VIEW(widget), tx, ty, &wx, &wy);

		return { wx, wy };
	}

	CGui::CoordinatesInfo TreeView::ConvertWidgetToBinWindowCoords(int wx, int wy)
	{
		gint bx, by;

		gtk_tree_view_convert_widget_to_bin_window_coords(GTK_TREE_VIEW(widget), wx, wy, &bx, &by);

		return { bx, by };
	}

	CGui::CoordinatesInfo TreeView::ConvertWidgetToTreeCoords(int wx, int wy)
	{
		gint tx, ty;

		gtk_tree_view_convert_widget_to_tree_coords(GTK_TREE_VIEW(widget), wx, wy, &tx, &ty);

		return { tx, ty };
	}

	void TreeView::UnsetRowsDragSource()
	{
		gtk_tree_view_unset_rows_drag_source(GTK_TREE_VIEW(widget));
	}

	void TreeView::UnsetRowsDragDest()
	{
		gtk_tree_view_unset_rows_drag_dest(GTK_TREE_VIEW(widget));
	}

	void TreeView::DragDestRow(TreeModel::TreePath& path, TreeViewDropPosition pos)
	{
		gtk_tree_view_set_drag_dest_row(GTK_TREE_VIEW(widget), path.GetWidget(), (GtkTreeViewDropPosition)pos);
	}

	CGui::TreeView::DragDestRowData TreeView::DragDestRow()
	{
		GtkTreePath* path;
		GtkTreeViewDropPosition pos;

		gtk_tree_view_get_drag_dest_row(GTK_TREE_VIEW(widget), &path, &pos);
		 
		return { TreeModel::TreePath(path), (TreeViewDropPosition)pos };
	}

	CGui::TreeView::DragDestRowData TreeView::DragDestRowAtPos(int drag_x, int drag_y)
	{
		GtkTreePath* path;
		GtkTreeViewDropPosition pos;

		gtk_tree_view_get_dest_row_at_pos(GTK_TREE_VIEW(widget), drag_x, drag_y, &path, &pos);

		return { TreeModel::TreePath(path), (TreeViewDropPosition)pos };
	}

	void TreeView::EnableSearch(bool enable)
	{
		gtk_tree_view_set_enable_search(GTK_TREE_VIEW(widget), enable);
	}

	bool TreeView::EnableSearch()
	{
		return gtk_tree_view_get_enable_search(GTK_TREE_VIEW(widget));
	}

	void TreeView::SearchColumn(int column)
	{
		gtk_tree_view_set_search_column(GTK_TREE_VIEW(widget), column);
	}

	int TreeView::SearchColumn()
	{
		gtk_tree_view_get_search_column(GTK_TREE_VIEW(widget));
	}

	void TreeView::SearchEntry(CGui::Entry& entry)
	{
		gtk_tree_view_set_search_entry(GTK_TREE_VIEW(widget), GTK_ENTRY(entry.GetWidget()));
	}

	CGui::Entry TreeView::SearchEntry()
	{
		return CGui::Entry(GTK_ENTRY(gtk_tree_view_get_search_entry(GTK_TREE_VIEW(widget))));
	}

	void TreeView::FixedHeightMode(bool enable)
	{
		gtk_tree_view_set_fixed_height_mode(GTK_TREE_VIEW(widget), enable);
	}

	bool TreeView::FixedHeightMode()
	{
		return gtk_tree_view_get_fixed_height_mode(GTK_TREE_VIEW(widget));
	}

	void TreeView::HoverSelection(bool selection)
	{
		gtk_tree_view_set_hover_selection(GTK_TREE_VIEW(widget), selection);
	}

	bool TreeView::HoverSelection()
	{
		return gtk_tree_view_get_hover_selection(GTK_TREE_VIEW(widget));
	}

	void TreeView::HoverExpand(bool expand)
	{
		gtk_tree_view_set_hover_expand(GTK_TREE_VIEW(widget), expand);
	}

	bool TreeView::HoverExpand()
	{
		return gtk_tree_view_get_hover_expand(GTK_TREE_VIEW(widget));
	}

	void TreeView::RubberBanding(bool enable)
	{
		gtk_tree_view_set_rubber_banding(GTK_TREE_VIEW(widget), enable);
	}

	bool TreeView::RubberBanding()
	{
		return gtk_tree_view_get_rubber_banding(GTK_TREE_VIEW(widget));
	}

	bool TreeView::IsRubberBandingActive()
	{
		return gtk_tree_view_is_rubber_banding_active(GTK_TREE_VIEW(widget));
	}

	void TreeView::EnableTreeLines(bool enabled)
	{
		gtk_tree_view_set_enable_tree_lines(GTK_TREE_VIEW(widget), enabled);
	}

	bool TreeView::EnableTreeLines()
	{
		return gtk_tree_view_get_enable_tree_lines(GTK_TREE_VIEW(widget));
	}

	void TreeView::GridLines(TreeViewGridLines grid_lines)
	{
		gtk_tree_view_set_grid_lines(GTK_TREE_VIEW(widget), (GtkTreeViewGridLines)grid_lines);
	}

	CGui::TreeViewGridLines TreeView::GridLines()
	{
		return (TreeViewGridLines)gtk_tree_view_get_grid_lines(GTK_TREE_VIEW(widget));
	}

	void TreeView::TooltipColumn(int column)
	{
		gtk_tree_view_set_tooltip_column(GTK_TREE_VIEW(widget), column);
	}

	int TreeView::TooltipColumn()
	{
		return gtk_tree_view_get_tooltip_column(GTK_TREE_VIEW(widget));
	}

	bool TreeView::IsTreeView()
	{
		return GTK_IS_TREE_VIEW(widget);
	}

}