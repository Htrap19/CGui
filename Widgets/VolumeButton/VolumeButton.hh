#pragma once

#include "../ScaleButton/ScaleButton.hh"

namespace CGui
{
	class VolumeButton : public ScaleButton
	{
	public:
		VolumeButton();
		bool IsVolumeButton();
	};
}