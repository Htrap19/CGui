#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Notebook : public Widget, public Container<Notebook>
	{
	public:
		Notebook();
		void AppendPage(Widget& child, Widget& tab_label);
		void AppendPageMenu(Widget& child, Widget& tab_label, Widget& menu_label);
		void PrependPage(Widget& child, Widget& tab_label);
		void PrependPageMenu(Widget& child, Widget& tab_label, Widget& menu_label);
		void InsertPage(Widget& child, Widget& tab_label, int position);
		void InsertPageMenu(Widget& child, Widget& tab_label, Widget& menu_label, int position);
		void RemovePage(int page_num);
		void DetachTab(Widget& child);
		int PageNum(Widget& child);
		void NextPage();
		void PrevPage();
		void ReorderChild(Widget& child, int position);
		void TabPos(PositionType type);
		PositionType TabPos();
		void ShowTabs(bool show_tabs);
		bool ShowTabs();
		void ShowBorder(bool show_border);
		bool ShowBorder();
		void Scrollable(bool scrollable);
		void PopupEnable();
		void PopupDisable();
		void CurrentPage(int page_num);
		int CurrentPage();
		Widget NthPages(int page_num);
		int NumPage();
		void MenuLabel(Widget& child, Widget& menu_label);
		Widget MenuLabel(Widget& child);
		void MenuLabelText(Widget& child, const char* menu_label);
		const char* MenuLabelText(Widget& child);
		void TabLabel(Widget& child, Widget& tab_label);
		Widget TabLabel(Widget& child);
		void TabLabelText(Widget& child, const char* tab_label);
		const char* TabLabelText(Widget& child);
		void TabReorderable(Widget& child, bool reorderable);
		bool TabReorderable(Widget& child);
		void TabDetachable(Widget& child, bool detachable);
		bool TabDetachable(Widget& child);
		void GroupName(const char* name);
		const char* GroupName();
		void ActionWidget(Widget& child, PackType type);
		Widget ActionWidget(PackType type);
	};
}