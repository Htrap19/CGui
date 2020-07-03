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
		void Icon(const char* iconpath);
		void DefaultSize(unsigned int xsize, unsigned int ysize);
		void CustomHeaderbar(Headerbar& hb);
		void Resizable(bool resizable);
		void Title(const char* title);
		const char* Title();
		void Maximize();
		void Unmaximize();
		void Fullscreen();
		void Unfullscreen();
		void IConify();
		void Deiconify();
		void Position(WindowPos pos);

	private:
		static unsigned int m_ref_count;
	};
}
