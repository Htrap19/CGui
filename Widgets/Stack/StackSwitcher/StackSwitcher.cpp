#include "./StackSwitcher.hh"

namespace CGui
{
	StackSwitcher::StackSwitcher() : Box::Container(this), Box::Orientable(this)
	{
		m_Widget = gtk_stack_switcher_new();
		this->SetContext(m_Widget);
	}

	StackSwitcher::StackSwitcher(GtkStackSwitcher* stack_switcher) : Box::Container(this), Box::Orientable(this)
	{
		m_Widget = GTK_WIDGET(stack_switcher);
		this->SetContext(m_Widget);
	}

	void StackSwitcher::Stack(CGui::Stack& stack)
	{
		gtk_stack_switcher_set_stack(GTK_STACK_SWITCHER(m_Widget), GTK_STACK(stack.GetWidget()));
	}

	CGui::Stack StackSwitcher::Stack()
	{
		return CGui::Stack(GTK_STACK(gtk_stack_switcher_get_stack(GTK_STACK_SWITCHER(m_Widget))));
	}

	bool StackSwitcher::IsStackSwitcher()
	{
		return GTK_IS_STACK_SWITCHER(m_Widget);
	}
}