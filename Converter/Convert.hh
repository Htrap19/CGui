#pragma once

#include <iostream>
#include <gtk/gtk.h>
#include <variant>

namespace CGui
{
  enum WindowType { TOPLEVEL, POPUP };
  enum WindowPos { CEN, MOU, CENA };

  enum BoxType { VER, HOR };
  enum BoxAddType { START, END };

  enum Alignments { FILL, BEGIN, LAST, CENTER };

  enum Events { CLICKED, DELETE, TOGGLED, CHANGED };

  namespace Converter
  {
    class Convert
    {
      public:
        std::variant<GtkAlign, GtkOrientation, GtkWindowType, GtkWindowPosition, char*> ConvertToGtkCode(std::variant<Alignments, BoxType, WindowType, WindowPos, Events> data)
        {
          std::variant<GtkAlign, GtkOrientation, GtkWindowType, GtkWindowPosition, char*> retValue;
          if(data.index() == 0)
            return GetGtkCode(std::get<Alignments>(data));
          else if(data.index() == 1)
            return GetGtkCode(std::get<BoxType>(data));
          else if(data.index() == 2)
            return GetGtkCode(std::get<WindowType>(data));
          else if(data.index() == 3)
            return GetGtkCode(std::get<WindowPos>(data));
          else if(data.index() == 4)
            return GetGtkCode(std::get<Events>(data));

          return retValue;
        }

        template<typename t> void AddIntoBox(GtkWidget *&box, t &w, BoxAddType type, gboolean expand, gboolean fill, guint padding)
        {
          switch (type)
          {
            case START:
              gtk_box_pack_start(GTK_BOX(box), w.GetWidget(), expand, fill, padding);
              break;

            case END:
              gtk_box_pack_end(GTK_BOX(box), w.GetWidget(), expand, fill, padding);
              break;
          }
        }

        // template<typename data> data EventDataConverter(std::variant<gpointer, GtkWidget, widget> data)
        // {
        //   if(data.index() == 0)
        //     return std::get<gpointer>(data);
        //   else if(data.index() == 1)
        //     return std::get<GtkWidget>(data);
        //   else
        //     return std::get<widget>(data).GetWidget();
        // }

      private:
        char *GetGtkCode(Events event)
        {
          char *retValue;
          switch (event)
          {
            case CLICKED:
              return "clicked";
              break;
            case DELETE:
              return "delete-event";
              break;
            case TOGGLED:
              return "toggled";
              break;
            case CHANGED:
              return "changed";
              break;
          }

          return retValue;
        }

        GtkWindowType GetGtkCode(WindowType data)
        {
          GtkWindowType retValue;
          switch (data)
          {
            case TOPLEVEL:
              return GTK_WINDOW_TOPLEVEL;
            break;
            case POPUP:
              return GTK_WINDOW_POPUP;
            break;
          }

          return retValue;
        }

        GtkWindowPosition GetGtkCode(WindowPos data)
        {
          GtkWindowPosition retValue;
          switch (data)
          {
            case CEN:
              return GTK_WIN_POS_CENTER;
              break;
            case MOU:
              return GTK_WIN_POS_MOUSE;
              break;
            case CENA:
              return GTK_WIN_POS_CENTER_ALWAYS;
          }

          return retValue;
        }

        GtkAlign GetGtkCode(Alignments data)
        {
          GtkAlign retValue;
          switch (data)
          {
            case BEGIN:
              return GTK_ALIGN_START;
            break;
            case FILL:
              return GTK_ALIGN_FILL;
            break;
            case LAST:
              return GTK_ALIGN_END;
            break;
            case CENTER:
              return GTK_ALIGN_CENTER;
            break;
          }

          return retValue;
        }

        GtkOrientation GetGtkCode(BoxType data)
        {
          GtkOrientation retValue;
          switch (data)
          {
            case VER:
              return GTK_ORIENTATION_VERTICAL;
            break;
            case HOR:
              return GTK_ORIENTATION_HORIZONTAL;
            break;
          }

          return retValue;
        }
    };
  }
}
