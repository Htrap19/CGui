#include "./FileChooserDialog.hh"

namespace CGui
{
	FileChooserDialog::FileChooserDialog(Window& parent, const char* title, FileChooserAction action) : Window::Container(this)
	{
		widget = gtk_file_chooser_dialog_new(title, GTK_WINDOW(parent.GetWidget()), (GtkFileChooserAction)action, NULL);
		this->SetFileChooser(GTK_FILE_CHOOSER(widget));
		this->SetContext(widget);
	}

	FileChooserDialog::FileChooserDialog(GtkFileChooserDialog* file_chooser_dialog) : Window::Container(this)
	{
		this->SetFileChooserDialog(file_chooser_dialog);
	}

	bool FileChooserDialog::IsFileChooserDialog()
	{
		return GTK_IS_FILE_CHOOSER_DIALOG(widget);
	}

	FileChooserDialog::FileChooserDialog() : Window::Container(this)
	{
	}

	void FileChooserDialog::SetFileChooserDialog(GtkFileChooserDialog* dialog)
	{
		widget = GTK_WIDGET(dialog);
		this->SetFileChooser(GTK_FILE_CHOOSER(widget));
		this->SetContext(widget);
	}
}
