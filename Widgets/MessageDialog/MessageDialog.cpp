#include "./MessageDialog.hh"

namespace CGui
{
	MessageDialog::MessageDialog(Window& parent, DialogFlags flags, MessageType message_type, ButtonsType buttons_type)
	{
		widget = gtk_message_dialog_new(GTK_WINDOW(parent.GetWidget()), (GtkDialogFlags)flags, (GtkMessageType)message_type, (GtkButtonsType)buttons_type, "");
		this->SetDialog(GTK_DIALOG(widget));
		Container<Widget>::t_widget = gtk_message_dialog_get_message_area(GTK_MESSAGE_DIALOG(widget));
	}

	void MessageDialog::Markup(const char* str)
	{
		gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(widget), str);
	}
}