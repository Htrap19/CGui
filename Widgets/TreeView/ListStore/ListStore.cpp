#include "./ListStore.hh"

namespace CGui
{
	ListStore::ListStore(Type types[], int n_columns)
	{
		store = gtk_list_store_newv(n_columns, (GType*)types);
		model = GTK_TREE_MODEL(store);
	}

	ListStore::ListStore(std::vector<Type> types)
	{
		store = gtk_list_store_newv(types.size(), (GType*)&types[0]);
		model = GTK_TREE_MODEL(store);
	}

	void ListStore::ColumnTypes(Type types[], int n_columns)
	{
		gtk_list_store_set_column_types(store, n_columns, (GType*)types);
	}

	bool ListStore::Remove(TreeIter& iter)
	{
		return gtk_list_store_remove(store, iter.GetWidget());
	}

	CGui::TreeModel::TreeIter ListStore::Insert(int position)
	{
		GtkTreeIter iter;

		gtk_list_store_insert(store, &iter, position);

		return TreeModel::TreeIter(&iter);
	}

	CGui::TreeModel::TreeIter ListStore::InsertBefore(TreeIter& sibling)
	{
		GtkTreeIter iter;

		gtk_list_store_insert_before(store, &iter, sibling.GetWidget());

		return TreeModel::TreeIter(&iter);
	}

	CGui::TreeModel::TreeIter ListStore::InsertAfter(TreeIter& sibling)
	{
		GtkTreeIter iter;

		gtk_list_store_insert_after(store, &iter, sibling.GetWidget());

		return TreeModel::TreeIter(&iter);
	}

	CGui::TreeModel::TreeIter ListStore::Append()
	{
		GtkTreeIter iter;

		gtk_list_store_append(store, &iter);

		return TreeModel::TreeIter(&iter);
	}

	CGui::TreeModel::TreeIter ListStore::Prepend()
	{
		GtkTreeIter iter;

		gtk_list_store_prepend(store, &iter);

		return TreeModel::TreeIter(&iter);
	}

	void ListStore::Clear()
	{
		gtk_list_store_clear(store);
	}

	bool ListStore::IterIsValid(TreeIter& iter)
	{
		return gtk_list_store_iter_is_valid(store, iter.GetWidget());
	}

	void ListStore::Reorder(int new_order[])
	{
		gtk_list_store_reorder(store, (gint*)new_order);
	}

	void ListStore::Swap(TreeIter& a, TreeIter& b)
	{
		gtk_list_store_swap(store, a.GetWidget(), b.GetWidget());
	}

	void ListStore::MoveAfter(TreeIter& iter, TreeIter& position)
	{
		gtk_list_store_move_after(store, iter.GetWidget(), position.GetWidget());
	}

	void ListStore::MoveBefore(TreeIter& iter, TreeIter& position)
	{
		gtk_list_store_move_before(store, iter.GetWidget(), position.GetWidget());
	}

	GtkListStore* ListStore::GetWidget()
	{
		return store;
	}

	bool ListStore::IsListStore()
	{
		return GTK_IS_LIST_STORE(store);
	}

}