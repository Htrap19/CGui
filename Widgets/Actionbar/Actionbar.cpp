#include "./Actionbar.hh"

namespace CGui
{
	Actionbar::Actionbar() : Container(this)
	{
		widget = gtk_action_bar_new();
		this->SetContext(widget);
	}

	void Actionbar::Add(PackType type, Widget& child)
	{
		auto func = Converter::Convert::GetInstance().ActionbarFuncPtr(type);
		func(GTK_ACTION_BAR(widget), child.GetWidget());
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
		gtk_action_bar_set_center_widget(GTK_ACTION_BAR(widget), child.GetWidget());
	}

	Widget Actionbar::CenterWidget()
	{
		return Widget(gtk_action_bar_get_center_widget(GTK_ACTION_BAR(widget)));
	}
}