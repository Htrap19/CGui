#include "./FileChooser.hh"

#include "../Custom/VectorsUtilities/VectorUtilities.hh"

namespace CGui
{
	FileChooser::FileChooser() : m_FileChooser{ nullptr }
	{
	}

	FileChooser::FileChooser(Widget& widget)
	{
		m_FileChooser = GTK_FILE_CHOOSER(widget.GetWidget());
	}

	FileChooserAction FileChooser::ChooseAction()
	{
		return (FileChooserAction)gtk_file_chooser_get_action(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::ChooseAction(FileChooserAction action)
	{
		gtk_file_chooser_set_action(GTK_FILE_CHOOSER(m_FileChooser), (GtkFileChooserAction)action);
	}

	bool FileChooser::LocalOnly()
	{
		return gtk_file_chooser_get_local_only(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::LocalOnly(bool local_only)
	{
		gtk_file_chooser_set_local_only(GTK_FILE_CHOOSER(m_FileChooser), local_only);
	}

	bool FileChooser::SelectMultiple()
	{
		return gtk_file_chooser_get_select_multiple(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::SelectMultiple(bool select_multiple)
	{
		gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(m_FileChooser), select_multiple);
	}

	bool FileChooser::DoOverwriteConfirmation()
	{
		return gtk_file_chooser_get_do_overwrite_confirmation(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::DoOverwriteConfirmation(bool do_overwrite_confirmation)
	{
		gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(m_FileChooser), do_overwrite_confirmation);
	}

	bool FileChooser::CreateFolders()
	{
		return gtk_file_chooser_get_create_folders(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::CreateFolders(bool create_folders)
	{
		gtk_file_chooser_set_create_folders(GTK_FILE_CHOOSER(m_FileChooser), create_folders);
	}

	const char* FileChooser::CurrentName()
	{
		return gtk_file_chooser_get_current_name(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::CurrentName(const char* name)
	{
		gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(m_FileChooser), name);
	}

	const char* FileChooser::Filename()
	{
		return gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::Filename(const char* filename)
	{
		gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(m_FileChooser), filename);
	}

	bool FileChooser::SelectFilename(const char* filename)
	{
		return gtk_file_chooser_select_filename(GTK_FILE_CHOOSER(m_FileChooser), filename);
	}

	void FileChooser::UnselectFilename(const char* filename)
	{
		gtk_file_chooser_unselect_filename(GTK_FILE_CHOOSER(m_FileChooser), filename);
	}

	void FileChooser::SelectAll()
	{
		gtk_file_chooser_select_all(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::UnselectAll()
	{
		gtk_file_chooser_unselect_all(GTK_FILE_CHOOSER(m_FileChooser));
	}

	Vector<std::string> FileChooser::Filenames()
	{
		auto list = gtk_file_chooser_get_filenames(GTK_FILE_CHOOSER(m_FileChooser));
		Vector<std::string> filenames(std::move(GSListToStringVector(list)));
		g_slist_free(list);
		return std::move(filenames);
	}

	const char* FileChooser::CurrentFolder()
	{
		return gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(m_FileChooser));
	}

	bool FileChooser::CurrentFolder(const char* filename)
	{
		return gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(m_FileChooser), filename);
	}

	const char* FileChooser::Uri()
	{
		return gtk_file_chooser_get_uri(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::Uri(const char* uri)
	{
		gtk_file_chooser_set_uri(GTK_FILE_CHOOSER(m_FileChooser), uri);
	}

	bool FileChooser::SelectUri(const char* uri)
	{
		return gtk_file_chooser_select_uri(GTK_FILE_CHOOSER(m_FileChooser), uri);
	}

	void FileChooser::UnselectUri(const char* uri)
	{
		gtk_file_chooser_unselect_uri(GTK_FILE_CHOOSER(m_FileChooser), uri);
	}

	Vector<std::string> FileChooser::Uris()
	{
		auto list = gtk_file_chooser_get_uris(GTK_FILE_CHOOSER(m_FileChooser));
		Vector<std::string> uris(std::move(GSListToStringVector(list)));		
		g_slist_free(list);
		return std::move(uris);
	}

	Widget FileChooser::PreviewWidget()
	{
		return Widget(gtk_file_chooser_get_preview_widget(GTK_FILE_CHOOSER(m_FileChooser)));
	}

	void FileChooser::PreviewWidget(Widget& w)
	{
		gtk_file_chooser_set_preview_widget(GTK_FILE_CHOOSER(m_FileChooser), w.GetWidget());
	}

	bool FileChooser::PreviewWidgetActive()
	{
		return gtk_file_chooser_get_preview_widget_active(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::PreviewWidgetActive(bool active)
	{
		gtk_file_chooser_set_preview_widget_active(GTK_FILE_CHOOSER(m_FileChooser), active);
	}

	bool FileChooser::UsePreviewLabel()
	{
		return gtk_file_chooser_get_use_preview_label(GTK_FILE_CHOOSER(m_FileChooser));
	}

	void FileChooser::UsePreviewLabel(bool use_label)
	{
		gtk_file_chooser_set_use_preview_label(GTK_FILE_CHOOSER(m_FileChooser), use_label);
	}

	const char* FileChooser::PreviewFilename()
	{
		return gtk_file_chooser_get_preview_filename(GTK_FILE_CHOOSER(m_FileChooser));
	}

	const char* FileChooser::PreviewUri()
	{
		return gtk_file_chooser_get_preview_uri(GTK_FILE_CHOOSER(m_FileChooser));
	}

	Widget FileChooser::ExtraWidget()
	{
		return Widget(gtk_file_chooser_get_extra_widget(GTK_FILE_CHOOSER(m_FileChooser)));
	}

	void FileChooser::ExtraWidget(Widget& w)
	{
		gtk_file_chooser_set_extra_widget(GTK_FILE_CHOOSER(m_FileChooser), w.GetWidget());
	}

	bool FileChooser::AddShortcutFolder(const char* folder)
	{
		GError* error = nullptr;
		if (gtk_file_chooser_add_shortcut_folder(GTK_FILE_CHOOSER(m_FileChooser), folder, &error))
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
		if (gtk_file_chooser_remove_shortcut_folder(GTK_FILE_CHOOSER(m_FileChooser), folder, &error))
			return true;
		else
		{
			fprintf(stderr, "%s\n", error->message);
			g_error_free(error);
			return false;
		}
	}

	Vector<std::string> FileChooser::ListShortcutFolders()
	{
		auto list = gtk_file_chooser_list_shortcut_folders(GTK_FILE_CHOOSER(m_FileChooser));
		Vector<std::string> shortcutfolders(std::move(GSListToStringVector(list)));
		g_slist_free(list);
		return std::move(shortcutfolders);
	}

	bool FileChooser::AddShortcutFolderUri(const char* uri)
	{
		GError* error;
		if (gtk_file_chooser_add_shortcut_folder_uri(GTK_FILE_CHOOSER(m_FileChooser), uri, &error))
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
		if (gtk_file_chooser_remove_shortcut_folder_uri(GTK_FILE_CHOOSER(m_FileChooser), uri, &error))
			return true;
		else
		{
			fprintf(stderr, "%s\n", error->message);
			g_error_free(error);
			return false;
		}
	}

	Vector<std::string> FileChooser::ListShortCutFolderUri()
	{
		auto list = gtk_file_chooser_list_shortcut_folder_uris(GTK_FILE_CHOOSER(m_FileChooser));
		Vector<std::string> shortcutfolderuris(std::move(GSListToStringVector(list)));
		g_slist_free(list);
		return std::move(shortcutfolderuris);
	}

	bool FileChooser::IsFileChooser()
	{
		return GTK_IS_FILE_CHOOSER(m_FileChooser);
	}

	void FileChooser::SetFileChooser(GtkFileChooser* filechooser)
	{
		this->m_FileChooser = filechooser;
	}
}
