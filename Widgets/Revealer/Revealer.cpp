#include "./Revealer.hh"

namespace CGui
{
	Revealer::Revealer(RevealerTransition transition, unsigned int duration) : Container(this)
	{
		widget = gtk_revealer_new();
		this->Transition(transition);
		gtk_revealer_set_transition_duration(GTK_REVEALER(widget), duration);
		this->SetContext(widget);
	}

	void Revealer::Transition(RevealerTransition transition)
	{
		gtk_revealer_set_transition_type(GTK_REVEALER(widget), (GtkRevealerTransitionType)transition);
	}

	RevealerTransition Revealer::Transition()
	{
		return (RevealerTransition)gtk_revealer_get_transition_type(GTK_REVEALER(widget));
	}

	void Revealer::Duration(unsigned int duration)
	{
		gtk_revealer_set_transition_duration(GTK_REVEALER(widget), duration);
	}

	unsigned int Revealer::Duration()
	{
		return gtk_revealer_get_transition_duration(GTK_REVEALER(widget));
	}

	void Revealer::Reveal(bool reveal)
	{
		gtk_revealer_set_reveal_child(GTK_REVEALER(widget), reveal);
	}

	bool Revealer::Reveal()
	{
		return gtk_revealer_get_reveal_child(GTK_REVEALER(widget));
	}
};
