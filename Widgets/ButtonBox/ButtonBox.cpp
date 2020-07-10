#include "./ButtonBox.hh"

namespace CGui
{
	ButtonBox::ButtonBox(Orientation orientation)
	{
		widget = gtk_button_box_new((GtkOrientation)orientation);
		this->SetBox(GTK_BOX(widget));
	}

	void ButtonBox::Layout(ButtonBoxStyle style)
	{
		gtk_button_box_set_layout(GTK_BUTTON_BOX(widget), (GtkButtonBoxStyle)style);
	}

	ButtonBoxStyle ButtonBox::Layout()
	{
		return (ButtonBoxStyle)gtk_button_box_get_layout(GTK_BUTTON_BOX(widget));
	}

	void ButtonBox::ChildSecondary(Widget& child, bool is_secondary)
	{
		gtk_button_box_set_child_secondary(GTK_BUTTON_BOX(widget), child.GetWidget(), is_secondary);
	}

	bool ButtonBox::ChildSecondary(Widget& child)
	{
		return gtk_button_box_get_child_secondary(GTK_BUTTON_BOX(widget), child.GetWidget());
	}

	void ButtonBox::ChildNonHomogeneous(Widget& child, bool non_homogeneous)
	{
		gtk_button_box_set_child_non_homogeneous(GTK_BUTTON_BOX(widget), child.GetWidget(), non_homogeneous);
	}

	bool ButtonBox::ChildNonHomogeneous(Widget& child)
	{
		return gtk_button_box_get_child_non_homogeneous(GTK_BUTTON_BOX(widget), child.GetWidget());
	}
}