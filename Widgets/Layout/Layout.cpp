#include "./Layout.hh"

namespace CGui
{
	Layout::Layout()
	{
		widget = gtk_layout_new(NULL, NULL);
		this->SetScrollable(GTK_SCROLLABLE(widget));
		this->SetContext(widget);
	}

	Layout::Layout(Adjustment hadjustment, Adjustment vadjustment)
	{
		widget = gtk_layout_new(hadjustment.GetAdjustment(), vadjustment.GetAdjustment());
		this->SetScrollable(GTK_SCROLLABLE(widget));
		this->SetContext(widget);
	}

	void Layout::Put(Widget& child, int x, int y)
	{
		gtk_layout_put(GTK_LAYOUT(widget), child.GetWidget(), x, y);
	}

	void Layout::Move(Widget& child, int x, int y)
	{
		gtk_layout_move(GTK_LAYOUT(widget), child.GetWidget(), x, y);
	}

	void Layout::Size(unsigned int width, unsigned int height)
	{
		gtk_layout_set_size(GTK_LAYOUT(widget), width, height);
	}

	Requisition Layout::Size()
	{
		unsigned int w, h;
		gtk_layout_get_size(GTK_LAYOUT(widget), &w, &h);

		return { (int)w, (int)h };
	}

}