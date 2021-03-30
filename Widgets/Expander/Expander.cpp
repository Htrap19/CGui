#include "./Expander.hh"

namespace CGui
{
	Expander::Expander(GtkExpander* expander) : Container(this)
	{
		m_Widget = GTK_WIDGET(expander);
		this->SetContext(m_Widget);
	}

	Expander::Expander(const char* label) : Container(this)
	{
		m_Widget = gtk_expander_new(label);
		this->SetContext(m_Widget);
	}

	void Expander::Expanded(bool expanded)
	{
		gtk_expander_set_expanded(GTK_EXPANDER(m_Widget), expanded);
	}

	bool Expander::Expanded()
	{
		return gtk_expander_get_expanded(GTK_EXPANDER(m_Widget));
	}

	void Expander::Label(const char* label)
	{
		gtk_expander_set_label(GTK_EXPANDER(m_Widget), label);
	}

	const char* Expander::Label()
	{
		return gtk_expander_get_label(GTK_EXPANDER(m_Widget));
	}

	void Expander::UseUnderline(bool use_underline)
	{
		gtk_expander_set_use_underline(GTK_EXPANDER(m_Widget), use_underline);
	}

	bool Expander::UseUnderline()
	{
		return gtk_expander_get_use_underline(GTK_EXPANDER(m_Widget));
	}

	void Expander::UseMarkup(bool use_markup)
	{
		gtk_expander_set_use_markup(GTK_EXPANDER(m_Widget), use_markup);
	}

	bool Expander::UseMarkup()
	{
		return gtk_expander_get_use_markup(GTK_EXPANDER(m_Widget));
	}

	void Expander::LabelWidget(Widget& label)
	{
		gtk_expander_set_label_widget(GTK_EXPANDER(m_Widget), label.GetWidget());
	}

	Widget Expander::LabelWidget()
	{
		return Widget(gtk_expander_get_label_widget(GTK_EXPANDER(m_Widget)));
	}

	void Expander::LabelFill(bool label_fill)
	{
		gtk_expander_set_label_fill(GTK_EXPANDER(m_Widget), label_fill);
	}

	bool Expander::LabelFill()
	{
		return gtk_expander_get_label_fill(GTK_EXPANDER(m_Widget));
	}

	void Expander::ResizeToplevel(bool resize)
	{
		gtk_expander_set_resize_toplevel(GTK_EXPANDER(m_Widget), resize);
	}

	bool Expander::ResizeToplevel()
	{
		return gtk_expander_get_resize_toplevel(GTK_EXPANDER(m_Widget));
	}

	bool Expander::IsExpander()
	{
		return GTK_IS_EXPANDER(m_Widget);
	}

}
