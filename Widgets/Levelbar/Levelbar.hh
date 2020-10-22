#pragma once

#include "../Widget.hh"
#include "../Orientable.hh"

namespace CGui
{
	class Levelbar : public Widget, public Orientable
	{
	public:
		Levelbar();
		Levelbar(double min_value, double max_value);
		void Mode(LevelbarMode mode);
		LevelbarMode Mode();
		void Value(double value);
		double Value();
		void MinValue(double min_value);
		double MinValue();
		void MaxValue(double max_value);
		double MaxValue();
		void Inverted(bool inverted);
		bool Inverted();
		void AddOffsetValue(const char* name, double value);
		void RemoveOffsetValue(const char* name);
		LevelbarOffsetData OffsetValue(const char* name);
		bool IsLevelbar();
	};
}