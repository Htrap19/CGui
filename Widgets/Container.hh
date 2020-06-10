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

		virtual void Add(Widget& w)
		{
			gtk_container_add(GTK_CONTAINER(t_widget->GetWidget()), w.GetWidget());
			children.Insert((void*)& w);
		}

		virtual void Remove(Widget& w)
		{
			gtk_container_remove(GTK_CONTAINER(t_widget->GetWidget()), w.GetWidget());
			if (children.Exists((void*)& w))
				children.Delete((void*)& w);
		}

		virtual void InternalWidth(unsigned int width) const
		{
			gtk_container_set_border_width(GTK_CONTAINER(t_widget->GetWidget()), width);
		}

		virtual unsigned int InternalWidth() const
		{
			return gtk_container_get_border_width(GTK_CONTAINER(t_widget->GetWidget()));
		}

		virtual void FocusChild(Widget& w)
		{
			gtk_container_set_focus_child(GTK_CONTAINER(t_widget->GetWidget()), w.GetWidget());
			children.SelectData((void*)& w);
		}

		virtual Widget& FocusChild()
		{
			return *(Widget*)children.SelectedData();
		}

		virtual Single::List<void*>* Children()
		{
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

		virtual void Add(Widget& w)
		{
			gtk_container_add(GTK_CONTAINER(t_widget), w.GetWidget());
			children.Insert((void*)& w);
		}

		virtual void Remove(Widget& w)
		{
			gtk_container_remove(GTK_CONTAINER(t_widget), w.GetWidget());
			if (children.Exists((void*)& w))
				children.Delete((void*)& w);
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
			children.SelectData((void*)& w);
		}

		virtual Widget& FocusChild()
		{
			return *(Widget*)children.SelectedData();
		}

		virtual Single::List<void*>* Children()
		{
			return &children;
		}

	protected:
		Container()
		{  }

		GtkWidget* t_widget;

		Single::List<void*> children;
	};
};
