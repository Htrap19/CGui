#include "./Overlay.hh"

namespace CGui
{
	Overlay::Overlay()
	{
		widget = gtk_overlay_new();
		this->SetContext(widget);
	}

	void Overlay::AddOverlay(Widget& child)
	{
		gtk_overlay_add_overlay(GTK_OVERLAY(widget), child.GetWidget());
	}

	void Overlay::ReorderOverlay(Widget& child, int position)
	{
		gtk_overlay_reorder_overlay(GTK_OVERLAY(widget), child.GetWidget(), position);
	}

	void Overlay::OverlayPassThrough(Widget& child, bool pass)
	{
		gtk_overlay_set_overlay_pass_through(GTK_OVERLAY(widget), child.GetWidget(), pass);
	}

	bool Overlay::OverlayPassThrough(Widget& child)
	{
		return gtk_overlay_get_overlay_pass_through(GTK_OVERLAY(widget), child.GetWidget());
	}
}