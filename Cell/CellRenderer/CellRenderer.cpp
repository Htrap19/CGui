#include "./CellRenderer.hh"

namespace CGui
{

	CellRenderer::CellRenderer(GtkCellRenderer* renderer)
	{
		this->m_Renderer = renderer;
	}

	Rectangle CellRenderer::AlignedArea(Widget& widget, CellRendererState flags, Rectangle cell_area)
	{
		GdkRectangle aligned_data;
		GdkRectangle cell_area_ori = Converter::Convert::GetInstance().ConvertFromRectangle(cell_area);

		gtk_cell_renderer_get_aligned_area(m_Renderer, widget.GetWidget(), (GtkCellRendererState)flags, &cell_area_ori, &aligned_data);

		return { { aligned_data.x, aligned_data.y }, { aligned_data.width, aligned_data.height } };
	}

	void CellRenderer::Render(cairo_t* cr, Widget& widget, Rectangle background_area, Rectangle cell_area, CellRendererState flags)
	{
		GdkRectangle background_area_ori = Converter::Convert::GetInstance().ConvertFromRectangle(background_area);
		GdkRectangle cell_area_ori = Converter::Convert::GetInstance().ConvertFromRectangle(cell_area);

		gtk_cell_renderer_render(m_Renderer, cr, widget.GetWidget(), &background_area_ori, &cell_area_ori, (GtkCellRendererState)flags);
	}

	void CellRenderer::FixedSize(Requisition size)
	{
		this->FixedSize(size.width, size.height);
	}

	void CellRenderer::FixedSize(int width, int height)
	{
		gtk_cell_renderer_set_fixed_size(m_Renderer, width, height);
	}

	CGui::Requisition CellRenderer::FixedSize()
	{
		gint width, height;

		gtk_cell_renderer_get_fixed_size(m_Renderer, &width, &height);

		return { width, height };
	}

	void CellRenderer::Visible(bool visible)
	{
		gtk_cell_renderer_set_visible(m_Renderer, visible);
	}

	bool CellRenderer::Visible()
	{
		return gtk_cell_renderer_get_visible(m_Renderer);
	}

	void CellRenderer::Sensitive(bool sensitive)
	{
		gtk_cell_renderer_set_sensitive(m_Renderer, sensitive);
	}

	bool CellRenderer::Sensitive()
	{
		gtk_cell_renderer_get_sensitive(m_Renderer);
	}

	void CellRenderer::Alignment(AlignData data)
	{
		this->Alignment(data.xalign, data.yalign);
	}

	void CellRenderer::Alignment(float xalign, float yalign)
	{
		gtk_cell_renderer_set_alignment(m_Renderer, xalign, yalign);
	}

	CGui::AlignData CellRenderer::Alignment()
	{
		gfloat xalign, yalign;

		gtk_cell_renderer_get_alignment(m_Renderer, &xalign, &yalign);

		return { xalign, yalign };
	}

	void CellRenderer::Padding(PaddingData data)
	{
		this->Padding(data.xpad, data.ypad);
	}

	void CellRenderer::Padding(int xpad, int ypad)
	{
		gtk_cell_renderer_set_padding(m_Renderer, xpad, ypad);
	}

	CGui::PaddingData CellRenderer::Padding()
	{
		gint xpad, ypad;

		gtk_cell_renderer_get_padding(m_Renderer, &xpad, &ypad);

		return { xpad, ypad };
	}

	CGui::StateFlags CellRenderer::State(Widget& widget, CellRendererState cell_state)
	{
		return (StateFlags)gtk_cell_renderer_get_state(m_Renderer, widget.GetWidget(), (GtkCellRendererState)cell_state);
	}

	bool CellRenderer::IsActivatable()
	{
		return gtk_cell_renderer_is_activatable(m_Renderer);
	}

	CGui::PreferredHeightData CellRenderer::PreferredHeight(Widget& widget)
	{
		gint minimum_size, natural_size;

		gtk_cell_renderer_get_preferred_height(m_Renderer, widget.GetWidget(), &minimum_size, &natural_size);

		return { minimum_size, natural_size };
	}

	CGui::PreferredHeightData CellRenderer::PreferredHeightForWidth(Widget& widget, int width)
	{
		gint minimum_size, natural_size;

		gtk_cell_renderer_get_preferred_height_for_width(m_Renderer, widget.GetWidget(), width, &minimum_size, &natural_size);

		return { minimum_size, natural_size };
	}

	CGui::PreferredSizeData CellRenderer::PreferredSize(Widget& widget)
	{
		GtkRequisition minimum_size, natural_size;

		gtk_cell_renderer_get_preferred_size(m_Renderer, widget.GetWidget(), &minimum_size, &natural_size);

		return { { minimum_size.width, minimum_size.height }, { natural_size.width, natural_size.height } };
	}

	CGui::PreferredWidthData CellRenderer::PreferredWidth(Widget& widget)
	{
		gint minimum_size, natural_size;

		gtk_cell_renderer_get_preferred_width(m_Renderer, widget.GetWidget(), &minimum_size, &natural_size);

		return { minimum_size, natural_size };
	}

	CGui::PreferredWidthData CellRenderer::PreferredWidthForHeight(Widget& widget, int height)
	{
		gint minimum_size, natural_size;

		gtk_cell_renderer_get_preferred_width_for_height(m_Renderer, widget.GetWidget(), height, &minimum_size, &natural_size);

		return { minimum_size, natural_size };
	}

	CGui::SizeRequestMode CellRenderer::RequestMode()
	{
		return (SizeRequestMode)gtk_cell_renderer_get_request_mode(m_Renderer);
	}

	GtkCellRenderer* CellRenderer::GetCellRenderer()
	{
		return m_Renderer;
	}

	CGui::CellRenderersTypes CellRenderer::CellRendererType()
	{
		return m_Type;
	}

	bool CellRenderer::IsCellRenderer()
	{
		return GTK_IS_CELL_RENDERER(m_Renderer);
	}

}