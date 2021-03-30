#include "./Range.hh"

namespace CGui
{
	Range::Range(GtkRange* range) : Orientable(this)
	{
		this->SetRange(range);
	}

	Range::Range(Widget& w) : Orientable(this)
	{
		m_Widget = w.GetWidget();
		this->SetContext(m_Widget);
	}

	void Range::FillLevel(double fill_level)
	{
		gtk_range_set_fill_level(GTK_RANGE(m_Widget), fill_level);
	}

	double Range::FillLevel()
	{
		return gtk_range_get_fill_level(GTK_RANGE(m_Widget));
	}

	void Range::RestrictToFillLevel(bool restrict)
	{
		gtk_range_set_restrict_to_fill_level(GTK_RANGE(m_Widget), restrict);
	}

	bool Range::RestrictToFillLevel()
	{
		return gtk_range_get_restrict_to_fill_level(GTK_RANGE(m_Widget));
	}

	void Range::ShowFillLevel(bool show)
	{
		gtk_range_set_show_fill_level(GTK_RANGE(m_Widget), show);
	}

	bool Range::ShowFillLevel()
	{
		return gtk_range_get_show_fill_level(GTK_RANGE(m_Widget));
	}

	void Range::Adjustment(CGui::Adjustment adjustment)
	{
		gtk_range_set_adjustment(GTK_RANGE(m_Widget), adjustment.GetAdjustment());
	}

	CGui::Adjustment Range::Adjustment()
	{
		return CGui::Adjustment(gtk_range_get_adjustment(GTK_RANGE(m_Widget)));
	}

	void Range::Inverted(bool inverted)
	{
		gtk_range_set_inverted(GTK_RANGE(m_Widget), inverted);
	}

	bool Range::Inverted()
	{
		return gtk_range_get_inverted(GTK_RANGE(m_Widget));
	}

	void Range::Value(double value)
	{
		gtk_range_set_value(GTK_RANGE(m_Widget), value);
	}

	double Range::Value()
	{
		return gtk_range_get_value(GTK_RANGE(m_Widget));
	}

	void Range::Increments(double step, double page)
	{
		gtk_range_set_increments(GTK_RANGE(m_Widget), step, page);
	}

	void Range::NewRange(double min, double max)
	{
		gtk_range_set_range(GTK_RANGE(m_Widget), min, max);
	}

	void Range::RoundedDigits(int rounded_digits)
	{
		gtk_range_set_round_digits(GTK_RANGE(m_Widget), rounded_digits);
	}

	int Range::RoundDigits()
	{
		return gtk_range_get_round_digits(GTK_RANGE(m_Widget));
	}

	void Range::LowerStepperSensitivity(SensitivityType type)
	{
		gtk_range_set_lower_stepper_sensitivity(GTK_RANGE(m_Widget), (GtkSensitivityType)type);
	}

	SensitivityType Range::LowerStepperSensitivity()
	{
		return (SensitivityType)gtk_range_get_lower_stepper_sensitivity(GTK_RANGE(m_Widget));
	}

	void Range::UpperStepperSensitivity(SensitivityType type)
	{
		gtk_range_set_upper_stepper_sensitivity(GTK_RANGE(m_Widget), (GtkSensitivityType)type);
	}

	SensitivityType Range::UpperStepperSensitivity()
	{
		return (SensitivityType)gtk_range_get_upper_stepper_sensitivity(GTK_RANGE(m_Widget));
	}

	void Range::Flippable(bool flippable)
	{
		gtk_range_set_flippable(GTK_RANGE(m_Widget), flippable);
	}

	bool Range::Flippable()
	{
		return gtk_range_get_flippable(GTK_RANGE(m_Widget));
	}

	SliderRangeData Range::SliderRage()
	{
		int start, end;
		gtk_range_get_slider_range(GTK_RANGE(m_Widget), &start, &end);

		return { start, end };
	}

	void Range::SliderSizeFixed(bool fixed)
	{
		gtk_range_set_slider_size_fixed(GTK_RANGE(m_Widget), fixed);
	}

	bool Range::SliderSizefixed()
	{
		return gtk_range_get_slider_size_fixed(GTK_RANGE(m_Widget));
	}

	bool Range::IsRange()
	{
		return GTK_IS_RANGE(m_Widget);
	}

	Range::Range() : Orientable(this)
	{
	}

	void Range::SetRange(GtkRange* range)
	{
		this->m_Widget = GTK_WIDGET(range);
		this->SetContext(m_Widget);
	}

}