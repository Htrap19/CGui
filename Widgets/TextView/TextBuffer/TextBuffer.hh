#pragma once

#include <gtk/gtk.h>
#include "../TextMark/TextMark.hh"

namespace CGui
{
	class TextBuffer
	{
	public:
		TextBuffer();
		TextBuffer(GtkTextBuffer* buffer);
		int LineCount();
		int CharCount();
		void InsertAtCursor(const char* text, int len = -1);
		void InsertInteractiveAtCursor(const char* text, bool default_editable, int len = -1);
		void Text(const char* text, int len = -1);
		TextMark Mark(const char* name);
		TextMark Insert();
		TextMark SelectionBound();
		bool HasSelection();
		void Modified(bool modified);
		bool Modified();
		bool DeleteSelection(bool interactive, bool default_editable);
		void BeginUserAction();
		void EndUserAction();

		GtkTextBuffer* GetWidget() const;

		bool IsTextBuffer();

	protected:
		GtkTextBuffer* buffer;
	};
}