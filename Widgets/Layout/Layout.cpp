#include "./Layout.hh"

namespace CGui
{
	Layout::Layout()
	{
		m_Widget = gtk_layout_new(NULL, NULL);
		this->SetScrollable(GTK_SCROLLABLE(m_Widget));
		this->SetContext(m_Widget);
	}

	Layout::Layout(GtkLayout* layout)
	{
		m_Widget = GTK_WIDGET(layout);
		this->SetContext(m_Widget);
		this->SetScrollable(GTK_SCROLLABLE(m_Widget));
	}

	Layout::Layout(Adjustment hadjustment, Adjustment vadjustment)
	{
		m_Widget = gtk_layout_new(hadjustment.GetAdjustment(), vadjustment.GetAdjustment());
		this->SetScrollable(GTK_SCROLLABLE(m_Widget));
		this->SetContext(m_Widget);
	}

	void Layout::Put(Widget& child, int x, int y)
	{
		gtk_layout_put(GTK_LAYOUT(m_Widget), child.GetWidget(), x, y);
	}

	void Layout::Move(Widget& child, int x, int y)
	{
		gtk_layout_move(GTK_LAYOUT(m_Widget), child.GetWidget(), x, y);
	}

	void Layout::Size(unsigned int width, unsigned int height)
	{
		gtk_layout_set_size(GTK_LAYOUT(m_Widget), width, height);
	}

	Requisition Layout::Size()
	{
		unsigned int w, h;
		gtk_layout_get_size(GTK_LAYOUT(m_Widget), &w, &h);

		return { (int)w, (int)h };
	}

	bool Layout::IsLayout()
	{
		return GTK_IS_LAYOUT(m_Widget);
	}

}