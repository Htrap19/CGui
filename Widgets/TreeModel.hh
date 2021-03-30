#pragma once

#include <gtk/gtk.h>
#include <utility>
#include "../Converter/Convert.hh"

namespace CGui
{
	class TreeModel
	{
	public:
		class TreePath
		{
		public:
			TreePath(const TreePath& modal);
			bool operator==(const TreePath& ins1);
			TreePath(GtkTreePath* path);
			TreePath(bool new_first = false);
			TreePath(const char* path);
			TreePath(int indices[], unsigned int length);
			const char* ToString();
			void AppendIndex(int index);
			void PrependIndex(int index);
			int Depth();
			int* Indices();
			IndicesAndDepthData IndicesWithDepth();
			void Free();
			void Next();
			bool Prev();
			bool Up();
			void Down();
			bool IsAncestor(TreePath& modal);
			bool IsDescendant(TreePath& modal);

			GtkTreePath* GetWidget();

		protected:
			GtkTreePath* m_Path;
		};

		class TreeRowReference
		{
		public:
			TreeRowReference(const TreeRowReference& ins);
			TreeRowReference(TreeModel& modal, TreeModel::TreePath& path);
			TreeRowReference(TreeRowReference& copy);
			TreeModel Modal();
			TreeModel::TreePath TreePath();
			bool Valid();
			void Free();

			GtkTreeRowReference* GetWidget();

		protected:
			GtkTreeRowReference* m_Reference;
		};

		class TreeIter
		{
		public:
			TreeIter() = default;
			TreeIter(GtkTreeIter iter);
			TreeIter(GtkTreeIter* iter);
			TreeIter(const TreeIter& iter);
			TreeModel::TreeIter Copy(TreeModel::TreeIter& iter);
			void Free();

			GtkTreeIter* GetWidget();

		protected:
			GtkTreeIter m_Iter;
		};

		struct IterData
		{
			TreeModel::TreeIter iter;
			TreeModel::TreePath path;
			bool was_set;
		};

		struct IterListData
		{
			TreeModel::TreeIter iter;
			bool was_set;
		};

		TreeModel(GtkTreeModel* model)
		{
			this->m_Model = model;
		}

		TreeModelFlags Flags();
		int NColumns();
		Type ColumnType(int index);
		IterData Iter();
		IterListData IterFromString(const char* path_string);
		IterListData IterFirst();
		TreeModel::TreePath Path(TreeModel::TreeIter& iter);

		template <typename N, typename value>
		void Get(TreeModel::TreeIter& iter, N column, value data);
		template <typename N, typename value, typename ... RS>
		void Get(TreeModel::TreeIter& iter, N column, value data, RS ... rest);

		bool IterNext(TreeModel::TreeIter& iter);
		bool IterPrevious(TreeModel::TreeIter& iter);
		bool IterChildren(TreeModel::TreeIter& iter, TreeModel::TreeIter& parent);
		bool IterHasChild(TreeModel::TreeIter& iter);
		int IterNChildren(TreeModel::TreeIter& iter);
		bool IterNthChild(TreeModel::TreeIter& iter, TreeModel::TreeIter& parent, int index);
		bool IterParent(TreeModel::TreeIter& iter, TreeModel::TreeIter& child);
		const char* StringFromIter(TreeModel::TreeIter& iter);
		void RefNode(TreeModel::TreeIter& iter);
		void UnrefNode(TreeModel::TreeIter& iter);
		void RowChanged(TreeModel::TreePath& path, TreeModel::TreeIter& iter);
		void RowInserted(TreeModel::TreePath& path, TreeModel::TreeIter& iter);
		void RowHasChildToggled(TreeModel::TreePath& path, TreeModel::TreeIter& iter);
		void RowDeleted(TreeModel::TreePath& path);
		void RowsReordered(TreeModel::TreePath& path, TreeModel::TreeIter& iter, int* new_order);
		void RowsReorderedWithLength(TreeModel::TreePath& path, TreeModel::TreeIter& iter, int* new_order, int length);
		GtkTreeModel* GetWidget();

		bool IsTreeModal();

	protected:
		TreeModel() = default;

		template <typename N>
		void Get(TreeModel::TreeIter& iter, N column);

		GtkTreeModel* m_Model;
	};

	template <typename N>
	void TreeModel::Get(TreeModel::TreeIter& iter, N column)
	{
		static_assert(false, "[Getter]: Missing reference(&) value parameter.");
	}

	template <typename N, typename value>
	void CGui::TreeModel::Get(TreeModel::TreeIter& iter, N column, value data)
	{
		static_assert(std::is_same_v<int, N>, "[Getter]: Unknown type of indexing columns.");

		gtk_tree_model_get(m_Model, iter.GetWidget(), column, data, -1);
	}

	template <typename N, typename value, typename ... RS>
	void TreeModel::Get(TreeModel::TreeIter& iter, N column, value data, RS ... rest)
	{
		Get(iter, column, data);
		Get(iter, rest...);
	}
}