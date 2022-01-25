#include "./Dialog.hh"

namespace CGui
{
	Dialog::Dialog(Window& window, bool modal, const char* title) : Window::Container(this)
	{
		m_Widget = gtk_dialog_new();
		Container<Widget>::m_WidgetIns = gtk_dialog_get_content_area(GTK_DIALOG(m_Widget));
		this->SetContext(m_Widget);
		this->TransientFor(window);
		this->Modal(modal);
		this->Title(title);
	}

	Dialog::Dialog(GtkDialog* dialog) : Window::Container(this)
	{
		this->SetDialog(dialog);
	}

	ResponseType Dialog::Run()
	{
		return (ResponseType)gtk_dialog_run(GTK_DIALOG(m_Widget));
	}

	void Dialog::ActionWidget(Widget& action_widget, ResponseType res_type)
	{
		gtk_dialog_add_action_widget(GTK_DIALOG(m_Widget), action_widget.GetWidget(), (int)res_type);
	}

	Widget Dialog::AddButton(const char* button_text, ResponseType res_type)
	{
		return Widget(gtk_dialog_add_button(GTK_DIALOG(m_Widget), button_text, (int)res_type));
	}

	void Dialog::DefaultResponse(ResponseType res_type)
	{
		gtk_dialog_set_default_response(GTK_DIALOG(m_Widget), (int)res_type);
	}

	void Dialog::ResponseSensitive(ResponseType res_type, bool sensitive)
	{
		gtk_dialog_set_response_sensitive(GTK_DIALOG(m_Widget), (int)res_type, sensitive);
	}

	ResponseType Dialog::ResponseForWidget(Widget& w)
	{
		return (ResponseType)gtk_dialog_get_response_for_widget(GTK_DIALOG(m_Widget), w.GetWidget());
	}

	Widget Dialog::WidgetForResponse(ResponseType res_type)
	{
		return Widget(gtk_dialog_get_widget_for_response(GTK_DIALOG(m_Widget), (int)res_type));
	}


	void Dialog::Add(Widget& child)
	{
		Container<Widget>::Add(child);
	}

	void Dialog::Remove(Widget& child)
	{
		Container<Widget>::Remove(child);
	}

	void Dialog::InternalWidth(unsigned int width)
	{
		Container<Widget>::InternalWidth(width);
	}

	unsigned int Dialog::InternalWidth()
	{
		return Container<Widget>::InternalWidth();
	}

	CGui::Vector<CGui::Widget> Dialog::Children()
	{
		return std::move(Container<Widget>::Children());
	}

	bool Dialog::IsDialog()
	{
		return GTK_IS_DIALOG(m_Widget);
	}

	Dialog::Dialog() : Window::Container(this)
	{ }

	void Dialog::SetDialog(GtkDialog* dialog)
	{
		this->m_Widget = GTK_WIDGET(dialog);
		Container<Widget>::m_WidgetIns = gtk_dialog_get_content_area(GTK_DIALOG(m_Widget));
		this->SetContext(m_Widget);
	}

};
