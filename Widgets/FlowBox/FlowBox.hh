#pragma once

#include <tuple>
#include <any>
#include "../Widget.hh"
#include "../Container.hh"
#include "../Orientable.hh"
#include "../../Misc/Adjustment/Adjustment.hh"
#include "../../Custom/List/List.hh"
#include "../../Custom/DeleteOnQuit/DeleteOnQuit.hh"

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
		void Prepend(Widget& child);
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
		Vector<Widget> SelectedChildren();
		template <typename ... Args>
		void SelectedForEach(void(*func)(FlowBox* sender, FlowBox::Child* child, Args ... args), Args ... args);
		void SelectChild(FlowBox::Child& child);
		void UnselectChild(FlowBox::Child& child);
		void SelectAll();
		void UnselectAll();
		void SelectionMode(CGui::SelectionMode mode);
		CGui::SelectionMode SelectionMode();

		bool IsFlowBox();
	};

	template <typename ... Args>
	void FlowBox::SelectedForEach(void(*func)(FlowBox*, FlowBox::Child*, Args ...), Args ... args)
	{
		std::tuple<decltype(func), Args...>* data = new std::tuple<decltype(func), Args...>{ func, args... };
		DeleteOnQuit::Instance().Add(data);

		auto callback = [](GtkFlowBox* sender, GtkFlowBoxChild* child, std::tuple<decltype(func), Args...>* data)
		{
			auto apply_func = [&sender, &child](void(*user_func)(FlowBox*, FlowBox::Child*, Args...), Args ... args)
			{
				user_func(sender, child, args...);
			};

			std::apply(apply_func, data);
		};

		gtk_flow_box_selected_foreach(GTK_FLOW_BOX(m_Widget), (void(*)(GtkFlowBox*, GtkFlowBoxChild*, std::tuple<decltype(func), Args...>*))callback, data);
	}

}