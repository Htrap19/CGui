#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Headerbar/Headerbar.hh"

namespace CGui
{
	class Window : public Widget, public Container<Window>
	{
	public:
		Window(WindowType type, const char* title, WindowPos pos);
		void Icon(const char* iconpath) const;
		void DefaultSize(unsigned int xsize, unsigned int ysize) const;
		void CustomHeaderbar(Headerbar& hb) const;
		void Resizable(bool resizable) const;
		void Title(const char* title) const;
		const char* Title() const;
		void Maximize() const;
		void Unmaximize() const;
		void Fullscreen() const;
		void Unfullscreen() const;
		void Position(WindowPos pos) const;
		void Quit() const;
	};
}
