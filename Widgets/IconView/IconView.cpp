#include "IconView.hh"
#include "../../Custom/VectorsUtilities/VectorUtilities.hh"

namespace CGui
{

	IconView::IconView() : Container(this), Scrollable(*this), m_DefaultStore(std::vector{ Type::STRING, Type::PIXBUF })
	{
		m_Widget = gtk_icon_view_new();
		this->SetContext(m_Widget);
		this->Model(m_DefaultStore);
		this->TextColumn(0);
		this->PixbufColumn(1);
	}

	IconView::IconView(TreeModel& model) : Container(this), Scrollable(*this), m_DefaultStore(model)
	{
		m_Widget = gtk_icon_view_new_with_model(model.GetWidget());
		this->SetContext(m_Widget);
	}

	void IconView::Model(TreeModel& model)
	{
		gtk_icon_view_set_model(GTK_ICON_VIEW(m_Widget), model.GetWidget());
	}

	CGui::TreeModel IconView::Model()
	{
		return TreeModel(gtk_icon_view_get_model(GTK_ICON_VIEW(m_Widget)));
	}

	void IconView::TextColumn(int column)
	{
		gtk_icon_view_set_text_column(GTK_ICON_VIEW(m_Widget), column);
	}

	int IconView::TextColumn()
	{
		return gtk_icon_view_get_text_column(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::MarkupColumn(int column)
	{
		gtk_icon_view_set_markup_column(GTK_ICON_VIEW(m_Widget), column);
	}

	int IconView::MarkupColumn()
	{
		return gtk_icon_view_get_markup_column(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::PixbufColumn(int column)
	{
		gtk_icon_view_set_pixbuf_column(GTK_ICON_VIEW(m_Widget), column);
	}

	int IconView::PixbufColumn()
	{
		return gtk_icon_view_get_pixbuf_column(GTK_ICON_VIEW(m_Widget));
	}

	CGui::TreeModel::TreePath IconView::PathAsPos(int x, int y)
	{
		return TreeModel::TreePath(gtk_icon_view_get_path_at_pos(GTK_ICON_VIEW(m_Widget), x, y));
	}

	CGui::IconView::ItemAsPosData IconView::ItemAsPos(int x, int y)
	{
		GtkTreePath* path;
		GtkCellRenderer* cell;
		bool exists = gtk_icon_view_get_item_at_pos(GTK_ICON_VIEW(m_Widget), x, y, &path, &cell);

		return { TreeModel::TreePath(path), CellRenderer(cell), exists };
	}

	CGui::CoordinatesInfo IconView::ConvertWidgetToBinWindowCoords(int wx, int wy)
	{
		int bin_x, bin_y;

		gtk_icon_view_convert_widget_to_bin_window_coords(GTK_ICON_VIEW(m_Widget), wx, wy, &bin_x, &bin_y);
		return { bin_x, bin_y };
	}

	void IconView::Cursor(TreeModel::TreePath path, CellRenderer cell, bool start_editing)
	{
		gtk_icon_view_set_cursor(GTK_ICON_VIEW(m_Widget), path.GetWidget(), cell.GetCellRenderer(), start_editing);
	}

	CGui::IconView::ItemAsPosData IconView::Cursor()
	{
		GtkTreePath* path;
		GtkCellRenderer* cell;
		bool is_set = gtk_icon_view_get_cursor(GTK_ICON_VIEW(m_Widget), &path, &cell);

		return { TreeModel::TreePath(path), CellRenderer(cell), is_set };
	}

	void IconView::SelectionMode(CGui::SelectionMode mode)
	{
		gtk_icon_view_set_selection_mode(GTK_ICON_VIEW(m_Widget), (GtkSelectionMode)mode);
	}

	CGui::SelectionMode IconView::SelectionMode()
	{
		return (CGui::SelectionMode)gtk_icon_view_get_selection_mode(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::ItemOrientation(Orientation orientation)
	{
		gtk_icon_view_set_item_orientation(GTK_ICON_VIEW(m_Widget), (GtkOrientation)orientation);
	}

	CGui::Orientation IconView::ItemOrientation()
	{
		return (CGui::Orientation)gtk_icon_view_get_item_orientation(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::Columns(int columns)
	{
		gtk_icon_view_set_columns(GTK_ICON_VIEW(m_Widget), columns);
	}

	int IconView::Columns()
	{
		return gtk_icon_view_get_columns(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::ItemWidth(int item_width)
	{
		gtk_icon_view_set_item_width(GTK_ICON_VIEW(m_Widget), item_width);
	}

	int IconView::ItemWidth()
	{
		return gtk_icon_view_get_item_width(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::Spacing(int spacing)
	{
		gtk_icon_view_set_spacing(GTK_ICON_VIEW(m_Widget), spacing);
	}

	int IconView::Spacing()
	{
		return gtk_icon_view_get_spacing(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::RowSpacing(int row_spacing)
	{
		gtk_icon_view_set_row_spacing(GTK_ICON_VIEW(m_Widget), row_spacing);
	}

	int IconView::RowSpacing()
	{
		return gtk_icon_view_get_row_spacing(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::ColumnSpacing(int columns_spacing)
	{
		gtk_icon_view_set_column_spacing(GTK_ICON_VIEW(m_Widget), columns_spacing);
	}

	int IconView::ColumnSpacing()
	{
		return gtk_icon_view_get_column_spacing(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::Margin(int margin)
	{
		gtk_icon_view_set_margin(GTK_ICON_VIEW(m_Widget), margin);
	}

	int IconView::Margin()
	{
		return gtk_icon_view_get_margin(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::ItemPadding(int item_padding)
	{
		gtk_icon_view_set_item_padding(GTK_ICON_VIEW(m_Widget), item_padding);
	}

	int IconView::ItemPadding()
	{
		return gtk_icon_view_get_item_padding(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::ActivateOnSingleClick(bool single)
	{
		gtk_icon_view_set_activate_on_single_click(GTK_ICON_VIEW(m_Widget), single);
	}

	bool IconView::ActivateOnSingleClick()
	{
		return gtk_icon_view_get_activate_on_single_click(GTK_ICON_VIEW(m_Widget));
	}

	CGui::PointingToData IconView::CellRect(TreeModel::TreePath path, CellRenderer cell)
	{
		GdkRectangle rect;

		bool valid = gtk_icon_view_get_cell_rect(GTK_ICON_VIEW(m_Widget), path.GetWidget(), cell.GetCellRenderer(), &rect);
		return { valid, { {rect.x, rect.y }, { rect.width, rect.height } } };
	}

	void IconView::SelectPath(TreeModel::TreePath path)
	{
		gtk_icon_view_select_path(GTK_ICON_VIEW(m_Widget), path.GetWidget());
	}

	void IconView::UnselectPath(TreeModel::TreePath path)
	{
		gtk_icon_view_unselect_path(GTK_ICON_VIEW(m_Widget), path.GetWidget());
	}

	bool IconView::PathIsSelected(TreeModel::TreePath path)
	{
		return gtk_icon_view_path_is_selected(GTK_ICON_VIEW(m_Widget), path.GetWidget());
	}

	CGui::Vector<CGui::TreeModel::TreePath> IconView::SelectedItems() // TreeModel::TreePath should be freed with .free() method
	{
		GList* g_list = gtk_icon_view_get_selected_items(GTK_ICON_VIEW(m_Widget));
		Vector<TreeModel::TreePath> paths = GListToTreePath(g_list);
		g_list_free(g_list);
		return std::move(paths);
	}

	void IconView::SelectAll()
	{
		gtk_icon_view_select_all(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::UnselectAll()
	{
		gtk_icon_view_unselect_all(GTK_ICON_VIEW(m_Widget));
	}

	void IconView::ItemActivated(TreeModel::TreePath path)
	{
		gtk_icon_view_item_activated(GTK_ICON_VIEW(m_Widget), path.GetWidget());
	}

	void IconView::ScrollToPath(TreeModel::TreePath path, bool use_align, float row_align, float col_align)
	{
		gtk_icon_view_scroll_to_path(GTK_ICON_VIEW(m_Widget), path.GetWidget(), use_align, row_align, col_align);
	}

	CGui::IconView::VisibleRangeData IconView::VisibleRange()
	{
		GtkTreePath* start_path, * end_path;
		bool valid = gtk_icon_view_get_visible_range(GTK_ICON_VIEW(m_Widget), &start_path, &end_path);
		return { TreeModel::TreePath(start_path), TreeModel::TreePath(end_path), valid };
	}

	int IconView::ItemRow(TreeModel::TreePath path)
	{
		return gtk_icon_view_get_item_row(GTK_ICON_VIEW(m_Widget), path.GetWidget());
	}

	int IconView::ItemColumn(TreeModel::TreePath path)
	{
		return gtk_icon_view_get_item_column(GTK_ICON_VIEW(m_Widget), path.GetWidget());
	}

	void IconView::Reorderable(bool reorderable)
	{
		gtk_icon_view_set_reorderable(GTK_ICON_VIEW(m_Widget), reorderable);
	}

	bool IconView::Reorderable()
	{
		return gtk_icon_view_get_reorderable(GTK_ICON_VIEW(m_Widget));
	}

	bool IconView::IsIconView()
	{
		return GTK_IS_ICON_VIEW(m_Widget);
	}

	CGui::ListStore& IconView::Store()
	{
		return m_DefaultStore;
	}

	CGui::TreeModel::TreeIter IconView::Append(const char* str, Pixbuf& icon)
	{
		auto iter = m_DefaultStore.Append();
		Insert(iter, str, icon);
		return iter;
	}

	CGui::TreeModel::TreeIter IconView::Prepend(const char* str, Pixbuf& icon)
	{
		auto iter = m_DefaultStore.Prepend();
		Insert(iter, str, icon);
		return iter;
	}

	void IconView::Insert(TreeModel::TreeIter& iter, const char* str, Pixbuf& icon)
	{
		m_DefaultStore.Set(iter, 0, str, 1, icon);
	}

}