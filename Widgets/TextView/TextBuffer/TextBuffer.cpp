#include "TextBuffer.hh"

namespace CGui
{
	TextBuffer::TextBuffer()
	{
		buffer = gtk_text_buffer_new(NULL);
	}

	TextBuffer::TextBuffer(GtkTextBuffer* buffer)
	{
		this->buffer = buffer;
	}

	int TextBuffer::LineCount()
	{
		return gtk_text_buffer_get_line_count(buffer);
	}

	int TextBuffer::CharCount()
	{
		return gtk_text_buffer_get_char_count(buffer);
	}

	void TextBuffer::InsertAtCursor(const char* text, int len /*= -1*/)
	{
		gtk_text_buffer_insert_at_cursor(buffer, text, len);
	}

	void TextBuffer::InsertInteractiveAtCursor(const char* text, bool default_editable, int len /*= -1*/)
	{
		gtk_text_buffer_insert_interactive_at_cursor(buffer, text, default_editable, len);
	}

	void TextBuffer::Text(const char* text, int len /*= -1*/)
	{
		gtk_text_buffer_set_text(buffer, text, len);
	}

	CGui::TextMark TextBuffer::Mark(const char* name)
	{
		return TextMark(gtk_text_buffer_get_mark(buffer, name));
	}

	CGui::TextMark TextBuffer::Insert()
	{
		return TextMark(gtk_text_buffer_get_insert(buffer));
	}

	CGui::TextMark TextBuffer::SelectionBound()
	{
		return TextMark(gtk_text_buffer_get_selection_bound(buffer));
	}

	bool TextBuffer::HasSelection()
	{
		return gtk_text_buffer_get_has_selection(buffer);
	}

	void TextBuffer::Modified(bool modified)
	{
		gtk_text_buffer_set_modified(buffer, modified);
	}

	bool TextBuffer::Modified()
	{
		return gtk_text_buffer_get_modified(buffer);
	}

	bool TextBuffer::DeleteSelection(bool interactive, bool default_editable)
	{
		return gtk_text_buffer_delete_selection(buffer, interactive, default_editable);
	}

	void TextBuffer::BeginUserAction()
	{
		gtk_text_buffer_begin_user_action(buffer);
	}

	void TextBuffer::EndUserAction()
	{
		gtk_text_buffer_end_user_action(buffer);
	}

	GtkTextBuffer* TextBuffer::GetWidget() const
	{
		return buffer;
	}

	bool TextBuffer::IsTextBuffer()
	{
		return GTK_IS_TEXT_BUFFER(buffer);
	}

}