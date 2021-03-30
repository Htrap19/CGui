#include "./Window.hh"
#include "../../Custom/Initialize/Initialize.hh"
#include "../../Custom/VectorsUtilities/VectorUtilities.hh"

namespace CGui
{
	unsigned int Window::m_RefCount = 0;

	Window::Window(WindowType type, const char* title, WindowPos pos, bool initialize) : Container(this), m_Error{ nullptr }
	{
		m_Widget = gtk_window_new((GtkWindowType)type);

		if (initialize)
		{
			Window::m_RefCount++;
			auto exit = [](GtkWidget* widget, Window* ins) -> void
			{
				if (Window::m_RefCount <= 1)
				{
					CGui::MainQuit();
				}
				else
				{
					ins->Destroy();
				}
			};
			g_signal_connect(G_OBJECT(m_Widget), Converter::Convert::GetInstance().GetGtkCode(Events::DELETE), G_CALLBACK((void(*)(GtkWidget*, Window*))exit), this);

			auto destroy_callback = [](GtkWidget* widget, gpointer data) -> void
			{
				Window::m_RefCount--;
			};
			g_signal_connect(G_OBJECT(m_Widget), Converter::Convert::GetInstance().GetGtkCode(Signals::DESTROY), G_CALLBACK((void(*)(GtkWidget*, gpointer))destroy_callback), nullptr);
		}

		this->Title(title);
		this->Position(pos);
		this->SetContext(m_Widget);
	}

	Window::Window(GtkWindow* window) : Container(this), m_Error{ nullptr }
	{
		this->SetWindow(window);
	}

	void Window::Icon(const char* filename)
	{
		gtk_window_set_icon_from_file(GTK_WINDOW(m_Widget), filename, &m_Error);
	}

	void Window::DefaultSize(unsigned int width, unsigned int height)
	{
		gtk_window_set_default_size(GTK_WINDOW(m_Widget), width, height);
	}

	Requisition Window::DefaultSize()
	{
		int width, height;
		gtk_window_get_default_size(GTK_WINDOW(m_Widget), &width, &height);

		return { width, height };
	}

	void Window::Headerbar(CGui::Headerbar& hb)
	{
		gtk_window_set_titlebar(GTK_WINDOW(m_Widget), hb.GetWidget());
	}

	CGui::Headerbar Window::Headerbar()
	{
		return CGui::Headerbar(GTK_HEADER_BAR(gtk_window_get_titlebar(GTK_WINDOW(m_Widget))));
	}

	void Window::Resizable(bool resizable)
	{
		gtk_window_set_resizable(GTK_WINDOW(m_Widget), resizable);
	}

	bool Window::Resizable()
	{
		return gtk_window_get_resizable(GTK_WINDOW(m_Widget));
	}

	void Window::AddAccelGroup(AccelGroup group)
	{
		gtk_window_add_accel_group(GTK_WINDOW(m_Widget), group.GetWidget());
	}

	void Window::RemoveAccelGroup(AccelGroup group)
	{
		gtk_window_remove_accel_group(GTK_WINDOW(m_Widget), group.GetWidget());
	}

	void Window::Title(const char* title)
	{
		gtk_window_set_title(GTK_WINDOW(m_Widget), title);
	}

	const char* Window::Title()
	{
		return gtk_window_get_title(GTK_WINDOW(m_Widget));
	}

	void Window::Maximize()
	{
		gtk_window_maximize(GTK_WINDOW(m_Widget));
	}

	bool Window::IsMaximized()
	{
		return gtk_window_is_maximized(GTK_WINDOW(m_Widget));
	}

	void Window::Unmaximize()
	{
		gtk_window_unmaximize(GTK_WINDOW(m_Widget));
	}

	void Window::Fullscreen()
	{
		gtk_window_fullscreen(GTK_WINDOW(m_Widget));
	}

	void Window::Unfullscreen()
	{
		gtk_window_unfullscreen(GTK_WINDOW(m_Widget));
	}

	void Window::IConify()
	{
		gtk_window_iconify(GTK_WINDOW(m_Widget));
	}

	void Window::Deiconify()
	{
		gtk_window_deiconify(GTK_WINDOW(m_Widget));
	}

	void Window::Position(WindowPos pos)
	{
		gtk_window_set_position(GTK_WINDOW(m_Widget), (GtkWindowPosition)pos);
	}

	WindowPositionData Window::Position()
	{
		int x, y;
		gtk_window_get_position(GTK_WINDOW(m_Widget), &x, &y);

		return { x, y };
	}

	bool Window::ActivateFocus()
	{
		return gtk_window_activate_focus(GTK_WINDOW(m_Widget));
	}

	bool Window::ActivateDefault()
	{
		return gtk_window_activate_default(GTK_WINDOW(m_Widget));
	}

	void Window::Modal(bool modal)
	{
		gtk_window_set_modal(GTK_WINDOW(m_Widget), modal);
	}

	bool Window::Modal()
	{
		return gtk_window_get_modal(GTK_WINDOW(m_Widget));
	}

	void Window::Gravity(CGui::Gravity gravity)
	{
		gtk_window_set_gravity(GTK_WINDOW(m_Widget), (GdkGravity)gravity);
	}

	CGui::Gravity Window::Gravity()
	{
		return (CGui::Gravity)gtk_window_get_gravity(GTK_WINDOW(m_Widget));
	}

	void Window::TransientFor(Window& parent)
	{
		gtk_window_set_transient_for(GTK_WINDOW(m_Widget), GTK_WINDOW(parent.GetWidget()));
	}

	Window Window::TransientFor()
	{
		return Window(gtk_window_get_transient_for(GTK_WINDOW(m_Widget)));
	}

	void Window::AttachedTo(Widget& attach_widget)
	{
		gtk_window_set_attached_to(GTK_WINDOW(m_Widget), attach_widget.GetWidget());
	}

	Widget Window::AttachedTo()
	{
		return Widget(gtk_window_get_attached_to(GTK_WINDOW(m_Widget)));
	}

	void Window::DestroyWithParent(bool destroy)
	{
		gtk_window_set_destroy_with_parent(GTK_WINDOW(m_Widget), destroy);
	}

	bool Window::DestroywithParent()
	{
		return gtk_window_get_destroy_with_parent(GTK_WINDOW(m_Widget));
	}

	void Window::HideHeaderbarWhenMaximized(bool hide)
	{
		gtk_window_set_hide_titlebar_when_maximized(GTK_WINDOW(m_Widget), hide);
	}

	bool Window::HideHeaderbarWhenMaximized()
	{
		return gtk_window_get_hide_titlebar_when_maximized(GTK_WINDOW(m_Widget));
	}

	bool Window::IsActive()
	{
		return gtk_window_is_active(GTK_WINDOW(m_Widget));
	}

	bool Window::HasToplevelFocus()
	{
		return gtk_window_has_toplevel_focus(GTK_WINDOW(m_Widget));
	}

	Vector<Window> Window::ListToplevels()
	{
		auto g_list = gtk_window_list_toplevels();
		Vector<Window> toplevels(std::move(WidgetVectorToWindow(std::move(GListToWidgetVector(g_list)))));
		g_list_free(g_list);
		return std::move(toplevels);
	}

	void Window::Focus(Widget& focus)
	{
		gtk_window_set_focus(GTK_WINDOW(m_Widget), focus.GetWidget());
	}

	Widget Window::Focus()
	{
		return Widget(gtk_window_get_focus(GTK_WINDOW(m_Widget)));
	}

	void Window::DefaultWidget(Widget& default_widget)
	{
		gtk_window_set_default(GTK_WINDOW(m_Widget), default_widget.GetWidget());
	}

	Widget Window::DefaultWidget()
	{
		return Widget(gtk_window_get_default_widget(GTK_WINDOW(m_Widget)));
	}

	void Window::Present()
	{
		gtk_window_present(GTK_WINDOW(m_Widget));
	}

	void Window::Close()
	{
		gtk_window_close(GTK_WINDOW(m_Widget));
	}

	void Window::Stick()
	{
		gtk_window_stick(GTK_WINDOW(m_Widget));
	}

	void Window::Unstick()
	{
		gtk_window_unstick(GTK_WINDOW(m_Widget));
	}

	void Window::KeepAbove(bool keep_above)
	{
		gtk_window_set_keep_above(GTK_WINDOW(m_Widget), keep_above);
	}

	void Window::KeepBelow(bool keep_below)
	{
		gtk_window_set_keep_below(GTK_WINDOW(m_Widget), keep_below);
	}

	void Window::Decorated(bool decorated)
	{
		gtk_window_set_decorated(GTK_WINDOW(m_Widget), decorated);
	}

	bool Window::Decorated()
	{
		return gtk_window_get_decorated(GTK_WINDOW(m_Widget));
	}

	void Window::Deletable(bool deletable)
	{
		gtk_window_set_deletable(GTK_WINDOW(m_Widget), deletable);
	}

	bool Window::Deletable()
	{
		return gtk_window_get_deletable(GTK_WINDOW(m_Widget));
	}

	void Window::SkipTaskbarHint(bool skip)
	{
		gtk_window_set_skip_taskbar_hint(GTK_WINDOW(m_Widget), skip);
	}

	bool Window::SkipTaskbarHint()
	{
		return gtk_window_get_skip_taskbar_hint(GTK_WINDOW(m_Widget));
	}

	void Window::SkipPagerHint(bool skip)
	{
		gtk_window_set_skip_pager_hint(GTK_WINDOW(m_Widget), skip);
	}

	bool Window::SkipPagerHint()
	{
		return gtk_window_get_skip_pager_hint(GTK_WINDOW(m_Widget));
	}

	void Window::UrgencyHint(bool urgency)
	{
		gtk_window_set_urgency_hint(GTK_WINDOW(m_Widget), urgency);
	}

	bool Window::UrgencyHint()
	{
		return gtk_window_get_urgency_hint(GTK_WINDOW(m_Widget));
	}

	void Window::AcceptFocus(bool accept)
	{
		gtk_window_set_accept_focus(GTK_WINDOW(m_Widget), accept);
	}

	bool Window::AcceptFocus()
	{
		return gtk_window_get_accept_focus(GTK_WINDOW(m_Widget));
	}

	void Window::FocusOnMap(bool focus)
	{
		gtk_window_set_focus_on_map(GTK_WINDOW(m_Widget), focus);
	}

	bool Window::FocusOnMap()
	{
		return gtk_window_get_focus_on_map(GTK_WINDOW(m_Widget));
	}

	void Window::StartupId(const char* startup_id)
	{
		gtk_window_set_startup_id(GTK_WINDOW(m_Widget), startup_id);
	}

	void Window::Icon(Pixbuf& icon)
	{
		gtk_window_set_icon(GTK_WINDOW(m_Widget), icon.GetWidget());
	}

	Pixbuf Window::Icon()
	{
		return Pixbuf(gtk_window_get_icon(GTK_WINDOW(m_Widget)));
	}

	void Window::IconList(Vector<Pixbuf>& list)
	{
		GList* glist = nullptr;

		for (auto& pixbuf : list)
		{
			glist->data = pixbuf.GetWidget();
			glist = g_list_next(glist);
		}

		gtk_window_set_icon_list(GTK_WINDOW(m_Widget), glist);
		g_list_free(glist);
	}

	Vector<Pixbuf> Window::IconList()
	{
		GList* glist = gtk_window_get_icon_list(GTK_WINDOW(m_Widget));
		Vector<Pixbuf> pbufs(std::move(GListToPixbufVector(glist)));
		g_list_free(glist);
		return std::move(pbufs);
	}

	void Window::Iconname(const char* iconname)
	{
		gtk_window_set_icon_name(GTK_WINDOW(m_Widget), iconname);
	}

	const char* Window::Iconname()
	{
		return gtk_window_get_icon_name(GTK_WINDOW(m_Widget));
	}

	Requisition Window::Size()
	{
		int width, height;
		gtk_window_get_size(GTK_WINDOW(m_Widget), &width, &height);

		return { width, height };
	}

	WindowType Window::Type()
	{
		return (WindowType)gtk_window_get_window_type(GTK_WINDOW(m_Widget));
	}

	void Window::Move(int x, int y)
	{
		gtk_window_move(GTK_WINDOW(m_Widget), x, y);
	}

	void Window::Resize(int width, int height)
	{
		gtk_window_resize(GTK_WINDOW(m_Widget), width, height);
	}

	void Window::FocusVisible(bool visible)
	{
		gtk_window_set_focus_visible(GTK_WINDOW(m_Widget), visible);
	}

	bool Window::FocusVisible()
	{
		return gtk_window_get_focus_visible(GTK_WINDOW(m_Widget));
	}

	void Window::HasUserRefCount(bool has)
	{
		gtk_window_set_has_user_ref_count(GTK_WINDOW(m_Widget), has);
	}

	bool Window::IsWindow()
	{
		return GTK_IS_WINDOW(m_Widget);
	}

	void Window::DefaultIconList(Vector<Pixbuf>& list)
	{
		GList* glist = nullptr;

		for (auto& pixbuf : list)
		{
			glist->data = pixbuf.GetWidget();
			glist = g_list_next(glist);
		}

		gtk_window_set_default_icon_list(glist);
		g_list_free(glist);
	}

	Vector<Pixbuf> Window::DefaultIconList()
	{
		GList* glist = gtk_window_get_default_icon_list();
		Vector<Pixbuf> pbufs(std::move(GListToPixbufVector(glist)));
		g_list_free(glist);
		return std::move(pbufs);
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
		fprintf(stderr, "%s\n", m_Error->message);
	}

	bool Window::HasError()
	{
		return (m_Error != nullptr);
	}

	Window::Window() : Container(this), m_Error{ nullptr }
	{ }

	void Window::SetWindow(GtkWindow* window)
	{
		this->m_Widget = GTK_WIDGET(window);
		this->SetContext(m_Widget);
	}
};