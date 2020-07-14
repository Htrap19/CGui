#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Orientable.hh"

namespace CGui
{
	class Infobar : public Widget, public Container<Widget>, public Orientable
	{
	public:
		Infobar();
		Infobar(CGui::MessageType messagetype, bool showclosebutton);
		void MessageType(CGui::MessageType messagetype);
		CGui::MessageType MessageType();
		void ShowCloseButton(bool showclosebutton);
		bool ShowCloseButton();
	};
};
