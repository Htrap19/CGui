#include "./Label.hh"

namespace CGui
{
	Label::Label(GtkLabel* label)
	{
		m_Widget = GTK_WIDGET(label);
		this->SetContext(m_Widget);
	}

	Label::Label(const char* text, bool mneomic /*= false*/)
	{
		if (mneomic)
			m_Widget = gtk_label_new_with_mnemonic(text);
		else
			m_Widget = gtk_label_new(text);
		this->SetContext(m_Widget);
	}

	void Label::Text(const char* text, bool mneomic /*= false*/)
	{
		if (mneomic)
			gtk_label_set_text_with_mnemonic(GTK_LABEL(m_Widget), text);
		else
			gtk_label_set_text(GTK_LABEL(m_Widget), text);
	}

	const char* Label::Text()
	{
		return gtk_label_get_text(GTK_LABEL(m_Widget));
	}

	void Label::TextLabel(const char* label)
	{
		gtk_label_set_label(GTK_LABEL(m_Widget), label);
	}

	const char* Label::TextLabel()
	{
		return gtk_label_get_label(GTK_LABEL(m_Widget));
	}

	void Label::Markup(const char* str, bool mnemonic /*= false*/)
	{
		if (mnemonic)
			gtk_label_set_markup_with_mnemonic(GTK_LABEL(m_Widget), str);
		else
			gtk_label_set_markup(GTK_LABEL(m_Widget), str);
	}

	void Label::Pattern(const char* pattern)
	{
		gtk_label_set_pattern(GTK_LABEL(m_Widget), pattern);
	}

	void Label::Justify(Justification justify)
	{
		gtk_label_set_justify(GTK_LABEL(m_Widget), (GtkJustification)justify);
	}

	Justification Label::Justify()
	{
		return (Justification)gtk_label_get_justify(GTK_LABEL(m_Widget));
	}

	void Label::XAlign(float x_align)
	{
		gtk_label_set_xalign(GTK_LABEL(m_Widget), x_align);
	}

	float Label::XAlign()
	{
		return gtk_label_get_xalign(GTK_LABEL(m_Widget));
	}

	void Label::YAlign(float y_align)
	{
		gtk_label_set_yalign(GTK_LABEL(m_Widget), y_align);
	}

	float Label::YAlign()
	{
		return gtk_label_get_yalign(GTK_LABEL(m_Widget));
	}

	void Label::Ellipsize(EllipsizeMode mode)
	{
		gtk_label_set_ellipsize(GTK_LABEL(m_Widget), (PangoEllipsizeMode)mode);
	}

	EllipsizeMode Label::Ellipsize()
	{
		return (EllipsizeMode)gtk_label_get_ellipsize(GTK_LABEL(m_Widget));
	}

	void Label::WidthChars(int n_chars)
	{
		gtk_label_set_width_chars(GTK_LABEL(m_Widget), n_chars);
	}

	int Label::WidthChars()
	{
		return gtk_label_get_width_chars(GTK_LABEL(m_Widget));
	}

	void Label::MaxWidthChars(int n_chars)
	{
		gtk_label_set_max_width_chars(GTK_LABEL(m_Widget), n_chars);
	}

	int Label::MaxWidthChars()
	{
		return gtk_label_get_max_width_chars(GTK_LABEL(m_Widget));
	}

	void Label::LineWrap(bool wrap)
	{
		gtk_label_set_line_wrap(GTK_LABEL(m_Widget), wrap);
	}

	bool Label::LineWrap()
	{
		return gtk_label_get_line_wrap(GTK_LABEL(m_Widget));
	}
	void Label::LineWrapMode(WrapMode mode)
	{
		gtk_label_set_line_wrap_mode(GTK_LABEL(m_Widget), (PangoWrapMode)mode);
	}

	WrapMode Label::LineWrapMode()
	{
		return (WrapMode)gtk_label_get_line_wrap_mode(GTK_LABEL(m_Widget));
	}

	void Label::Lines(int lines)
	{
		gtk_label_set_lines(GTK_LABEL(m_Widget), lines);
	}

	int Label::Lines()
	{
		return gtk_label_get_lines(GTK_LABEL(m_Widget));
	}

	CoordinatesInfo Label::LayoutOffsets()
	{
		int x, y;
		gtk_label_get_layout_offsets(GTK_LABEL(m_Widget), &x, &y);
		return { x, y };
	}

	unsigned int Label::MnemonicKeyval()
	{
		return gtk_label_get_mnemonic_keyval(GTK_LABEL(m_Widget));
	}

	void Label::SelectRegion(int start_offset, int end_offset)
	{
		gtk_label_select_region(GTK_LABEL(m_Widget), start_offset, end_offset);
	}

	void Label::MnemonicWidget(Widget& widget)
	{
		gtk_label_set_mnemonic_widget(GTK_LABEL(this->m_Widget), widget.GetWidget());
	}

	void Label::Selectable(bool selectable)
	{
		gtk_label_set_selectable(GTK_LABEL(m_Widget), selectable);
	}

	bool Label::Selectable()
	{
		return gtk_label_get_selectable(GTK_LABEL(m_Widget));
	}

	void Label::UseMarkup(bool use_markup)
	{
		gtk_label_set_use_markup(GTK_LABEL(m_Widget), use_markup);
	}

	bool Label::UseMarkup()
	{
		return gtk_label_get_use_markup(GTK_LABEL(m_Widget));
	}

	void Label::UseUnderline(bool use_underline)
	{
		gtk_label_set_use_underline(GTK_LABEL(m_Widget), use_underline);
	}

	bool Label::UseUnderline()
	{
		return gtk_label_get_use_underline(GTK_LABEL(m_Widget));
	}

	void Label::SingleLineMode(bool mode)
	{
		gtk_label_set_single_line_mode(GTK_LABEL(m_Widget), mode);
	}

	bool Label::SingleLineMode()
	{
		return gtk_label_get_single_line_mode(GTK_LABEL(m_Widget));
	}

	void Label::Angle(double angle)
	{
		gtk_label_set_angle(GTK_LABEL(m_Widget), angle);
	}

	double Label::Angle()
	{
		return gtk_label_get_angle(GTK_LABEL(m_Widget));
	}

	const char* Label::CurrentUri()
	{
		return gtk_label_get_current_uri(GTK_LABEL(m_Widget));
	}

	void Label::TrackVisitedLinks(bool track_links)
	{
		gtk_label_set_track_visited_links(GTK_LABEL(m_Widget), track_links);
	}

	bool Label::TrackVisitedLinks()
	{
		return gtk_label_get_track_visited_links(GTK_LABEL(m_Widget));
	}

	bool Label::IsLabel()
	{
		return GTK_IS_LABEL(m_Widget);
	}
};
