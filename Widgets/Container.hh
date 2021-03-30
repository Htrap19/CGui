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
		Container(WidgetType* w)
		{
			t_widget = w;
		}

		virtual ~Container()
		{
		}

		virtual void Add(Widget& w)
		{
			gtk_container_add(GTK_CONTAINER(t_widget->GetWidget()), w.GetWidget());
		}

		virtual void Remove(Widget& w)
		{
			gtk_container_remove(GTK_CONTAINER(t_widget->GetWidget()), w.GetWidget());
		}

		virtual void InternalWidth(unsigned int width)
		{
			gtk_container_set_border_width(GTK_CONTAINER(t_widget->GetWidget()), width);
		}

		virtual unsigned int InternalWidth()
		{
			return gtk_container_get_border_width(GTK_CONTAINER(t_widget->GetWidget()));
		}

		virtual void FocusChild(Widget& w)
		{
			gtk_container_set_focus_child(GTK_CONTAINER(t_widget->GetWidget()), w.GetWidget());
		}

		virtual Widget FocusChild()
		{
			return Widget(gtk_container_get_focus_child(GTK_CONTAINER(t_widget->GetWidget())));
		}

		virtual Vector<Widget> Children()
		{
			auto g_list = gtk_container_get_children(GTK_CONTAINER(t_widget->GetWidget()));
			Vector<Widget> children(std::move(GListToWidgetVector(g_list)));
			g_list_free(g_list);
			return std::move(children);
		}

		bool IsContainer()
		{
			return GTK_IS_CONTAINER(t_widget->GetWidget());
		}

	private:
		WidgetType* t_widget;
	};

	template <>
	class Container<Widget>
	{
	public:
		Container(GtkWidget* w)
		{
			t_widget = w;
		}

		virtual ~Container()
		{
			//if (children.Size() >= 1)
			//{
			//	children.ForEach([](void* data)
			//		{
			//			//DeleteOnQuit::GetInstance().Add(data);
			//			delete data;
			//		});
			//	children.DeleteAll();
			//}
		}

		virtual void Add(Widget& w)
		{
			gtk_container_add(GTK_CONTAINER(t_widget), w.GetWidget());
		}

		virtual void Remove(Widget& w)
		{
			gtk_container_remove(GTK_CONTAINER(t_widget), w.GetWidget());
		}

		virtual void InternalWidth(unsigned int width)
		{
			gtk_container_set_border_width(GTK_CONTAINER(t_widget), width);
		}

		virtual unsigned int InternalWidth()
		{
			return gtk_container_get_border_width(GTK_CONTAINER(t_widget));
		}

		virtual void FocusChild(Widget& w)
		{
			gtk_container_set_focus_child(GTK_CONTAINER(t_widget), w.GetWidget());
		}

		virtual Widget FocusChild()
		{
			return Widget(gtk_container_get_focus_child(GTK_CONTAINER(t_widget)));
		}

		virtual Vector<Widget> Children()
		{
			auto g_list = gtk_container_get_children(GTK_CONTAINER(t_widget));

			//if (children.Size() >= 1)
			//{
			//	children.ForEach([](void* data) -> void
			//		{
			//			delete data;
			//		});

			//	children.DeleteAll();
			//}
			Vector<Widget> children(std::move(GListToWidgetVector(g_list)));
			g_list_free(g_list);
			return std::move(children);
		}

		bool IsContainer()
		{
			return GTK_IS_CONTAINER(t_widget);
		}

	protected:
		Container() : t_widget{ nullptr }
		{
		}

		GtkWidget* t_widget;
	};
};
