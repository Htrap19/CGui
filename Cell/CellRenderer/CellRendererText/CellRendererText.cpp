#include "./CellRendererText.hh"

namespace CGui
{
	namespace CellRenderers
	{
		Text::Text()
		{
			renderer = gtk_cell_renderer_text_new();
			cell_renderer_type = CellRenderersTypes::TEXT;
		}

		void Text::FixedHeightFromFont(int number_of_rows)
		{
			gtk_cell_renderer_text_set_fixed_height_from_font(GTK_CELL_RENDERER_TEXT(renderer), number_of_rows);
		}

		bool Text::IsCellRendererText()
		{
			return GTK_IS_CELL_RENDERER_TEXT(renderer);
		}

	}
}

