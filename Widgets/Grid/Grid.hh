#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Orientable.hh"

namespace CGui
{
	class Grid : public virtual Widget, public virtual Container<Grid>, public virtual Orientable
	{
	public:
		Grid();
		Grid(GtkGrid* grid);
		void Add(Widget& w, int left, int top, int width, int height);
		void InsertRow(int position);
		void InsertColumn(int position);
		void RemoveRow(int position);
		void RemoveColumn(int position);
		void RowHomogeneous(bool row_homogeneous);
		bool RowHomogeneous();
		void RowSpacing(bool row_spacing);
		bool RowSpacing();
		void ColumnHomogeneous(bool column_homogeneous);
		bool ColumnHomogeneous();
		void ColumnSpacing(bool column_spacing);
		bool ColumnSpacing();
		void BaselineRow(int row);
		int BaselineRow();
		void BaselinePosition(int row, CGui::BaselinePosition pos);
		CGui::BaselinePosition BaselinePosition(int row);
		bool IsGrid();
	};
}