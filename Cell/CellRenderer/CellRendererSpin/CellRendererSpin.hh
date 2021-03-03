#pragma once

#include "../CellRendererText/CellRendererText.hh"

namespace CGui
{
	namespace CellRenderers
	{
		class Spin : public virtual Text
		{
		public:
			Spin();

			bool IsCellRendererSpin();
		};
	}
}