#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Entry/Entry.hh"

namespace CGui
{
	class Searchbar : public Widget, public Container<Searchbar>
	{
	public:
		Searchbar();
		void Connect(Entry& entry);
		void SearchMode(bool mode);
		bool SearchMode();
		void ShowCloseButton(bool show);
		bool ShowCloseButton();
		bool IsSearchbar();
	};
}