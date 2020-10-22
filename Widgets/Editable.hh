#pragma once

#include <gtk/gtk.h>
#include "./Widget.hh"

namespace CGui
{
	class Editable
	{
	public:
		Editable()
		{

		}

		Editable(Widget& w)
		{
			m_editable = GTK_EDITABLE(w.GetWidget());
		}

		void SetEditable(Widget& w)
		{
			m_editable = GTK_EDITABLE(w.GetWidget());
		}

		void SelectRegion(int start_pos, int end_pos)
		{
			gtk_editable_select_region(GTK_EDITABLE(m_editable), start_pos, end_pos);
		}

		SelectionBoundsData SelectionBounds()
		{
			bool found;
			int start_pos, end_pos;
			found = gtk_editable_get_selection_bounds(GTK_EDITABLE(m_editable), &start_pos, &end_pos);

			return { found, start_pos, end_pos };
		}

		void InsertText(const char* new_text, int new_text_length, int position)
		{
			gtk_editable_insert_text(GTK_EDITABLE(m_editable), new_text, new_text_length, &position);
		}

		void DeleteText(int start_pos, int end_pos)
		{
			gtk_editable_delete_text(GTK_EDITABLE(m_editable), start_pos, end_pos);
		}

		const char* Chars(int start_pos, int end_pos)
		{
			return gtk_editable_get_chars(GTK_EDITABLE(m_editable), start_pos, end_pos);
		}

		void CutClipboard()
		{
			gtk_editable_cut_clipboard(GTK_EDITABLE(m_editable));
		}

		void CopyClipboard()
		{
			gtk_editable_copy_clipboard(GTK_EDITABLE(m_editable));
		}

		void PasteClipboard()
		{
			gtk_editable_paste_clipboard(GTK_EDITABLE(m_editable));
		}

		void DeleteSelection()
		{
			gtk_editable_delete_selection(GTK_EDITABLE(m_editable));
		}

		void Position(int position)
		{
			gtk_editable_set_position(GTK_EDITABLE(m_editable), position);
		}

		int Position()
		{
			return gtk_editable_get_position(GTK_EDITABLE(m_editable));
		}

		void TextEditable(bool editable)
		{
			gtk_editable_set_editable(GTK_EDITABLE(m_editable), editable);
		}

		bool TextEditable()
		{
			return gtk_editable_get_editable(GTK_EDITABLE(m_editable));
		}

		GtkEditable* GetEditable()
		{
			return m_editable;
		}

		bool IsEditable()
		{
			return GTK_IS_EDITABLE(m_editable);
		}

	protected:
		GtkEditable* m_editable;
	};
}