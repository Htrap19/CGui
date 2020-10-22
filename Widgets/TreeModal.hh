#pragma once

#include <gtk/gtk.h>
#include "../Converter/Convert.hh"

namespace CGui
{
	class TreeModal
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
				int* depth;

				indices = gtk_tree_path_get_indices_with_depth(path, depth);
				return { indices, depth };
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
			TreeRowReference(TreeModal& modal, TreeModal::TreePath& path)
			{
				this->reference = gtk_tree_row_reference_new(modal.GetWidget(), path.GetWidget());
			}

			TreeRowReference(TreeRowReference& copy)
			{
				this->reference = gtk_tree_row_reference_copy(copy.GetWidget());
			}

			TreeModal Modal()
			{
				return TreeModal(gtk_tree_row_reference_get_model(reference));
			}

			TreeModal::TreePath TreePath()
			{
				return TreeModal::TreePath(gtk_tree_row_reference_get_path(reference));
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
			TreeModal::TreeIter iter;
			TreeModal::TreePath path;
			bool was_set;
		};

		struct IterListData
		{
			TreeModal::TreeIter iter;
			bool was_set;
		};

		TreeModal(GtkTreeModel* modal)
		{
			this->modal = modal;
		}

		TreeModalFlags Flags()
		{
			return (TreeModalFlags)gtk_tree_model_get_flags(modal);
		}

		int NColumns()
		{
			return gtk_tree_model_get_n_columns(modal);
		}

		IterData Iter()
		{
			GtkTreeIter* iter;
			GtkTreePath* path;
			bool was_set;

			was_set = gtk_tree_model_get_iter(modal, iter, path);

			return { TreeModal::TreeIter(iter), TreeModal::TreePath(path), was_set };
		}

		IterListData IterFromString(const char* path_string)
		{
			GtkTreeIter* iter;
			bool was_set;

			was_set = gtk_tree_model_get_iter_from_string(modal, iter, path_string);

			return { TreeModal::TreeIter(iter), was_set };
		}

		IterListData IterFirst()
		{
			GtkTreeIter* iter;
			bool was_set;

			was_set = gtk_tree_model_get_iter_first(modal, iter);

			return { TreeModal::TreeIter(iter), was_set };
		}

		GtkTreeModel* GetWidget()
		{
			return modal;
		}

		bool IsTreeModal()
		{
			return GTK_IS_TREE_MODEL(modal);
		}

	protected:
		GtkTreeModel* modal;
	};
}