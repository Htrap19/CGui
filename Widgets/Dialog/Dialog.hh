#pragma once

#include "../Widget.hh"
#include "../Window/Window.hh"
#include "../Container.hh"

namespace CGui
{
	class Dialog : public virtual Window, public virtual Container<Widget>
	{
	public:
		Dialog(Window& window, bool modal, const char* title = "");
		Dialog(GtkDialog* dialog);
		ResponseType Run();
		void ActionWidget(Widget& action_widget, ResponseType res_type);
		Widget AddButton(const char* button_text, ResponseType res_type);
		void DefaultResponse(ResponseType res_type);
		void ResponseSensitive(ResponseType res_type, bool sensitive);
		ResponseType ResponseForWidget(Widget& w);
		Widget WidgetForResponse(ResponseType res_type);
		void Add(Widget& child) override;
		void Remove(Widget& child) override;
		void InternalWidth(unsigned int width) override;
		unsigned int InternalWidth() override;
		Vector<Widget> Children() override;
		bool IsDialog();

	protected:
		Dialog();
		void SetDialog(GtkDialog* dialog);
	};
};
