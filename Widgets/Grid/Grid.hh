#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Grid : public Widget, public Container<Grid>
	{
	public:
		Grid();
		template <typename addtype> void Add(addtype &w, int left, int top, int width, int height);
		void InsertRow(int position);
		void InsertColumn(int position);
		void RowHomogeneous(bool row_homogeneous);
		bool RowHomogeneous();
		void RowSpacing(bool row_spacing);
		bool RowSpacing();
		void ColumnHomogeneous(bool column_homogeneous);
		bool ColumnHomogeneous();
		void ColumnSpacing(bool column_spacing);
		bool ColumnSpacing();
	};

	template <typename addtype> void Grid::Add(addtype& w, int left, int top, int width, int height)
	{
		gtk_grid_attach(GTK_GRID(widget), w.GetWidget(), left, top, width, height);
		children.Insert((void*)& w);
	}
}