#include "./Window.hh"
#include "../../Custom/Initialize/Initialize.hh"

namespace CGui
{
	unsigned int Window::m_ref_count = 0;

	Window::Window(WindowType type, const char* title, WindowPos pos) : Container(this), error{ NULL }
	{
		widget = gtk_window_new((GtkWindowType)type);
		Window::m_ref_count++;

		auto exit = [](GtkWidget * widget, Window * ins) -> void
		{
			if (Window::m_ref_count <= 1)
			{
				CGui::MainQuit();
			}
			else
			{
				ins->Close();
				Window::m_ref_count--;
			}
		};
		g_signal_connect(G_OBJECT(widget), Converter::Convert::GetInstance().GetGtkCode(Signals::DELETE), G_CALLBACK((void(*)(GtkWidget*, Window*))exit), this);
		this->Title(title);
		this->Position(pos);
		this->SetContext(widget);
	}

	Window::Window(GtkWindow* window) : Container(this), error{ NULL }
	{
		widget = GTK_WIDGET(window);
		this->SetContext(widget);
	}

	void Window::Icon(const char* filename)
	{
		gtk_window_set_icon_from_file(GTK_WINDOW(widget), filename, &error);
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

	void Window::CustomHeaderbar(Headerbar& hb)
	{
		gtk_window_set_titlebar(GTK_WINDOW(widget), hb.GetWidget());
	}

	Headerbar Window::CustomHeaderbar()
	{
		return Headerbar(GTK_HEADER_BAR(gtk_window_get_titlebar(GTK_WINDOW(widget))));
	}

	void Window::Resizable(bool resizable)
	{
		gtk_window_set_resizable(GTK_WINDOW(widget), resizable);
	}

	bool Window::Resizable()
	{
		return gtk_window_get_resizable(GTK_WINDOW(widget));
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

	WindowPositionData Window::Position()
	{
		int x, y;
		gtk_window_get_position(GTK_WINDOW(widget), &x, &y);

		return { x, y };
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

	Single::List<Window*> Window::ListToplevels()
	{
		auto g_list = gtk_window_list_toplevels();
		Single::List<Window*> ret;

		for (GList* it = g_list; it != NULL; it = it->next)
		{
			ret.Insert(&Window((GtkWindow*)it->data));
		}

		g_list_free(g_list);

		return ret;
	}

	void Window::Focus(Widget& focus)
	{
		gtk_window_set_focus(GTK_WINDOW(widget), focus.GetWidget());
	}

	Widget Window::Focus()
	{
		return Widget(gtk_window_get_focus(GTK_WINDOW(widget)));
	}

	void Window::DefaultWidget(Widget& default_widget)
	{
		gtk_window_set_default(GTK_WINDOW(widget), default_widget.GetWidget());
	}

	Widget Window::DefaultWidget()
	{
		return Widget(gtk_window_get_default_widget(GTK_WINDOW(widget)));
	}

	void Window::Present()
	{
		gtk_window_present(GTK_WINDOW(widget));
	}

	void Window::Close()
	{
		gtk_window_close(GTK_WINDOW(widget));
	}

	void Window::Stick()
	{
		gtk_window_stick(GTK_WINDOW(widget));
	}

	void Window::Unstick()
	{
		gtk_window_unstick(GTK_WINDOW(widget));
	}

	void Window::KeepAbove(bool keep_above)
	{
		gtk_window_set_keep_above(GTK_WINDOW(widget), keep_above);
	}

	void Window::KeepBelow(bool keep_below)
	{
		gtk_window_set_keep_below(GTK_WINDOW(widget), keep_below);
	}

	void Window::Decorated(bool decorated)
	{
		gtk_window_set_decorated(GTK_WINDOW(widget), decorated);
	}

	bool Window::Decorated()
	{
		return gtk_window_get_decorated(GTK_WINDOW(widget));
	}

	void Window::Deletable(bool deletable)
	{
		gtk_window_set_deletable(GTK_WINDOW(widget), deletable);
	}

	bool Window::Deletable()
	{
		return gtk_window_get_deletable(GTK_WINDOW(widget));
	}

	void Window::SkipTaskbarHint(bool skip)
	{
		gtk_window_set_skip_taskbar_hint(GTK_WINDOW(widget), skip);
	}

	bool Window::SkipTaskbarHint()
	{
		return gtk_window_get_skip_taskbar_hint(GTK_WINDOW(widget));
	}

	void Window::SkipPagerHint(bool skip)
	{
		gtk_window_set_skip_pager_hint(GTK_WINDOW(widget), skip);
	}

	bool Window::SkipPagerHint()
	{
		return gtk_window_get_skip_pager_hint(GTK_WINDOW(widget));
	}

	void Window::UrgencyHint(bool urgency)
	{
		gtk_window_set_urgency_hint(GTK_WINDOW(widget), urgency);
	}

	bool Window::UrgencyHint()
	{
		return gtk_window_get_urgency_hint(GTK_WINDOW(widget));
	}

	void Window::AcceptFocus(bool accept)
	{
		gtk_window_set_accept_focus(GTK_WINDOW(widget), accept);
	}

	bool Window::AcceptFocus()
	{
		return gtk_window_get_accept_focus(GTK_WINDOW(widget));
	}

	void Window::FocusOnMap(bool focus)
	{
		gtk_window_set_focus_on_map(GTK_WINDOW(widget), focus);
	}

	bool Window::FocusOnMap()
	{
		return gtk_window_get_focus_on_map(GTK_WINDOW(widget));
	}

	void Window::StartupId(const char* startup_id)
	{
		gtk_window_set_startup_id(GTK_WINDOW(widget), startup_id);
	}

	void Window::Icon(Pixbuf& icon)
	{
		gtk_window_set_icon(GTK_WINDOW(widget), icon.GetWidget());
	}

	Pixbuf Window::Icon()
	{
		return Pixbuf(gtk_window_get_icon(GTK_WINDOW(widget)));
	}

	void Window::IconList(Single::List<Pixbuf*>& list)
	{
		GList* glist = NULL;

		for (unsigned int i = 0; i < list.Size(); i++)
		{
			glist->data = list[0]->GetWidget();
			glist = g_list_next(glist);
		}

		gtk_window_set_icon_list(GTK_WINDOW(widget), glist);
		g_list_free(glist);
	}

	Single::List<Pixbuf*> Window::IconList()
	{
		GList* glist = gtk_window_get_icon_list(GTK_WINDOW(widget));
		Single::List<Pixbuf*> ret;

		for (GList* it = glist; it != NULL; it = g_list_next(glist))
		{
			ret.Insert(&Pixbuf((GdkPixbuf*)it->data, true));
		}

		g_list_free(glist);

		return ret;
	}

	void Window::Iconname(const char* iconname)
	{
		gtk_window_set_icon_name(GTK_WINDOW(widget), iconname);
	}

	const char* Window::Iconname()
	{
		return gtk_window_get_icon_name(GTK_WINDOW(widget));
	}

	Requisition Window::Size()
	{
		int width, height;
		gtk_window_get_size(GTK_WINDOW(widget), &width, &height);

		return { width, height };
	}

	WindowType Window::Type()
	{
		return (WindowType)gtk_window_get_window_type(GTK_WINDOW(widget));
	}

	void Window::Move(int x, int y)
	{
		gtk_window_move(GTK_WINDOW(widget), x, y);
	}

	void Window::Resize(int width, int height)
	{
		gtk_window_resize(GTK_WINDOW(widget), width, height);
	}

	void Window::FocusVisible(bool visible)
	{
		gtk_window_set_focus_visible(GTK_WINDOW(widget), visible);
	}

	bool Window::FocusVisible()
	{
		return gtk_window_get_focus_visible(GTK_WINDOW(widget));
	}

	void Window::HasUserRefCount(bool has)
	{
		gtk_window_set_has_user_ref_count(GTK_WINDOW(widget), has);
	}

	void Window::DefaultIconList(Single::List<Pixbuf*>& list)
	{
		GList* glist = NULL;

		for (unsigned int i = 0; i < list.Size(); i++)
		{
			glist->data = list[0]->GetWidget();
			glist = g_list_next(glist);
		}

		gtk_window_set_default_icon_list(glist);
		g_list_free(glist);
	}

	Single::List<Pixbuf*> Window::DefaultIconList()
	{
		GList* glist = gtk_window_get_default_icon_list();
		Single::List<Pixbuf*> ret;

		for (GList* it = glist; it != NULL; it = g_list_next(glist))
		{
			ret.Insert(&Pixbuf((GdkPixbuf*)it->data, true));
		}

		g_list_free(glist);

		return ret;
	}

	void Window::DefaultIconname(const char* name)
	{
		gtk_window_set_default_icon_name(name);
	}

	const char* Window::DefaultIconname()
	{
		return gtk_window_get_default_icon_name();
	}

	void Window::AutoStartupNotification(bool setting)
	{
		gtk_window_set_auto_startup_notification(setting);
	}

	void Window::InteractiveDebugging(bool enable)
	{
		gtk_window_set_interactive_debugging(enable);
	}

	void Window::ErrorMessage()
	{
		fprintf(stderr, "%s\n", error->message);
	}

	bool Window::HasError()
	{
		return (error != NULL);
	}
};
