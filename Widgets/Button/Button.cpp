#include "./Button.hh"

namespace CGui
{
	Button::Button() : Handler(this), Container(this)
	{
		m_Widget = gtk_button_new();
		this->SetContext(m_Widget);
	}

	Button::Button(const char* text, bool mnemonic) : Handler(this), Container(this)
	{
		if (mnemonic)
			m_Widget = gtk_button_new_with_mnemonic(text);
		else
			m_Widget = gtk_button_new_with_label(text);
		this->SetContext(m_Widget);
	}

	Button::Button(GtkButton* button) : Handler(this), Container(this)
	{
		this->m_Widget = GTK_WIDGET(button);
		this->SetContext(m_Widget);
	}

	void Button::Text(const char* text)
	{
		gtk_button_set_label(GTK_BUTTON(m_Widget), text);
	}

	const char* Button::Text()
	{
		return gtk_button_get_label(GTK_BUTTON(m_Widget));
	}

	void Button::Click()
	{
		gtk_button_clicked(GTK_BUTTON(m_Widget));
	}

	void Button::Relief(ReliefStyle style)
	{
		gtk_button_set_relief(GTK_BUTTON(m_Widget), (GtkReliefStyle)style);
	}

	ReliefStyle Button::Relief()
	{
		return (ReliefStyle)gtk_button_get_relief(GTK_BUTTON(m_Widget));
	}

	void Button::UseUnderline(bool use_underline)
	{
		gtk_button_set_use_underline(GTK_BUTTON(m_Widget), use_underline);
	}

	bool Button::UseUnderline()
	{
		return gtk_button_get_use_underline(GTK_BUTTON(m_Widget));
	}

	void Button::Image(CGui::Image& image)
	{
		gtk_button_set_image(GTK_BUTTON(m_Widget), image.GetWidget());
	}

	CGui::Image Button::Image()
	{
		return CGui::Image(GTK_IMAGE(gtk_button_get_image(GTK_BUTTON(m_Widget))));
	}

	void Button::Image(CGui::Pixbuf& pixbuf)
	{
		CGui::Image temp_image(pixbuf);
		this->Image(temp_image);
	}

	void Button::ImagePosition(PositionType position)
	{
		gtk_button_set_image_position(GTK_BUTTON(m_Widget), (GtkPositionType)position);
	}

	PositionType Button::ImagePosition()
	{
		return (PositionType)gtk_button_get_image_position(GTK_BUTTON(m_Widget));
	}

	void Button::AlwaysShowImage(bool always_show_image)
	{
		gtk_button_set_always_show_image(GTK_BUTTON(m_Widget), always_show_image);
	}

	bool Button::AlwaysShowImage()
	{
		return gtk_button_get_always_show_image(GTK_BUTTON(m_Widget));
	}

	long unsigned int Button::Clicked(void(*func)())
	{
		return this->SignalHandler(Signals::CLICKED, func);
	}

	long unsigned int Button::Clicked(void(*func)(Button*))
	{
		return this->SignalHandler(Signals::CLICKED, func);
	}

	bool Button::IsButton()
	{
		return GTK_IS_BUTTON(m_Widget);
	}

	void Button::SetButton(GtkButton* button)
	{
		this->m_Widget = GTK_WIDGET(button);
		this->SetContext(m_Widget);
	}
};
