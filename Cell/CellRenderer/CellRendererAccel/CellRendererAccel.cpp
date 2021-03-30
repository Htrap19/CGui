#include "./CellRendererAccel.hh"

namespace CGui
{
	namespace CellRenderers
	{
		
		Accel::Accel()
		{
			auto renderer_ptr = G_OBJECT(m_Renderer);
			g_clear_object(&renderer_ptr);

			m_Renderer = gtk_cell_renderer_accel_new();
		}

		bool Accel::IsCellRendererAccel()
		{
			return GTK_IS_CELL_RENDERER_ACCEL(m_Renderer);
		}

	}
}