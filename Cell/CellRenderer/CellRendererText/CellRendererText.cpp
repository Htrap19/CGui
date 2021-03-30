#include "./CellRendererText.hh"

namespace CGui
{
	namespace CellRenderers
	{
		Text::Text()
		{
			m_Renderer = gtk_cell_renderer_text_new();
			m_Type = CellRenderersTypes::TEXT;
		}

		void Text::FixedHeightFromFont(int number_of_rows)
		{
			gtk_cell_renderer_text_set_fixed_height_from_font(GTK_CELL_RENDERER_TEXT(m_Renderer), number_of_rows);
		}

		bool Text::IsCellRendererText()
		{
			return GTK_IS_CELL_RENDERER_TEXT(m_Renderer);
		}

	}
}

