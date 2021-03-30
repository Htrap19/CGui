#include "./Paned.hh"

namespace CGui
{
	Paned::Paned(CGui::Orientation orientation) : Container(this), Orientable(this)
	{
		m_Widget = gtk_paned_new((GtkOrientation)orientation);
		this->SetContext(m_Widget);
	}

	Paned::Paned(GtkPaned* paned) : Container(this), Orientable(this)
	{
		m_Widget = GTK_WIDGET(paned);
		this->SetContext(m_Widget);
	}

	void Paned::Add1(Widget& child)
	{
		gtk_paned_add1(GTK_PANED(m_Widget), child.GetWidget());
	}

	void Paned::Add2(Widget& child)
	{
		gtk_paned_add2(GTK_PANED(m_Widget), child.GetWidget());
	}

	void Paned::Pack1(Widget& child, bool resize, bool shrink)
	{
		gtk_paned_pack1(GTK_PANED(m_Widget), child.GetWidget(), resize, shrink);
	}

	void Paned::Pack2(Widget& child, bool resize, bool shrink)
	{
		gtk_paned_pack2(GTK_PANED(m_Widget), child.GetWidget(), resize, shrink);
	}

	Widget Paned::Child1()
	{
		return Widget(gtk_paned_get_child1(GTK_PANED(m_Widget)));
	}

	Widget Paned::Child2()
	{
		return Widget(gtk_paned_get_child2(GTK_PANED(m_Widget)));
	}

	void Paned::Position(int position)
	{
		gtk_paned_set_position(GTK_PANED(m_Widget), position);
	}

	int Paned::Position()
	{
		return gtk_paned_get_position(GTK_PANED(m_Widget));
	}

	void Paned::WideHandle(bool handle)
	{
		gtk_paned_set_wide_handle(GTK_PANED(m_Widget), handle);
	}

	bool Paned::WideHandle()
	{
		return gtk_paned_get_wide_handle(GTK_PANED(m_Widget));
	}
	bool Paned::IsPaned()
	{
		return GTK_IS_PANED(m_Widget);
	}
}