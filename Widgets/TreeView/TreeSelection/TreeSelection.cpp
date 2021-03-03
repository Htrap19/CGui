#include "./TreeSelection.hh"

#include "../TreeView.hh"

namespace CGui
{

	TreeSelection::TreeSelection(GtkTreeSelection* selection) : Handler(this)
	{
		this->selection = selection;
	}

	void TreeSelection::Mode(SelectionMode mode)
	{
		gtk_tree_selection_set_mode(selection, (GtkSelectionMode)mode);
	}

	CGui::SelectionMode TreeSelection::Mode()
	{
		return (SelectionMode)gtk_tree_selection_get_mode(selection);
	}

	CGui::TreeView TreeSelection::TreeView()
	{
		return CGui::TreeView(gtk_tree_selection_get_tree_view(selection));
	}

	TreeSelection::SelectionData TreeSelection::Selected()
	{
		GtkTreeModel* model;
		GtkTreeIter iter;
		bool is_selected;

		is_selected = gtk_tree_selection_get_selected(selection, &model, &iter);

		return { TreeModel(model), TreeModel::TreeIter(&iter), is_selected };
	}

	TreeSelection::SelectedRowsData TreeSelection::SelectedRows()
	{
		GtkTreeModel* model;
		Single::List<TreeModel::TreePath> ret;
		auto g_list = gtk_tree_selection_get_selected_rows(selection, &model);

		for (GList* it = g_list; it != NULL; it = g_list_next(it))
		{
			ret.Insert(TreeModel::TreePath((GtkTreePath*)it->data));
		}


		// Note the path should be freed with Path::Free() method to free allocated memory
		return { ret, TreeModel(model) };
	}

	int TreeSelection::CountSelectedRows()
	{
		return gtk_tree_selection_count_selected_rows(selection);
	}

	void TreeSelection::SelectPath(TreeModel::TreePath& path)
	{
		gtk_tree_selection_select_path(selection, path.GetWidget());
	}

	void TreeSelection::UnselectPath(TreeModel::TreePath& path)
	{
		gtk_tree_selection_unselect_path(selection, path.GetWidget());
	}

	bool TreeSelection::PathIsSelected(TreeModel::TreePath& path)
	{
		return gtk_tree_selection_path_is_selected(selection, path.GetWidget());
	}

	void TreeSelection::SelectIter(TreeModel::TreeIter& iter)
	{
		gtk_tree_selection_select_iter(selection, iter.GetWidget());
	}

	void TreeSelection::UnselectIter(TreeModel::TreeIter& iter)
	{
		gtk_tree_selection_unselect_iter(selection, iter.GetWidget());
	}

	bool TreeSelection::IterIsSelected(TreeModel::TreeIter& iter)
	{
		return gtk_tree_selection_iter_is_selected(selection, iter.GetWidget());
	}

	void TreeSelection::SelectAll()
	{
		gtk_tree_selection_select_all(selection);
	}

	void TreeSelection::UnselectAll()
	{
		gtk_tree_selection_unselect_all(selection);
	}

	void TreeSelection::SelectRange(TreeModel::TreePath& start_path, TreeModel::TreePath& end_path)
	{
		gtk_tree_selection_select_range(selection, start_path.GetWidget(), end_path.GetWidget());
	}

	void TreeSelection::UnselectRange(TreeModel::TreePath& start_path, TreeModel::TreePath& end_path)
	{
		gtk_tree_selection_unselect_range(selection, start_path.GetWidget(), end_path.GetWidget());
	}

	GtkTreeSelection* TreeSelection::GetWidget()
	{
		return selection;
	}

	bool TreeSelection::IsTreeSelecion()
	{
		return GTK_IS_TREE_SELECTION(selection);
	}

}