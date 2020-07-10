#pragma once

#include "../Widget.hh"
#include "../Handler.hh"
#include "../Container.hh"
#include "../Image/Image.hh"

namespace CGui
{
	class Button : public Widget, public Handler<Button>, public Container<Button>
	{
	public:
		Button();
		Button(const char* text);
		void Text(const char* text);
		const char* Text();
		void Click();
		void Relief(ReliefStyle style);
		ReliefStyle Relief();
		void UseUnderline(bool use_underline);
		bool UseUnderline();
		void ButtonImage(Image& image);
		Image& ButtonImage();
		void ButtonImagePosition(PositionType position);
		PositionType ButtonImagePosition();
		void AlwaysShowImage(bool always_show_image);
		bool AlwaysShowImage();
		long unsigned int Clicked(void(*func)());
		long unsigned int Clicked(void(*func)(Button*));
		template <typename ... Args> long unsigned int Clicked(void(*func)(Button*, Args* ...), Args& ... args);
		template <typename ... Args> long unsigned int Clicked(void(*func)(Args* ...), Args& ... args);

	protected:
		Image* image;
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