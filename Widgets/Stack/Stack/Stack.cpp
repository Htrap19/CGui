#include "./Stack.hh"

namespace CGui
{
	Stack::Stack() : Container(this)
	{
		m_Widget = gtk_stack_new();
		this->SetContext(m_Widget);
	}

	Stack::Stack(GtkStack* stack) : Container(this)
	{
		this->m_Widget = GTK_WIDGET(stack);
		this->SetContext(m_Widget);
	}

	void Stack::AddNamed(Widget& child, const char* name)
	{
		gtk_stack_add_named(GTK_STACK(m_Widget), child.GetWidget(), name);
	}

	void Stack::AddTitled(Widget& child, const char* name, const char* title)
	{
		gtk_stack_add_titled(GTK_STACK(m_Widget), child.GetWidget(), name, title);
	}

	Widget Stack::ChildByName(const char* name)
	{
		return Widget(gtk_stack_get_child_by_name(GTK_STACK(m_Widget), name));
	}

	void Stack::VisibleChild(Widget& child)
	{
		gtk_stack_set_visible_child(GTK_STACK(m_Widget), child.GetWidget());
	}

	Widget Stack::VisibleChild()
	{
		return Widget(gtk_stack_get_visible_child(GTK_STACK(m_Widget)));
	}

	void Stack::VisibleChildName(const char* name)
	{
		gtk_stack_set_visible_child_name(GTK_STACK(m_Widget), name);
	}

	const char* Stack::VisibleChildName()
	{
		return gtk_stack_get_visible_child_name(GTK_STACK(m_Widget));
	}

	void Stack::VisibleChildFull(const char* name, StackTransitionType transition)
	{
		gtk_stack_set_visible_child_full(GTK_STACK(m_Widget), name, (GtkStackTransitionType)transition);
	}

	void Stack::Homogeneous(bool homogeneous)
	{
		gtk_stack_set_homogeneous(GTK_STACK(m_Widget), homogeneous);
	}

	bool Stack::Homogeneous()
	{
		return gtk_stack_get_homogeneous(GTK_STACK(m_Widget));
	}

	void Stack::HHomogeneous(bool hhomogeneous)
	{
		gtk_stack_set_hhomogeneous(GTK_STACK(m_Widget), hhomogeneous);
	}

	bool Stack::HHomogeneous()
	{
		return gtk_stack_get_hhomogeneous(GTK_STACK(m_Widget));
	}

	void Stack::VHomogeneous(bool vhomogeneous)
	{
		gtk_stack_set_vhomogeneous(GTK_STACK(m_Widget), vhomogeneous);
	}

	bool Stack::VHomogeneous()
	{
		return gtk_stack_get_vhomogeneous(GTK_STACK(m_Widget));
	}

	void Stack::TransitionDuration(unsigned int duration)
	{
		gtk_stack_set_transition_duration(GTK_STACK(m_Widget), duration);
	}

	unsigned int Stack::TransitionDuration()
	{
		return gtk_stack_get_transition_duration(GTK_STACK(m_Widget));
	}

	void Stack::TransitionType(StackTransitionType type)
	{
		gtk_stack_set_transition_type(GTK_STACK(m_Widget), (GtkStackTransitionType)type);
	}

	StackTransitionType Stack::TransitionType()
	{
		return (StackTransitionType)gtk_stack_get_transition_type(GTK_STACK(m_Widget));
	}

	bool Stack::TransitionRunning()
	{
		return gtk_stack_get_transition_running(GTK_STACK(m_Widget));
	}

	void Stack::InterpolateSize(bool interpolate)
	{
		gtk_stack_set_interpolate_size(GTK_STACK(m_Widget), interpolate);
	}

	bool Stack::InterpolateSize()
	{
		return gtk_stack_get_interpolate_size(GTK_STACK(m_Widget));
	}

	bool Stack::IsStack()
	{
		return GTK_IS_STACK(m_Widget);
	}
}