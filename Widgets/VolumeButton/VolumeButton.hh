#pragma once

#include "../ScaleButton/ScaleButton.hh"

namespace CGui
{
	class VolumeButton : public virtual ScaleButton
	{
	public:
		VolumeButton();
		VolumeButton(GtkVolumeButton* volume_button);
		bool IsVolumeButton();
	};
}