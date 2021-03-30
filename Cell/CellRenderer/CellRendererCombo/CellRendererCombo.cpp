#include "./CellRendererCombo.hh"

namespace CGui
{
	namespace CellRenderers
	{
		Combo::Combo()
		{
			auto renderer_ptr = G_OBJECT(m_Renderer);
			g_clear_object(&renderer_ptr);

			m_Renderer = gtk_cell_renderer_combo_new();
		}

		bool Combo::IsCellRendererCombo()
		{
			return GTK_IS_CELL_RENDERER_COMBO(m_Renderer);
		}

	}
}