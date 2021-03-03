#pragma once

#include "../Widget.hh"
#include "../Handler.hh"
#include "../Container.hh"
#include "../Image/Image.hh"

namespace CGui
{
	class Button : public virtual Widget, public virtual Handler<Button>, public virtual Container<Button>
	{
	public:
		Button();
		Button(const char* text, bool mnemonic = false);
		Button(GtkButton* button);
		void Text(const char* text);
		const char* Text();
		void Click();
		void Relief(ReliefStyle style);
		ReliefStyle Relief();
		void UseUnderline(bool use_underline);
		bool UseUnderline();
		void Image(CGui::Image& image);
		void Image(CGui::Pixbuf& pixbuf);
		CGui::Image Image();
		void ImagePosition(PositionType position);
		PositionType ImagePosition();
		void AlwaysShowImage(bool always_show_image);
		bool AlwaysShowImage();
		long unsigned int Clicked(void(*func)());
		long unsigned int Clicked(void(*func)(Button*));
		template <typename ... Args> long unsigned int Clicked(void(*func)(Button*, Args* ...), Args& ... args);
		template <typename ... Args> long unsigned int Clicked(void(*func)(Args* ...), Args& ... args);
		bool IsButton();

	protected:
		void SetButton(GtkButton* button);
	};

	template <typename ... Args> long unsigned int Button::Clicked(void(*func)(Button*, Args* ...), Args& ... args)
	{
		return this->SignalHandler(Signals::CLICKED, func, args...);
	}

	template <typename ... Args> long unsigned int Button::Clicked(void(*func)(Args* ...), Args& ... args)
	{
		return this->SignalHandler(Signals::CLICKED, func, args...);
	}
}