#pragma once

#include "../Button/Button.hh"

namespace CGui
{
	class LinkButton : public virtual Button
	{
	public:
		LinkButton(GtkLinkButton* link_button);
		LinkButton(const char* uri);
		LinkButton(const char* uri, const char* label);
		void Uri(const char* uri);
		const char* Uri();
		void Visited(bool visited);
		bool Visited();
		bool IsLinkButton();
	};
}