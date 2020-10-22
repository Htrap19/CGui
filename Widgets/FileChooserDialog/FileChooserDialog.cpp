#include "./FileChooserDialog.hh"

namespace CGui
{
	FileChooserDialog::FileChooserDialog(Window& parent, const char* title, FileChooserAction action)
	{
		Dialog::widget = gtk_file_chooser_dialog_new(title, GTK_WINDOW(parent.GetWidget()), (GtkFileChooserAction)action, NULL);
		this->SetFileChooser(GTK_FILE_CHOOSER(Dialog::widget));
	}

	bool FileChooserDialog::IsFileChooserDialog()
	{
		return GTK_IS_FILE_CHOOSER_DIALOG(Dialog::widget);
	}

	FileChooserDialog::FileChooserDialog()
	{
	}

	void FileChooserDialog::SetFileChooserDialog(GtkFileChooserDialog* dialog)
	{
		Dialog::widget = GTK_WIDGET(dialog);
		this->SetFileChooser(GTK_FILE_CHOOSER(Dialog::widget));
	}
}
