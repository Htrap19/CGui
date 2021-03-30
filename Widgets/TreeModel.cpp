#include "./TreeModel.hh"

namespace CGui
{

	TreeModel::TreePath::TreePath(int indices[], unsigned int length)
	{
		this->m_Path = gtk_tree_path_new_from_indicesv(indices, length);
	}

	TreeModel::TreePath::TreePath(const char* path)
	{
		this->m_Path = gtk_tree_path_new_from_string(path);
	}

	TreeModel::TreePath::TreePath(bool new_first /*= false*/)
	{
		if (new_first)
			this->m_Path = gtk_tree_path_new_first();
		else
			this->m_Path = gtk_tree_path_new();
	}

	TreeModel::TreePath::TreePath(GtkTreePath* path)
	{
		this->m_Path = path;
	}

	TreeModel::TreePath::TreePath(const TreePath& modal)
	{
		this->m_Path = gtk_tree_path_copy(const_cast<TreePath&>(modal).GetWidget());
	}

	bool TreeModel::TreePath::operator==(const TreePath& ins1)
	{
		return gtk_tree_path_compare(m_Path, const_cast<TreePath&>(ins1).GetWidget());
	}

	const char* TreeModel::TreePath::ToString()
	{
		return gtk_tree_path_to_string(m_Path);
	}

	void TreeModel::TreePath::AppendIndex(int index)
	{
		gtk_tree_path_append_index(m_Path, index);
	}

	void TreeModel::TreePath::PrependIndex(int index)
	{
		gtk_tree_path_prepend_index(m_Path, index);
	}

	int TreeModel::TreePath::Depth()
	{
		return gtk_tree_path_get_depth(m_Path);
	}

	int* TreeModel::TreePath::Indices()
	{
		return gtk_tree_path_get_indices(m_Path);
	}

	CGui::IndicesAndDepthData TreeModel::TreePath::IndicesWithDepth()
	{
		int* indices;
		int depth;

		indices = gtk_tree_path_get_indices_with_depth(m_Path, &depth);
		return { indices, &depth };
	}

	void TreeModel::TreePath::Free()
	{
		gtk_tree_path_free(m_Path);
	}

	void TreeModel::TreePath::Next()
	{
		gtk_tree_path_next(m_Path);
	}

	bool TreeModel::TreePath::Prev()
	{
		return gtk_tree_path_prev(m_Path);
	}

	bool TreeModel::TreePath::Up()
	{
		return gtk_tree_path_up(m_Path);
	}

	void TreeModel::TreePath::Down()
	{
		gtk_tree_path_down(m_Path);
	}

	bool TreeModel::TreePath::IsAncestor(TreePath& modal)
	{
		return gtk_tree_path_is_ancestor(m_Path, modal.GetWidget());
	}

	bool TreeModel::TreePath::IsDescendant(TreePath& modal)
	{
		return gtk_tree_path_is_descendant(m_Path, modal.GetWidget());
	}

	GtkTreePath* TreeModel::TreePath::GetWidget()
	{
		return m_Path;
	}

	TreeModel::TreeRowReference::TreeRowReference(TreeRowReference& copy)
	{
		this->m_Reference = gtk_tree_row_reference_copy(copy.GetWidget());
	}

	TreeModel::TreeRowReference::TreeRowReference(TreeModel& modal, TreeModel::TreePath& path)
	{
		this->m_Reference = gtk_tree_row_reference_new(modal.GetWidget(), path.GetWidget());
	}

	TreeModel::TreeRowReference::TreeRowReference(const TreeRowReference& ins)
	{
		this->m_Reference = gtk_tree_row_reference_copy(const_cast<TreeRowReference&>(ins).GetWidget());
	}

	CGui::TreeModel TreeModel::TreeRowReference::Modal()
	{
		return TreeModel(gtk_tree_row_reference_get_model(m_Reference));
	}

	CGui::TreeModel::TreePath TreeModel::TreeRowReference::TreePath()
	{
		return TreeModel::TreePath(gtk_tree_row_reference_get_path(m_Reference));
	}

	bool TreeModel::TreeRowReference::Valid()
	{
		return gtk_tree_row_reference_valid(m_Reference);
	}

	void TreeModel::TreeRowReference::Free()
	{
		gtk_tree_row_reference_free(m_Reference);
	}

	GtkTreeRowReference* TreeModel::TreeRowReference::GetWidget()
	{
		return m_Reference;
	}

	TreeModel::TreeIter::TreeIter(const TreeIter& iter)
	{
		this->m_Iter = *gtk_tree_iter_copy(const_cast<TreeIter&>(iter).GetWidget());
	}

	TreeModel::TreeIter::TreeIter(GtkTreeIter* iter)
	{
		this->m_Iter = *iter;
	}

	TreeModel::TreeIter::TreeIter(GtkTreeIter iter)
	{
		this->m_Iter = iter;
	}

	CGui::TreeModel::TreeIter TreeModel::TreeIter::Copy(TreeModel::TreeIter& iter)
	{
		return TreeModel::TreeIter(gtk_tree_iter_copy(iter.GetWidget()));
	}

	void TreeModel::TreeIter::Free()
	{
		gtk_tree_iter_free(&m_Iter);
	}

	GtkTreeIter* TreeModel::TreeIter::GetWidget()
	{
		return &m_Iter;
	}

	CGui::TreeModelFlags TreeModel::Flags()
	{
		return (TreeModelFlags)gtk_tree_model_get_flags(m_Model);
	}

	int TreeModel::NColumns()
	{
		return gtk_tree_model_get_n_columns(m_Model);
	}

	CGui::Type TreeModel::ColumnType(int index)
	{
		return (Type)gtk_tree_model_get_column_type(m_Model, index);
	}

	CGui::TreeModel::IterData TreeModel::Iter()
	{
		GtkTreeIter iter;
		GtkTreePath* path = nullptr;
		bool was_set;

		was_set = gtk_tree_model_get_iter(m_Model, &iter, path);

		return { TreeModel::TreeIter(iter), TreeModel::TreePath(path), was_set };
	}

	CGui::TreeModel::IterListData TreeModel::IterFromString(const char* path_string)
	{
		GtkTreeIter iter;
		bool was_set;

		was_set = gtk_tree_model_get_iter_from_string(m_Model, &iter, path_string);

		return { TreeModel::TreeIter(iter), was_set };
	}

	CGui::TreeModel::IterListData TreeModel::IterFirst()
	{
		GtkTreeIter iter;
		bool was_set;

		was_set = gtk_tree_model_get_iter_first(m_Model, &iter);

		return { TreeModel::TreeIter(iter), was_set };
	}

	CGui::TreeModel::TreePath TreeModel::Path(TreeModel::TreeIter& iter)
	{
		return TreeModel::TreePath(gtk_tree_model_get_path(m_Model, iter.GetWidget()));
	}

	bool TreeModel::IterNext(TreeModel::TreeIter& iter)
	{
		return gtk_tree_model_iter_next(m_Model, iter.GetWidget());
	}

	bool TreeModel::IterPrevious(TreeModel::TreeIter& iter)
	{
		return gtk_tree_model_iter_previous(m_Model, iter.GetWidget());
	}

	bool TreeModel::IterChildren(TreeModel::TreeIter& iter, TreeModel::TreeIter& parent)
	{
		return gtk_tree_model_iter_children(m_Model, iter.GetWidget(), parent.GetWidget());
	}

	bool TreeModel::IterHasChild(TreeModel::TreeIter& iter)
	{
		return gtk_tree_model_iter_has_child(m_Model, iter.GetWidget());
	}

	int TreeModel::IterNChildren(TreeModel::TreeIter& iter)
	{
		return gtk_tree_model_iter_n_children(m_Model, iter.GetWidget());
	}

	bool TreeModel::IterNthChild(TreeModel::TreeIter& iter, TreeModel::TreeIter& parent, int index)
	{
		return gtk_tree_model_iter_nth_child(m_Model, iter.GetWidget(), parent.GetWidget(), index);
	}

	bool TreeModel::IterParent(TreeModel::TreeIter& iter, TreeModel::TreeIter& child)
	{
		return gtk_tree_model_iter_parent(m_Model, iter.GetWidget(), child.GetWidget());
	}

	const char* TreeModel::StringFromIter(TreeModel::TreeIter& iter)
	{
		return gtk_tree_model_get_string_from_iter(m_Model, iter.GetWidget());
	}

	void TreeModel::RefNode(TreeModel::TreeIter& iter)
	{
		gtk_tree_model_ref_node(m_Model, iter.GetWidget());
	}

	void TreeModel::UnrefNode(TreeModel::TreeIter& iter)
	{
		gtk_tree_model_unref_node(m_Model, iter.GetWidget());
	}

	void TreeModel::RowChanged(TreeModel::TreePath& path, TreeModel::TreeIter& iter)
	{
		gtk_tree_model_row_changed(m_Model, path.GetWidget(), iter.GetWidget());
	}

	void TreeModel::RowInserted(TreeModel::TreePath& path, TreeModel::TreeIter& iter)
	{
		gtk_tree_model_row_inserted(m_Model, path.GetWidget(), iter.GetWidget());
	}

	void TreeModel::RowHasChildToggled(TreeModel::TreePath& path, TreeModel::TreeIter& iter)
	{
		gtk_tree_model_row_has_child_toggled(m_Model, path.GetWidget(), iter.GetWidget());
	}

	void TreeModel::RowDeleted(TreeModel::TreePath& path)
	{
		gtk_tree_model_row_deleted(m_Model, path.GetWidget());
	}

	void TreeModel::RowsReordered(TreeModel::TreePath& path, TreeModel::TreeIter& iter, int* new_order)
	{
		gtk_tree_model_rows_reordered(m_Model, path.GetWidget(), iter.GetWidget(), new_order);
	}

	void TreeModel::RowsReorderedWithLength(TreeModel::TreePath& path, TreeModel::TreeIter& iter, int* new_order, int length)
	{
		gtk_tree_model_rows_reordered_with_length(m_Model, path.GetWidget(), iter.GetWidget(), new_order, length);
	}

	GtkTreeModel* TreeModel::GetWidget()
	{
		return m_Model;
	}

	bool TreeModel::IsTreeModal()
	{
		return GTK_IS_TREE_MODEL(m_Model);
	}

}