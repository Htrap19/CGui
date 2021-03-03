#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Orientable.hh"
#include "../../Misc/Adjustment/Adjustment.hh"
#include "../../Custom/List/List.hh"

namespace CGui
{
	class FlowBox : public virtual Widget, public virtual Container<FlowBox>, public virtual Orientable
	{
	public:
		class Child : public virtual Widget, public virtual Container<Child>
		{
		public:
			Child();
			Child(GtkFlowBoxChild* child);
			int Index();
			bool IsSelected();
			void Changed();
			bool IsChild();
		};

		FlowBox();
		FlowBox(GtkFlowBox* flow_box);
		void Insert(Widget& child, int position);
		void Append(Widget& child);
		FlowBox::Child ChildAtIndex(int index);
		FlowBox::Child ChildAtPos(int x, int y);
		void HAdjustment(Adjustment adjustment);
		void VAdjustment(Adjustment adjustment);
		void Homogeneous(bool homogeneous);
		bool Homogeneous();
		void RowSpacing(unsigned int spacing);
		unsigned int RowSpacing();
		void ColumnSpacing(unsigned int spacing);
		unsigned int ColumnSpacing();
		void MinChildrenPerLine(unsigned int n_children);
		unsigned int MinChildrenPerLine();
		void MaxChildrenPerLine(unsigned int n_children);
		unsigned int MaxChildrenPerLine();
		void ActivateOnSingleClick(bool activate);
		bool ActivateOnSingleClick();
		Single::List<Widget> SelectedChildren();
		void SelectChild(FlowBox::Child& child);
		void UnselectChild(FlowBox::Child& child);
		void SelectAll();
		void UnselectAll();
		void SelectionMode(CGui::SelectionMode mode);
		CGui::SelectionMode SelectionMode();
		bool IsFlowBox();
	};
}