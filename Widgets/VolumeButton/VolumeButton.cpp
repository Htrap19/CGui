#include "./VolumeButton.hh"

namespace CGui
{
	VolumeButton::VolumeButton() : Handler<Button>::Handler(this), Button::Container(this), ScaleButton::Orientable(this)
	{
		m_Widget = gtk_volume_button_new();
		this->SetContext(m_Widget);
	}

	VolumeButton::VolumeButton(GtkVolumeButton* volume_button) : Handler<Button>::Handler(this), Button::Container(this), ScaleButton::Orientable(this)
	{
		m_Widget = GTK_WIDGET(volume_button);
		this->SetContext(m_Widget);
	}

	bool VolumeButton::IsVolumeButton()
	{
		return GTK_IS_VOLUME_BUTTON(m_Widget);
	}
}