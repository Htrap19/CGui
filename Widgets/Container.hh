#pragma once

#include <gtk/gtk.h>

namespace CGui
{
  class Container
  {
    public:
      Container(GtkWidget *w)
      { t_widget = w; }

      template <typename addtype> void Add(addtype &w)
      { gtk_container_add(GTK_CONTAINER(t_widget), w.GetWidget()); }

      template <typename removetype> void Remove(removetype &w)
      { gtk_container_remove(GTK_CONTAINER(t_widget), w.GetWidget()); }

    protected:
      Container()
      {  }
      
      void SetContainer(GtkWidget *w)
      { t_widget = w; }

    private:
      GtkWidget *t_widget;
  };
};
