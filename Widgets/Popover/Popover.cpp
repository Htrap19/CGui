#include "Popover.hh"

namespace CGui
{

	Popover::Popover(Widget& relative_to) : Container(this)
	{
		m_Widget = gtk_popover_new(relative_to.GetWidget());
		this->SetContext(m_Widget);
	}

	Popover::Popover(GtkPopover* popover) : Container(this)
	{
		this->m_Widget = GTK_WIDGET(popover);
		this->SetContext(m_Widget);
	}

	Popover::Popover() : Container(this)
	{
		m_Widget = gtk_popover_new(NULL);
		this->SetContext(m_Widget);
	}

	void Popover::PopUp()
	{
		gtk_popover_popup(GTK_POPOVER(m_Widget));
	}

	void Popover::PopDown()
	{
		gtk_popover_popdown(GTK_POPOVER(m_Widget));
	}

	void Popover::RelativeTo(Widget& relative_to)
	{
		gtk_popover_set_relative_to(GTK_POPOVER(m_Widget), relative_to.GetWidget());
	}

	CGui::Widget Popover::RelativeTo()
	{
		return Widget(gtk_popover_get_relative_to(GTK_POPOVER(m_Widget)));
	}

	void Popover::PointingTo(Rectangle rect)
	{
		GdkRectangle rectangle;
		rectangle.x = rect.coord_info.x;
		rectangle.y = rect.coord_info.y;
		rectangle.width = rect.requisition.width;
		rectangle.height = rect.requisition.height;
		gtk_popover_set_pointing_to(GTK_POPOVER(m_Widget), &rectangle);
	}

	CGui::PointingToData Popover::PointingTo()
	{
		GdkRectangle rect;
		bool was_set;

		was_set = gtk_popover_get_pointing_to(GTK_POPOVER(m_Widget), &rect);

		return { was_set, { { rect.x, rect.y }, { rect.width, rect.height } } };
	}

	void Popover::Position(PositionType type)
	{
		gtk_popover_set_position(GTK_POPOVER(m_Widget), (GtkPositionType)type);
	}

	CGui::PositionType Popover::Position()
	{
		return (PositionType)gtk_popover_get_position(GTK_POPOVER(m_Widget));
	}

	void Popover::ConstrainTo(PopoverConstraint constrain_to)
	{
		gtk_popover_set_constrain_to(GTK_POPOVER(m_Widget), (GtkPopoverConstraint)constrain_to);
	}

	CGui::PopoverConstraint Popover::ConstrainTo()
	{
		return (PopoverConstraint)gtk_popover_get_constrain_to(GTK_POPOVER(m_Widget));
	}

	void Popover::Modal(bool modal)
	{
		gtk_popover_set_modal(GTK_POPOVER(m_Widget), modal);
	}

	bool Popover::Modal()
	{
		return gtk_popover_get_modal(GTK_POPOVER(m_Widget));
	}

	void Popover::DefaultWidget(Widget& default_widget)
	{
		gtk_popover_set_default_widget(GTK_POPOVER(m_Widget), default_widget.GetWidget());
	}

	CGui::Widget Popover::DefaultWidget()
	{
		return Widget(gtk_popover_get_default_widget(GTK_POPOVER(m_Widget)));
	}

	bool Popover::IsPopover()
	{
		return GTK_IS_POPOVER(m_Widget);
	}

}