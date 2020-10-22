#pragma once

#include "../Container.hh"
#include "../Box/Box.hh"

namespace CGui
{
	class Infobar : public Box, public Container<Widget>
	{
	public:
		Infobar();
		Infobar(GtkInfoBar* infobar);
		Infobar(CGui::MessageType messagetype, bool showclosebutton);
		void MessageType(CGui::MessageType messagetype);
		CGui::MessageType MessageType();
		void ShowCloseButton(bool showclosebutton);
		bool ShowCloseButton();
		void ActionWidget(Widget& child, ResponseType res_id);
		Widget AddButton(const char* button_text, ResponseType res_id);
		void ResponseSensitive(ResponseType res, bool sensitive);
		void DefaultResponse(ResponseType res);
		void Response(ResponseType res);
		Widget ContentArea();
		Widget ActionArea();
		bool IsInfobar();
	};
};
