#include "./Actionbar.hh"

namespace CGui
{
	Actionbar::Actionbar() : Container(this)
	{
		m_Widget = gtk_action_bar_new();
		this->SetContext(m_Widget);
	}

	Actionbar::Actionbar(GtkActionBar* actionbar) : Container(this)
	{
		m_Widget = GTK_WIDGET(actionbar);
		this->SetContext(m_Widget);
	}

	void Actionbar::Add(PackType type, Widget& child)
	{
		auto func = Converter::Convert::GetInstance().ActionbarFuncPtr(type);
		func(GTK_ACTION_BAR(m_Widget), child.GetWidget());
	}

	void Actionbar::AddStart(Widget& child)
	{
		this->Add(PackType::START, child);
	}

	void Actionbar::AddEnd(Widget& child)
	{
		this->Add(PackType::END, child);
	}

	void Actionbar::CenterWidget(Widget& child)
	{
		gtk_action_bar_set_center_widget(GTK_ACTION_BAR(m_Widget), child.GetWidget());
	}

	Widget Actionbar::CenterWidget()
	{
		return Widget(gtk_action_bar_get_center_widget(GTK_ACTION_BAR(m_Widget)));
	}
	bool Actionbar::IsActionbar()
	{
		return GTK_IS_ACTION_BAR(m_Widget);
	}
}