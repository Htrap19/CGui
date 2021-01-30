#pragma once

#include "../Widget.hh"
#include "../Dialog/Dialog.hh"
#include "../FileChooser.hh"
#include "../Window/Window.hh"

namespace CGui
{
	class FileChooserDialog : public virtual Dialog, public virtual FileChooser
	{
	public:
		FileChooserDialog(Window& parent, const char* title, FileChooserAction action);
		FileChooserDialog(GtkFileChooserDialog* file_chooser_dialog);
		bool IsFileChooserDialog();

	protected:
		FileChooserDialog();
		void SetFileChooserDialog(GtkFileChooserDialog* dialog);
	};
}