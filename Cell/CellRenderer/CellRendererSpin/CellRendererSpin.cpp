#include "./CellRendererSpin.hh"

namespace CGui
{
	namespace CellRenderers
	{

		Spin::Spin()
		{
			auto renderer_ptr = G_OBJECT(m_Renderer);
			g_clear_object(&renderer_ptr);

			m_Renderer = gtk_cell_renderer_spin_new();
		}

		bool Spin::IsCellRendererSpin()
		{
			return GTK_IS_CELL_RENDERER_SPIN(m_Renderer);
		}

	}
}