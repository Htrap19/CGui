#pragma once

#include "../Widget.hh"

namespace CGui
{
	class Spinner : public virtual Widget
	{
	public:
		Spinner();
		Spinner(GtkSpinner* spinner);
		void Start();
		void Stop();
		bool IsSpinner();
	};
};
