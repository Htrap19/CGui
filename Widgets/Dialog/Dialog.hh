#pragma once

#include "../Widget.hh"
#include "../Window/Window.hh"

namespace CGui
{
	class Dialog : public Widget, public Container<Widget>
	{
	public:
		Dialog(Window& window, bool modal, const char* title = "");
		void Resizable(bool resizable);
		void DefaultSize(unsigned int xsize, unsigned int ysize);
		void CustomHeaderbar(Headerbar& hb);
		void Title(const char* title);
		const char* Title();
		void Modal(bool modal);
		bool Modal();
		void Parent(Window& window);
		ResponseType Run();
		void ActionWidget(Widget& action_widget, ResponseType res_type);
		Widget AddButton(const char* button_text, ResponseType res_type);
		void DefaultResponse(ResponseType res_type);
		void ResponseSensitive(ResponseType res_type, bool sensitive);
		ResponseType ResponseForWidget(Widget& w);
		Widget WidgetForResponse(ResponseType res_type);
	};
};
