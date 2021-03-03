#pragma once

#include "../CellRenderer.hh"

namespace CGui
{
	namespace CellRenderers
	{
		class Text : public virtual CellRenderer
		{
		public:
			Text();
			void FixedHeightFromFont(int number_of_rows);

			bool IsCellRendererText();
		};
	}
}