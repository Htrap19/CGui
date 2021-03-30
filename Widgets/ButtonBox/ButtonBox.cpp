#include "./ButtonBox.hh"

namespace CGui
{
	ButtonBox::ButtonBox(CGui::Orientation orientation) : Box::Container(this), Box::Orientable(this)
	{
		m_Widget = gtk_button_box_new((GtkOrientation)orientation);
		this->SetContext(m_Widget);
	}

	ButtonBox::ButtonBox(GtkButtonBox* buttonbox) : Box::Container(this), Box::Orientable(this)
	{
		m_Widget = GTK_WIDGET(buttonbox);
		this->SetContext(m_Widget);
	}

	void ButtonBox::Layout(ButtonBoxStyle style)
	{
		gtk_button_box_set_layout(GTK_BUTTON_BOX(m_Widget), (GtkButtonBoxStyle)style);
	}

	ButtonBoxStyle ButtonBox::Layout()
	{
		return (ButtonBoxStyle)gtk_button_box_get_layout(GTK_BUTTON_BOX(m_Widget));
	}

	void ButtonBox::ChildSecondary(Widget& child, bool is_secondary)
	{
		gtk_button_box_set_child_secondary(GTK_BUTTON_BOX(m_Widget), child.GetWidget(), is_secondary);
	}

	bool ButtonBox::ChildSecondary(Widget& child)
	{
		return gtk_button_box_get_child_secondary(GTK_BUTTON_BOX(m_Widget), child.GetWidget());
	}

	void ButtonBox::ChildNonHomogeneous(Widget& child, bool non_homogeneous)
	{
		gtk_button_box_set_child_non_homogeneous(GTK_BUTTON_BOX(m_Widget), child.GetWidget(), non_homogeneous);
	}

	bool ButtonBox::ChildNonHomogeneous(Widget& child)
	{
		return gtk_button_box_get_child_non_homogeneous(GTK_BUTTON_BOX(m_Widget), child.GetWidget());
	}
	bool ButtonBox::IsButtonBox()
	{
		return GTK_IS_BUTTON_BOX(m_Widget);
	}
}