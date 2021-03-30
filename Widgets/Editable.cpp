#include "./Editable.hh"

namespace CGui
{

	Editable::Editable(Widget& w)
	{
		m_Editable = GTK_EDITABLE(w.GetWidget());
	}

	Editable::Editable() : m_Editable(nullptr)
	{
	}

	void Editable::SetEditable(Widget& w)
	{
		m_Editable = GTK_EDITABLE(w.GetWidget());
	}

	void Editable::SelectRegion(int start_pos, int end_pos)
	{
		gtk_editable_select_region(GTK_EDITABLE(m_Editable), start_pos, end_pos);
	}

	CGui::SelectionBoundsData Editable::SelectionBounds()
	{
		bool found;
		int start_pos, end_pos;
		found = gtk_editable_get_selection_bounds(GTK_EDITABLE(m_Editable), &start_pos, &end_pos);

		return { found, start_pos, end_pos };
	}

	void Editable::InsertText(const char* new_text, int new_text_length, int position)
	{
		gtk_editable_insert_text(GTK_EDITABLE(m_Editable), new_text, new_text_length, &position);
	}

	void Editable::DeleteText(int start_pos, int end_pos)
	{
		gtk_editable_delete_text(GTK_EDITABLE(m_Editable), start_pos, end_pos);
	}

	const char* Editable::Chars(int start_pos, int end_pos)
	{
		return gtk_editable_get_chars(GTK_EDITABLE(m_Editable), start_pos, end_pos);
	}

	void Editable::CutClipboard()
	{
		gtk_editable_cut_clipboard(GTK_EDITABLE(m_Editable));
	}

	void Editable::CopyClipboard()
	{
		gtk_editable_copy_clipboard(GTK_EDITABLE(m_Editable));
	}

	void Editable::PasteClipboard()
	{
		gtk_editable_paste_clipboard(GTK_EDITABLE(m_Editable));
	}

	void Editable::DeleteSelection()
	{
		gtk_editable_delete_selection(GTK_EDITABLE(m_Editable));
	}

	int Editable::Position()
	{
		return gtk_editable_get_position(GTK_EDITABLE(m_Editable));
	}

	void Editable::Position(int position)
	{
		gtk_editable_set_position(GTK_EDITABLE(m_Editable), position);
	}

	bool Editable::TextEditable()
	{
		return gtk_editable_get_editable(GTK_EDITABLE(m_Editable));
	}

	void Editable::TextEditable(bool editable)
	{
		gtk_editable_set_editable(GTK_EDITABLE(m_Editable), editable);
	}

	GtkEditable* Editable::GetEditable()
	{
		return m_Editable;
	}

	bool Editable::IsEditable()
	{
		return GTK_IS_EDITABLE(m_Editable);
	}

}