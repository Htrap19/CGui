#include "./Entry.hh"

namespace CGui
{
	Entry::Entry() : Handler(this)
	{
		m_Widget = gtk_entry_new();
		this->SetContext(m_Widget);
		this->SetEditable(*this);
	}

	Entry::Entry(const char* placeholdertext) : Handler(this)
	{
		m_Widget = gtk_entry_new();
		gtk_entry_set_placeholder_text(GTK_ENTRY(m_Widget), placeholdertext);
		this->SetContext(m_Widget);
		this->SetEditable(*this);
	}

	Entry::Entry(EntryBuffer buffer) : Handler(this)
	{
		m_Widget = gtk_entry_new_with_buffer(buffer.GetEntryBuffer());
		this->SetContext(m_Widget);
		this->SetEditable(*this);
	}

	Entry::Entry(GtkEntry* entry) : Handler(this)
	{
		this->SetEntry(entry);
	}

	void Entry::Buffer(EntryBuffer buffer)
	{
		gtk_entry_set_buffer(GTK_ENTRY(m_Widget), buffer.GetEntryBuffer());
	}

	EntryBuffer Entry::Buffer()
	{
		return EntryBuffer(gtk_entry_get_buffer(GTK_ENTRY(m_Widget)));
	}

	void Entry::Visibility(bool visibility)
	{
		gtk_entry_set_visibility(GTK_ENTRY(m_Widget), visibility);
	}

	bool Entry::Visibility()
	{
		return gtk_entry_get_visibility(GTK_ENTRY(m_Widget));
	}

	void Entry::MaxLength(int max)
	{
		gtk_entry_set_max_length(GTK_ENTRY(m_Widget), max);
	}

	int Entry::MaxLength()
	{
		return gtk_entry_get_max_length(GTK_ENTRY(m_Widget));
	}

	void Entry::OverwriteMode(bool overwrite)
	{
		gtk_entry_set_overwrite_mode(GTK_ENTRY(m_Widget), overwrite);
	}

	bool Entry::OverwriteMode()
	{
		return gtk_entry_get_overwrite_mode(GTK_ENTRY(m_Widget));
	}

	void Entry::Alignment(float alignment)
	{
		gtk_entry_set_alignment(GTK_ENTRY(m_Widget), alignment);
	}

	float Entry::Alignment()
	{
		return gtk_entry_get_alignment(GTK_ENTRY(m_Widget));
	}

	void Entry::InvisibleChar(char ch)
	{
		gtk_entry_set_invisible_char(GTK_ENTRY(m_Widget), ch);
	}

	void Entry::UnsetInvisibleChar()
	{
		gtk_entry_unset_invisible_char(GTK_ENTRY(m_Widget));
	}

	char Entry::InvisibleChar()
	{
		return gtk_entry_get_invisible_char(GTK_ENTRY(m_Widget));
	}

	void Entry::WidthChar(int n_ch)
	{
		gtk_entry_set_width_chars(GTK_ENTRY(m_Widget), n_ch);
	}

	int Entry::WidthChar()
	{
		return gtk_entry_get_width_chars(GTK_ENTRY(m_Widget));
	}

	void Entry::MaxWidthChar(int n_ch)
	{
		gtk_entry_set_max_width_chars(GTK_ENTRY(m_Widget), n_ch);
	}

	int Entry::MaxWidthChar()
	{
		return gtk_entry_get_max_width_chars(GTK_ENTRY(m_Widget));
	}

	void Entry::HasFrame(bool frame)
	{
		gtk_entry_set_has_frame(GTK_ENTRY(m_Widget), frame);
	}

	bool Entry::HasFrame()
	{
		return gtk_entry_get_has_frame(GTK_ENTRY(m_Widget));
	}

	void Entry::ProgressFraction(double fraction)
	{
		gtk_entry_set_progress_fraction(GTK_ENTRY(m_Widget), fraction);
	}

	double Entry::ProgressFraction()
	{
		return gtk_entry_get_progress_fraction(GTK_ENTRY(m_Widget));
	}

	void Entry::ProgressPulse()
	{
		gtk_entry_progress_pulse(GTK_ENTRY(m_Widget));
	}

	void Entry::ProgressPulseStep(double fraction)
	{
		gtk_entry_set_progress_pulse_step(GTK_ENTRY(m_Widget), fraction);
	}

	double Entry::ProgressPulseStep()
	{
		return gtk_entry_get_progress_pulse_step(GTK_ENTRY(m_Widget));
	}

	void Entry::Icon(EntryIconPosition pos, Pixbuf& pixbuf)
	{
		gtk_entry_set_icon_from_pixbuf(GTK_ENTRY(m_Widget), (GtkEntryIconPosition)pos, pixbuf.GetWidget());
	}

	Pixbuf Entry::Icon(EntryIconPosition pos)
	{
		return Pixbuf(gtk_entry_get_icon_pixbuf(GTK_ENTRY(m_Widget), (GtkEntryIconPosition)pos));
	}

	void Entry::IconActivatable(EntryIconPosition pos, bool activatable)
	{
		gtk_entry_set_icon_activatable(GTK_ENTRY(m_Widget), (GtkEntryIconPosition)pos, activatable);
	}

	bool Entry::IconActivatable(EntryIconPosition pos)
	{
		return gtk_entry_get_icon_activatable(GTK_ENTRY(m_Widget), (GtkEntryIconPosition)pos);
	}

	void Entry::IconSensitive(EntryIconPosition pos, bool sensitive)
	{
		gtk_entry_set_icon_sensitive(GTK_ENTRY(m_Widget), (GtkEntryIconPosition)pos, sensitive);
	}

	bool Entry::IconSensitive(EntryIconPosition pos)
	{
		return gtk_entry_get_icon_sensitive(GTK_ENTRY(m_Widget), (GtkEntryIconPosition)pos);
	}

	void Entry::IconTooltipText(EntryIconPosition pos, const char* tooltip)
	{
		gtk_entry_set_icon_tooltip_text(GTK_ENTRY(m_Widget), (GtkEntryIconPosition)pos, tooltip);
	}

	const char* Entry::IconTooltipText(EntryIconPosition pos)
	{
		return gtk_entry_get_icon_tooltip_text(GTK_ENTRY(m_Widget), (GtkEntryIconPosition)pos);
	}

	void Entry::Purpose(InputPurpose purpose)
	{
		gtk_entry_set_input_purpose(GTK_ENTRY(m_Widget), (GtkInputPurpose)purpose);
	}

	InputPurpose Entry::Purpose()
	{
		return (InputPurpose)gtk_entry_get_input_purpose(GTK_ENTRY(m_Widget));
	}

	void Entry::Hints(InputHints hints)
	{
		gtk_entry_set_input_hints(GTK_ENTRY(m_Widget), (GtkInputHints)hints);
	}

	InputHints Entry::Hints()
	{
		return (InputHints)gtk_entry_get_input_hints(GTK_ENTRY(m_Widget));
	}

	void Entry::GrabFocusWithoutSelecting()
	{
		gtk_entry_grab_focus_without_selecting(GTK_ENTRY(m_Widget));
	}

	void Entry::Text(const char* text)
	{
		gtk_entry_set_text(GTK_ENTRY(m_Widget), text);
	}

	const char* Entry::Text()
	{
		return gtk_entry_get_text(GTK_ENTRY(m_Widget));
	}

	unsigned short Entry::TextLength()
	{
		return gtk_entry_get_text_length(GTK_ENTRY(m_Widget));
	}

	long unsigned int Entry::Changed(void(*func)())
	{
		return this->SignalHandler(Signals::CHANGED, func);
	}

	long unsigned int Entry::Changed(void(*func)(Entry*))
	{
		return this->SignalHandler(Signals::CHANGED, func);
	}

	bool Entry::IsEntry()
	{
		return GTK_IS_ENTRY(m_Widget);
	}

	void Entry::SetEntry(GtkEntry* entry)
	{
		this->m_Widget = GTK_WIDGET(entry);
		this->SetContext(m_Widget);
		this->SetEditable(*this);
	}
};
