#pragma once

#include "../Widget.hh"

namespace CGui
{
	class Spinner : public Widget
	{
	public:
		Spinner();
		void Start();
		void Stop();
		bool IsSpinner();
	};
};
