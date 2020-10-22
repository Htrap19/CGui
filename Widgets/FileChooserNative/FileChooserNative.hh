#pragma once

#include "../FileChooser/FileChooser.hh"
#include "../NativeDialog.hh"
#include "../Window/Window.hh"

namespace CGui
{
	class FileChooserNative : public FileChooser, public NativeDialog
	{
	public:
		FileChooserNative(const char* title, Window& parent, FileChooserAction action, const char* accept_label, const char* cancel_label);
		void AcceptLabel(const char* label);
		const char* AcceptLabel();
		void CancelLabel(const char* label);
		const char* CancelLabel();
		bool IsFileChooserNative();
	};
}