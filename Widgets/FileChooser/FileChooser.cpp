#include "./FileChooser.hh"

namespace CGui
{
	FileChooser::FileChooser(Action action)
	{
		widget = gtk_file_chooser_widget_new((GtkFileChooserAction)action);
		this->SetContext(widget);
	}

	void FileChooser::ChooseAction(Action action)
	{
		gtk_file_chooser_set_action(GTK_FILE_CHOOSER(widget), (GtkFileChooserAction)action);
	}

	Action FileChooser::ChooseAction()
	{
		return (Action)gtk_file_chooser_get_action(GTK_FILE_CHOOSER(widget));
	}

	void FileChooser::LocalOnly(bool local_only)
	{
		gtk_file_chooser_set_local_only(GTK_FILE_CHOOSER(widget), local_only);
	}

	bool FileChooser::LocalOnly()
	{
		return gtk_file_chooser_get_local_only(GTK_FILE_CHOOSER(widget));
	}

	void FileChooser::SelectMultiple(bool select_multiple)
	{
		gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(widget), select_multiple);
	}

	bool FileChooser::SelectMultiple()
	{
		return gtk_file_chooser_get_select_multiple(GTK_FILE_CHOOSER(widget));
	}

	void FileChooser::DoOverwriteConfirmation(bool do_overwrite_confirmation)
	{
		gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(widget), do_overwrite_confirmation);
	}

	bool FileChooser::DoOverwriteConfirmation()
	{
		return gtk_file_chooser_get_do_overwrite_confirmation(GTK_FILE_CHOOSER(widget));
	}

	void FileChooser::CreateFolders(bool create_folders)
	{
		gtk_file_chooser_set_create_folders(GTK_FILE_CHOOSER(widget), create_folders);
	}

	bool FileChooser::CreateFolders()
	{
		return gtk_file_chooser_get_create_folders(GTK_FILE_CHOOSER(widget));
	}

	void FileChooser::CurrentName(const char* name)
	{
		gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(widget), name);
	}

	const char* FileChooser::CurrentName()
	{
		return gtk_file_chooser_get_current_name(GTK_FILE_CHOOSER(widget));
	}

	void FileChooser::Filename(const char* filename)
	{
		gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(widget), filename);
	}

	const char* FileChooser::Filename()
	{
		return gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(widget));
	}

	bool FileChooser::SelectFilename(const char* filename)
	{
		return gtk_file_chooser_select_filename(GTK_FILE_CHOOSER(widget), filename);
	}

	void FileChooser::UnselectFilename(const char* filename)
	{
		gtk_file_chooser_unselect_filename(GTK_FILE_CHOOSER(widget), filename);
	}

	void FileChooser::SelectAll()
	{
		gtk_file_chooser_select_all(GTK_FILE_CHOOSER(widget));
	}
};
