#include "./Headerbar.hh"

namespace CGui
{
	Headerbar::Headerbar(const char* title, const char* subtitle) : Container(this)
	{
		m_Widget = gtk_header_bar_new();
		this->Title(title);
		this->SubTitle(subtitle);
		this->SetContext(m_Widget);
	}

	Headerbar::Headerbar(GtkHeaderBar* headerbar) : Container(this)
	{
		m_Widget = GTK_WIDGET(headerbar);
		this->SetContext(m_Widget);
	}

	void Headerbar::Title(const char* title)
	{
		gtk_header_bar_set_title(GTK_HEADER_BAR(m_Widget), title);
	}

	const char* Headerbar::Title()
	{
		return gtk_header_bar_get_title(GTK_HEADER_BAR(m_Widget));
	}

	void Headerbar::SubTitle(const char* subtitle)
	{
		gtk_header_bar_set_subtitle(GTK_HEADER_BAR(m_Widget), subtitle);
	}
	const char* Headerbar::SubTitle()
	{
		return gtk_header_bar_get_subtitle(GTK_HEADER_BAR(m_Widget));
	}

	void Headerbar::HasSubTitle(bool has_subtitle)
	{
		gtk_header_bar_set_has_subtitle(GTK_HEADER_BAR(m_Widget), has_subtitle);
	}

	bool Headerbar::HasSubTitle()
	{
		return gtk_header_bar_get_has_subtitle(GTK_HEADER_BAR(m_Widget));
	}

	void Headerbar::CustomTitle(Widget& w)
	{
		gtk_header_bar_set_custom_title(GTK_HEADER_BAR(m_Widget), w.GetWidget());
	}

	Widget Headerbar::CustomTitle()
	{
		return Widget(gtk_header_bar_get_custom_title(GTK_HEADER_BAR(m_Widget)));
	}

	void Headerbar::ShowCloseButton(bool show_close_button)
	{
		gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(m_Widget), show_close_button);
	}

	bool Headerbar::ShowCloseButton()
	{
		return gtk_header_bar_get_show_close_button(GTK_HEADER_BAR(m_Widget));
	}

	void Headerbar::DecorationLayout(const char* layout)
	{
		gtk_header_bar_set_decoration_layout(GTK_HEADER_BAR(m_Widget), layout);
	}

	const char* Headerbar::DecorationLayout()
	{
		return gtk_header_bar_get_decoration_layout(GTK_HEADER_BAR(m_Widget));
	}

	void Headerbar::Add(PackType type, Widget& w)
	{
		auto func = Converter::Convert::GetInstance().HeaderbarFuncPtr(type);
		func(GTK_HEADER_BAR(m_Widget), w.GetWidget());
	}

	void Headerbar::AddStart(Widget& w)
	{
		this->Add(PackType::START, w);
	}

	void Headerbar::AddEnd(Widget& w)
	{
		this->Add(PackType::END, w);
	}
	bool Headerbar::IsHeaderbar()
	{
		return GTK_IS_HEADER_BAR(m_Widget);
	}
};