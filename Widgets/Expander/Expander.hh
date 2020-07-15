#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Expander : public Widget, public Container<Expander>
	{
	public:
		Expander(const char* label);
		void Expanded(bool expanded);
		bool Expanded();
		void Label(const char* label);
		const char* Label();
		void UseUnderline(bool use_underline);
		bool UseUnderline();
		void UseMarkup(bool use_markup);
		bool UseMarkup();
		void LabelWidget(Widget& label);
		Widget LabelWidget();
		void LabelFill(bool label_fill);
		bool LabelFill();
		void ResizeToplevel(bool resize);
		bool ResizeToplevel();
	};
}