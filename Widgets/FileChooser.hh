#pragma once

#include "./Widget.hh"

namespace CGui
{
	class FileChooser
	{
	public:
		FileChooser(Widget& widget)
		{
			filechooser = GTK_FILE_CHOOSER(widget.GetWidget());
		}

		FileChooser() : filechooser{ nullptr }
		{ }

		void ChooseAction(FileChooserAction action)
		{
			gtk_file_chooser_set_action(GTK_FILE_CHOOSER(filechooser), (GtkFileChooserAction)action);
		}

		FileChooserAction ChooseAction()
		{
			return (FileChooserAction)gtk_file_chooser_get_action(GTK_FILE_CHOOSER(filechooser));
		}

		void LocalOnly(bool local_only)
		{
			gtk_file_chooser_set_local_only(GTK_FILE_CHOOSER(filechooser), local_only);
		}

		bool LocalOnly()
		{
			return gtk_file_chooser_get_local_only(GTK_FILE_CHOOSER(filechooser));
		}

		void SelectMultiple(bool select_multiple)
		{
			gtk_file_chooser_set_select_multiple(GTK_FILE_CHOOSER(filechooser), select_multiple);
		}

		bool SelectMultiple()
		{
			return gtk_file_chooser_get_select_multiple(GTK_FILE_CHOOSER(filechooser));
		}

		void DoOverwriteConfirmation(bool do_overwrite_confirmation)
		{
			gtk_file_chooser_set_do_overwrite_confirmation(GTK_FILE_CHOOSER(filechooser), do_overwrite_confirmation);
		}

		bool DoOverwriteConfirmation()
		{
			return gtk_file_chooser_get_do_overwrite_confirmation(GTK_FILE_CHOOSER(filechooser));
		}

		void CreateFolders(bool create_folders)
		{
			gtk_file_chooser_set_create_folders(GTK_FILE_CHOOSER(filechooser), create_folders);
		}

		bool CreateFolders()
		{
			return gtk_file_chooser_get_create_folders(GTK_FILE_CHOOSER(filechooser));
		}

		void CurrentName(const char* name)
		{
			gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(filechooser), name);
		}

		const char* CurrentName()
		{
			return gtk_file_chooser_get_current_name(GTK_FILE_CHOOSER(filechooser));
		}

		void Filename(const char* filename)
		{
			gtk_file_chooser_set_filename(GTK_FILE_CHOOSER(filechooser), filename);
		}

		const char* Filename()
		{
			return gtk_file_chooser_get_filename(GTK_FILE_CHOOSER(filechooser));
		}

		bool SelectFilename(const char* filename)
		{
			return gtk_file_chooser_select_filename(GTK_FILE_CHOOSER(filechooser), filename);
		}

		void UnselectFilename(const char* filename)
		{
			gtk_file_chooser_unselect_filename(GTK_FILE_CHOOSER(filechooser), filename);
		}

		void SelectAll()
		{
			gtk_file_chooser_select_all(GTK_FILE_CHOOSER(filechooser));
		}

		void UnselectAll()
		{
			gtk_file_chooser_unselect_all(GTK_FILE_CHOOSER(filechooser));
		}

		Single::List<const char*> Filenames()
		{
			auto list = gtk_file_chooser_get_filenames(GTK_FILE_CHOOSER(filechooser));
			Single::List<const char*> ret;

			for (GSList* li = list; li != NULL; li = li->next)
			{
				ret.Insert((const char*)li->data);
			}

			g_slist_free(list);

			return ret;
		}

		bool CurrentFolder(const char* filename)
		{
			return gtk_file_chooser_set_current_folder(GTK_FILE_CHOOSER(filechooser), filename);
		}

		const char* CurrentFolder()
		{
			return gtk_file_chooser_get_current_folder(GTK_FILE_CHOOSER(filechooser));
		}

		void Uri(const char* uri)
		{
			gtk_file_chooser_set_uri(GTK_FILE_CHOOSER(filechooser), uri);
		}

		const char* Uri()
		{
			return gtk_file_chooser_get_uri(GTK_FILE_CHOOSER(filechooser));
		}

		bool SelectUri(const char* uri)
		{
			return gtk_file_chooser_select_uri(GTK_FILE_CHOOSER(filechooser), uri);
		}

		void UnselectUri(const char* uri)
		{
			gtk_file_chooser_unselect_uri(GTK_FILE_CHOOSER(filechooser), uri);
		}

		Single::List<const char*> Uris()
		{
			auto list = gtk_file_chooser_get_uris(GTK_FILE_CHOOSER(filechooser));
			Single::List<const char*> ret;

			for (GSList* li = list; li != NULL; li = li->next)
			{
				ret.Insert((const char*)li->data);
			}

			g_slist_free(list);

			return ret;
		}

		void PreviewWidget(Widget& w)
		{
			gtk_file_chooser_set_preview_widget(GTK_FILE_CHOOSER(filechooser), w.GetWidget());
		}

		Widget PreviewWidget()
		{
			return Widget(gtk_file_chooser_get_preview_widget(GTK_FILE_CHOOSER(filechooser)));
		}

		void PreviewWidgetActive(bool active)
		{
			gtk_file_chooser_set_preview_widget_active(GTK_FILE_CHOOSER(filechooser), active);
		}

		bool PreviewWidgetActive()
		{
			return gtk_file_chooser_get_preview_widget_active(GTK_FILE_CHOOSER(filechooser));
		}

		void UsePreviewLabel(bool use_label)
		{
			gtk_file_chooser_set_use_preview_label(GTK_FILE_CHOOSER(filechooser), use_label);
		}

		bool UsePreviewLabel()
		{
			return gtk_file_chooser_get_use_preview_label(GTK_FILE_CHOOSER(filechooser));
		}

		const char* PreviewFilename()
		{
			return gtk_file_chooser_get_preview_filename(GTK_FILE_CHOOSER(filechooser));
		}

		const char* PreviewUri()
		{
			return gtk_file_chooser_get_preview_uri(GTK_FILE_CHOOSER(filechooser));
		}

		void ExtraWidget(Widget& w)
		{
			gtk_file_chooser_set_extra_widget(GTK_FILE_CHOOSER(filechooser), w.GetWidget());
		}

		Widget ExtraWidget()
		{
			return Widget(gtk_file_chooser_get_extra_widget(GTK_FILE_CHOOSER(filechooser)));
		}

		bool AddShortcutFolder(const char* folder)
		{
			GError* error = NULL;
			if (gtk_file_chooser_add_shortcut_folder(GTK_FILE_CHOOSER(filechooser), folder, &error))
				return true;
			else
			{
				fprintf(stderr, "%s\n", error->message);
				g_error_free(error);
				return false;
			}
		}

		bool RemoveShortcutFolder(const char* folder)
		{
			GError* error;
			if (gtk_file_chooser_remove_shortcut_folder(GTK_FILE_CHOOSER(filechooser), folder, &error))
				return true;
			else
			{
				fprintf(stderr, "%s\n", error->message);
				g_error_free(error);
				return false;
			}
		}

		Single::List<const char*> ListShortcutFolders()
		{
			auto list = gtk_file_chooser_list_shortcut_folders(GTK_FILE_CHOOSER(filechooser));
			Single::List<const char*> ret;

			for (GSList* li = list; li != NULL; li = li->next)
			{
				ret.Insert((const char*)li->data);
			}

			g_slist_free(list);

			return ret;
		}

		bool AddShortcutFolderUri(const char* uri)
		{
			GError* error;
			if (gtk_file_chooser_add_shortcut_folder_uri(GTK_FILE_CHOOSER(filechooser), uri, &error))
				return true;
			else
			{
				fprintf(stderr, "%s\n", error->message);
				g_error_free(error);
				return false;
			}
		}

		bool RemoveShortcutFolderUri(const char* uri)
		{
			GError* error;
			if (gtk_file_chooser_remove_shortcut_folder_uri(GTK_FILE_CHOOSER(filechooser), uri, &error))
				return true;
			else
			{
				fprintf(stderr, "%s\n", error->message);
				g_error_free(error);
				return false;
			}
		}

		Single::List<const char*> ListShortCutFolderUri()
		{
			auto list = gtk_file_chooser_list_shortcut_folder_uris(GTK_FILE_CHOOSER(filechooser));
			Single::List<const char*> ret;

			for (GSList* li = list; li != NULL; li = li->next)
			{
				ret.Insert((const char*)li->data);
			}

			g_slist_free(list);

			return ret;
		}

		bool IsFileChooser()
		{
			return GTK_IS_FILE_CHOOSER(filechooser);
		}

		void SetFileChooser(GtkFileChooser* filechooser)
		{
			this->filechooser = filechooser;
		}

	protected:
		GtkFileChooser* filechooser;
	};
}