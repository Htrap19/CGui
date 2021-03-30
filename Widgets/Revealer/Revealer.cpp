#include "./Revealer.hh"

namespace CGui
{
	Revealer::Revealer(GtkRevealer* revealer) : Container(this)
	{
		m_Widget = GTK_WIDGET(revealer);
		this->SetContext(m_Widget);
	}

	Revealer::Revealer() : Container(this)
	{
		m_Widget = gtk_revealer_new();
		this->SetContext(m_Widget);
	}

	Revealer::Revealer(RevealerTransition transition, unsigned int duration) : Container(this)
	{
		m_Widget = gtk_revealer_new();
		this->Transition(transition);
		this->Duration(duration);
		this->SetContext(m_Widget);
	}

	void Revealer::Transition(RevealerTransition transition)
	{
		gtk_revealer_set_transition_type(GTK_REVEALER(m_Widget), (GtkRevealerTransitionType)transition);
	}

	RevealerTransition Revealer::Transition()
	{
		return (RevealerTransition)gtk_revealer_get_transition_type(GTK_REVEALER(m_Widget));
	}

	void Revealer::Duration(unsigned int duration)
	{
		gtk_revealer_set_transition_duration(GTK_REVEALER(m_Widget), duration);
	}

	unsigned int Revealer::Duration()
	{
		return gtk_revealer_get_transition_duration(GTK_REVEALER(m_Widget));
	}

	void Revealer::Reveal(bool reveal)
	{
		gtk_revealer_set_reveal_child(GTK_REVEALER(m_Widget), reveal);
	}

	bool Revealer::Reveal()
	{
		return gtk_revealer_get_reveal_child(GTK_REVEALER(m_Widget));
	}

	bool Revealer::ChildRevealed()
	{
		return gtk_revealer_get_child_revealed(GTK_REVEALER(m_Widget));
	}
	bool Revealer::IsRevealer()
	{
		return GTK_IS_REVEALER(m_Widget);
	}
};
