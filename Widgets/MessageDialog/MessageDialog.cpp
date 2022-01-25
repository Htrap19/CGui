#include "./MessageDialog.hh"

namespace CGui
{
	MessageDialog::MessageDialog(GtkMessageDialog* message_dialog) : Window::Container(this)
	{
		m_Widget = GTK_WIDGET(message_dialog);
		Container<Widget>::m_WidgetIns = gtk_message_dialog_get_message_area(GTK_MESSAGE_DIALOG(m_Widget));
		this->SetContext(m_Widget);
	}

	MessageDialog::MessageDialog(Window& parent, DialogFlags flags, MessageType message_type, ButtonsType buttons_type) : Window::Container(this)
	{
		m_Widget = gtk_message_dialog_new(GTK_WINDOW(parent.GetWidget()), (GtkDialogFlags)flags, (GtkMessageType)message_type, (GtkButtonsType)buttons_type, "");
		Container<Widget>::m_WidgetIns = gtk_message_dialog_get_message_area(GTK_MESSAGE_DIALOG(m_Widget));
		this->SetContext(m_Widget);
	}

	void MessageDialog::Markup(const char* str)
	{
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(m_Widget), str);
	}
	bool MessageDialog::IsMessageDialog()
	{
		return GTK_IS_MESSAGE_DIALOG(m_Widget);
	}
}