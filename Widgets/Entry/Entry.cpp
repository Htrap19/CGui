#include "./Entry.hh"

namespace CGui
{
	Entry::Entry() : Handler(this)
	{
		widget = gtk_entry_new();
		this->SetContext(widget);
		this->SetEditable(*this);
	}

	Entry::Entry(const char* placeholdertext) : Handler(this)
	{
		widget = gtk_entry_new();
		gtk_entry_set_placeholder_text(GTK_ENTRY(widget), placeholdertext);
		this->SetContext(widget);
		this->SetEditable(*this);
	}

	Entry::Entry(EntryBuffer buffer) : Handler(this)
	{
		widget = gtk_entry_new_with_buffer(buffer.GetEntryBuffer());
		this->SetContext(widget);
		this->SetEditable(*this);
	}

	void Entry::Buffer(EntryBuffer buffer)
	{
		gtk_entry_set_buffer(GTK_ENTRY(widget), buffer.GetEntryBuffer());
	}

	EntryBuffer Entry::Buffer()
	{
		return EntryBuffer(gtk_entry_get_buffer(GTK_ENTRY(widget)));
	}

	void Entry::Visibility(bool visibility)
	{
		gtk_entry_set_visibility(GTK_ENTRY(widget), visibility);
	}

	bool Entry::Visibility()
	{
		return gtk_entry_get_visibility(GTK_ENTRY(widget));
	}

	void Entry::MaxLength(int max)
	{
		gtk_entry_set_max_length(GTK_ENTRY(widget), max);
	}

	int Entry::MaxLength()
	{
		return gtk_entry_get_max_length(GTK_ENTRY(widget));
	}

	void Entry::OverwriteMode(bool overwrite)
	{
		gtk_entry_set_overwrite_mode(GTK_ENTRY(widget), overwrite);
	}

	bool Entry::OverwriteMode()
	{
		return gtk_entry_get_overwrite_mode(GTK_ENTRY(widget));
	}

	void Entry::Alignment(float alignment)
	{
		gtk_entry_set_alignment(GTK_ENTRY(widget), alignment);
	}

	float Entry::Alignment()
	{
		return gtk_entry_get_alignment(GTK_ENTRY(widget));
	}

	void Entry::InvisibleChar(char ch)
	{
		gtk_entry_set_invisible_char(GTK_ENTRY(widget), ch);
	}

	void Entry::UnsetInvisibleChar()
	{
		gtk_entry_unset_invisible_char(GTK_ENTRY(widget));
	}

	char Entry::InvisibleChar()
	{
		return gtk_entry_get_invisible_char(GTK_ENTRY(widget));
	}

	void Entry::WidthChar(int n_ch)
	{
		gtk_entry_set_width_chars(GTK_ENTRY(widget), n_ch);
	}

	int Entry::WidthChar()
	{
		return gtk_entry_get_width_chars(GTK_ENTRY(widget));
	}

	void Entry::MaxWidthChar(int n_ch)
	{
		gtk_entry_set_max_width_chars(GTK_ENTRY(widget), n_ch);
	}

	int Entry::MaxWidthChar()
	{
		return gtk_entry_get_max_width_chars(GTK_ENTRY(widget));
	}

	void Entry::HasFrame(bool frame)
	{
		gtk_entry_set_has_frame(GTK_ENTRY(widget), frame);
	}

	bool Entry::HasFrame()
	{
		return gtk_entry_get_has_frame(GTK_ENTRY(widget));
	}

	void Entry::ProgressFraction(double fraction)
	{
		gtk_entry_set_progress_fraction(GTK_ENTRY(widget), fraction);
	}

	double Entry::ProgressFraction()
	{
		return gtk_entry_get_progress_fraction(GTK_ENTRY(widget));
	}

	void Entry::ProgressPulse()
	{
		gtk_entry_progress_pulse(GTK_ENTRY(widget));
	}

	void Entry::ProgressPulseStep(double fraction)
	{
		gtk_entry_set_progress_pulse_step(GTK_ENTRY(widget), fraction);
	}

	double Entry::ProgressPulseStep()
	{
		return gtk_entry_get_progress_pulse_step(GTK_ENTRY(widget));
	}

	void Entry::Icon(EntryIconPosition pos, Pixbuf& pixbuf)
	{
		gtk_entry_set_icon_from_pixbuf(GTK_ENTRY(widget), (GtkEntryIconPosition)pos, pixbuf.GetWidget());
	}

	Pixbuf Entry::Icon(EntryIconPosition pos)
	{
		return Pixbuf(gtk_entry_get_icon_pixbuf(GTK_ENTRY(widget), (GtkEntryIconPosition)pos));
	}

	void Entry::IconActivatable(EntryIconPosition pos, bool activatable)
	{
		gtk_entry_set_icon_activatable(GTK_ENTRY(widget), (GtkEntryIconPosition)pos, activatable);
	}

	bool Entry::IconActivatable(EntryIconPosition pos)
	{
		return gtk_entry_get_icon_activatable(GTK_ENTRY(widget), (GtkEntryIconPosition)pos);
	}

	void Entry::IconSensitive(EntryIconPosition pos, bool sensitive)
	{
		gtk_entry_set_icon_sensitive(GTK_ENTRY(widget), (GtkEntryIconPosition)pos, sensitive);
	}

	bool Entry::IconSensitive(EntryIconPosition pos)
	{
		return gtk_entry_get_icon_sensitive(GTK_ENTRY(widget), (GtkEntryIconPosition)pos);
	}

	void Entry::IconTooltipText(EntryIconPosition pos, const char* tooltip)
	{
		gtk_entry_set_icon_tooltip_text(GTK_ENTRY(widget), (GtkEntryIconPosition)pos, tooltip);
	}

	const char* Entry::IconTooltipText(EntryIconPosition pos)
	{
		return gtk_entry_get_icon_tooltip_text(GTK_ENTRY(widget), (GtkEntryIconPosition)pos);
	}

	void Entry::Purpose(InputPurpose purpose)
	{
		gtk_entry_set_input_purpose(GTK_ENTRY(widget), (GtkInputPurpose)purpose);
	}

	InputPurpose Entry::Purpose()
	{
		return (InputPurpose)gtk_entry_get_input_purpose(GTK_ENTRY(widget));
	}

	void Entry::Hints(InputHints hints)
	{
		gtk_entry_set_input_hints(GTK_ENTRY(widget), (GtkInputHints)hints);
	}

	InputHints Entry::Hints()
	{
		return (InputHints)gtk_entry_get_input_hints(GTK_ENTRY(widget));
	}

	void Entry::GrabFocusWithoutSelecting()
	{
		gtk_entry_grab_focus_without_selecting(GTK_ENTRY(widget));
	}

	void Entry::Text(const char* text)
	{
		gtk_entry_set_text(GTK_ENTRY(widget), text);
	}

	const char* Entry::Text()
	{
		return gtk_entry_get_text(GTK_ENTRY(widget));
	}

	unsigned short Entry::TextLength()
	{
		return gtk_entry_get_text_length(GTK_ENTRY(widget));
	}

	long unsigned int Entry::Changed(void(*func)())
	{
		return this->SignalHandler(Signals::CHANGED, func);
	}

	long unsigned int Entry::Changed(void(*func)(Entry*))
	{
		return this->SignalHandler(Signals::CHANGED, func);
	}

	void Entry::SetEntry(GtkEntry* entry)
	{
		this->widget = GTK_WIDGET(entry);
		this->SetContext(widget);
		this->SetEditable(*this);
	}
};
