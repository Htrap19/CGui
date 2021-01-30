#pragma once

#include "../Entry/Entry.hh"

namespace CGui
{
	class SearchEntry : public virtual Entry, public virtual Handler<SearchEntry>
	{
	public:
		SearchEntry();
		SearchEntry(GtkSearchEntry* search_entry);
		long unsigned int Changed(void(*func)());
		long unsigned int Changed(void(*func)(SearchEntry*));
		template <typename ... Args> long unsigned int Changed(void(*func)(SearchEntry*, Args* ...), Args& ... args);
		template <typename ... Args> long unsigned int Changed(void(*func)(Args* ...), Args& ... args);
		bool IsSearchEntry();
	};

	template <typename ... Args> long unsigned int SearchEntry::Changed(void(*func)(SearchEntry*, Args* ...), Args& ... args)
	{
		return this->Handler<SearchEntry>::SignalHandler(Signals::CHANGED, func, args...);
	}

	template <typename ... Args> long unsigned int SearchEntry::Changed(void(*func)(Args* ...), Args& ... args)
	{
		return this->Handler<SearchEntry>::SignalHandler(Signals::CHANGED, func, args...);
	}
}