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
		Window(GtkWindow* window);
		void Icon(const char* iconpath);
		void DefaultSize(unsigned int width, unsigned int height);
		Requisition DefaultSize();
		void CustomHeaderbar(Headerbar& hb);
		void Resizable(bool resizable);
		void Title(const char* title);
		const char* Title();
		void Maximize();
		bool IsMaximized();
		void Unmaximize();
		void Fullscreen();
		void Unfullscreen();
		void IConify();
		void Deiconify();
		void Position(WindowPos pos);
		bool ActivateFocus();
		bool ActivateDefault();
		void Modal(bool modal);
		bool Modal();
		void WindowGravity(Gravity gravity);
		Gravity WindowGravity();
		void TransientFor(Window& parent);
		Window TransientFor();
		void AttachedTo(Widget& attach_widget);
		Widget AttachedTo();
		void DestroyWithParent(bool destroy);
		bool DestroywithParent();
		void HideHeaderbarWhenMaximized(bool hide);
		bool HideHeaderbarWhenMaximized();
		bool IsActive();
		bool HasToplevelFocus();

	private:
		static unsigned int m_ref_count;
	};
}
