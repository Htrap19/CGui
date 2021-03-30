#include "./SearchEntry.hh"

namespace CGui
{
	SearchEntry::SearchEntry() : Handler<SearchEntry>::Handler(this), Handler<Entry>::Handler(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = gtk_search_entry_new();
		this->SetContext(m_Widget);
	}

	SearchEntry::SearchEntry(GtkSearchEntry* search_entry) : Handler<SearchEntry>::Handler(this), Handler<Entry>::Handler(this)
	{
		if (m_Widget != nullptr)
			gtk_widget_destroy(m_Widget);
		m_Widget = GTK_WIDGET(search_entry);
		this->SetContext(m_Widget);
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
		return GTK_IS_SEARCH_ENTRY(m_Widget);
	}
}