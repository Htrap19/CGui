#include "WindowGroup.hh"

#include "../../../Custom/VectorsUtilities/VectorUtilities.hh"

namespace CGui
{

	WindowGroup::WindowGroup()
	{
		m_WindowGroup = gtk_window_group_new();
	}

	void WindowGroup::AddWindow(Window& window)
	{
		gtk_window_group_add_window(m_WindowGroup, GTK_WINDOW(window.GetWidget()));
	}

	void WindowGroup::RemoveWindow(Window& window)
	{
		gtk_window_group_remove_window(m_WindowGroup, GTK_WINDOW(window.GetWidget()));
	}

	Vector<CGui::Window> WindowGroup::ListWindows()
	{
		auto g_list = gtk_window_group_list_windows(m_WindowGroup);
		Vector<Window> windows(std::move(WidgetVectorToWindow(std::move(GListToWidgetVector(g_list)))));
		g_list_free(g_list);
		return std::move(windows);
	}

	CGui::Widget WindowGroup::CurrentGrab()
	{
		return Widget(gtk_window_group_get_current_grab(m_WindowGroup));
	}

}