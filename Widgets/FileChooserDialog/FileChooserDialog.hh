#pragma once

#include "../Widget.hh"
#include "../Dialog/Dialog.hh"
#include "../FileChooser/FileChooser.hh"
#include "../Window/Window.hh"

namespace CGui
{
	class FileChooserDialog : public Dialog, public FileChooser
	{
	public:
		FileChooserDialog(Window& parent, const char* title, FileChooserAction action);
		bool IsFileChooserDialog();

	protected:
		FileChooserDialog();
		void SetFileChooserDialog(GtkFileChooserDialog* dialog);
	};
}