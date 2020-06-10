#pragma once

#include "../Widget.hh"
#include "../Container.hh"

namespace CGui
{
	class ScrolledWindow : public Widget, public Container<ScrolledWindow>
	{
	public:
		ScrolledWindow(Policy hpolicy, Policy vpolicy);
		void ScrollPolicy(Policy hpolicy, Policy vpolicy);
	};
};
