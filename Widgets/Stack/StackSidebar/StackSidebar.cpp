#include "./StackSidebar.hh"

namespace CGui
{
	StackSidebar::StackSidebar()
	{
		m_Widget = gtk_stack_sidebar_new();
		this->SetContext(m_Widget);
	}

	StackSidebar::StackSidebar(GtkStackSidebar* stack_sidebar)
	{
		m_Widget = GTK_WIDGET(stack_sidebar);
		this->SetContext(m_Widget);
	}

	void StackSidebar::Stack(CGui::Stack& stack)
	{
		gtk_stack_sidebar_set_stack(GTK_STACK_SIDEBAR(m_Widget), GTK_STACK(stack.GetWidget()));
	}

	Stack StackSidebar::Stack()
	{
		return CGui::Stack(gtk_stack_sidebar_get_stack(GTK_STACK_SIDEBAR(m_Widget)));
	}

	bool StackSidebar::IsStackSidebar()
	{
		return GTK_IS_STACK_SIDEBAR(m_Widget);
	}
}