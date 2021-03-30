#include "./Searchbar.hh"

namespace CGui
{
	Searchbar::Searchbar(GtkSearchBar* search_bar) : Container(this)
	{
		m_Widget = GTK_WIDGET(search_bar);
		this->SetContext(m_Widget);
	}
	
	Searchbar::Searchbar() : Container(this)
	{
		m_Widget = gtk_search_bar_new();
		this->SetContext(m_Widget);
	}

	void Searchbar::Connect(Entry& entry)
	{
		gtk_search_bar_connect_entry(GTK_SEARCH_BAR(m_Widget), GTK_ENTRY(entry.GetWidget()));
	}

	void Searchbar::SearchMode(bool mode)
	{
		gtk_search_bar_set_search_mode(GTK_SEARCH_BAR(m_Widget), mode);
	}

	bool Searchbar::SearchMode()
	{
		return gtk_search_bar_get_search_mode(GTK_SEARCH_BAR(m_Widget));
	}

	void Searchbar::ShowCloseButton(bool show)
	{
		gtk_search_bar_set_show_close_button(GTK_SEARCH_BAR(m_Widget), show);
	}

	bool Searchbar::ShowCloseButton()
	{
		return gtk_search_bar_get_show_close_button(GTK_SEARCH_BAR(m_Widget));
	}

	bool Searchbar::IsSearchbar()
	{
		return GTK_IS_SEARCH_BAR(m_Widget);
	}

}