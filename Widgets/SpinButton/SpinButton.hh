#pragma once

#include "../Orientable.hh"
#include "../Entry/Entry.hh"
#include "../../Misc/Adjustment/Adjustment.hh"

namespace CGui
{
	class SpinButton : public Entry, public Orientable
	{
	public:
		SpinButton(CGui::Adjustment adjustment, double climb_rate, unsigned int digits);
		SpinButton(double min, double max, double step);
		void Adjustment(CGui::Adjustment adjustment);
		CGui::Adjustment Adjustment();
		void Digits(unsigned int digits);
		unsigned int Digits();
		void Increments(double step, double page);
		IncrementsData Increments();
		void Range(double min, double max);
		RangeData Range();
		void Value(double value);
		double Value();
		int ValueasInt();
		void UpdatePolicy(SpinButtonUpdatePolicy policy);
		SpinButtonUpdatePolicy UpdatePolicy();
		void Numeric(bool numeric);
		bool Numeric();
		void Spin(SpinType direction, double increment);
		void Wrap(bool wrap);
		bool Wrap();
		void SnapToTicks(bool snap_to_ticks);
		bool SnapToTicks();
		void Update();
	};
}