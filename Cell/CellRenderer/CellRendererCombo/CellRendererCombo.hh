#pragma once

#include "../CellRendererText/CellRendererText.hh"

namespace CGui
{
	namespace CellRenderers
	{
		class Combo : public virtual Text
		{
		public:
			Combo();

			bool IsCellRendererCombo();
		};
	}
}