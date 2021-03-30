#include "./Fixed.hh"

namespace CGui
{
	Fixed::Fixed() : Container(this)
	{
		m_Widget = gtk_fixed_new();
		this->SetContext(m_Widget);
	}

	Fixed::Fixed(GtkFixed* fixed) : Container(this)
	{
		m_Widget = GTK_WIDGET(fixed);
		this->SetContext(m_Widget);
	}

	void Fixed::Put(Widget& child, int x, int y)
	{
		gtk_fixed_put(GTK_FIXED(m_Widget), child.GetWidget(), x, y);
	}

	void Fixed::Move(Widget& child, int x, int y)
	{
		gtk_fixed_move(GTK_FIXED(m_Widget), child.GetWidget(), x, y);
	}
	bool Fixed::IsFixed()
	{
		return GTK_IS_FIXED(m_Widget);
	}
}