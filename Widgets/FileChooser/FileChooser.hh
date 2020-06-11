#pragma once

#include "../Widget.hh"

namespace CGui
{
	class FileChooser : public Widget
	{
	public:
		FileChooser(Action action);
		void ChooseAction(Action action);
		Action ChooseAction();
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
	};
};
