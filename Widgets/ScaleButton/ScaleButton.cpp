#include "./ScaleButton.hh"

namespace CGui
{
	ScaleButton::ScaleButton(IconSize size, double min, double max, double step, const char** icons) : Orientable(this)
	{
		if (widget != nullptr)
			gtk_widget_destroy(widget);
		widget = gtk_scale_button_new((GtkIconSize)size, min, max, step, icons);
		this->SetButton(GTK_BUTTON(widget));
	}

	void ScaleButton::Adjustment(CGui::Adjustment adjustment)
	{
		gtk_scale_button_set_adjustment(GTK_SCALE_BUTTON(widget), adjustment.GetAdjustment());
	}

	CGui::Adjustment ScaleButton::Adjustment()
	{
		return CGui::Adjustment(gtk_scale_button_get_adjustment(GTK_SCALE_BUTTON(widget)));
	}

	void ScaleButton::Icons(const char** icons)
	{
		gtk_scale_button_set_icons(GTK_SCALE_BUTTON(widget), icons);
	}

	void ScaleButton::Value(double value)
	{
		gtk_scale_button_set_value(GTK_SCALE_BUTTON(widget), value);
	}

	double ScaleButton::Value()
	{
		return gtk_scale_button_get_value(GTK_SCALE_BUTTON(widget));
	}

	Widget ScaleButton::Popup()
	{
		return Widget(gtk_scale_button_get_popup(GTK_SCALE_BUTTON(widget)));
	}

	Button ScaleButton::PlusButton()
	{
		return Button(GTK_BUTTON(gtk_scale_button_get_plus_button(GTK_SCALE_BUTTON(widget))));
	}

	Button ScaleButton::MinusButton()
	{
		return Button(GTK_BUTTON(gtk_scale_button_get_minus_button(GTK_SCALE_BUTTON(widget))));
	}

	bool ScaleButton::IsScaleButton()
	{
		return GTK_IS_SCALE_BUTTON(widget);
	}

	ScaleButton::ScaleButton() : Orientable(this)
	{
	}

	void ScaleButton::SetScaleButton(GtkScaleButton* scalebutton)
	{
		this->widget = GTK_WIDGET(scalebutton);
		this->SetButton(GTK_BUTTON(widget));
	}

}