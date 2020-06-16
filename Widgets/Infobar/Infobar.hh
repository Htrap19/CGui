#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Revealer/Revealer.hh"

namespace CGui
{
	class Infobar : public Widget, public Container<Widget>
	{
	public:
		Infobar();
		Infobar(MessageType messagetype, bool showclosebutton);
		void MessageBoxType(MessageType messagetype);
		MessageType MessageBoxType();
		void ShowCloseButton(bool showclosebutton);
		bool ShowCloseButton();
	};
};
