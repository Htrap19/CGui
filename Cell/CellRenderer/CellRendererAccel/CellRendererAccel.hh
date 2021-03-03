#pragma once

#include "../CellRendererText/CellRendererText.hh"

namespace CGui
{
	namespace CellRenderers
	{
		class Accel : public virtual Text
		{
		public:
			Accel();

			bool IsCellRendererAccel();
		};
	}
}