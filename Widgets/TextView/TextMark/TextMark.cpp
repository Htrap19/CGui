#include "TextMark.hh"

#include "../TextBuffer/TextBuffer.hh"

namespace CGui
{
	TextMark::TextMark(const char* name, bool left_gravity)
	{
		mark = gtk_text_mark_new(name, left_gravity);
	}

	TextMark::TextMark(GtkTextMark* mark)
	{
		this->mark = mark;
	}

	void TextMark::Visible(bool visible)
	{
		gtk_text_mark_set_visible(mark, visible);
	}

	bool TextMark::Visible()
	{
		return gtk_text_mark_get_visible(mark);
	}

	bool TextMark::Deleted()
	{
		return gtk_text_mark_get_deleted(mark);
	}

	const char* TextMark::Name()
	{
		return gtk_text_mark_get_name(mark);
	}

	TextBuffer TextMark::Buffer()
	{
		return TextBuffer(gtk_text_mark_get_buffer(mark));
	}

	bool TextMark::LeftGravity()
	{
		return gtk_text_mark_get_left_gravity(mark);
	}

	GtkTextMark* TextMark::GetWidget() const
	{
		return mark;
	}

	bool TextMark::IsTextMark()
	{
		return GTK_IS_TEXT_MARK(mark);
	}

}
