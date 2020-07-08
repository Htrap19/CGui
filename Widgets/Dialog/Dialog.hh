#pragma once

#include "../Widget.hh"
#include "../Window/Window.hh"
#include "../Container.hh"

namespace CGui
{
	class Dialog : public Window, public Container<Widget>
	{
	public:
		Dialog(Window& window, bool modal, const char* title = "");
		ResponseType Run();
		void ActionWidget(Widget& action_widget, ResponseType res_type);
		Widget AddButton(const char* button_text, ResponseType res_type);
		void DefaultResponse(ResponseType res_type);
		void ResponseSensitive(ResponseType res_type, bool sensitive);
		ResponseType ResponseForWidget(Widget& w);
		Widget WidgetForResponse(ResponseType res_type);
		void Add(Widget& child) override;
		void InternalWidth(unsigned int width) override;
		void Remove(Widget& child) override;

	protected:
		Dialog();
		void SetDialog(GtkDialog* dialog);
	};
};
