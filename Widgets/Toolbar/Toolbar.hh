#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Orientable.hh"
#include "../ToolShell.hh"
#include "../ToolItem/ToolItem.hh"

namespace CGui
{
	class Toolbar : public virtual Widget, public virtual Container<Toolbar>, public virtual Orientable, public virtual ToolShell
	{
	public:
		Toolbar();
		Toolbar(GtkToolbar* tool_bar);
		void Insert(ToolItem& item, int pos);
		int ItemIndex(ToolItem& item);
		int NumItems();
		ToolItem NthItem(int pos);
		int DropIndex(int x, int y);
		void DropHighlightItem(ToolItem& item, int index);
		void ShowArrow(bool show);
		bool ShowArrow();
		void UnsetIconSize();
		void IconSize(CGui::IconSize size);
		CGui::IconSize IconSize() override;
		void Style(ToolbarStyle style);
		void UnsetStyle();
		bool IsToolbar();
	};
}