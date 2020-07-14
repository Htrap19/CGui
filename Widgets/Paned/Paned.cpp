#include "./Paned.hh"

namespace CGui
{
	Paned::Paned(CGui::Orientation orientation) : Container(this), Orientable(this)
	{
		widget = gtk_paned_new((GtkOrientation)orientation);
		this->SetContext(widget);
	}

	void Paned::Add1(Widget& child)
	{
		gtk_paned_add1(GTK_PANED(widget), child.GetWidget());
	}

	void Paned::Add2(Widget& child)
	{
		gtk_paned_add2(GTK_PANED(widget), child.GetWidget());
	}

	void Paned::Pack1(Widget& child, bool resize, bool shrink)
	{
		gtk_paned_pack1(GTK_PANED(widget), child.GetWidget(), resize, shrink);
	}

	void Paned::Pack2(Widget& child, bool resize, bool shrink)
	{
		gtk_paned_pack2(GTK_PANED(widget), child.GetWidget(), resize, shrink);
	}

	Widget Paned::Child1()
	{
		return Widget(gtk_paned_get_child1(GTK_PANED(widget)));
	}

	Widget Paned::Child2()
	{
		return Widget(gtk_paned_get_child2(GTK_PANED(widget)));
	}

	void Paned::Position(int position)
	{
		gtk_paned_set_position(GTK_PANED(widget), position);
	}

	int Paned::Position()
	{
		return gtk_paned_get_position(GTK_PANED(widget));
	}

	void Paned::WideHandle(bool handle)
	{
		gtk_paned_set_wide_handle(GTK_PANED(widget), handle);
	}

	bool Paned::WideHandle()
	{
		return gtk_paned_get_wide_handle(GTK_PANED(widget));
	}
}