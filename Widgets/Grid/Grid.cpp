#include "Grid.hh"

namespace CGui
{
	Grid::Grid() : Container(this)
	{
		widget = gtk_grid_new();
		this->SetContext(widget);
	}

	void Grid::InsertRow(int position)
	{
		gtk_grid_insert_row(GTK_GRID(widget), position);
	}

	void Grid::InsertColumn(int position)
	{
		gtk_grid_insert_column(GTK_GRID(widget), position);
	}

	void Grid::RowHomogeneous(bool row_homogeneous)
	{
		gtk_grid_set_row_homogeneous(GTK_GRID(widget), row_homogeneous);
	}

	bool Grid::RowHomogeneous()
	{
		return gtk_grid_get_row_homogeneous(GTK_GRID(widget));
	}

	void Grid::RowSpacing(bool row_spacing)
	{
		gtk_grid_set_row_spacing(GTK_GRID(widget), row_spacing);
	}

	bool Grid::RowSpacing()
	{
		return gtk_grid_get_row_spacing(GTK_GRID(widget));
	}

	void Grid::ColumnHomogeneous(bool column_homogeneous)
	{
		gtk_grid_set_column_homogeneous(GTK_GRID(widget), column_homogeneous);
	}

	bool Grid::ColumnHomogeneous()
	{
		return gtk_grid_get_column_homogeneous(GTK_GRID(widget));
	}

	void Grid::ColumnSpacing(bool column_spacing)
	{
		gtk_grid_set_column_spacing(GTK_GRID(widget), column_spacing);
	}

	bool Grid::ColumnSpacing()
	{
		return gtk_grid_get_column_spacing(GTK_GRID(widget));
	}
}
