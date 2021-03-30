#include "./Scale.hh"

namespace CGui
{
	Scale::Scale(GtkScale* scale) : Range::Orientable(this)
	{
		m_Widget = GTK_WIDGET(scale);
		this->SetContext(m_Widget);
	}
	
	Scale::Scale(CGui::Orientation orientation) : Range::Orientable(this)
	{
		m_Widget = gtk_scale_new((GtkOrientation)orientation, NULL);
		this->SetContext(m_Widget);
	}

	Scale::Scale(CGui::Orientation orientation, CGui::Adjustment adjustment) : Range::Orientable(this)
	{
		m_Widget = gtk_scale_new((GtkOrientation)orientation, adjustment.GetAdjustment());
		this->SetContext(m_Widget);
	}

	Scale::Scale(CGui::Orientation orientation, double min, double max, double step) : Range::Orientable(this)
	{
		m_Widget = gtk_scale_new_with_range((GtkOrientation)orientation, min, max, step);
		this->SetContext(m_Widget);
	}

	void Scale::Digits(int digits)
	{
		gtk_scale_set_digits(GTK_SCALE(m_Widget), digits);
	}

	int Scale::Digits()
	{
		return gtk_scale_get_digits(GTK_SCALE(m_Widget));
	}

	void Scale::DrawValue(bool draw_value)
	{
		gtk_scale_set_draw_value(GTK_SCALE(m_Widget), draw_value);
	}

	bool Scale::DrawValue()
	{
		return gtk_scale_get_draw_value(GTK_SCALE(m_Widget));
	}

	void Scale::HasOrigin(bool has_origin)
	{
		gtk_scale_set_has_origin(GTK_SCALE(m_Widget), has_origin);
	}

	bool Scale::HasOrigin()
	{
		return gtk_scale_get_has_origin(GTK_SCALE(m_Widget));
	}

	void Scale::ValuePos(PositionType position)
	{
		gtk_scale_set_value_pos(GTK_SCALE(m_Widget), (GtkPositionType)position);
	}

	PositionType Scale::ValuePos()
	{
		return (PositionType)gtk_scale_get_value_pos(GTK_SCALE(m_Widget));
	}

	void Scale::AddMark(double value, PositionType position, const char* markup)
	{
		gtk_scale_add_mark(GTK_SCALE(m_Widget), value, (GtkPositionType)position, markup);
	}

	void Scale::ClearMarks()
	{
		gtk_scale_clear_marks(GTK_SCALE(m_Widget));
	}

	bool Scale::IsScale()
	{
		return GTK_IS_SCALE(m_Widget);
	}

}