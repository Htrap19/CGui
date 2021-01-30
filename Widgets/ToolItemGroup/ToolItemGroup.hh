#pragma once

#include "../ToolShell.hh"
#include "../Widget.hh"
#include "../Container.hh"
#include "../ToolItem/ToolItem.hh"

namespace CGui
{
	class ToolItemGroup : public virtual Widget, public virtual Container<ToolItemGroup>, public virtual ToolShell
	{
	public:
		ToolItemGroup(GtkToolItemGroup* group);
		ToolItemGroup(const char* label);
		void Collapsed(bool collapsed);
		bool Collapsed();
		void EllipsizeMode(CGui::EllipsizeMode mode);
		CGui::EllipsizeMode EllipsizeMode() override;
		void ItemPosition(ToolItem& item, int pos);
		int ItemPosition(ToolItem& item);
		void Label(const char* label);
		const char* Label();
		void LabelWidget(Widget& label);
		Widget LabelWidget();
		void HeaderRelief(CGui::ReliefStyle style);
		CGui::ReliefStyle HeaderRelief();
		unsigned int NumItems();
		ToolItem NthItem(int index);
		void Insert(ToolItem& item, int pos);
		bool IsToolItemGroup();
	};
}