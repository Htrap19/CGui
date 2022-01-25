#pragma once

#include <gtk/gtk.h>
#include "../Custom/Vector/Vector.hh"
#include "../Custom/VectorsUtilities/VectorUtilities.hh"
#include "./Widget.hh"

namespace CGui
{
	template <typename WidgetType>
	class Container
	{
	public:
		using WidgetPtr = WidgetType*;

	public:
		Container(WidgetPtr w) : m_WidgetIns(w)
		{
		}

		virtual ~Container()
		{
		}

		virtual void Add(Widget& w)
		{
			gtk_container_add(GTK_CONTAINER(m_WidgetIns->GetWidget()), w.GetWidget());
		}

		virtual void Remove(Widget& w)
		{
			gtk_container_remove(GTK_CONTAINER(m_WidgetIns->GetWidget()), w.GetWidget());
		}

		virtual void InternalWidth(unsigned int width)
		{
			gtk_container_set_border_width(GTK_CONTAINER(m_WidgetIns->GetWidget()), width);
		}

		virtual unsigned int InternalWidth()
		{
			return gtk_container_get_border_width(GTK_CONTAINER(m_WidgetIns->GetWidget()));
		}

		virtual void FocusChild(Widget& w)
		{
			gtk_container_set_focus_child(GTK_CONTAINER(m_WidgetIns->GetWidget()), w.GetWidget());
		}

		virtual Widget FocusChild()
		{
			return Widget(gtk_container_get_focus_child(GTK_CONTAINER(m_WidgetIns->GetWidget())));
		}

		virtual Vector<Widget> Children()
		{
			auto g_list = gtk_container_get_children(GTK_CONTAINER(m_WidgetIns->GetWidget()));
			Vector<Widget> children(std::move(GListToWidgetVector(g_list)));
			g_list_free(g_list);
			return std::move(children);
		}

		virtual Widget Child()
		{
			return Widget(gtk_bin_get_child(GTK_BIN(m_WidgetIns->GetWidget())));
		}

		bool IsContainer()
		{
			return GTK_IS_CONTAINER(m_WidgetIns->GetWidget());
		}
	private:
		WidgetPtr m_WidgetIns;
	};

	template <>
	class Container<Widget>
	{
	public:
		Container(GtkWidget* w) : m_WidgetIns(w)
		{
		}

		virtual ~Container()
		{
		}

		virtual void Add(Widget& w)
		{
			gtk_container_add(GTK_CONTAINER(m_WidgetIns), w.GetWidget());
		}

		virtual void Remove(Widget& w)
		{
			gtk_container_remove(GTK_CONTAINER(m_WidgetIns), w.GetWidget());
		}

		virtual void InternalWidth(unsigned int width)
		{
			gtk_container_set_border_width(GTK_CONTAINER(m_WidgetIns), width);
		}

		virtual unsigned int InternalWidth()
		{
			return gtk_container_get_border_width(GTK_CONTAINER(m_WidgetIns));
		}

		virtual void FocusChild(Widget& w)
		{
			gtk_container_set_focus_child(GTK_CONTAINER(m_WidgetIns), w.GetWidget());
		}

		virtual Widget FocusChild()
		{
			return Widget(gtk_container_get_focus_child(GTK_CONTAINER(m_WidgetIns)));
		}

		virtual Vector<Widget> Children()
		{
			auto g_list = gtk_container_get_children(GTK_CONTAINER(m_WidgetIns));
			Vector<Widget> children(std::move(GListToWidgetVector(g_list)));
			g_list_free(g_list);
			return std::move(children);
		}

		virtual Widget Child()
		{
			return Widget(gtk_bin_get_child(GTK_BIN(m_WidgetIns)));
		}

		bool IsContainer()
		{
			return GTK_IS_CONTAINER(m_WidgetIns);
		}

	protected:
		Container() : m_WidgetIns(nullptr)
		{
		}

		GtkWidget* m_WidgetIns;
	};
};
