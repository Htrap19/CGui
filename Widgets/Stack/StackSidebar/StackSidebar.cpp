#include "./StackSidebar.hh"

namespace CGui
{
	StackSidebar::StackSidebar()
	{
		widget = gtk_stack_sidebar_new();
		this->SetContext(widget);
	}

	void StackSidebar::SidebarStack(Stack& stack)
	{
		gtk_stack_sidebar_set_stack(GTK_STACK_SIDEBAR(widget), GTK_STACK(stack.GetWidget()));
	}

	Stack StackSidebar::SidebarStack()
	{
		return Stack(gtk_stack_sidebar_get_stack(GTK_STACK_SIDEBAR(widget)));
	}
}