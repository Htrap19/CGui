#include "./CssProvider.hh"

namespace CGui
{
	CssProvider::CssProvider(const char* cssfilepath, Priority priority)
	{
		cssProvider = gtk_css_provider_new();
		gtk_style_context_add_provider_for_screen(gdk_display_get_default_screen(gdk_display_get_default()), GTK_STYLE_PROVIDER(cssProvider), (unsigned int)priority);
		gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(cssProvider), cssfilepath, NULL);
	}

	GtkCssProvider* CssProvider::GetWidget()
	{
		return cssProvider;
	}
};
