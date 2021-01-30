#include "./StackSidebar.hh"

namespace CGui
{
	StackSidebar::StackSidebar()
	{
		widget = gtk_stack_sidebar_new();
		this->SetContext(widget);
	}

	StackSidebar::StackSidebar(GtkStackSidebar* stack_sidebar)
	{
		widget = GTK_WIDGET(stack_sidebar);
		this->SetContext(widget);
	}

	void StackSidebar::Stack(CGui::Stack& stack)
	{
		gtk_stack_sidebar_set_stack(GTK_STACK_SIDEBAR(widget), GTK_STACK(stack.GetWidget()));
	}

	Stack StackSidebar::Stack()
	{
		return CGui::Stack(gtk_stack_sidebar_get_stack(GTK_STACK_SIDEBAR(widget)));
	}

	bool StackSidebar::IsStackSidebar()
	{
		return GTK_IS_STACK_SIDEBAR(widget);
	}
}