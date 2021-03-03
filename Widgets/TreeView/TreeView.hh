#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Scrollable.hh"
#include "../TreeModel.hh"
#include "./TreeSelection/TreeSelection.hh"
#include "./TreeViewColumn/TreeViewColumn.hh"
#include "../Entry/Entry.hh"

namespace CGui
{
	class TreeView : public virtual Widget, public virtual Container<TreeView>, public virtual Scrollable
	{
	public:
		struct CursorData
		{
			TreeModel::TreePath path;
			TreeViewColumn focus_column;
		};

		struct PathFromPosData
		{
			TreeModel::TreePath path;
			TreeViewColumn column;
			int cell_x, cell_y;
			bool row_exists;
		};

		struct VisibleRangeData
		{
			TreeModel::TreePath start_path, end_path;
			bool valid_paths;
		};

		struct DragDestRowData
		{
			TreeModel::TreePath path;
			TreeViewDropPosition pos;
		};

		TreeView();
		TreeView(GtkTreeView* view);
		TreeView(TreeModel& model);
		void LevelIndentation(int indentation);
		int LevelIndentation();
		void ShowExpanders(bool show);
		bool ShowExpanders();
		void Model(TreeModel& tree_model);
		TreeModel Model();
		TreeSelection Selection();
		void HeadersVisible(bool visible);
		bool HeadersVisible();
		void ColumnsAutosize();
		void HeadersClickable(bool clickable);
		bool HeadersClickable();
		void ActivateOnSingleClick(bool activate);
		bool ActivateOnSingleClick();
		void AppendColumn(TreeViewColumn& column);
		void RemoveColumn(TreeViewColumn& column);
		void InsertColumn(TreeViewColumn& column, int position);
		unsigned int NColumns();
		TreeViewColumn Column(int n);
		Single::List<TreeViewColumn> Columns();
		void MoveColumnAfter(TreeViewColumn& column, TreeViewColumn& base_column);
		void ExpanderColumn(TreeViewColumn& column);
		TreeViewColumn ExpanderColumn();
		void ScrollToPoint(int tree_x, int tree_y);
		void ScrollToCell(TreeModel::TreePath& path, TreeViewColumn& column, bool use_align, float row_align, float col_align);
		void Cursor(TreeModel::TreePath& path, TreeViewColumn& focus_column, bool start_editing);
		void CursorOnCell(TreeModel::TreePath& path, TreeViewColumn& focus_column, CellRenderer& focus_cell, bool start_editing);
		CursorData Cursor();
		void RowActivated(TreeModel::TreePath& path, TreeViewColumn& column);
		void ExpandAll();
		void CollapseAll();
		void ExpandToPath(TreeModel::TreePath& path);
		bool ExpandRow(TreeModel::TreePath& path, bool open_all);
		bool CollapseRow(TreeModel::TreePath& path);
		bool RowExpanded(TreeModel::TreePath& path);
		void Reorderable(bool reorderable);
		bool Reorderable();
		PathFromPosData PathAtPos(int x, int y);
		PathFromPosData IsBlankAtPos(int x, int y);
		Rectangle CellArea(TreeModel::TreePath& path, TreeViewColumn& column);
		Rectangle BackgroundArea(TreeModel::TreePath& path, TreeViewColumn& column);
		VisibleRangeData VisibleRange();
		CoordinatesInfo ConvertBinWindowToTreeCoords(int bx, int by);
		CoordinatesInfo ConvertBinWindowToWidgetCoords(int bx, int by);
		CoordinatesInfo ConvertTreeToBinWindowCoords(int tx, int ty);
		CoordinatesInfo ConvertTreeToWidgetCoords(int tx, int ty);
		CoordinatesInfo ConvertWidgetToBinWindowCoords(int wx, int wy);
		CoordinatesInfo ConvertWidgetToTreeCoords(int wx, int wy);
		void UnsetRowsDragSource();
		void UnsetRowsDragDest();
		void DragDestRow(TreeModel::TreePath& path, TreeViewDropPosition pos);
		DragDestRowData DragDestRow();
		DragDestRowData DragDestRowAtPos(int drag_x, int drag_y);
		void EnableSearch(bool enable);
		bool EnableSearch();
		void SearchColumn(int column);
		int SearchColumn();
		void SearchEntry(CGui::Entry& entry);
		CGui::Entry SearchEntry();
		void FixedHeightMode(bool enable);
		bool FixedHeightMode();
		void HoverSelection(bool selection);
		bool HoverSelection();
		void HoverExpand(bool expand);
		bool HoverExpand();
		void RubberBanding(bool enable);
		bool RubberBanding();
		bool IsRubberBandingActive();
		void EnableTreeLines(bool enabled);
		bool EnableTreeLines();
		void GridLines(TreeViewGridLines grid_lines);
		TreeViewGridLines GridLines();
		void TooltipColumn(int column);
		int TooltipColumn();

		bool IsTreeView();
	};
}