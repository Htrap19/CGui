#include "./SearchEntry.hh"

namespace CGui
{
	SearchEntry::SearchEntry() : Handler<SearchEntry>::Handler(this)
	{
		if (widget != nullptr)
			gtk_widget_destroy(widget);
		widget = gtk_search_entry_new();
		this->SetEntry(GTK_ENTRY(widget));
	}

	long unsigned int SearchEntry::Changed(void(*func)())
	{
		return this->Handler<SearchEntry>::SignalHandler(Signals::CHANGED, func);
	}

	long unsigned int SearchEntry::Changed(void(*func)(SearchEntry*))
	{
		return this->Handler<SearchEntry>::SignalHandler(Signals::CHANGED, func);
	}

	bool SearchEntry::IsSearchEntry()
	{
		return GTK_IS_SEARCH_ENTRY(widget);
	}
}