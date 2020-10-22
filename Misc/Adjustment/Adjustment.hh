#pragma once

#include <gtk/gtk.h>

namespace CGui
{
	class Adjustment
	{
	public:
		Adjustment(GtkAdjustment* adjustment);
		Adjustment(double value, double lower, double upper, double step_increment, double page_increment, double page_size);
		void Value(double value);
		double Value();
		void ClampPage(double lower, double upper);
		void Configure(double value, double lower, double upper, double step_increment, double page_increment, double page_size);
		void Lower(double lower);
		double Lower();
		void PageIncrement(double page_increment);
		double PageIncrement();
		void Pagesize(double page_size);
		double PageSize();
		void StepIncrement(double step_increment);
		double StepIncrement();
		double MinimumIncrement();
		void Upper(double upper);
		double Upper();
		bool IsAdjustment();

		GtkAdjustment* GetAdjustment();

	protected:
		GtkAdjustment* adjustment;
	};
}