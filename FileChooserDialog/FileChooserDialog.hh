#pragma once

#include "../Widgets/FileChooser/FileChooser.hh"
#include "../Widgets/Dialog/Dialog.hh"
#include "../Widgets/Headerbar/Headerbar.hh"
#include "../Widgets/Window/Window.hh"

namespace CGui
{
	class FileChooserDialog
	{
	public:
		FileChooserDialog(Action action, Window& window, const char* title);
	};
};
