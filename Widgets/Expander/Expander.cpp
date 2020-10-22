#include "./Expander.hh"

namespace CGui
{
	Expander::Expander(GtkExpander* expander) : Container(this)
	{
		widget = GTK_WIDGET(expander);
		this->SetContext(widget);
	}

	Expander::Expander(const char* label) : Container(this)
	{
		widget = gtk_expander_new(label);
		this->SetContext(widget);
	}

	void Expander::Expanded(bool expanded)
	{
		gtk_expander_set_expanded(GTK_EXPANDER(widget), expanded);
	}

	bool Expander::Expanded()
	{
		return gtk_expander_get_expanded(GTK_EXPANDER(widget));
	}

	void Expander::Label(const char* label)
	{
		gtk_expander_set_label(GTK_EXPANDER(widget), label);
	}

	const char* Expander::Label()
	{
		return gtk_expander_get_label(GTK_EXPANDER(widget));
	}

	void Expander::UseUnderline(bool use_underline)
	{
		gtk_expander_set_use_underline(GTK_EXPANDER(widget), use_underline);
	}

	bool Expander::UseUnderline()
	{
		return gtk_expander_get_use_underline(GTK_EXPANDER(widget));
	}

	void Expander::UseMarkup(bool use_markup)
	{
		gtk_expander_set_use_markup(GTK_EXPANDER(widget), use_markup);
	}

	bool Expander::UseMarkup()
	{
		return gtk_expander_get_use_markup(GTK_EXPANDER(widget));
	}

	void Expander::LabelWidget(Widget& label)
	{
		gtk_expander_set_label_widget(GTK_EXPANDER(widget), label.GetWidget());
	}

	Widget Expander::LabelWidget()
	{
		return Widget(gtk_expander_get_label_widget(GTK_EXPANDER(widget)));
	}

	void Expander::LabelFill(bool label_fill)
	{
		gtk_expander_set_label_fill(GTK_EXPANDER(widget), label_fill);
	}

	bool Expander::LabelFill()
	{
		return gtk_expander_get_label_fill(GTK_EXPANDER(widget));
	}

	void Expander::ResizeToplevel(bool resize)
	{
		gtk_expander_set_resize_toplevel(GTK_EXPANDER(widget), resize);
	}

	bool Expander::ResizeToplevel()
	{
		return gtk_expander_get_resize_toplevel(GTK_EXPANDER(widget));
	}

	bool Expander::IsExpander()
	{
		return GTK_IS_EXPANDER(widget);
	}

}
