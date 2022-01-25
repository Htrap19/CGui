#pragma once

#include <vector>
#include "../../../Converter/Convert.hh"
#include "../../TreeModel.hh"
#include "../../../Custom/List/List.hh"
#include "../../../Pixbuf/Pixbuf/Pixbuf.hh"

namespace CGui
{
	class ListStore : public virtual TreeModel
	{
	public:
		ListStore(Type types[], int n_columns);
		ListStore(std::vector<Type> types);
		ListStore(TreeModel& model);
		void ColumnTypes(Type types[], int n_columns);
		bool Remove(TreeIter& iter);
		template <typename N, typename value>
		void Set(TreeModel::TreeIter& iter, N column, value data);
		template <typename N, typename value, typename ... RS>
		void Set(TreeModel::TreeIter& iter, N column, value data, RS ... rest);
		TreeModel::TreeIter Insert(int position);
		TreeModel::TreeIter InsertBefore(TreeIter& sibling);
		TreeModel::TreeIter InsertAfter(TreeIter& sibling);
		TreeModel::TreeIter Append();
		TreeModel::TreeIter Prepend();
		void Clear();
		bool IterIsValid(TreeIter& iter);
		void Reorder(int new_order[]);
		void Swap(TreeModel::TreeIter& a, TreeModel::TreeIter& b);
		void MoveAfter(TreeModel::TreeIter& iter, TreeModel::TreeIter& position);
		void MoveBefore(TreeModel::TreeIter& iter, TreeModel::TreeIter& position);

		GtkListStore* GetWidget();

		bool IsListStore();

	protected:
		ListStore() = default;

		template <typename N> // Only for determination of missing value args
		void Set(TreeModel::TreeIter& iter, N column);

		GtkListStore* store;
	};

	template <typename N>
	// Only for determination of missing value args
	void CGui::ListStore::Set(TreeModel::TreeIter& iter, N column)
	{
		static_assert(false, "[Setter]: Missing value parameter!");
	}

	template <typename N, typename value>
	void CGui::ListStore::Set(TreeModel::TreeIter& iter, N column, value data)
	{
		static_assert(std::is_same_v<int, N>, "[Setter]: Unknown type of indexing column.");

		if constexpr (std::is_same_v<Pixbuf, value>)
			gtk_list_store_set(store, iter.GetWidget(), column, data.GetWidget(), -1);
		else
			gtk_list_store_set(store, iter.GetWidget(), column, data, -1);
	}

	template <typename N, typename value, typename ... RS>
	void CGui::ListStore::Set(TreeModel::TreeIter& iter, N column, value data, RS ... rest)
	{
		Set(iter, column, data);
		Set(iter, rest...);
	}
}