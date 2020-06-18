#pragma once

#include <gtk/gtk.h>
#include "./Widget.hh"
#include "../Custom/List/List.hh"

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

		~Container()
		{
			children.ForEach([](void*& data)
				{
					delete data;
				});
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
			this->Children();
			children.SelectData((void*)& w);
		}

		virtual Widget& FocusChild()
		{
			return *(Widget*)children.SelectedData();
		}

		virtual Single::List<void*>* Children()
		{
			auto g_list = gtk_container_get_children(GTK_CONTAINER(t_widget->GetWidget()));

			for (GList* li = g_list; li != NULL; li = li->next)
			{
				children.Insert(new Widget(GTK_WIDGET(li->data)));
			}

			g_list_free(g_list);

			return &children;
		}

	protected:
		Single::List<void*> children;

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

		~Container()
		{
			children.ForEach([](void*& data)
				{
					delete data;
				});
		}

		virtual void Add(Widget& w)
		{
			gtk_container_add(GTK_CONTAINER(t_widget), w.GetWidget());
		}

		virtual void Remove(Widget& w)
		{
			gtk_container_remove(GTK_CONTAINER(t_widget), w.GetWidget());
		}

		virtual void InternalWidth(unsigned int width) const
		{
			gtk_container_set_border_width(GTK_CONTAINER(t_widget), width);
		}

		virtual unsigned int InternalWidth() const
		{
			return gtk_container_get_border_width(GTK_CONTAINER(t_widget));
		}

		virtual void FocusChild(Widget& w)
		{
			gtk_container_set_focus_child(GTK_CONTAINER(t_widget), w.GetWidget());
			this->Children();
			children.SelectData((void*)& w);
		}

		virtual Widget& FocusChild()
		{
			return *(Widget*)children.SelectedData();
		}

		virtual Single::List<void*>* Children()
		{
			auto g_list = gtk_container_get_children(GTK_CONTAINER(t_widget));

			for (GList* li = g_list; li != NULL; li = li->next)
			{
				children.Insert(new Widget(GTK_WIDGET(li->data)));
			}

			g_list_free(g_list);

			return &children;
		}

	protected:
		Container()
		{  }

		GtkWidget* t_widget;

		Single::List<void*> children;
	};
};
