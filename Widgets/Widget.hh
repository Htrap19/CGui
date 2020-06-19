#pragma once

#include "../Converter/Convert.hh"
#include "./StyleContext.hh"

namespace CGui
{
	class Widget : public StyleContext
	{
	public:
		Widget()
		{

		}

		Widget(GtkWidget *w)
		{
			this->SetWidget(w);
		}

		virtual void SetWidget(GtkWidget* widget)
		{
			this->widget = widget;
		}

		virtual GtkWidget* GetWidget()
		{
			return widget;
		}

		virtual void Align(Alignments halign, Alignments valign)
		{
			gtk_widget_set_halign(GTK_WIDGET(widget), (GtkAlign)halign);
			gtk_widget_set_valign(GTK_WIDGET(widget), (GtkAlign)valign);
		}

		virtual AlignmentsInfo Align()
		{
			return { (Alignments)gtk_widget_get_halign(GTK_WIDGET(widget)), (Alignments)gtk_widget_get_valign(GTK_WIDGET(widget)) };
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

		virtual bool AppPaintable()
		{
			return gtk_widget_get_app_paintable(GTK_WIDGET(widget));
		}

		virtual void Sensitive(bool sensitive)
		{
			gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive);
		}

		virtual bool Sensitive()
		{
			return gtk_widget_get_sensitive(GTK_WIDGET(widget));
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

		virtual void ShowNow()
		{
			gtk_widget_show_now(GTK_WIDGET(widget));
		}

		virtual void Map()
		{
			gtk_widget_map(GTK_WIDGET(widget));
		}

		virtual void UnMap()
		{
			gtk_widget_unmap(GTK_WIDGET(widget));
		}

		virtual void Realize()
		{
			gtk_widget_realize(GTK_WIDGET(widget));
		}

		virtual void UnRealize()
		{
			gtk_widget_unrealize(GTK_WIDGET(widget));
		}

		virtual int ScaleFactor()
		{
			return gtk_widget_get_scale_factor(GTK_WIDGET(widget));
		}

		virtual void IsFocus()
		{
			gtk_widget_is_focus(GTK_WIDGET(widget));
		}

		virtual void GrabFocus()
		{
			gtk_widget_grab_focus(GTK_WIDGET(widget));
		}

		virtual void GrabDefault()
		{
			gtk_widget_grab_default(GTK_WIDGET(widget));
		}

		virtual void Parent(Widget& w)
		{
			gtk_widget_set_parent(GTK_WIDGET(widget), w.GetWidget());
		}

		virtual Widget& Parent()
		{
			m_parent = &Widget(gtk_widget_get_parent(GTK_WIDGET(widget)));
			return *m_parent;
		}

		virtual bool IsAncestor(Widget& ancestor)
		{
			return gtk_widget_is_ancestor(GTK_WIDGET(widget), ancestor.GetWidget());
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
		Widget* m_parent;
	};
}
