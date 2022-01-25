#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Scrollable.hh"
#include "../TreeModel.hh"
#include "../../Cell/CellRenderer/CellRenderer.hh"
#include "../TreeView/ListStore/ListStore.hh"

namespace CGui
{
	class IconView : public virtual Widget, public virtual Container<IconView>, public virtual Scrollable
	{
	public:
		struct ItemAsPosData
		{
			TreeModel::TreePath path;
			CellRenderer cell;
			bool exists;
		};

		struct VisibleRangeData
		{
			TreeModel::TreePath start_path;
			TreeModel::TreePath end_path;
			bool valid;
		};

	public:
		IconView();
		IconView(TreeModel& model);
		void Model(TreeModel& model);
		TreeModel Model();
		void TextColumn(int column);
		int TextColumn();
		void MarkupColumn(int column);
		int MarkupColumn();
		void PixbufColumn(int column);
		int PixbufColumn();
		TreeModel::TreePath PathAsPos(int x, int y);
		ItemAsPosData ItemAsPos(int x, int y);
		CoordinatesInfo ConvertWidgetToBinWindowCoords(int wx, int wy);
		void Cursor(TreeModel::TreePath path, CellRenderer cell, bool start_editing);
		ItemAsPosData Cursor();
		void SelectionMode(CGui::SelectionMode mode);
		CGui::SelectionMode SelectionMode();
		void ItemOrientation(Orientation orientation);
		Orientation ItemOrientation();
		void Columns(int columns);
		int Columns();
		void ItemWidth(int item_width);
		int ItemWidth();
		void Spacing(int spacing);
		int Spacing();
		void RowSpacing(int row_spacing);
		int RowSpacing();
		void ColumnSpacing(int columns_spacing);
		int ColumnSpacing();
		void Margin(int margin);
		int Margin();
		void ItemPadding(int item_padding);
		int ItemPadding();
		void ActivateOnSingleClick(bool single);
		bool ActivateOnSingleClick();
		PointingToData CellRect(TreeModel::TreePath path, CellRenderer cell);
		void SelectPath(TreeModel::TreePath path);
		void UnselectPath(TreeModel::TreePath path);
		bool PathIsSelected(TreeModel::TreePath path);
		Vector<TreeModel::TreePath> SelectedItems();
		void SelectAll();
		void UnselectAll();
		void ItemActivated(TreeModel::TreePath path);
		void ScrollToPath(TreeModel::TreePath path, bool use_align, float row_align, float col_align);
		VisibleRangeData VisibleRange();
		int ItemRow(TreeModel::TreePath path);
		int ItemColumn(TreeModel::TreePath path);
		void Reorderable(bool reorderable);
		bool Reorderable();

		bool IsIconView();

		ListStore& Store();
		TreeModel::TreeIter Append(const char* str, Pixbuf& icon);
		TreeModel::TreeIter Prepend(const char* str, Pixbuf& icon);

	protected:
		void Insert(TreeModel::TreeIter& iter, const char* str, Pixbuf& icon);

	private:
		ListStore m_DefaultStore;
	};
}