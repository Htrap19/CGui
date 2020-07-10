#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Orientable.hh"

namespace CGui
{
	class Box : public Widget, public Container<Box>, public Orientable
	{
	public:
		Box(Orientation type, int spacing);
		void Add(PackType type, Widget& w, bool expand = false, bool fill = false, unsigned int padding = 0);
		void AddStart(Widget& w, bool expand = false, bool fill = false, unsigned int padding = 0);
		void AddEnd(Widget& w, bool expand = false, bool fill = false, unsigned int padding = 0);
		void Homogeneous(bool homogeneous);
		bool Homogeneous();
		void Spacing(bool spacing);
		bool Spacing();
		void ReorderChild(Widget& w, int position);
		void ChildPacking(Widget& w, PackType type, bool expand = false, bool fill = false, unsigned int padding = 0);
		ChildPackingInfo QueryChildPacking(Widget& w);
		void BoxBaselinePosition(BaselinePosition position);
		BaselinePosition BoxBaselinePosition();
		void CenterWidget(Widget& w);
		Widget CenterWidget();

	protected:
		Box();
		void SetBox(GtkBox* box);
	};
}