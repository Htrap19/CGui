#pragma once

#include "../../../Converter/Convert.hh"
#include "../../TreeModel.hh"
#include "../../Menifest.hh"
#include "../../Handler.hh"
#include "../../../Custom/Vector/Vector.hh"

namespace CGui
{
	class TreeSelection : public virtual Handler<TreeSelection>
	{
	public:
		struct SelectionData
		{
			TreeModel model;
			TreeModel::TreeIter iter;
			bool is_selected;
		};

		struct SelectedRowsData
		{
			Vector<TreeModel::TreePath> rows;
			TreeModel model;
		};

		TreeSelection(GtkTreeSelection* selection);
		void Mode(SelectionMode mode);
		SelectionMode Mode();
		CGui::TreeView TreeView();
		SelectionData Selected();
		SelectedRowsData SelectedRows();
		int CountSelectedRows();
		void SelectPath(TreeModel::TreePath& path);
		void UnselectPath(TreeModel::TreePath& path);
		bool PathIsSelected(TreeModel::TreePath& path);
		void SelectIter(TreeModel::TreeIter& iter);
		void UnselectIter(TreeModel::TreeIter& iter);
		bool IterIsSelected(TreeModel::TreeIter& iter);
		void SelectAll();
		void UnselectAll();
		void SelectRange(TreeModel::TreePath& start_path, TreeModel::TreePath& end_path);
		void UnselectRange(TreeModel::TreePath& start_path, TreeModel::TreePath& end_path);

		GtkTreeSelection* GetWidget();

		bool IsTreeSelecion();

	private:
		GtkTreeSelection* selection;
	};
}