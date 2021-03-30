#include "./ScaleButton.hh"

namespace CGui
{
	ScaleButton::ScaleButton(GtkScaleButton* scale_button) : Orientable(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = GTK_WIDGET(scale_button);
		this->SetContext(m_Widget);
	}

	ScaleButton::ScaleButton(IconSize size, double min, double max, double step, const char** icons) : Orientable(this), Handler<Button>::Handler(this), Button::Container(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = gtk_scale_button_new((GtkIconSize)size, min, max, step, icons);
		this->SetContext(m_Widget);
	}

	void ScaleButton::Adjustment(CGui::Adjustment adjustment)
	{
		gtk_scale_button_set_adjustment(GTK_SCALE_BUTTON(m_Widget), adjustment.GetAdjustment());
	}

	CGui::Adjustment ScaleButton::Adjustment()
	{
		return CGui::Adjustment(gtk_scale_button_get_adjustment(GTK_SCALE_BUTTON(m_Widget)));
	}

	void ScaleButton::Icons(const char** icons)
	{
		gtk_scale_button_set_icons(GTK_SCALE_BUTTON(m_Widget), icons);
	}

	void ScaleButton::Value(double value)
	{
		gtk_scale_button_set_value(GTK_SCALE_BUTTON(m_Widget), value);
	}

	double ScaleButton::Value()
	{
		return gtk_scale_button_get_value(GTK_SCALE_BUTTON(m_Widget));
	}

	Widget ScaleButton::Popup()
	{
		return Widget(gtk_scale_button_get_popup(GTK_SCALE_BUTTON(m_Widget)));
	}

	Button ScaleButton::PlusButton()
	{
		return Button(GTK_BUTTON(gtk_scale_button_get_plus_button(GTK_SCALE_BUTTON(m_Widget))));
	}

	Button ScaleButton::MinusButton()
	{
		return Button(GTK_BUTTON(gtk_scale_button_get_minus_button(GTK_SCALE_BUTTON(m_Widget))));
	}

	bool ScaleButton::IsScaleButton()
	{
		return GTK_IS_SCALE_BUTTON(m_Widget);
	}

	ScaleButton::ScaleButton() : Orientable(this), Handler<Button>::Handler(this), Button::Container(this)
	{
	}

	void ScaleButton::SetScaleButton(GtkScaleButton* scalebutton)
	{
		this->m_Widget = GTK_WIDGET(scalebutton);
	}

}