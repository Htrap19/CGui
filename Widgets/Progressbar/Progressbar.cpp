#include "./Progressbar.hh"

namespace CGui
{
	Progressbar::Progressbar() : Orientable(this)
	{
		widget = gtk_progress_bar_new();
		this->SetContext(widget);
	}

	Progressbar::Progressbar(GtkProgressBar* progressbar) : Orientable(this)
	{
		widget = GTK_WIDGET(progressbar);
		this->SetContext(widget);
	}

	Progressbar::Progressbar(const char* text) : Orientable(this)
	{
		widget = gtk_progress_bar_new();
		this->ShowText(true);
		this->Text(text);
		this->SetContext(widget);
	}

	void Progressbar::Pulse()
	{
		gtk_progress_bar_pulse(GTK_PROGRESS_BAR(widget));
	}

	void Progressbar::PulseStep(double fraction)
	{
		gtk_progress_bar_set_pulse_step(GTK_PROGRESS_BAR(widget), fraction);
	}

	double Progressbar::PulseStep()
	{
		return gtk_progress_bar_get_pulse_step(GTK_PROGRESS_BAR(widget));
	}

	void Progressbar::Fraction(double fraction)
	{
		gtk_progress_bar_set_fraction(GTK_PROGRESS_BAR(widget), fraction);
		while (gtk_events_pending())
			gtk_main_iteration();
	}

	double Progressbar::Fraction()
	{
		return gtk_progress_bar_get_fraction(GTK_PROGRESS_BAR(widget));
	}

	void Progressbar::Inverted(bool inverted)
	{
		gtk_progress_bar_set_inverted(GTK_PROGRESS_BAR(widget), inverted);
	}

	bool Progressbar::Inverted()
	{
		return gtk_progress_bar_get_inverted(GTK_PROGRESS_BAR(widget));
	}

	void Progressbar::ShowText(bool show)
	{
		gtk_progress_bar_set_show_text(GTK_PROGRESS_BAR(widget), show);
	}

	bool Progressbar::ShowText()
	{
		return gtk_progress_bar_get_show_text(GTK_PROGRESS_BAR(widget));
	}

	void Progressbar::Text(const char* text)
	{
		gtk_progress_bar_set_text(GTK_PROGRESS_BAR(widget), text);
	}

	const char* Progressbar::Text()
	{
		return gtk_progress_bar_get_text(GTK_PROGRESS_BAR(widget));
	}

	void Progressbar::Ellipsize(EllipsizeMode mode)
	{
		gtk_progress_bar_set_ellipsize(GTK_PROGRESS_BAR(widget), (PangoEllipsizeMode)mode);
	}

	EllipsizeMode Progressbar::Ellipsize()
	{
		return (EllipsizeMode)gtk_progress_bar_get_ellipsize(GTK_PROGRESS_BAR(widget));
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
		return GTK_IS_PROGRESS_BAR(widget);
	}
};
