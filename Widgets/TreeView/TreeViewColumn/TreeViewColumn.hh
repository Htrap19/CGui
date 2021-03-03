#pragma once

#include <gtk/gtk.h>
#include "../../../Cell/CellRenderer/CellRenderer.hh"
#include "../../TreeModel.hh"
#include "../../Menifest.hh"

namespace CGui
{
	class TreeViewColumn
	{
	public:
		TreeViewColumn();
		TreeViewColumn(const char* title, CellRenderer& cell_renderer, bool expand, bool bind = true, PackType type = PackType::START);
		TreeViewColumn(GtkTreeViewColumn* column);
		void PackStart(CellRenderer& cell_renderer, bool expand);
		void PackEnd(CellRenderer& cell_renderer, bool expand);
		void Clear();
		void AddAttribute(CellRenderer& cell_renderer, const char* attribute);
		void AddAttribute(CellRenderer& cell_renderer, const char* attribute, int column);
		void ClearAttributes(CellRenderer& cell_renderer);
		void Spacing(int spacing);
		int Spacing();
		void Visible(bool visible);
		bool Visible();
		void Resizable(bool resizable);
		bool Resizable();
		void Sizing(TreeViewColumnSizing type);
		TreeViewColumnSizing Sizing();
		int Width();
		void FixedWidth(int fixed_width);
		int FixedWidth();
		void MinWidth(int min_width);
		int MinWidth();
		void MaxWidth(int max_width);
		int MaxWidth();
		void Clicked();
		void Title(const char* title);
		const char* Title();
		void Expand(bool expand);
		bool Expand();
		void Clickable(bool clickable);
		bool Clickable();
		void Widget(Widget& widget);
		CGui::Widget Widget();
		CGui::Button Button();
		void Alignment(float xalign);
		float Alignment();
		void Reorderable(bool reorderable);
		bool Reorderable();
		void SortColumnId(int sort_column_id);
		int SortColumnId();
		void SortIndicator(bool indicator);
		bool SortIndicator();
		void SortOrder(CGui::SortType type);
		CGui::SortType SortOrder();
		void CellSetCellData(TreeModel& tree_model, TreeModel::TreeIter& iter, bool is_expander, bool is_expanded);
		Rectangle CellSize(Rectangle cell_area);
		CellPositionData CellPosition(CellRenderer& cell_renderer);
		bool CellIsVisible();
		void FocusCell(CellRenderer& cell_renderer);
		void QueueResize();
		CGui::TreeView TreeView();
		int XOffset();

		GtkTreeViewColumn* GetWidget();
		int Index();

		bool IsTreeViewColumn();

	protected:
		static int increment_index;
		int index;

	private:
		GtkTreeViewColumn* column;
	};
}