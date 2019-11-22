#ifndef CONVERT_HH
#define CONVERT_HH

#include <iostream>
#include <gtk/gtk.h>
#include <typeinfo>
#include <variant>

enum WindowType { TOPLEVEL, POPUP };
enum WindowPos { CEN, MOU, CENA };

enum BoxType { VER, HOR };
enum BoxAddType { START, END };

enum Alignments { FILL, BEGIN, LAST, CENTER };

enum Events { CLICKED, DELETE, TOGGLED };

namespace Converter
{
  class Convert
  {
    public:
      std::variant<GtkAlign, GtkOrientation, GtkWindowType, GtkWindowPosition, gchar*> ConvertToGtkCode(std::variant<Alignments, BoxType, WindowType, WindowPos, Events> data)
      {
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
      }

    private:
      gchar *GetGtkCode(Events event)
      {
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
        }

        return "clicked";
      }

      GtkWindowType GetGtkCode(WindowType data)
      {
        switch (data)
        {
          case TOPLEVEL:
            return GTK_WINDOW_TOPLEVEL;
          break;
          case POPUP:
            return GTK_WINDOW_POPUP;
          break;
        }

        return GTK_WINDOW_TOPLEVEL;
      }

      GtkWindowPosition GetGtkCode(WindowPos data)
      {
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

        return GTK_WIN_POS_CENTER;
      }

      GtkAlign GetGtkCode(Alignments data)
      {
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

        return GTK_ALIGN_START;
      }

      GtkOrientation GetGtkCode(BoxType data)
      {
        switch (data)
        {
          case VER:
            return GTK_ORIENTATION_VERTICAL;
          break;
          case HOR:
            return GTK_ORIENTATION_HORIZONTAL;
          break;
        }

        return GTK_ORIENTATION_VERTICAL;
      }
  };
}

#endif
