#include "./StackSwitcher.hh"

namespace CGui
{
	StackSwitcher::StackSwitcher() : Box::Container(this), Box::Orientable(this)
	{
		widget = gtk_stack_switcher_new();
		this->SetContext(widget);
	}

	StackSwitcher::StackSwitcher(GtkStackSwitcher* stack_switcher) : Box::Container(this), Box::Orientable(this)
	{
		widget = GTK_WIDGET(stack_switcher);
		this->SetContext(widget);
	}

	void StackSwitcher::Stack(CGui::Stack& stack)
	{
		gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(widget), GTK_STACK(stack.GetWidget()));
	}

	CGui::Stack StackSwitcher::Stack()
	{
		return CGui::Stack(GTK_STACK(gtk_stack_switcher_get_stack(GTK_STACK_SWITCHER(widget))));
	}

	bool StackSwitcher::IsStackSwitcher()
	{
		return GTK_IS_STACK_SWITCHER(widget);
	}
}