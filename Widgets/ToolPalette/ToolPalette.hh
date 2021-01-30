#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Orientable.hh"
#include "../Scrollable.hh"
#include "../ToolItemGroup/ToolItemGroup.hh"

namespace CGui
{
	class ToolPalette : public virtual Widget, public virtual Container<ToolPalette>, public virtual Orientable, public virtual Scrollable
	{
	public:
		ToolPalette();
		ToolPalette(GtkToolPalette* tool_palette);
		void Exclusive(ToolItemGroup& group, bool exclusive);
		bool Exclusive(ToolItemGroup& group);
		void Expand(ToolItemGroup& group, bool expand);
		bool Expand(ToolItemGroup& group);
		void GroupPosition(ToolItemGroup& group, int pos);
		int GroupPosition(ToolItemGroup& group);
		void IconSize(CGui::IconSize size);
		CGui::IconSize IconSize();
		void UnsetIconSize();
		void Style(ToolbarStyle style);
		ToolbarStyle Style();
		void UnsetStyle();
		void AddDragDest(Widget& w, DestDefaults flags, ToolPaletteDragTargets targets, DragAction action);
		ToolItemGroup DropGroup(int x, int y);
		ToolItem DropItem(int x, int y);
		void DragSource(ToolPaletteDragTargets targets);
		bool IsToolPalette();
	};
}