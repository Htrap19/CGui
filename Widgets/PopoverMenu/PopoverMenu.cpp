#include "PopoverMenu.hh"

namespace CGui
{

	PopoverMenu::PopoverMenu() : Popover::Container(this)
	{
		if (widget != nullptr)
			gtk_widget_destroy(widget);
		widget = gtk_popover_menu_new();
		this->SetContext(widget);
	}

	PopoverMenu::PopoverMenu(GtkPopoverMenu* popover_menu) : Popover::Container(this)
	{
		if (widget != nullptr)
			gtk_widget_destroy(widget);
		widget = GTK_WIDGET(popover_menu);
		this->SetContext(widget);
	}

	void PopoverMenu::OpenSubmenu(const char* name)
	{
		gtk_popover_menu_open_submenu(GTK_POPOVER_MENU(widget), name);
	}

	bool PopoverMenu::IsPopoverMenu()
	{
		return GTK_IS_POPOVER_MENU(widget);
	}

}