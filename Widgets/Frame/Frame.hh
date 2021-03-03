#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Frame : public virtual Widget, public virtual Container<Frame>
	{
	public:
		Frame(const char* label);
		Frame(GtkFrame* frame);
		void Label(const char* label);
		const char* Label();
		void LabelWidget(Widget& label);
		Widget LabelWidget();
		void LabelAlign(float xalign, float yalign);
		AlignData LabelAlign();
		void Shadow(ShadowType type);
		ShadowType Shadow();
		bool IsFrame();

	protected:
		Frame();
		void SetFrame(GtkFrame* frame);
	};
}