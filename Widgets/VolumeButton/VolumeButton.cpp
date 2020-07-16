#include "./VolumeButton.hh"

namespace CGui
{
	VolumeButton::VolumeButton()
	{
		widget = gtk_volume_button_new();
		this->SetScaleButton(GTK_SCALE_BUTTON(widget));
	}
}