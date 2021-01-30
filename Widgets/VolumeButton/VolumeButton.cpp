#include "./VolumeButton.hh"

namespace CGui
{
	VolumeButton::VolumeButton() : Handler<Button>::Handler(this), Button::Container(this), ScaleButton::Orientable(this)
	{
		widget = gtk_volume_button_new();
		this->SetContext(widget);
	}

	VolumeButton::VolumeButton(GtkVolumeButton* volume_button) : Handler<Button>::Handler(this), Button::Container(this), ScaleButton::Orientable(this)
	{
		widget = GTK_WIDGET(volume_button);
		this->SetContext(widget);
	}

	bool VolumeButton::IsVolumeButton()
	{
		return GTK_IS_VOLUME_BUTTON(widget);
	}
}