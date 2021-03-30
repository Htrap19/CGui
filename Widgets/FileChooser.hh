#pragma once

#include "./Widget.hh"

namespace CGui
{
	class FileChooser
	{
	public:
		FileChooser(Widget& widget);
		FileChooser();
		void ChooseAction(FileChooserAction action);
		FileChooserAction ChooseAction();
		void LocalOnly(bool local_only);
		bool LocalOnly();
		void SelectMultiple(bool select_multiple);
		bool SelectMultiple();
		void DoOverwriteConfirmation(bool do_overwrite_confirmation);
		bool DoOverwriteConfirmation();
		void CreateFolders(bool create_folders);
		bool CreateFolders();
		void CurrentName(const char* name);
		const char* CurrentName();
		void Filename(const char* filename);
		const char* Filename();
		bool SelectFilename(const char* filename);
		void UnselectFilename(const char* filename);
		void SelectAll();
		void UnselectAll();
		Vector<std::string> Filenames();
		bool CurrentFolder(const char* filename);
		const char* CurrentFolder();
		void Uri(const char* uri);
		const char* Uri();
		bool SelectUri(const char* uri);
		void UnselectUri(const char* uri);
		Vector<std::string> Uris();
		void PreviewWidget(Widget& w);
		Widget PreviewWidget();
		void PreviewWidgetActive(bool active);
		bool PreviewWidgetActive();
		void UsePreviewLabel(bool use_label);
		bool UsePreviewLabel();
		const char* PreviewFilename();
		const char* PreviewUri();
		void ExtraWidget(Widget& w);
		Widget ExtraWidget();
		bool AddShortcutFolder(const char* folder);
		bool RemoveShortcutFolder(const char* folder);
		Vector<std::string> ListShortcutFolders();
		bool AddShortcutFolderUri(const char* uri);
		bool RemoveShortcutFolderUri(const char* uri);
		Vector<std::string> ListShortCutFolderUri();
		bool IsFileChooser();
		void SetFileChooser(GtkFileChooser* filechooser);

	protected:
		GtkFileChooser* m_FileChooser;
	};
}