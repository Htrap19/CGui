#include "./Label.hh"

namespace CGui
{
	Label::Label(const char* text)
	{
		widget = gtk_label_new(text);
		this->SetContext(widget);
	}

	void Label::Text(const char* text)
	{
		gtk_label_set_label(GTK_LABEL(widget), text);
	}

	const char* Label::Text()
	{
		return gtk_label_get_text(GTK_LABEL(widget));
	}
};
