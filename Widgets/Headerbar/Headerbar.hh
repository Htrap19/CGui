#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Headerbar : public Widget, public Container<Headerbar>
	{
	public:
		Headerbar(const char* title = "", const char* subtitle = "");
		Headerbar(GtkHeaderBar* headerbar);
		void Title(const char* title);
		const char* Title();
		void SubTitle(const char* subtitle);
		const char* SubTitle();
		void HasSubTitle(bool has_subtitle);
		bool HasSubTitle();
		void CustomTitle(Widget& w);
		Widget CustomTitle();
		void ShowCloseButton(bool show_close_button);
		bool ShowCloseButton();
		void DecorationLayout(const char* layout);
		const char* DecorationLayout();
		void Add(PackType type, Widget& w);
		void AddStart(Widget& w);
		void AddEnd(Widget& w);
	};
}
