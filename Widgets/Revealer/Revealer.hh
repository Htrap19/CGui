#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class Revealer : public virtual Widget, public virtual Container<Revealer>
	{
	public:
		Revealer();
		Revealer(GtkRevealer* revealer);
		Revealer(RevealerTransition transition, unsigned int duration);
		void Transition(RevealerTransition transition);
		RevealerTransition Transition();
		void Duration(unsigned int duration);
		unsigned int Duration();
		void Reveal(bool reveal);
		bool Reveal();
		bool ChildRevealed();
		bool IsRevealer();
	};
};
