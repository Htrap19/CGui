#include "./Spinner.hh"

namespace CGui
{
	Spinner::Spinner()
	{
		m_Widget = gtk_spinner_new();
		this->SetContext(m_Widget);
	}

	Spinner::Spinner(GtkSpinner* spinner)
	{
		m_Widget = GTK_WIDGET(spinner);
		this->SetContext(m_Widget);
	}

	void Spinner::Start()
	{
		gtk_spinner_start(GTK_SPINNER(m_Widget));
	}

	void Spinner::Stop()
	{
		gtk_spinner_stop(GTK_SPINNER(m_Widget));
	}

	bool Spinner::IsSpinner()
	{
		return GTK_IS_SPINNER(m_Widget);
	}
};
