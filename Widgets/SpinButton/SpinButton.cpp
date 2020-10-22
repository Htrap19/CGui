#include "./SpinButton.hh"

namespace CGui
{
	SpinButton::SpinButton(CGui::Adjustment adjustment, double climb_rate, unsigned int digits) : Orientable(this)
	{
		if (widget != nullptr)
			gtk_widget_destroy(widget);
		widget = gtk_spin_button_new(adjustment.GetAdjustment(), climb_rate, digits);
		this->SetEntry(GTK_ENTRY(widget));
	}

	SpinButton::SpinButton(double min, double max, double step) : Orientable(this)
	{
		if (widget != nullptr)
			gtk_widget_destroy(widget);
		widget = gtk_spin_button_new_with_range(min, max, step);
		this->SetEntry(GTK_ENTRY(widget));
	}

	void SpinButton::Adjustment(CGui::Adjustment adjustment)
	{
		gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(widget), adjustment.GetAdjustment());
	}

	CGui::Adjustment SpinButton::Adjustment()
	{
		return CGui::Adjustment(gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(widget)));
	}

	void SpinButton::Digits(unsigned int digits)
	{
		gtk_spin_button_set_digits(GTK_SPIN_BUTTON(widget), digits);
	}

	unsigned int SpinButton::Digits()
	{
		return gtk_spin_button_get_digits(GTK_SPIN_BUTTON(widget));
	}

	void SpinButton::Increments(double step, double page)
	{
		gtk_spin_button_set_increments(GTK_SPIN_BUTTON(widget), step, page);
	}

	IncrementsData SpinButton::Increments()
	{
		double s, p;
		gtk_spin_button_get_increments(GTK_SPIN_BUTTON(widget), &s, &p);

		return { s, p };
	}

	void SpinButton::Range(double min, double max)
	{
		gtk_spin_button_set_range(GTK_SPIN_BUTTON(widget), min, max);
	}

	RangeData SpinButton::Range()
	{
		double n, m;
		gtk_spin_button_get_range(GTK_SPIN_BUTTON(widget), &n, &m);

		return { n, m };
	}

	void SpinButton::Value(double value)
	{
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(widget), value);
	}

	double SpinButton::Value()
	{
		return gtk_spin_button_get_value(GTK_SPIN_BUTTON(widget));
	}

	int SpinButton::ValueasInt()
	{
		return gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(widget));
	}

	void SpinButton::UpdatePolicy(SpinButtonUpdatePolicy policy)
	{
		gtk_spin_button_set_update_policy(GTK_SPIN_BUTTON(widget), (GtkSpinButtonUpdatePolicy)policy);
	}

	SpinButtonUpdatePolicy SpinButton::UpdatePolicy()
	{
		return (SpinButtonUpdatePolicy)gtk_spin_button_get_update_policy(GTK_SPIN_BUTTON(widget));
	}

	void SpinButton::Numeric(bool numeric)
	{
		gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(widget), numeric);
	}

	bool SpinButton::Numeric()
	{
		return gtk_spin_button_get_numeric(GTK_SPIN_BUTTON(widget));
	}

	void SpinButton::Spin(SpinType direction, double increment)
	{
		gtk_spin_button_spin(GTK_SPIN_BUTTON(widget), (GtkSpinType)direction, increment);
	}

	void SpinButton::Wrap(bool wrap)
	{
		gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(widget), wrap);
	}

	bool SpinButton::Wrap()
	{
		return gtk_spin_button_get_wrap(GTK_SPIN_BUTTON(widget));
	}

	void SpinButton::SnapToTicks(bool snap_to_ticks)
	{
		gtk_spin_button_set_snap_to_ticks(GTK_SPIN_BUTTON(widget), snap_to_ticks);
	}

	bool SpinButton::SnapToTicks()
	{
		return gtk_spin_button_get_snap_to_ticks(GTK_SPIN_BUTTON(widget));
	}

	void SpinButton::Update()
	{
		gtk_spin_button_update(GTK_SPIN_BUTTON(widget));
	}

	bool SpinButton::IsSpinButton()
	{
		return GTK_IS_SPIN_BUTTON(widget);
	}

}