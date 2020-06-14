#pragma once

#include "../Converter/Convert.hh"
#include "./StyleContext.hh"

namespace CGui
{
	class Widget : public StyleContext
	{
	public:
		virtual GtkWidget* GetWidget() const
		{
			return widget;
		}

		virtual void Align(Alignments halign, Alignments valign) const
		{
			gtk_widget_set_halign(GTK_WIDGET(widget), (GtkAlign)halign);
			gtk_widget_set_valign(GTK_WIDGET(widget), (GtkAlign)valign);
		}

		virtual void Name(const char* name) const
		{
			gtk_widget_set_name(GTK_WIDGET(widget), name);
		}

		virtual const char* Name() const
		{
			return gtk_widget_get_name(GTK_WIDGET(widget));
		}

		virtual void AppPaintable(bool paintable)
		{
			gtk_widget_set_app_paintable(GTK_WIDGET(widget), paintable);
		}

		virtual void Sensitive(bool sensitive) const
		{
			gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive);
		}

		virtual void SizeRequest(unsigned int x, unsigned int y) const
		{
			gtk_widget_set_size_request(GTK_WIDGET(widget), x, y);
		}

		virtual void Tooltip(const char* text) const
		{
			gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text);
		}

		virtual const char* Tooltip() const
		{
			return gtk_widget_get_tooltip_text(GTK_WIDGET(widget));
		}

		virtual void Hide() const
		{
			gtk_widget_hide(GTK_WIDGET(widget));
		}

		virtual void Show() const
		{
			gtk_widget_show(GTK_WIDGET(widget));
		}

		virtual void Destroy() const
		{
			gtk_widget_destroy(GTK_WIDGET(widget));
		}

		virtual void ShowAll() const
		{
			gtk_widget_show_all(GTK_WIDGET(widget));
		}

		virtual ~Widget()
		{  }

	protected:
		GtkWidget* widget;
	};
}
