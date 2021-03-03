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
			TreePath(const TreePath& modal)
			{
				this->path = gtk_tree_path_copy(const_cast<TreePath&>(modal).GetWidget());
			}

			bool operator==(const TreePath& ins1)
			{
				return gtk_tree_path_compare(path, const_cast<TreePath&>(ins1).GetWidget());
			}

			TreePath(GtkTreePath* path)
			{
				this->path = path;
			}

			TreePath(bool new_first = false)
			{
				if (new_first)
					this->path = gtk_tree_path_new_first();
				else
					this->path = gtk_tree_path_new();
			}

			TreePath(const char* path)
			{
				this->path = gtk_tree_path_new_from_string(path);
			}

			TreePath(int indices[], unsigned int length)
			{
				this->path = gtk_tree_path_new_from_indicesv(indices, length);
			}

			const char* ToString()
			{
				return gtk_tree_path_to_string(path);
			}

			void AppendIndex(int index)
			{
				gtk_tree_path_append_index(path, index);
			}

			void PrependIndex(int index)
			{
				gtk_tree_path_prepend_index(path, index);
			}

			int Depth()
			{
				return gtk_tree_path_get_depth(path);
			}

			int* Indices()
			{
				return gtk_tree_path_get_indices(path);
			}

			IndicesAndDepthData IndicesWithDepth()
			{
				int* indices;
				int depth;

				indices = gtk_tree_path_get_indices_with_depth(path, &depth);
				return { indices, &depth };
			}

			void Free()
			{
				gtk_tree_path_free(path);
			}

			void Next()
			{
				gtk_tree_path_next(path);
			}

			bool Prev()
			{
				return gtk_tree_path_prev(path);
			}

			bool Up()
			{
				return gtk_tree_path_up(path);
			}

			void Down()
			{
				gtk_tree_path_down(path);
			}

			bool IsAncestor(TreePath& modal)
			{
				return gtk_tree_path_is_ancestor(path, modal.GetWidget());
			}

			bool IsDescendant(TreePath& modal)
			{
				return gtk_tree_path_is_descendant(path, modal.GetWidget());
			}

			GtkTreePath* GetWidget()
			{
				return path;
			}

		protected:
			GtkTreePath* path;
		};

		class TreeRowReference
		{
		public:
			TreeRowReference(const TreeRowReference& ins)
			{
				this->reference = gtk_tree_row_reference_copy(const_cast<TreeRowReference&>(ins).GetWidget());
			}

			TreeRowReference(TreeModel& modal, TreeModel::TreePath& path)
			{
				this->reference = gtk_tree_row_reference_new(modal.GetWidget(), path.GetWidget());
			}

			TreeRowReference(TreeRowReference& copy)
			{
				this->reference = gtk_tree_row_reference_copy(copy.GetWidget());
			}

			TreeModel Modal()
			{
				return TreeModel(gtk_tree_row_reference_get_model(reference));
			}

			TreeModel::TreePath TreePath()
			{
				return TreeModel::TreePath(gtk_tree_row_reference_get_path(reference));
			}

			bool Valid()
			{
				return gtk_tree_row_reference_valid(reference);
			}

			void Free()
			{
				gtk_tree_row_reference_free(reference);
			}

			GtkTreeRowReference* GetWidget()
			{
				return reference;
			}

		protected:
			GtkTreeRowReference* reference;
		};

		class TreeIter
		{
		public:
			TreeIter() = default;

			TreeIter(GtkTreeIter* iter)
			{
				this->iter = iter;
			}

			TreeIter(const TreeIter& iter)
			{
				this->iter = gtk_tree_iter_copy(const_cast<TreeIter&>(iter).GetWidget());
			}

			void Free()
			{
				gtk_tree_iter_free(iter);
			}

			GtkTreeIter* GetWidget()
			{
				return iter;
			}

		protected:
			GtkTreeIter* iter;
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
			this->model = model;
		}

		TreeModelFlags Flags()
		{
			return (TreeModelFlags)gtk_tree_model_get_flags(model);
		}

		int NColumns()
		{
			return gtk_tree_model_get_n_columns(model);
		}

		Type ColumnType(int index)
		{
			return (Type)gtk_tree_model_get_column_type(model, index);
		}

		IterData Iter()
		{
			GtkTreeIter iter;
			GtkTreePath* path = nullptr;
			bool was_set;

			was_set = gtk_tree_model_get_iter(model, &iter, path);

			return { TreeModel::TreeIter(&iter), TreeModel::TreePath(path), was_set };
		}

		IterListData IterFromString(const char* path_string)
		{
			GtkTreeIter* iter = nullptr;
			bool was_set;

			was_set = gtk_tree_model_get_iter_from_string(model, iter, path_string);

			return { TreeModel::TreeIter(iter), was_set };
		}

		IterListData IterFirst()
		{
			GtkTreeIter* iter = nullptr;
			bool was_set;

			was_set = gtk_tree_model_get_iter_first(model, iter);

			return { TreeModel::TreeIter(iter), was_set };
		}

		TreeModel::TreePath Path(TreeModel::TreeIter& iter)
		{
			return TreeModel::TreePath(gtk_tree_model_get_path(model, iter.GetWidget()));
		}

		Value Value(TreeModel::TreeIter& iter, int column)
		{
			GValue value;

			gtk_tree_model_get_value(model, iter.GetWidget(), column, &value);

			return std::move(CGui::Value(&value));
		}

		template <typename N>
		void Get(TreeModel::TreeIter& iter, N column)
		{
			static_assert(false, "[Getter]: Missing reference(&) value parameter.");
		}

		template <typename N, typename value>
		void Get(TreeModel::TreeIter& iter, N column, value data)
		{
			static_assert(std::is_same_v<int, N>, "[Getter]: Unknown type of indexing columns.");

			gtk_tree_model_get(model, iter.GetWidget(), column, data, -1);
		}

		template <typename N, typename value, typename ... RS>
		void Get(TreeModel::TreeIter& iter, N column, value data, RS ... rest)
		{
			Get(iter, column, data);
			Get(iter, rest...);
		}


		bool IterNext(TreeModel::TreeIter& iter)
		{
			return gtk_tree_model_iter_next(model, iter.GetWidget());
		}

		bool IterPrevious(TreeModel::TreeIter& iter)
		{
			return gtk_tree_model_iter_previous(model, iter.GetWidget());
		}

		bool IterChildren(TreeModel::TreeIter& iter, TreeModel::TreeIter& parent)
		{
			return gtk_tree_model_iter_children(model, iter.GetWidget(), parent.GetWidget());
		}

		bool IterHasChild(TreeModel::TreeIter& iter)
		{
			return gtk_tree_model_iter_has_child(model, iter.GetWidget());
		}

		int IterNChildren(TreeModel::TreeIter& iter)
		{
			return gtk_tree_model_iter_n_children(model, iter.GetWidget());
		}

		bool IterNthChild(TreeModel::TreeIter& iter, TreeModel::TreeIter& parent, int index)
		{
			return gtk_tree_model_iter_nth_child(model, iter.GetWidget(), parent.GetWidget(), index);
		}

		bool IterParent(TreeModel::TreeIter& iter, TreeModel::TreeIter& child)
		{
			return gtk_tree_model_iter_parent(model, iter.GetWidget(), child.GetWidget());
		}

		const char* StringFromIter(TreeModel::TreeIter& iter)
		{
			return gtk_tree_model_get_string_from_iter(model, iter.GetWidget());
		}

		void RefNode(TreeModel::TreeIter& iter)
		{
			gtk_tree_model_ref_node(model, iter.GetWidget());
		}

		void UnrefNode(TreeModel::TreeIter& iter)
		{
			gtk_tree_model_unref_node(model, iter.GetWidget());
		}

		void RowChanged(TreeModel::TreePath& path, TreeModel::TreeIter& iter)
		{
			gtk_tree_model_row_changed(model, path.GetWidget(), iter.GetWidget());
		}

		void RowInserted(TreeModel::TreePath& path, TreeModel::TreeIter& iter)
		{
			gtk_tree_model_row_inserted(model, path.GetWidget(), iter.GetWidget());
		}

		void RowHasChildToggled(TreeModel::TreePath& path, TreeModel::TreeIter& iter)
		{
			gtk_tree_model_row_has_child_toggled(model, path.GetWidget(), iter.GetWidget());
		}

		void RowDeleted(TreeModel::TreePath& path)
		{
			gtk_tree_model_row_deleted(model, path.GetWidget());
		}

		void RowsReordered(TreeModel::TreePath& path, TreeModel::TreeIter& iter, int* new_order)
		{
			gtk_tree_model_rows_reordered(model, path.GetWidget(), iter.GetWidget(), new_order);
		}

		void RowsReorderedWithLength(TreeModel::TreePath& path, TreeModel::TreeIter& iter, int* new_order, int length)
		{
			gtk_tree_model_rows_reordered_with_length(model, path.GetWidget(), iter.GetWidget(), new_order, length);
		}

		GtkTreeModel* GetWidget()
		{
			return model;
		}

		bool IsTreeModal()
		{
			return GTK_IS_TREE_MODEL(model);
		}

	protected:
		TreeModel() = default;

		GtkTreeModel* model;
	};
}