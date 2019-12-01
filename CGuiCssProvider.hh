#pragma once

#include <gtk/gtk.h>

class CssProvider
{
  public:
    CssProvider(const gchar *cssfilepath);
    GtkCssProvider *GetWidget();

  private:
    GtkCssProvider *cssProvider;
};

CssProvider::CssProvider(const gchar *cssfilepath)
{
  cssProvider = gtk_css_provider_new();
  gtk_style_context_add_provider_for_screen(gdk_display_get_default_screen(gdk_display_get_default()), GTK_STYLE_PROVIDER(cssProvider), GTK_STYLE_PROVIDER_PRIORITY_USER);
  gtk_css_provider_load_from_path(GTK_CSS_PROVIDER(cssProvider), cssfilepath, NULL);
}

GtkCssProvider *CssProvider::GetWidget()
{ return cssProvider; }
