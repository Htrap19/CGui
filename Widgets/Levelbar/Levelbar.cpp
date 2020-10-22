#include "./Levelbar.hh"

namespace CGui
{
	Levelbar::Levelbar() : Orientable(this)
	{
		widget = gtk_level_bar_new();
		this->SetContext(widget);
	}
	Levelbar::Levelbar(double min_value, double max_value) : Orientable(this)
	{
		widget = gtk_level_bar_new_for_interval(min_value, max_value);
		this->SetContext(widget);
	}

	void Levelbar::Mode(LevelbarMode mode)
	{
		gtk_level_bar_set_mode(GTK_LEVEL_BAR(widget), (GtkLevelBarMode)mode);
	}

	LevelbarMode Levelbar::Mode()
	{
		return (LevelbarMode)gtk_level_bar_get_mode(GTK_LEVEL_BAR(widget));
	}

	void Levelbar::Value(double value)
	{
		gtk_level_bar_set_value(GTK_LEVEL_BAR(widget), value);
	}

	double Levelbar::Value()
	{
		return gtk_level_bar_get_value(GTK_LEVEL_BAR(widget));
	}

	void Levelbar::MinValue(double min_value)
	{
		gtk_level_bar_set_min_value(GTK_LEVEL_BAR(widget), min_value);
	}

	double Levelbar::MinValue()
	{
		return gtk_level_bar_get_min_value(GTK_LEVEL_BAR(widget));
	}

	void Levelbar::MaxValue(double max_value)
	{
		gtk_level_bar_set_max_value(GTK_LEVEL_BAR(widget), max_value);
	}

	double Levelbar::MaxValue()
	{
		return gtk_level_bar_get_max_value(GTK_LEVEL_BAR(widget));
	}

	void Levelbar::Inverted(bool inverted)
	{
		gtk_level_bar_set_inverted(GTK_LEVEL_BAR(widget), inverted);
	}

	bool Levelbar::Inverted()
	{
		return gtk_level_bar_get_inverted(GTK_LEVEL_BAR(widget));
	}

	void Levelbar::AddOffsetValue(const char* name, double value)
	{
		gtk_level_bar_add_offset_value(GTK_LEVEL_BAR(widget), name, value);
	}

	void Levelbar::RemoveOffsetValue(const char* name)
	{
		gtk_level_bar_remove_offset_value(GTK_LEVEL_BAR(widget), name);
	}

	LevelbarOffsetData Levelbar::OffsetValue(const char* name)
	{
		bool found;
		double value;
		found = gtk_level_bar_get_offset_value(GTK_LEVEL_BAR(widget), name, &value);

		return { found, value };
	}

	bool Levelbar::IsLevelbar()
	{
		return GTK_IS_LEVEL_BAR(widget);
	}

}