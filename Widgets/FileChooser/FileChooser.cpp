#include "./FileChooser.hh"

namespace CGui
{
	FileChooser::FileChooser(FileChooserAction action) : Orientable(this)
	{
		widget = gtk_file_chooser_widget_new((GtkFileChooserAction)action);
		this->SetContext(widget);
	}

	void FileChooser::ChooseAction(FileChooserAction action)
	{
		gtk_file_chooser_set_action(GTK_FILE_CHOOSER(widget), (GtkFileChooserAction)action);
	}

	FileChooserAction FileChooser::ChooseAction()
	{
		return (FileChooserAction)gtk_file_chooser_get_action(GTK_FILE_CHOOSER(widget));
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

	void FileChooser::UnselectAll()
	{
		gtk_file_chooser_unselect_all(GTK_FILE_CHOOSER(widget));
	}

	Single::List<const char*> FileChooser::Filenames()
	{
		auto list = gtk_file_chooser_get_filenames(GTK_FILE_CHOOSER(widget));
		Single::List<const char*> ret;
		
		for (GSList* li = list; li != NULL; li = li->next)
		{
			ret.Insert((const char*)li->data);
		}

		g_slist_free(list);

		return ret;
	}

	bool FileChooser::CurrentFolder(const char* filename)
	{
		return gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(widget), filename);
	}

	const char* FileChooser::CurrentFolder()
	{
		return gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(widget));
	}

	void FileChooser::Uri(const char* uri)
	{
		gtk_file_chooser_set_uri(GTK_FILE_CHOOSER(widget), uri);
	}

	const char* FileChooser::Uri()
	{
		return gtk_file_chooser_get_uri(GTK_FILE_CHOOSER(widget));
	}

	bool FileChooser::SelectUri(const char* uri)
	{
		return gtk_file_chooser_select_uri(GTK_FILE_CHOOSER(widget), uri);
	}

	void FileChooser::UnselectUri(const char* uri)
	{
		gtk_file_chooser_unselect_uri(GTK_FILE_CHOOSER(widget), uri);
	}

	Single::List<const char*> FileChooser::Uris()
	{
		auto list = gtk_file_chooser_get_uris(GTK_FILE_CHOOSER(widget));
		Single::List<const char*> ret;

		for (GSList* li = list; li != NULL; li = li->next)
		{
			ret.Insert((const char*)li->data);
		}

		g_slist_free(list);

		return ret;
	}

	void FileChooser::PreviewWidget(Widget& w)
	{
		gtk_file_chooser_set_preview_widget(GTK_FILE_CHOOSER(widget), w.GetWidget());
	}

	Widget FileChooser::PreviewWidget()
	{
		return Widget(gtk_file_chooser_get_preview_widget(GTK_FILE_CHOOSER(widget)));
	}

	void FileChooser::PreviewWidgetActive(bool active)
	{
		gtk_file_chooser_set_preview_widget_active(GTK_FILE_CHOOSER(widget), active);
	}

	bool FileChooser::PreviewWidgetActive()
	{
		return gtk_file_chooser_get_preview_widget_active(GTK_FILE_CHOOSER(widget));
	}

	void FileChooser::UsePreviewLabel(bool use_label)
	{
		gtk_file_chooser_set_use_preview_label(GTK_FILE_CHOOSER(widget), use_label);
	}

	bool FileChooser::UsePreviewLabel()
	{
		return gtk_file_chooser_get_use_preview_label(GTK_FILE_CHOOSER(widget));
	}

	const char* FileChooser::PreviewFilename()
	{
		return gtk_file_chooser_get_preview_filename(GTK_FILE_CHOOSER(widget));
	}

	const char* FileChooser::PreviewUri()
	{
		return gtk_file_chooser_get_preview_uri(GTK_FILE_CHOOSER(widget));
	}

	void FileChooser::ExtraWidget(Widget& w)
	{
		gtk_file_chooser_set_extra_widget(GTK_FILE_CHOOSER(widget), w.GetWidget());
	}

	Widget FileChooser::ExtraWidget()
	{
		return Widget(gtk_file_chooser_get_extra_widget(GTK_FILE_CHOOSER(widget)));
	}

	bool FileChooser::AddShortcutFolder(const char* folder)
	{
		GError* error = NULL;
		if (gtk_file_chooser_add_shortcut_folder(GTK_FILE_CHOOSER(widget), folder, &error))
			return true;
		else
		{
			fprintf(stderr, "%s\n", error->message);
			g_error_free(error);
			return false;
		}
	}

	bool FileChooser::RemoveShortcutFolder(const char* folder)
	{
		GError* error;
		if (gtk_file_chooser_remove_shortcut_folder(GTK_FILE_CHOOSER(widget), folder, &error))
			return true;
		else
		{
			fprintf(stderr, "%s\n", error->message);
			g_error_free(error);
			return false;
		}
	}

	Single::List<const char*> FileChooser::ListShortcutFolders()
	{
		auto list = gtk_file_chooser_list_shortcut_folders(GTK_FILE_CHOOSER(widget));
		Single::List<const char*> ret;

		for (GSList* li = list; li != NULL; li = li->next)
		{
			ret.Insert((const char*)li->data);
		}

		g_slist_free(list);

		return ret;
	}

	bool FileChooser::AddShortcutFolderUri(const char* uri)
	{
		GError* error;
		if (gtk_file_chooser_add_shortcut_folder_uri(GTK_FILE_CHOOSER(widget), uri, &error))
			return true;
		else
		{
			fprintf(stderr, "%s\n", error->message);
			g_error_free(error);
			return false;
		}
	}

	bool FileChooser::RemoveShortcutFolderUri(const char* uri)
	{
		GError* error;
		if (gtk_file_chooser_remove_shortcut_folder_uri(GTK_FILE_CHOOSER(widget), uri, &error))
			return true;
		else
		{
			fprintf(stderr, "%s\n", error->message);
			g_error_free(error);
			return false;
		}
	}

	Single::List<const char*> FileChooser::ListShortCutFolderUri()
	{
		auto list = gtk_file_chooser_list_shortcut_folder_uris(GTK_FILE_CHOOSER(widget));
		Single::List<const char*> ret;

		for (GSList* li = list; li != NULL; li = li->next)
		{
			ret.Insert((const char*)li->data);
		}

		g_slist_free(list);

		return ret;
	}

	bool FileChooser::IsFileChooser()
	{
		return GTK_IS_FILE_CHOOSER(widget);
	}

	FileChooser::FileChooser() : Orientable(this)
	{ }

	void FileChooser::SetFileChooser(GtkFileChooser* filechooser)
	{
		this->widget = GTK_WIDGET(filechooser);
		this->SetContext(widget);
	}
};
