#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class ToolItem : public virtual Widget, public virtual Container<ToolItem>
	{
	public:
		ToolItem();
		ToolItem(GtkToolItem* item);
		void Homogeneous(bool homogeneous);
		bool Homogeneous();
		void ItemExpand(bool expand);
		bool ItemExpand();
		void TooltipText(const char* text);
		void TooltipMarkup(const char* markup);
		void UseDragWindow(bool use);
		bool UseDragWindow();
		void VisibleHorizontal(bool visible);
		bool VisibleHorizontal();
		void VisibleVertical(bool visible);
		bool VisibleVertical();
		void IsImportant(bool is_important);
		bool IsImportant();
		Widget RetrieveProxyMenuItem();
		void ProxyMenuItem(const char* menu_id, Widget& child);
		Widget ProxyMenuItem(const char* menu_id);
		void ToolbarReconfigured();

		bool IsToolItem();
	};
}