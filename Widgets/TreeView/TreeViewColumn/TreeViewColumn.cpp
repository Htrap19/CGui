#include "./TreeViewColumn.hh"
#include "../../Button/Button.hh"
#include "../TreeView.hh"

namespace CGui
{
	int TreeViewColumn::increment_index = 0;

	TreeViewColumn::TreeViewColumn()
	{
		column = gtk_tree_view_column_new();
		index = increment_index++;
	}

	TreeViewColumn::TreeViewColumn(GtkTreeViewColumn* column)
	{
		this->column = column;
	}

	TreeViewColumn::TreeViewColumn(const char* title, CellRenderer& cell_renderer, bool expand, bool bind /*= true*/, PackType type /*= PackType::START*/)
	{
		column = gtk_tree_view_column_new();
		index = increment_index++;
		this->Title(title);
		
		if (type == PackType::START)
			this->PackStart(cell_renderer, expand);
		else
			this->PackEnd(cell_renderer, expand);

		if (bind)
		{
			auto attribute = Converter::Convert::GetInstance().GetGtkCode(cell_renderer.CellRendererType());
			this->AddAttribute(cell_renderer, attribute);
		}
	}

	void TreeViewColumn::PackStart(CellRenderer& cell_renderer, bool expand)
	{
		gtk_tree_view_column_pack_start(column, cell_renderer.GetCellRenderer(), expand);
	}

	void TreeViewColumn::PackEnd(CellRenderer& cell_renderer, bool expand)
	{
		gtk_tree_view_column_pack_end(column, cell_renderer.GetCellRenderer(), expand);
	}

	void TreeViewColumn::Clear()
	{
		gtk_tree_view_column_clear(column);
	}

	void TreeViewColumn::AddAttribute(CellRenderer& cell_renderer, const char* attribute, int column)
	{
		gtk_tree_view_column_add_attribute(this->column, cell_renderer.GetCellRenderer(), attribute, column);
	}

	void TreeViewColumn::AddAttribute(CellRenderer& cell_renderer, const char* attribute)
	{
		this->AddAttribute(cell_renderer, attribute, this->index);
	}

	void TreeViewColumn::ClearAttributes(CellRenderer& cell_renderer)
	{
		gtk_tree_view_column_clear_attributes(column, cell_renderer.GetCellRenderer());
	}

	void TreeViewColumn::Spacing(int spacing)
	{
		gtk_tree_view_column_set_spacing(column, spacing);
	}

	int TreeViewColumn::Spacing()
	{
		return gtk_tree_view_column_get_spacing(column);
	}

	void TreeViewColumn::Visible(bool visible)
	{
		gtk_tree_view_column_set_visible(column, visible);
	}

	bool TreeViewColumn::Visible()
	{
		return gtk_tree_view_column_get_visible(column);
	}

	void TreeViewColumn::Resizable(bool resizable)
	{
		gtk_tree_view_column_set_resizable(column, resizable);
	}

	bool TreeViewColumn::Resizable()
	{
		return gtk_tree_view_column_get_resizable(column);
	}

	void TreeViewColumn::Sizing(TreeViewColumnSizing type)
	{
		gtk_tree_view_column_set_sizing(column, (GtkTreeViewColumnSizing)type);
	}

	CGui::TreeViewColumnSizing TreeViewColumn::Sizing()
	{
		return (TreeViewColumnSizing)gtk_tree_view_column_get_sizing(column);
	}

	int TreeViewColumn::Width()
	{
		return gtk_tree_view_column_get_width(column);
	}

	void TreeViewColumn::FixedWidth(int fixed_width)
	{
		gtk_tree_view_column_set_fixed_width(column, fixed_width);
	}

	int TreeViewColumn::FixedWidth()
	{
		return gtk_tree_view_column_get_fixed_width(column);
	}

	void TreeViewColumn::MinWidth(int min_width)
	{
		gtk_tree_view_column_set_min_width(column, min_width);
	}

	int TreeViewColumn::MinWidth()
	{
		return gtk_tree_view_column_get_min_width(column);
	}

	void TreeViewColumn::MaxWidth(int max_width)
	{
		gtk_tree_view_column_set_max_width(column, max_width);
	}

	int TreeViewColumn::MaxWidth()
	{
		return gtk_tree_view_column_get_max_width(column);
	}

	void TreeViewColumn::Clicked()
	{
		gtk_tree_view_column_clicked(column);
	}

	void TreeViewColumn::Title(const char* title)
	{
		gtk_tree_view_column_set_title(column, title);
	}

	const char* TreeViewColumn::Title()
	{
		return gtk_tree_view_column_get_title(column);
	}

	void TreeViewColumn::Expand(bool expand)
	{
		gtk_tree_view_column_set_expand(column, expand);
	}

	bool TreeViewColumn::Expand()
	{
		return gtk_tree_view_column_get_expand(column);
	}

	void TreeViewColumn::Clickable(bool clickable)
	{
		gtk_tree_view_column_set_clickable(column, clickable);
	}

	bool TreeViewColumn::Clickable()
	{
		return gtk_tree_view_column_get_clickable(column);
	}

	void TreeViewColumn::Widget(CGui::Widget& widget)
	{
		gtk_tree_view_column_set_widget(column, widget.GetWidget());
	}

	CGui::Widget TreeViewColumn::Widget()
	{
		return CGui::Widget(gtk_tree_view_column_get_widget(column));
	}

	CGui::Button TreeViewColumn::Button()
	{
		return CGui::Button(GTK_BUTTON(gtk_tree_view_column_get_button(column)));
	}

	void TreeViewColumn::Alignment(float xalign)
	{
		gtk_tree_view_column_set_alignment(column, xalign);
	}

	float TreeViewColumn::Alignment()
	{
		return gtk_tree_view_column_get_alignment(column);
	}

	void TreeViewColumn::Reorderable(bool reorderable)
	{
		gtk_tree_view_column_set_reorderable(column, reorderable);
	}

	bool TreeViewColumn::Reorderable()
	{
		return gtk_tree_view_column_get_reorderable(column);
	}

	void TreeViewColumn::SortColumnId(int sort_column_id)
	{
		gtk_tree_view_column_set_sort_column_id(column, sort_column_id);
	}

	int TreeViewColumn::SortColumnId()
	{
		return gtk_tree_view_column_get_sort_column_id(column);
	}

	void TreeViewColumn::SortIndicator(bool indicator)
	{
		gtk_tree_view_column_set_sort_indicator(column, indicator);
	}

	bool TreeViewColumn::SortIndicator()
	{
		return gtk_tree_view_column_get_sort_indicator(column);
	}

	void TreeViewColumn::SortOrder(CGui::SortType type)
	{
		gtk_tree_view_column_set_sort_order(column, (GtkSortType)type);
	}

	CGui::SortType TreeViewColumn::SortOrder()
	{
		return (SortType)gtk_tree_view_column_get_sort_order(column);
	}

	void TreeViewColumn::CellSetCellData(TreeModel& tree_model, TreeModel::TreeIter& iter, bool is_expander, bool is_expanded)
	{
		gtk_tree_view_column_cell_set_cell_data(column, tree_model.GetWidget(), iter.GetWidget(), is_expander, is_expanded);
	}

	Rectangle TreeViewColumn::CellSize(Rectangle cell_area)
	{
		GdkRectangle cell_area_ori = Converter::Convert::GetInstance().ConvertFromRectangle(cell_area);
		gint x_offset, y_offset, width, height;

		gtk_tree_view_column_cell_get_size(column, &cell_area_ori, &x_offset, &y_offset, &width, &height);

		return { { x_offset, y_offset }, { width, height } };
	}

	CGui::CellPositionData TreeViewColumn::CellPosition(CellRenderer& cell_renderer)
	{
		gint x_offset, width;
		bool belo;
		
		belo = gtk_tree_view_column_cell_get_position(column, cell_renderer.GetCellRenderer(), &x_offset, &width);

		return { x_offset, width, belo };
	}

	bool TreeViewColumn::CellIsVisible()
	{
		return gtk_tree_view_column_cell_is_visible(column);
	}

	void TreeViewColumn::FocusCell(CellRenderer& cell_renderer)
	{
		gtk_tree_view_column_focus_cell(column, cell_renderer.GetCellRenderer());
	}

	void TreeViewColumn::QueueResize()
	{
		gtk_tree_view_column_queue_resize(column);
	}

	CGui::TreeView TreeViewColumn::TreeView()
	{
		return CGui::TreeView(GTK_TREE_VIEW(gtk_tree_view_column_get_tree_view(column)));
	}

	int TreeViewColumn::XOffset()
	{
		return gtk_tree_view_column_get_x_offset(column);
	}

	GtkTreeViewColumn* TreeViewColumn::GetWidget()
	{
		return column;
	}

	int TreeViewColumn::Index()
	{
		return index;
	}

	bool TreeViewColumn::IsTreeViewColumn()
	{
		return GTK_IS_TREE_SELECTION(column);
	}

}