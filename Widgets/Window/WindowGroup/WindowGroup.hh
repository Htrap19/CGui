#pragma once

#include <gtk/gtk.h>
#include "../Window.hh"
#include "../../Widget.hh"

namespace CGui
{
	class WindowGroup
	{
	public:
		WindowGroup();
		void AddWindow(Window& window);
		void RemoveWindow(Window& window);
		Vector<Window> ListWindows();
		Widget CurrentGrab();

	private:
		GtkWindowGroup* m_WindowGroup;
	};
}