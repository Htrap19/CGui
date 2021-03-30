#pragma once

#include <gtk/gtk.h>
#include "./Widget.hh"

namespace CGui
{
	class Editable
	{
	public:
		Editable();
		Editable(Widget& w);
		virtual void SetEditable(Widget& w);
		virtual void SelectRegion(int start_pos, int end_pos);
		virtual SelectionBoundsData SelectionBounds();
		virtual void InsertText(const char* new_text, int new_text_length, int position);
		virtual void DeleteText(int start_pos, int end_pos);
		virtual const char* Chars(int start_pos, int end_pos);
		virtual void CutClipboard();
		virtual void CopyClipboard();
		virtual void PasteClipboard();
		virtual void DeleteSelection();
		virtual void Position(int position);
		virtual int Position();
		virtual void TextEditable(bool editable);
		virtual bool TextEditable();
		virtual GtkEditable* GetEditable();

		bool IsEditable();

	protected:
		GtkEditable* m_Editable;
	};
}