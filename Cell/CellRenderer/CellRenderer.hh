#pragma once

#include "../../Converter/Convert.hh"
#include "../../Widgets/Widget.hh"

namespace CGui
{
	class CellRenderer
	{
	public:
		CellRenderer() = default;
		CellRenderer(GtkCellRenderer* renderer);
		Rectangle AlignedArea(Widget& widget, CellRendererState flags, Rectangle cell_area);
		void Render(cairo_t* cr, Widget& widget, Rectangle background_area, Rectangle cell_area, CellRendererState flags);
		void FixedSize(Requisition size);
		void FixedSize(int width, int height);
		Requisition FixedSize();
		void Visible(bool visible);
		bool Visible();
		void Sensitive(bool sensitive);
		bool Sensitive();
		void Alignment(AlignData data);
		void Alignment(float xalign, float yalign);
		AlignData Alignment();
		void Padding(PaddingData data);
		void Padding(int xpad, int ypad);
		PaddingData Padding();
		StateFlags State(Widget& widget, CellRendererState cell_state);
		bool IsActivatable();
		PreferredHeightData PreferredHeight(Widget& widget);
		PreferredHeightData PreferredHeightForWidth(Widget& widget, int width);
		PreferredSizeData PreferredSize(Widget& widget);
		PreferredWidthData PreferredWidth(Widget& widget);
		PreferredWidthData PreferredWidthForHeight(Widget& widget, int height);
		SizeRequestMode RequestMode();

		GtkCellRenderer* GetCellRenderer();
		CellRenderersTypes CellRendererType();

		bool IsCellRenderer();

	protected:
		GtkCellRenderer* m_Renderer;
		CellRenderersTypes m_Type;
	};
}