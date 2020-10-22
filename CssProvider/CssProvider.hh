#pragma once

#include <gtk/gtk.h>
#include "../Converter/Convert.hh"

namespace CGui
{
	class CssProvider
	{
	public:
		CssProvider(const char* cssfilepath, Priority priority);
		bool IsCssProvider();
		GtkCssProvider* GetWidget();

	private:
		GtkCssProvider* cssProvider;
	};
};
