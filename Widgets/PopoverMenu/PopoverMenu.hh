#pragma once

#include "../Popover/Popover.hh"

namespace CGui
{
	class PopoverMenu : public virtual Popover
	{
	public:
		PopoverMenu();
		PopoverMenu(GtkPopoverMenu* popover_menu);
		void OpenSubmenu(const char* name);

		bool IsPopoverMenu();
	};
}