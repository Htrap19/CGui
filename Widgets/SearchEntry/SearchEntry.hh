#pragma once

#include "../Entry/Entry.hh"

namespace CGui
{
	class SearchEntry : public Entry, public Handler<SearchEntry>
	{
	public:
		SearchEntry();
		long unsigned int Changed(void(*func)());
		long unsigned int Changed(void(*func)(SearchEntry*));
		template <typename ... Args> long unsigned int Changed(void(*func)(SearchEntry*, Args* ...), Args& ... args);
		template <typename ... Args> long unsigned int Changed(void(*func)(Args* ...), Args& ... args);
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