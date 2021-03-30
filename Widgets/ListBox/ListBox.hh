#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../../Custom/List/List.hh"
#include "../../Misc/Adjustment/Adjustment.hh"

namespace CGui
{
	class ListBox : public virtual Widget, public virtual Container<ListBox>
	{
	public:
		class Row : public virtual Widget, public virtual Container<Row>
		{
		public:
			Row();
			Row(GtkListBoxRow* row);
			void Changed();
			bool IsSelected();
			void Header(Widget& header);
			Widget Header();
			int Index();
			void Activatable(bool activatable);
			bool Activatable();
			void Selectable(bool selectable);
			bool Selectable();

			bool IsRow();
		};

		ListBox();
		ListBox(GtkListBox* list_box);
		void Prepend(Widget& child);
		void Insert(Widget& child, int pos);
		void SelectRow(Row& row);
		void UnselectRow(Row& row);
		void SelectAll();
		void UnselectAll();
		ListBox::Row SelectedRow();
		Vector<Widget> SelectedRows();
		void SelectionMode(CGui::SelectionMode mode);
		CGui::SelectionMode SelectionMode();
		void ActivateOnSingleClick(bool activate);
		bool ActivateOnSingleClick();
		void Adjustment(CGui::Adjustment adjustment);
		CGui::Adjustment Adjustment();
		void PlaceHolder(Widget& placeholder);
		ListBox::Row RowAtIndex(int index);
		ListBox::Row RowAtY(int y);
		void InvalidateFilter();
		void InvalidateHeader();
		void InvalidateSort();
		void DragHighlightRow(ListBox::Row& row);
		void DragUnhighlightRow(ListBox::Row& row);
		bool IsListBox();
	};
}