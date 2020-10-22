#pragma once

#include "../Widget.hh"
#include "../Orientable.hh"

namespace CGui
{
	class Progressbar : public Widget, public Orientable
	{
	public:
		Progressbar();
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
