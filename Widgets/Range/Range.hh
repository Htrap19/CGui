#pragma once

#include "../Widget.hh"
#include "../Orientable.hh"
#include "../../Misc/Adjustment/Adjustment.hh"

namespace CGui
{
	class Range : public Widget, public Orientable
	{
	public:
		Range(Widget& w);
		void FillLevel(double fill_level);
		double FillLevel();
		void RestrictToFillLevel(bool restrict);
		bool RestrictToFillLevel();
		void ShowFillLevel(bool show);
		bool ShowFillLevel();
		void Adjustment(CGui::Adjustment adjustment);
		CGui::Adjustment Adjustment();
		void Inverted(bool inverted);
		bool Inverted();
		void Value(double value);
		double Value();
		void Increments(double step, double page);
		void NewRange(double min, double max);
		void RoundedDigits(int rounded_digits);
		int RoundDigits();
		void LowerStepperSensitivity(SensitivityType type);
		SensitivityType LowerStepperSensitivity();
		void UpperStepperSensitivity(SensitivityType type);
		SensitivityType UpperStepperSensitivity();
		void Flippable(bool flippable);
		bool Flippable();
		SliderRangeData SliderRage();
		void SliderSizeFixed(bool fixed);
		bool SliderSizefixed();
		bool IsRange();

	protected:
		Range();
		void SetRange(GtkRange* range);
	};
}