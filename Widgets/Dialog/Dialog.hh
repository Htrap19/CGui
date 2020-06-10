#pragma once

#include "../Widget.hh"
#include "../Window/Window.hh"

namespace CGui
{
	class Dialog : public Widget, public Container<Widget>
	{
	public:
		Dialog(Window& window, bool modal, const char* title = "");
		void Resizable(bool resizable);
		void DefaultSize(unsigned int xsize, unsigned int ysize);
		void CustomHeaderbar(Headerbar& hb);
		void Title(const char* title);
		const char* Title();
		void Modal(bool modal);
		bool Modal();
		void Parent(Window& window);
	};
};
