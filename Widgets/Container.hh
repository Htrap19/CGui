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
      Container(WidgetType *w)
	  {
		  t_widget = w;
	  }

	  template <typename addtype> void Add(addtype& w)
	  {
		  gtk_container_add(GTK_CONTAINER(t_widget->GetWidget()), w.GetWidget());
		  children.Insert((void*)& w);
	  }

	  template <typename removetype> void Remove(removetype& w)
	  {
		  gtk_container_remove(GTK_CONTAINER(t_widget->GetWidget()), w.GetWidget());
		  if (children.Exists((void*)& w))
			  children.Delete((void*)& w);
	  }

	  virtual Single::List<void*> *Children()
	  {
		  return &children;
	  }

    protected:
	  Single::List<void*> children;

    private:
      WidgetType *t_widget;
  };

  template <>
  class Container<Widget>
  {
  public:
	  Container(GtkWidget *w)
	  {
		  t_widget = w;
	  }

	  template <typename addtype> void Add(addtype& w)
	  {
		  gtk_container_add(GTK_CONTAINER(t_widget), w.GetWidget());
		  children.Insert((void*)& w);
	  }

	  template <typename removetype> void Remove(removetype& w)
	  {
		  gtk_container_remove(GTK_CONTAINER(t_widget), w.GetWidget());
		  if (children.Exists((void*)& w))
			  children.Delete((void*)& w);
	  }

	  virtual Single::List<void*> *Children()
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
