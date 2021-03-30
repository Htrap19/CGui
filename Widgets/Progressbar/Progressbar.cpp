#include "./Progressbar.hh"

namespace CGui
{
	Progressbar::Progressbar() : Orientable(this)
	{
		m_Widget = gtk_progress_bar_new();
		this->SetContext(m_Widget);
	}

	Progressbar::Progressbar(GtkProgressBar* progressbar) : Orientable(this)
	{
		m_Widget = GTK_WIDGET(progressbar);
		this->SetContext(m_Widget);
	}

	Progressbar::Progressbar(const char* text) : Orientable(this)
	{
		m_Widget = gtk_progress_bar_new();
		this->ShowText(true);
		this->Text(text);
		this->SetContext(m_Widget);
	}

	void Progressbar::Pulse()
	{
		gtk_progress_bar_pulse(GTK_PROGRESS_BAR(m_Widget));
	}

	void Progressbar::PulseStep(double fraction)
	{
		gtk_progress_bar_set_pulse_step(GTK_PROGRESS_BAR(m_Widget), fraction);
	}

	double Progressbar::PulseStep()
	{
		return gtk_progress_bar_get_pulse_step(GTK_PROGRESS_BAR(m_Widget));
	}

	void Progressbar::Fraction(double fraction)
	{
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(m_Widget), fraction);
		while (gtk_events_pending())
			gtk_main_iteration();
	}

	double Progressbar::Fraction()
	{
		return gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(m_Widget));
	}

	void Progressbar::Inverted(bool inverted)
	{
		gtk_progress_bar_set_inverted(GTK_PROGRESS_BAR(m_Widget), inverted);
	}

	bool Progressbar::Inverted()
	{
		return gtk_progress_bar_get_inverted(GTK_PROGRESS_BAR(m_Widget));
	}

	void Progressbar::ShowText(bool show)
	{
		gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(m_Widget), show);
	}

	bool Progressbar::ShowText()
	{
		return gtk_progress_bar_get_show_text(GTK_PROGRESS_BAR(m_Widget));
	}

	void Progressbar::Text(const char* text)
	{
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(m_Widget), text);
	}

	const char* Progressbar::Text()
	{
		return gtk_progress_bar_get_text(GTK_PROGRESS_BAR(m_Widget));
	}

	void Progressbar::Ellipsize(EllipsizeMode mode)
	{
		gtk_progress_bar_set_ellipsize(GTK_PROGRESS_BAR(m_Widget), (PangoEllipsizeMode)mode);
	}

	EllipsizeMode Progressbar::Ellipsize()
	{
		return (EllipsizeMode)gtk_progress_bar_get_ellipsize(GTK_PROGRESS_BAR(m_Widget));
	}

	void Progressbar::Increment(double fraction)
	{
		this->Fraction(this->Fraction() + fraction);
	}

	void Progressbar::Increment()
	{
		this->Fraction(this->Fraction() + this->Fraction());
	}
	bool Progressbar::IsProgressbar()
	{
		return GTK_IS_PROGRESS_BAR(m_Widget);
	}
};
