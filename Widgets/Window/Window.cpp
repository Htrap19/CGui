#include "./Window.hh"
#include "../../Custom/Storage/Storage.hh"

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
				auto f = [](KeyValue::Node<const char*, Single::List<std::any>*> * node) -> void
				{
					if (std::string(node->key) == "Instance")
						delete node->value;
				};

				Storage::GetInstance().ForEach<const char*, Single::List<std::any>*>(f, "allcallbacks");
				Storage::GetInstance().Free<const char*, Single::List<std::any>*>("allcallbacks");
				gtk_main_quit();
			}
			else
			{
				gtk_widget_destroy(widget);
				Window::m_ref_count--;
			}
		};
		g_signal_connect(G_OBJECT(widget), Converter::Convert::GetInstance().GetGtkCode(Events::DELETE), G_CALLBACK((void(*)(GtkWidget*, gpointer))exit), NULL);
		this->Title(title);
		this->Position(pos);
		this->SetContext(widget);
	}

	void Window::Icon(const char* iconpath) const
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

	void Window::DefaultSize(unsigned int xsize, unsigned int ysize) const
	{
		gtk_window_set_default_size(GTK_WINDOW(widget), xsize, ysize);
	}

	void Window::CustomHeaderbar(Headerbar & hb) const
	{
		gtk_window_set_titlebar(GTK_WINDOW(widget), hb.GetWidget());
	}

	void Window::Resizable(bool resizable) const
	{
		gtk_window_set_resizable(GTK_WINDOW(widget), resizable);
	}

	void Window::Title(const char* title) const
	{
		gtk_window_set_title(GTK_WINDOW(widget), title);
	}

	const char* Window::Title() const
	{
		return gtk_window_get_title(GTK_WINDOW(widget));
	}

	void Window::Maximize() const
	{
		gtk_window_maximize(GTK_WINDOW(widget));
	}

	void Window::Unmaximize() const
	{
		gtk_window_unmaximize(GTK_WINDOW(widget));
	}

	void Window::Fullscreen() const
	{
		gtk_window_fullscreen(GTK_WINDOW(widget));
	}

	void Window::Unfullscreen() const
	{
		gtk_window_unfullscreen(GTK_WINDOW(widget));
	}

	void Window::Position(WindowPos pos) const
	{
		gtk_window_set_position(GTK_WINDOW(widget), (GtkWindowPosition)pos);
	}
};
