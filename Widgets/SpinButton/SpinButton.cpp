#include "./SpinButton.hh"

namespace CGui
{
	SpinButton::SpinButton(GtkSpinButton* spin_button) : Orientable(this), Handler<Entry>::Handler(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = GTK_WIDGET(m_Widget);
		this->SetContext(m_Widget);
	}
	
	SpinButton::SpinButton(CGui::Adjustment adjustment, double climb_rate, unsigned int digits) : Orientable(this), Handler<Entry>::Handler(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = gtk_spin_button_new(adjustment.GetAdjustment(), climb_rate, digits);
		this->SetContext(m_Widget);
	}

	SpinButton::SpinButton(double min, double max, double step) : Orientable(this), Handler<Entry>::Handler(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = gtk_spin_button_new_with_range(min, max, step);
		this->SetContext(m_Widget);
	}

	void SpinButton::Adjustment(CGui::Adjustment adjustment)
	{
		gtk_spin_button_set_adjustment(GTK_SPIN_BUTTON(m_Widget), adjustment.GetAdjustment());
	}

	CGui::Adjustment SpinButton::Adjustment()
	{
		return CGui::Adjustment(gtk_spin_button_get_adjustment(GTK_SPIN_BUTTON(m_Widget)));
	}

	void SpinButton::Digits(unsigned int digits)
	{
		gtk_spin_button_set_digits(GTK_SPIN_BUTTON(m_Widget), digits);
	}

	unsigned int SpinButton::Digits()
	{
		return gtk_spin_button_get_digits(GTK_SPIN_BUTTON(m_Widget));
	}

	void SpinButton::Increments(double step, double page)
	{
		gtk_spin_button_set_increments(GTK_SPIN_BUTTON(m_Widget), step, page);
	}

	IncrementsData SpinButton::Increments()
	{
		double s, p;
		gtk_spin_button_get_increments(GTK_SPIN_BUTTON(m_Widget), &s, &p);

		return { s, p };
	}

	void SpinButton::Range(double min, double max)
	{
		gtk_spin_button_set_range(GTK_SPIN_BUTTON(m_Widget), min, max);
	}

	RangeData SpinButton::Range()
	{
		double n, m;
		gtk_spin_button_get_range(GTK_SPIN_BUTTON(m_Widget), &n, &m);

		return { n, m };
	}

	void SpinButton::Value(double value)
	{
		gtk_spin_button_set_value(GTK_SPIN_BUTTON(m_Widget), value);
	}

	double SpinButton::Value()
	{
		return gtk_spin_button_get_value(GTK_SPIN_BUTTON(m_Widget));
	}

	int SpinButton::ValueasInt()
	{
		return gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(m_Widget));
	}

	void SpinButton::UpdatePolicy(SpinButtonUpdatePolicy policy)
	{
		gtk_spin_button_set_update_policy(GTK_SPIN_BUTTON(m_Widget), (GtkSpinButtonUpdatePolicy)policy);
	}

	SpinButtonUpdatePolicy SpinButton::UpdatePolicy()
	{
		return (SpinButtonUpdatePolicy)gtk_spin_button_get_update_policy(GTK_SPIN_BUTTON(m_Widget));
	}

	void SpinButton::Numeric(bool numeric)
	{
		gtk_spin_button_set_numeric(GTK_SPIN_BUTTON(m_Widget), numeric);
	}

	bool SpinButton::Numeric()
	{
		return gtk_spin_button_get_numeric(GTK_SPIN_BUTTON(m_Widget));
	}

	void SpinButton::Spin(SpinType direction, double increment)
	{
		gtk_spin_button_spin(GTK_SPIN_BUTTON(m_Widget), (GtkSpinType)direction, increment);
	}

	void SpinButton::Wrap(bool wrap)
	{
		gtk_spin_button_set_wrap(GTK_SPIN_BUTTON(m_Widget), wrap);
	}

	bool SpinButton::Wrap()
	{
		return gtk_spin_button_get_wrap(GTK_SPIN_BUTTON(m_Widget));
	}

	void SpinButton::SnapToTicks(bool snap_to_ticks)
	{
		gtk_spin_button_set_snap_to_ticks(GTK_SPIN_BUTTON(m_Widget), snap_to_ticks);
	}

	bool SpinButton::SnapToTicks()
	{
		return gtk_spin_button_get_snap_to_ticks(GTK_SPIN_BUTTON(m_Widget));
	}

	void SpinButton::Update()
	{
		gtk_spin_button_update(GTK_SPIN_BUTTON(m_Widget));
	}

	bool SpinButton::IsSpinButton()
	{
		return GTK_IS_SPIN_BUTTON(m_Widget);
	}

}