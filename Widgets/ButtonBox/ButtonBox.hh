#pragma once

#include "../Box/Box.hh"

namespace CGui
{
	class ButtonBox : public Box
	{
	public:
		ButtonBox(CGui::Orientation orientation);
		void Layout(ButtonBoxStyle style);
		ButtonBoxStyle Layout();
		void ChildSecondary(Widget& child, bool is_secondary);
		bool ChildSecondary(Widget& child);
		void ChildNonHomogeneous(Widget& child, bool non_homogeneous);
		bool ChildNonHomogeneous(Widget& child);
		bool IsButtonBox();
	};
}