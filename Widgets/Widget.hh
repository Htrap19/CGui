#pragma once

#include "../Converter/Convert.hh"
#include "./StyleContext.hh"

namespace CGui
{
	class Widget : public StyleContext
	{
	public:
		virtual GtkWidget* GetWidget()
		{
			return widget;
		}

		virtual void Align(Alignments halign, Alignments valign)
		{
			gtk_widget_set_halign(GTK_WIDGET(widget), (GtkAlign)halign);
			gtk_widget_set_valign(GTK_WIDGET(widget), (GtkAlign)valign);
		}

		virtual void Name(const char* name)
		{
			gtk_widget_set_name(GTK_WIDGET(widget), name);
		}

		virtual const char* Name()
		{
			return gtk_widget_get_name(GTK_WIDGET(widget));
		}

		virtual void AppPaintable(bool paintable)
		{
			gtk_widget_set_app_paintable(GTK_WIDGET(widget), paintable);
		}

		virtual void Sensitive(bool sensitive)
		{
			gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive);
		}

		virtual void SizeRequest(unsigned int x, unsigned int y)
		{
			gtk_widget_set_size_request(GTK_WIDGET(widget), x, y);
		}

		virtual void Tooltip(const char* text)
		{
			gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text);
		}

		virtual const char* Tooltip()
		{
			return gtk_widget_get_tooltip_text(GTK_WIDGET(widget));
		}

		virtual void Hide()
		{
			gtk_widget_hide(GTK_WIDGET(widget));
		}

		virtual void Show()
		{
			gtk_widget_show(GTK_WIDGET(widget));
		}

		virtual void Destroy()
		{
			gtk_widget_destroy(GTK_WIDGET(widget));
		}

		virtual void ShowAll()
		{
			gtk_widget_show_all(GTK_WIDGET(widget));
		}

		virtual ~Widget()
		{  }

	protected:
		GtkWidget* widget;
	};
}
