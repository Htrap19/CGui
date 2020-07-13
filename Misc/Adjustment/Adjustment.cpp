#include "./Adjustment.hh"

namespace CGui
{
	Adjustment::Adjustment(GtkAdjustment* adjustment)
	{
		this->adjustment = adjustment;
	}

	Adjustment::Adjustment(double value, double lower, double upper, double step_increment, double page_increment, double page_size)
	{
		adjustment = gtk_adjustment_new(value, lower, upper, step_increment, page_increment, page_size);
	}

	void Adjustment::Value(double value)
	{
		gtk_adjustment_set_value(adjustment, value);
	}

	double Adjustment::Value()
	{
		return gtk_adjustment_get_value(adjustment);
	}

	void Adjustment::ClampPage(double lower, double upper)
	{
		gtk_adjustment_clamp_page(adjustment, lower, upper);
	}

	void Adjustment::Configure(double value, double lower, double upper, double step_increment, double page_increment, double page_size)
	{
		gtk_adjustment_configure(adjustment, value, lower, upper, step_increment, page_increment, page_size);
	}

	void Adjustment::Lower(double lower)
	{
		gtk_adjustment_set_lower(adjustment, lower);
	}

	double Adjustment::Lower()
	{
		return gtk_adjustment_get_lower(GTK_ADJUSTMENT(adjustment));
	}

	void Adjustment::PageIncrement(double page_increment)
	{
		gtk_adjustment_set_page_increment(adjustment, page_increment);
	}

	double Adjustment::PageIncrement()
	{
		return gtk_adjustment_get_page_increment(adjustment);
	}

	void Adjustment::Pagesize(double page_size)
	{
		gtk_adjustment_set_page_size(adjustment, page_size);
	}

	double Adjustment::PageSize()
	{
		return gtk_adjustment_get_page_size(adjustment);
	}

	void Adjustment::StepIncrement(double step_increment)
	{
		gtk_adjustment_set_step_increment(adjustment, step_increment);
	}

	double Adjustment::StepIncrement()
	{
		return gtk_adjustment_get_step_increment(adjustment);
	}

	double Adjustment::MinimumIncrement()
	{
		return gtk_adjustment_get_minimum_increment(adjustment);
	}

	void Adjustment::Upper(double upper)
	{
		gtk_adjustment_set_upper(adjustment, upper);
	}

	double Adjustment::Upper()
	{
		return gtk_adjustment_get_upper(adjustment);
	}

	GtkAdjustment* Adjustment::GetAdjustment()
	{
		return adjustment;
	}

}