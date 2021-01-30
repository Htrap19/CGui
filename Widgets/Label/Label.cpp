#include "./Label.hh"

namespace CGui
{
	Label::Label(GtkLabel* label)
	{
		widget = GTK_WIDGET(widget);
		this->SetContext(widget);
	}

	Label::Label(const char* text)
	{
		widget = gtk_label_new(text);
		this->SetContext(widget);
	}

	void Label::Text(const char* text)
	{
		gtk_label_set_label(GTK_LABEL(widget), text);
	}

	const char* Label::Text()
	{
		return gtk_label_get_text(GTK_LABEL(widget));
	}

	void Label::Markup(const char* str)
	{
		gtk_label_set_markup(GTK_LABEL(widget), str);
	}

	void Label::Pattern(const char* pattern)
	{
		gtk_label_set_pattern(GTK_LABEL(widget), pattern);
	}

	void Label::Justify(Justification justify)
	{
		gtk_label_set_justify(GTK_LABEL(widget), (GtkJustification)justify);
	}

	Justification Label::Justify()
	{
		return (Justification)gtk_label_get_justify(GTK_LABEL(widget));
	}

	void Label::XAlign(float x_align)
	{
		gtk_label_set_xalign(GTK_LABEL(widget), x_align);
	}

	float Label::XAlign()
	{
		return gtk_label_get_xalign(GTK_LABEL(widget));
	}

	void Label::YAlign(float y_align)
	{
		gtk_label_set_yalign(GTK_LABEL(widget), y_align);
	}

	float Label::YAlign()
	{
		return gtk_label_get_yalign(GTK_LABEL(widget));
	}

	void Label::Ellipsize(EllipsizeMode mode)
	{
		gtk_label_set_ellipsize(GTK_LABEL(widget), (PangoEllipsizeMode)mode);
	}

	EllipsizeMode Label::Ellipsize()
	{
		return (EllipsizeMode)gtk_label_get_ellipsize(GTK_LABEL(widget));
	}

	void Label::WidthChars(int n_chars)
	{
		gtk_label_set_width_chars(GTK_LABEL(widget), n_chars);
	}

	int Label::WidthChars()
	{
		return gtk_label_get_width_chars(GTK_LABEL(widget));
	}

	void Label::MaxWidthChars(int n_chars)
	{
		gtk_label_set_max_width_chars(GTK_LABEL(widget), n_chars);
	}

	int Label::MaxWidthChars()
	{
		return gtk_label_get_max_width_chars(GTK_LABEL(widget));
	}

	void Label::LineWrap(bool wrap)
	{
		gtk_label_set_line_wrap(GTK_LABEL(widget), wrap);
	}

	bool Label::LineWrap()
	{
		return gtk_label_get_line_wrap(GTK_LABEL(widget));
	}
	void Label::LineWrapMode(WrapMode mode)
	{
		gtk_label_set_line_wrap_mode(GTK_LABEL(widget), (PangoWrapMode)mode);
	}

	WrapMode Label::LineWrapMode()
	{
		return (WrapMode)gtk_label_get_line_wrap_mode(GTK_LABEL(widget));
	}

	void Label::Lines(int lines)
	{
		gtk_label_set_lines(GTK_LABEL(widget), lines);
	}

	int Label::Lines()
	{
		return gtk_label_get_lines(GTK_LABEL(widget));
	}

	std::pair<int, int> Label::LayoutOffsets()
	{
		int x, y;
		gtk_label_get_layout_offsets(GTK_LABEL(widget), &x, &y);
		return std::make_pair(x, y);
	}

	void Label::SelectRegion(int start_offset, int end_offset)
	{
		gtk_label_select_region(GTK_LABEL(widget), start_offset, end_offset);
	}

	void Label::Selectable(bool selectable)
	{
		gtk_label_set_selectable(GTK_LABEL(widget), selectable);
	}

	bool Label::Selectable()
	{
		return gtk_label_get_selectable(GTK_LABEL(widget));
	}

	void Label::UseMarkup(bool use_markup)
	{
		gtk_label_set_use_markup(GTK_LABEL(widget), use_markup);
	}

	bool Label::UseMarkup()
	{
		return gtk_label_get_use_markup(GTK_LABEL(widget));
	}

	void Label::UseUnderline(bool use_underline)
	{
		gtk_label_set_use_underline(GTK_LABEL(widget), use_underline);
	}

	bool Label::UseUnderline()
	{
		return gtk_label_get_use_underline(GTK_LABEL(widget));
	}

	void Label::SingleLineMode(bool mode)
	{
		gtk_label_set_single_line_mode(GTK_LABEL(widget), mode);
	}

	bool Label::SingleLineMode()
	{
		return gtk_label_get_single_line_mode(GTK_LABEL(widget));
	}

	void Label::Angle(double angle)
	{
		gtk_label_set_angle(GTK_LABEL(widget), angle);
	}

	double Label::Angle()
	{
		return gtk_label_get_angle(GTK_LABEL(widget));
	}

	const char* Label::CurrentUri()
	{
		return gtk_label_get_current_uri(GTK_LABEL(widget));
	}

	void Label::TrackVisitedLinks(bool track_links)
	{
		gtk_label_set_track_visited_links(GTK_LABEL(widget), track_links);
	}

	bool Label::TrackVisitedLinks()
	{
		return gtk_label_get_track_visited_links(GTK_LABEL(widget));
	}

	bool Label::IsLabel()
	{
		return GTK_IS_LABEL(widget);
	}
};
