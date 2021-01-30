#pragma once

#include "../Widget.hh"
#include "../Orientable.hh"

namespace CGui
{
	class Progressbar : public virtual Widget, public virtual Orientable
	{
	public:
		Progressbar();
		Progressbar(GtkProgressBar* progressbar);
		Progressbar(const char* text);
		void Pulse();
		void PulseStep(double fraction);
		double PulseStep();
		void Fraction(double fraction);
		double Fraction();
		void Inverted(bool inverted);
		bool Inverted();
		void ShowText(bool show);
		bool ShowText();
		void Text(const char* text);
		const char* Text();
		void Ellipsize(EllipsizeMode mode);
		EllipsizeMode Ellipsize();
		void Increment(double fraction);
		void Increment();
		bool IsProgressbar();
	};
}
