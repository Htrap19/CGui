#pragma once

#include "../Widget.hh"

namespace CGui
{
	class Label : public Widget
	{
	public:
		Label(const char* text);
		void Text(const char* text);
		const char* Text();
	};
};
