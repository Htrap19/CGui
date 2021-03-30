#include "PopoverMenu.hh"

namespace CGui
{

	PopoverMenu::PopoverMenu() : Popover::Container(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = gtk_popover_menu_new();
		this->SetContext(m_Widget);
	}

	PopoverMenu::PopoverMenu(GtkPopoverMenu* popover_menu) : Popover::Container(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = GTK_WIDGET(popover_menu);
		this->SetContext(m_Widget);
	}

	void PopoverMenu::OpenSubmenu(const char* name)
	{
		gtk_popover_menu_open_submenu(GTK_POPOVER_MENU(m_Widget), name);
	}

	bool PopoverMenu::IsPopoverMenu()
	{
		return GTK_IS_POPOVER_MENU(m_Widget);
	}

}