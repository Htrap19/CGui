#include "./Scale.hh"

namespace CGui
{
	Scale::Scale(CGui::Orientation orientation)
	{
		widget = gtk_scale_new((GtkOrientation)orientation, NULL);
		this->SetRange(GTK_RANGE(widget));
	}

	Scale::Scale(CGui::Orientation orientation, CGui::Adjustment adjustment)
	{
		widget = gtk_scale_new((GtkOrientation)orientation, adjustment.GetAdjustment());
		this->SetRange(GTK_RANGE(widget));
	}

	Scale::Scale(CGui::Orientation orientation, double min, double max, double step)
	{
		widget = gtk_scale_new_with_range((GtkOrientation)orientation, min, max, step);
		this->SetRange(GTK_RANGE(widget));
	}

	void Scale::Digits(int digits)
	{
		gtk_scale_set_digits(GTK_SCALE(widget), digits);
	}

	int Scale::Digits()
	{
		return gtk_scale_get_digits(GTK_SCALE(widget));
	}

	void Scale::DrawValue(bool draw_value)
	{
		gtk_scale_set_draw_value(GTK_SCALE(widget), draw_value);
	}

	bool Scale::DrawValue()
	{
		return gtk_scale_get_draw_value(GTK_SCALE(widget));
	}

	void Scale::HasOrigin(bool has_origin)
	{
		gtk_scale_set_has_origin(GTK_SCALE(widget), has_origin);
	}

	bool Scale::HasOrigin()
	{
		return gtk_scale_get_has_origin(GTK_SCALE(widget));
	}

	void Scale::ValuePos(PositionType position)
	{
		gtk_scale_set_value_pos(GTK_SCALE(widget), (GtkPositionType)position);
	}

	PositionType Scale::ValuePos()
	{
		return (PositionType)gtk_scale_get_value_pos(GTK_SCALE(widget));
	}

	void Scale::AddMark(double value, PositionType position, const char* markup)
	{
		gtk_scale_add_mark(GTK_SCALE(widget), value, (GtkPositionType)position, markup);
	}

	void Scale::ClearMarks()
	{
		gtk_scale_clear_marks(GTK_SCALE(widget));
	}

}