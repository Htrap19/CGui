#pragma once

#include "../Widget.hh"
#include "../Window/Window.hh"
#include "../../Converter/Convert.hh"
#include "../Container.hh"

namespace CGui
{
	class MessageDialog : public Widget, public Container<Widget>
	{
	public:
		MessageDialog(Window& parent, DialogFlags flags, MessageType message_type, ButtonsType buttons_type);
		void Markup(const char* str);
		template <typename ... Args> void SecondaryText(const char* fmt, Args ... args);
		template <typename ... Args> void SecondaryTextMarkup(const char* fmt, Args ... args);
		ResponseType Run();
	};

	template<typename ... Args>
	void MessageDialog::SecondaryText(const char* fmt, Args ... args)
	{
		gtk_message_dialog_format_secondary_text(GTK_MESSAGE_DIALOG(widget), fmt, args...);
	}

	template<typename ...Args>
	void MessageDialog::SecondaryTextMarkup(const char* fmt, Args ...args)
	{
		gtk_message_dialog_format_secondary_markup(GTK_MESSAGE_DIALOG(widget), fmt, args...);
	}
}