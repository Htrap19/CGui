#include "./Searchbar.hh"

namespace CGui
{
	Searchbar::Searchbar() : Container(this)
	{
		widget = gtk_search_bar_new();
		this->SetContext(widget);
	}

	void Searchbar::Connect(Entry& entry)
	{
		gtk_search_bar_connect_entry(GTK_SEARCH_BAR(widget), GTK_ENTRY(entry.GetWidget()));
	}

	void Searchbar::SearchMode(bool mode)
	{
		gtk_search_bar_set_search_mode(GTK_SEARCH_BAR(widget), mode);
	}

	bool Searchbar::SearchMode()
	{
		return gtk_search_bar_get_search_mode(GTK_SEARCH_BAR(widget));
	}

	void Searchbar::ShowCloseButton(bool show)
	{
		gtk_search_bar_set_show_close_button(GTK_SEARCH_BAR(widget), show);
	}

	bool Searchbar::ShowCloseButton()
	{
		return gtk_search_bar_get_show_close_button(GTK_SEARCH_BAR(widget));
	}

}