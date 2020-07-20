#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../../Custom/List/List.hh"
#include "../../Misc/Adjustment/Adjustment.hh"

namespace CGui
{
	class ListBox : public Widget, public Container<ListBox>
	{
	public:
		class Row : public Widget, public Container<Row>
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
		};

		ListBox();
		void Prepend(Widget& child);
		void Insert(Widget& child, int pos);
		void SelectRow(Row& row);
		void UnselectRow(Row& row);
		void SelectAll();
		void UnselectAll();
		ListBox::Row SelectedRow();
		Single::List<Widget> SelectedRows();
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
	};
}