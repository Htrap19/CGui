#pragma once

#include "../Widget.hh"
#include "../Orientable.hh"
#include "../FileChooser.hh"

namespace CGui
{
	class FileChooserWidget : public virtual Widget, public virtual Orientable, public virtual FileChooser
	{
	public:
		FileChooserWidget(GtkFileChooserWidget* file_chooser);
		FileChooserWidget(FileChooserAction action);
		bool IsFileChooserWidget();

	protected:
		FileChooserWidget();
		void SetFileChooserWidget(GtkFileChooserWidget* filechooserwidget);
	};
};
