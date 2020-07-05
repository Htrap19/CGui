#include "./Window.hh"
#include "../../Custom/Initialize/Initialize.hh"

namespace CGui
{
	unsigned int Window::m_ref_count = 0;

	Window::Window(WindowType type, const char* title, WindowPos pos) : Container(this)
	{
		widget = gtk_window_new((GtkWindowType)type);
		Window::m_ref_count++;

		auto exit = [](GtkWidget * widget, gpointer data) -> void
		{
			if (Window::m_ref_count <= 1)
			{
				CGui::MainQuit();
			}
			else
			{
				gtk_widget_destroy(widget);
				Window::m_ref_count--;
			}
		};
		g_signal_connect(G_OBJECT(widget), Converter::Convert::GetInstance().GetGtkCode(Signals::DELETE), G_CALLBACK((void(*)(GtkWidget*, gpointer))exit), NULL);
		this->Title(title);
		this->Position(pos);
		this->SetContext(widget);
	}

	Window::Window(GtkWindow* window) : Container(this)
	{
		widget = GTK_WIDGET(window);
		this->SetContext(widget);
	}

	void Window::Icon(const char* iconpath)
	{
		GError* error = NULL;
		GdkPixbuf* icon = gdk_pixbuf_new_from_file(iconpath, &error);
		if (!icon)
		{
			fprintf(stderr, "%s\n", error->message);
			g_error_free(error);
		}
		gtk_window_set_icon(GTK_WINDOW(widget), icon);
	}

	void Window::DefaultSize(unsigned int width, unsigned int height)
	{
		gtk_window_set_default_size(GTK_WINDOW(widget), width, height);
	}

	Requisition Window::DefaultSize()
	{
		int width, height;
		gtk_window_get_default_size(GTK_WINDOW(widget), &width, &height);

		return { width, height };
	}

	void Window::CustomHeaderbar(Headerbar & hb)
	{
		gtk_window_set_titlebar(GTK_WINDOW(widget), hb.GetWidget());
	}

	void Window::Resizable(bool resizable)
	{
		gtk_window_set_resizable(GTK_WINDOW(widget), resizable);
	}

	void Window::Title(const char* title)
	{
		gtk_window_set_title(GTK_WINDOW(widget), title);
	}

	const char* Window::Title()
	{
		return gtk_window_get_title(GTK_WINDOW(widget));
	}

	void Window::Maximize()
	{
		gtk_window_maximize(GTK_WINDOW(widget));
	}

	bool Window::IsMaximized()
	{
		return gtk_window_is_maximized(GTK_WINDOW(widget));
	}

	void Window::Unmaximize()
	{
		gtk_window_unmaximize(GTK_WINDOW(widget));
	}

	void Window::Fullscreen()
	{
		gtk_window_fullscreen(GTK_WINDOW(widget));
	}

	void Window::Unfullscreen()
	{
		gtk_window_unfullscreen(GTK_WINDOW(widget));
	}

	void Window::IConify()
	{
		gtk_window_iconify(GTK_WINDOW(widget));
	}

	void Window::Deiconify()
	{
		gtk_window_deiconify(GTK_WINDOW(widget));
	}

	void Window::Position(WindowPos pos)
	{
		gtk_window_set_position(GTK_WINDOW(widget), (GtkWindowPosition)pos);
	}

	bool Window::ActivateFocus()
	{
		return gtk_window_activate_focus(GTK_WINDOW(widget));
	}

	bool Window::ActivateDefault()
	{
		return gtk_window_activate_default(GTK_WINDOW(widget));
	}

	void Window::Modal(bool modal)
	{
		gtk_window_set_modal(GTK_WINDOW(widget), modal);
	}

	bool Window::Modal()
	{
		return gtk_window_get_modal(GTK_WINDOW(widget));
	}

	void Window::WindowGravity(Gravity gravity)
	{
		gtk_window_set_gravity(GTK_WINDOW(widget), (GdkGravity)gravity);
	}

	Gravity Window::WindowGravity()
	{
		return (Gravity)gtk_window_get_gravity(GTK_WINDOW(widget));
	}

	void Window::TransientFor(Window& parent)
	{
		gtk_window_set_transient_for(GTK_WINDOW(widget), GTK_WINDOW(parent.GetWidget()));
	}

	Window Window::TransientFor()
	{
		return Window(gtk_window_get_transient_for(GTK_WINDOW(widget)));
	}

	void Window::AttachedTo(Widget& attach_widget)
	{
		gtk_window_set_attached_to(GTK_WINDOW(widget), attach_widget.GetWidget());
	}

	Widget Window::AttachedTo()
	{
		return Widget(gtk_window_get_attached_to(GTK_WINDOW(widget)));
	}

	void Window::DestroyWithParent(bool destroy)
	{
		gtk_window_set_destroy_with_parent(GTK_WINDOW(widget), destroy);
	}

	bool Window::DestroywithParent()
	{
		return gtk_window_get_destroy_with_parent(GTK_WINDOW(widget));
	}

	void Window::HideHeaderbarWhenMaximized(bool hide)
	{
		gtk_window_set_hide_titlebar_when_maximized(GTK_WINDOW(widget), hide);
	}

	bool Window::HideHeaderbarWhenMaximized()
	{
		return gtk_window_get_hide_titlebar_when_maximized(GTK_WINDOW(widget));
	}

	bool Window::IsActive()
	{
		return gtk_window_is_active(GTK_WINDOW(widget));
	}

	bool Window::HasToplevelFocus()
	{
		return gtk_window_has_toplevel_focus(GTK_WINDOW(widget));
	}
};
