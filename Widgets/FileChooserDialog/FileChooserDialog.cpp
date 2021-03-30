#include "./FileChooserDialog.hh"

namespace CGui
{
	FileChooserDialog::FileChooserDialog(Window& parent, const char* title, FileChooserAction action) : Window::Container(this)
	{
		m_Widget = gtk_file_chooser_dialog_new(title, GTK_WINDOW(parent.GetWidget()), (GtkFileChooserAction)action, NULL);
		this->SetFileChooser(GTK_FILE_CHOOSER(m_Widget));
		this->SetContext(m_Widget);
	}

	FileChooserDialog::FileChooserDialog(GtkFileChooserDialog* file_chooser_dialog) : Window::Container(this)
	{
		this->SetFileChooserDialog(file_chooser_dialog);
	}

	bool FileChooserDialog::IsFileChooserDialog()
	{
		return GTK_IS_FILE_CHOOSER_DIALOG(m_Widget);
	}

	FileChooserDialog::FileChooserDialog() : Window::Container(this)
	{
	}

	void FileChooserDialog::SetFileChooserDialog(GtkFileChooserDialog* dialog)
	{
		m_Widget = GTK_WIDGET(dialog);
		this->SetFileChooser(GTK_FILE_CHOOSER(m_Widget));
		this->SetContext(m_Widget);
	}
}
