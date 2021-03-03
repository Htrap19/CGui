#include "TextView.hh"

namespace CGui
{
	TextView::TextChildAnchor::TextChildAnchor()
	{
		anchor = gtk_text_child_anchor_new();
	}

	Single::List<Widget> TextView::TextChildAnchor::Widgets()
	{
		auto g_list = gtk_text_child_anchor_get_widgets(anchor);
		Single::List<Widget> ret;

		for (GList* it = g_list; it != NULL; it = it->next)
		{
			ret.Insert(Widget((void*)it->data));
		}

		g_list_free(g_list);
		return ret;
	}

	bool TextView::TextChildAnchor::Deleted()
	{
		return gtk_text_child_anchor_get_deleted(anchor);
	}

	GtkTextChildAnchor* TextView::TextChildAnchor::GetWidget() const
	{
		return anchor;
	}

	TextView::TextView() : Container(this), Scrollable(*this)
	{
		widget = gtk_text_view_new();
		this->SetContext(widget);
	}

	TextView::TextView(TextBuffer& buffer) : Container(this), Scrollable(*this)
	{
		widget = gtk_text_view_new_with_buffer(buffer.GetWidget());
		this->SetContext(widget);
	}

	TextView::TextView(GtkTextView* text_view) : Container(this), Scrollable(*this)
	{
		widget = GTK_WIDGET(text_view);
		this->SetContext(widget);
	}

	void TextView::Buffer(TextBuffer& buffer)
	{
		gtk_text_view_set_buffer(GTK_TEXT_VIEW(widget), buffer.GetWidget());
	}

	TextBuffer TextView::Buffer()
	{
		return TextBuffer(gtk_text_view_get_buffer(GTK_TEXT_VIEW(widget)));
	}

	void TextView::ScrollToMark(TextMark& mark, double within_margin, bool use_align, double xalign, double yalign)
	{
		gtk_text_view_scroll_to_mark(GTK_TEXT_VIEW(widget), mark.GetWidget(), within_margin, use_align, xalign, yalign);
	}

	void TextView::ScrollMarkOnScreen(TextMark& mark)
	{
		gtk_text_view_scroll_mark_onscreen(GTK_TEXT_VIEW(widget), mark.GetWidget());
	}

	void TextView::MoveMarkOnScreen(TextMark& mark)
	{
		gtk_text_view_move_mark_onscreen(GTK_TEXT_VIEW(widget), mark.GetWidget());
	}

	bool TextView::PlaceCursorOnScreen()
	{
		return gtk_text_view_place_cursor_onscreen(GTK_TEXT_VIEW(widget));
	}

	Rectangle TextView::VisibleRect()
	{
		GdkRectangle rect;
		gtk_text_view_get_visible_rect(GTK_TEXT_VIEW(widget), &rect);
		
		return { { rect.x, rect.y }, { rect.width, rect.height } };
	}

	CoordinatesInfo TextView::BufferToWindowCoords(TextWindowType type, int buffer_x, int buffer_y)
	{
		gint window_x, window_y;

		gtk_text_view_buffer_to_window_coords(GTK_TEXT_VIEW(widget), (GtkTextWindowType)type, buffer_x, buffer_y, &window_x, &window_y);

		return { window_x, window_y };
	}

	CoordinatesInfo TextView::WindowToBufferCoords(TextWindowType type, int window_x, int window_y)
	{
		gint buffer_x, buffer_y;

		gtk_text_view_window_to_buffer_coords(GTK_TEXT_VIEW(widget), (GtkTextWindowType)type, window_x, window_y, &buffer_x, &buffer_y);

		return { buffer_x, buffer_y };
	}

	void TextView::BorderWindowSize(TextWindowType type, int size)
	{
		gtk_text_view_set_border_window_size(GTK_TEXT_VIEW(widget), (GtkTextWindowType)type, size);
	}

	int TextView::BorderWindowSize(TextWindowType type)
	{
		return gtk_text_view_get_border_window_size(GTK_TEXT_VIEW(widget), (GtkTextWindowType)type);
	}

	void TextView::AddChildAtAnchor(Widget& child, TextChildAnchor& anchor)
	{
		gtk_text_view_add_child_at_anchor(GTK_TEXT_VIEW(widget), child.GetWidget(), anchor.GetWidget());
	}

	void TextView::AddChildInWindow(Widget& child, TextWindowType which_window, int xpos, int ypos)
	{
		gtk_text_view_add_child_in_window(GTK_TEXT_VIEW(widget), child.GetWidget(), (GtkTextWindowType)which_window, xpos, ypos);
	}

	void TextView::MoveChild(Widget& child, int xpos, int ypos)
	{
		gtk_text_view_move_child(GTK_TEXT_VIEW(widget), child.GetWidget(), xpos, ypos);
	}

	void TextView::WrapMode(CGui::WrapMode mode)
	{
		gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(widget), (GtkWrapMode)mode);
	}

	CGui::WrapMode TextView::WrapMode()
	{
		return (CGui::WrapMode)gtk_text_view_get_wrap_mode(GTK_TEXT_VIEW(widget));
	}

	void TextView::Editable(bool editable)
	{
		gtk_text_view_set_editable(GTK_TEXT_VIEW(widget), editable);
	}

	bool TextView::Editable()
	{
		return gtk_text_view_get_editable(GTK_TEXT_VIEW(widget));
	}

	void TextView::CursorVisible(bool visible)
	{
		gtk_text_view_set_cursor_visible(GTK_TEXT_VIEW(widget), visible);
	}

	bool TextView::CursorVisble()
	{
		return gtk_text_view_get_cursor_visible(GTK_TEXT_VIEW(widget));
	}

	void TextView::ResetCursorBlink()
	{
		gtk_text_view_reset_cursor_blink(GTK_TEXT_VIEW(widget));
	}

	void TextView::Overwrite(bool overwrite)
	{
		gtk_text_view_set_overwrite(GTK_TEXT_VIEW(widget), overwrite);
	}

	bool TextView::Overwrite()
	{
		return gtk_text_view_get_overwrite(GTK_TEXT_VIEW(widget));
	}

	void TextView::PixelsAboveLine(int pixels)
	{
		gtk_text_view_set_pixels_above_lines(GTK_TEXT_VIEW(widget), pixels);
	}

	int TextView::PixelsAboveLine()
	{
		return gtk_text_view_get_pixels_above_lines(GTK_TEXT_VIEW(widget));
	}

	void TextView::PixelsBelowLines(int pixels)
	{
		gtk_text_view_set_pixels_below_lines(GTK_TEXT_VIEW(widget), pixels);
	}

	int TextView::PixelsBelowLines()
	{
		return gtk_text_view_get_pixels_below_lines(GTK_TEXT_VIEW(widget));
	}

	void TextView::PixelsInsideWrap(int pixels)
	{
		gtk_text_view_set_pixels_inside_wrap(GTK_TEXT_VIEW(widget), pixels);
	}

	int TextView::PixelsInsideWrap()
	{
		return gtk_text_view_get_pixels_inside_wrap(GTK_TEXT_VIEW(widget));
	}

	void TextView::Justification(CGui::Justification justification)
	{
		gtk_text_view_set_justification(GTK_TEXT_VIEW(widget), (GtkJustification)justification);
	}

	CGui::Justification TextView::Justification()
	{
		return (CGui::Justification)gtk_text_view_get_justification(GTK_TEXT_VIEW(widget));
	}

	void TextView::LeftMargin(int margin)
	{
		gtk_text_view_set_left_margin(GTK_TEXT_VIEW(widget), margin);
	}	

	int TextView::LeftMargin()
	{
		return gtk_text_view_get_left_margin(GTK_TEXT_VIEW(widget));
	}

	void TextView::RightMargin(int margin)
	{
		gtk_text_view_set_right_margin(GTK_TEXT_VIEW(widget), margin);
	}

	int TextView::RightMargin()
	{
		return gtk_text_view_get_right_margin(GTK_TEXT_VIEW(widget));
	}

	void TextView::TopMargin(int margin)
	{
		gtk_text_view_set_top_margin(GTK_TEXT_VIEW(widget), margin);
	}

	int TextView::TopMargin()
	{
		return gtk_text_view_get_top_margin(GTK_TEXT_VIEW(widget));
	}

	void TextView::BottomMargin(int margin)
	{
		gtk_text_view_set_bottom_margin(GTK_TEXT_VIEW(widget), margin);
	}

	int TextView::BottomMargin()
	{
		return gtk_text_view_get_bottom_margin(GTK_TEXT_VIEW(widget));
	}

	void TextView::Indent(int indent)
	{
		gtk_text_view_set_indent(GTK_TEXT_VIEW(widget), indent);
	}

	int TextView::Indent()
	{
		return gtk_text_view_get_indent(GTK_TEXT_VIEW(widget));
	}

	void TextView::AcceptsTabs(bool accepts)
	{
		gtk_text_view_set_accepts_tab(GTK_TEXT_VIEW(widget), accepts);
	}

	bool TextView::AcceptsTabs()
	{
		return gtk_text_view_get_accepts_tab(GTK_TEXT_VIEW(widget));
	}

	void TextView::InputPerpose(CGui::InputPurpose purpose)
	{
		gtk_text_view_set_input_purpose(GTK_TEXT_VIEW(widget), (GtkInputPurpose)purpose);
	}

	CGui::InputPurpose TextView::InputPurpose()
	{
		return (CGui::InputPurpose)gtk_text_view_get_input_purpose(GTK_TEXT_VIEW(widget));
	}

	void TextView::InputHints(CGui::InputHints hints)
	{
		gtk_text_view_set_input_hints(GTK_TEXT_VIEW(widget), (GtkInputHints)hints);
	}

	CGui::InputHints TextView::InputHints()
	{
		return (CGui::InputHints)gtk_text_view_get_input_hints(GTK_TEXT_VIEW(widget));
	}

	void TextView::Monospace(bool monospace)
	{
		gtk_text_view_set_monospace(GTK_TEXT_VIEW(widget), monospace);
	}

	bool TextView::Monospace()
	{
		return gtk_text_view_get_monospace(GTK_TEXT_VIEW(widget));
	}

	bool TextView::IsTextView()
	{
		return GTK_IS_TEXT_VIEW(widget);
	}
}