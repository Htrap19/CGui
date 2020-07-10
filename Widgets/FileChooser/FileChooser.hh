#pragma once

#include "../Widget.hh"
#include "../Orientable.hh"

namespace CGui
{
	class FileChooser : public Widget, public Orientable
	{
	public:
		FileChooser(FileChooserAction action);
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
		Single::List<const char*> Filenames();
		bool CurrentFolder(const char* filename);
		const char* CurrentFolder();
		void Uri(const char* uri);
		const char* Uri();
		bool SelectUri(const char* uri);
		void UnselectUri(const char* uri);
		Single::List<const char*> Uris();
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
		Single::List<const char*> ListShortcutFolders();
		bool AddShortcutFolderUri(const char* uri);
		bool RemoveShortcutFolderUri(const char* uri);
		Single::List<const char*> ListShortCutFolderUri();

	protected:
		FileChooser();
		void SetFileChooser(GtkFileChooser* filechooser);
	};
};
