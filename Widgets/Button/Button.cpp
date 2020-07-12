#include "./Button.hh"

namespace CGui
{
	Button::Button() : Handler(this), Container(this)
	{
		widget = gtk_button_new();
		this->SetContext(widget);
	}

	Button::Button(const char* text) : Handler(this), Container(this)
	{
		widget = gtk_button_new_with_label(text);
		this->SetContext(widget);
	}

	void Button::Text(const char* text)
	{
		gtk_button_set_label(GTK_BUTTON(widget), text);
	}

	const char* Button::Text()
	{
		return gtk_button_get_label(GTK_BUTTON(widget));
	}

	void Button::Click()
	{
		gtk_button_clicked(GTK_BUTTON(widget));
	}

	void Button::Relief(ReliefStyle style)
	{
		gtk_button_set_relief(GTK_BUTTON(widget), (GtkReliefStyle)style);
	}

	ReliefStyle Button::Relief()
	{
		return (ReliefStyle)gtk_button_get_relief(GTK_BUTTON(widget));
	}

	void Button::UseUnderline(bool use_underline)
	{
		gtk_button_set_use_underline(GTK_BUTTON(widget), use_underline);
	}

	bool Button::UseUnderline()
	{
		return gtk_button_get_use_underline(GTK_BUTTON(widget));
	}

	void Button::ButtonImage(Image& image)
	{
		gtk_button_set_image(GTK_BUTTON(widget), image.GetWidget());
	}

	Image Button::ButtonImage()
	{
		return Image(GTK_IMAGE(gtk_button_get_image(GTK_BUTTON(widget))));
	}

	void Button::ButtonImagePosition(PositionType position)
	{
		gtk_button_set_image_position(GTK_BUTTON(widget), (GtkPositionType)position);
	}

	PositionType Button::ButtonImagePosition()
	{
		return (PositionType)gtk_button_get_image_position(GTK_BUTTON(widget));
	}

	void Button::AlwaysShowImage(bool always_show_image)
	{
		gtk_button_set_always_show_image(GTK_BUTTON(widget), always_show_image);
	}

	bool Button::AlwaysShowImage()
	{
		return gtk_button_get_always_show_image(GTK_BUTTON(widget));
	}

	long unsigned int Button::Clicked(void(*func)())
	{
		return this->SignalHandler(Signals::CLICKED, func);
	}

	long unsigned int Button::Clicked(void(*func)(Button*))
	{
		return this->SignalHandler(Signals::CLICKED, func);
	}

	void Button::SetButton(GtkButton* button)
	{
		this->widget = GTK_WIDGET(button);
		this->SetContext(widget);
	}
};
