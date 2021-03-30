#include "Grid.hh"

namespace CGui
{
	Grid::Grid() : Container(this), Orientable(this)
	{
		m_Widget = gtk_grid_new();
		this->SetContext(m_Widget);
	}

	Grid::Grid(GtkGrid* grid) : Container(this), Orientable(this)
	{
		m_Widget = GTK_WIDGET(grid);
		this->SetContext(m_Widget);
	}

	void Grid::Add(Widget& w, int left, int top, int width, int height)
	{
		gtk_grid_attach(GTK_GRID(m_Widget), w.GetWidget(), left, top, width, height);
	}

	void Grid::InsertRow(int position)
	{
		gtk_grid_insert_row(GTK_GRID(m_Widget), position);
	}

	void Grid::InsertColumn(int position)
	{
		gtk_grid_insert_column(GTK_GRID(m_Widget), position);
	}

	void Grid::RemoveRow(int position)
	{
		gtk_grid_remove_row(GTK_GRID(m_Widget), position);
	}

	void Grid::RemoveColumn(int position)
	{
		gtk_grid_remove_column(GTK_GRID(m_Widget), position);
	}

	void Grid::RowHomogeneous(bool row_homogeneous)
	{
		gtk_grid_set_row_homogeneous(GTK_GRID(m_Widget), row_homogeneous);
	}

	bool Grid::RowHomogeneous()
	{
		return gtk_grid_get_row_homogeneous(GTK_GRID(m_Widget));
	}

	void Grid::RowSpacing(bool row_spacing)
	{
		gtk_grid_set_row_spacing(GTK_GRID(m_Widget), row_spacing);
	}

	bool Grid::RowSpacing()
	{
		return gtk_grid_get_row_spacing(GTK_GRID(m_Widget));
	}

	void Grid::ColumnHomogeneous(bool column_homogeneous)
	{
		gtk_grid_set_column_homogeneous(GTK_GRID(m_Widget), column_homogeneous);
	}

	bool Grid::ColumnHomogeneous()
	{
		return gtk_grid_get_column_homogeneous(GTK_GRID(m_Widget));
	}

	void Grid::ColumnSpacing(bool column_spacing)
	{
		gtk_grid_set_column_spacing(GTK_GRID(m_Widget), column_spacing);
	}

	bool Grid::ColumnSpacing()
	{
		return gtk_grid_get_column_spacing(GTK_GRID(m_Widget));
	}

	void Grid::BaselineRow(int row)
	{
		gtk_grid_set_baseline_row(GTK_GRID(m_Widget), row);
	}

	int Grid::BaselineRow()
	{
		return gtk_grid_get_baseline_row(GTK_GRID(m_Widget));
	}

	void Grid::BaselinePosition(int row, CGui::BaselinePosition pos)
	{
		gtk_grid_set_row_baseline_position(GTK_GRID(m_Widget), row, (GtkBaselinePosition)pos);
	}

	CGui::BaselinePosition Grid::BaselinePosition(int row)
	{
		return (CGui::BaselinePosition)gtk_grid_get_row_baseline_position(GTK_GRID(m_Widget), row);
	}
	bool Grid::IsGrid()
	{
		return GTK_IS_GRID(m_Widget);
	}
}
