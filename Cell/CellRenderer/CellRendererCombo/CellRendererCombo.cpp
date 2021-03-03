#include "./CellRendererCombo.hh"

namespace CGui
{
	namespace CellRenderers
	{
		Combo::Combo()
		{
			auto renderer_ptr = G_OBJECT(renderer);
			g_clear_object(&renderer_ptr);

			renderer = gtk_cell_renderer_combo_new();
		}

		bool Combo::IsCellRendererCombo()
		{
			return GTK_IS_CELL_RENDERER_COMBO(renderer);
		}

	}
}