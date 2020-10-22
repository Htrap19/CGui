#include "./Fixed.hh"

namespace CGui
{
	Fixed::Fixed() : Container(this)
	{
		widget = gtk_fixed_new();
		this->SetContext(widget);
	}

	void Fixed::Put(Widget& child, int x, int y)
	{
		gtk_fixed_put(GTK_FIXED(widget), child.GetWidget(), x, y);
	}

	void Fixed::Move(Widget& child, int x, int y)
	{
		gtk_fixed_move(GTK_FIXED(widget), child.GetWidget(), x, y);
	}
	bool Fixed::IsFixed()
	{
		return GTK_IS_FIXED(widget);
	}
}