#pragma once

#include "../Range/Range.hh"

namespace CGui
{
	class Scale : public Range
	{
	public:
		Scale(CGui::Orientation orientation);
		Scale(CGui::Orientation orientation, CGui::Adjustment adjustment);
		Scale(CGui::Orientation orientation, double min, double max, double step);
		void Digits(int digits);
		int Digits();
		void DrawValue(bool draw_value);
		bool DrawValue();
		void HasOrigin(bool has_origin);
		bool HasOrigin();
		void ValuePos(PositionType position);
		PositionType ValuePos();
		void AddMark(double value, PositionType position, const char* markup);
		void ClearMarks();
	};
}