#include "./Overlay.hh"

namespace CGui
{
	Overlay::Overlay() : Container(this)
	{
		m_Widget = gtk_overlay_new();
		this->SetContext(m_Widget);
	}

	Overlay::Overlay(GtkOverlay* overlay) : Container(this)
	{
		m_Widget = GTK_WIDGET(overlay);
		this->SetContext(m_Widget);
	}

	void Overlay::AddOverlay(Widget& child)
	{
		gtk_overlay_add_overlay(GTK_OVERLAY(m_Widget), child.GetWidget());
	}

	void Overlay::ReorderOverlay(Widget& child, int position)
	{
		gtk_overlay_reorder_overlay(GTK_OVERLAY(m_Widget), child.GetWidget(), position);
	}

	void Overlay::OverlayPassThrough(Widget& child, bool pass)
	{
		gtk_overlay_set_overlay_pass_through(GTK_OVERLAY(m_Widget), child.GetWidget(), pass);
	}

	bool Overlay::OverlayPassThrough(Widget& child)
	{
		return gtk_overlay_get_overlay_pass_through(GTK_OVERLAY(m_Widget), child.GetWidget());
	}
	bool Overlay::IsOverlay()
	{
		return GTK_IS_OVERLAY(m_Widget);
	}
}