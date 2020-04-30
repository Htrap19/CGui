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

  enum Events { CLICKED, DELETE, TOGGLED, CHANGED, ENTER };

  enum Transition { SLIDERIGHT, SLIDELEFT, SLIDEUP, SLIDEDOWN, CROSSFADE, NONE };
  enum MessageType { INFO, WARNING, QUESTION, ERROR, OTHER };

  enum Policy { AUTOMATIC, NEVER, ALWAYS };

  enum Action { OPEN, SAVE, SELECT_FOLDER, CREATE_FOLDER };

  namespace Converter
  {
    class Convert
    {
      public:
        std::variant<GtkAlign, GtkOrientation, GtkWindowType, GtkWindowPosition, GtkRevealerTransitionType, GtkMessageType, GtkPolicyType, GtkFileChooserAction, char*> ConvertToGtkCode(std::variant<Alignments, BoxType, WindowType, WindowPos, Transition, MessageType, Events, Policy, Action> data)
        {
          std::variant<GtkAlign, GtkOrientation, GtkWindowType, GtkWindowPosition, GtkRevealerTransitionType, GtkMessageType, GtkPolicyType, GtkFileChooserAction, char*> retValue;
          if(data.index() == 0)
            return GetGtkCode(std::get<Alignments>(data));
          else if(data.index() == 1)
            return GetGtkCode(std::get<BoxType>(data));
          else if(data.index() == 2)
            return GetGtkCode(std::get<WindowType>(data));
          else if(data.index() == 3)
            return GetGtkCode(std::get<WindowPos>(data));
          else if(data.index() == 4)
            return GetGtkCode(std::get<Transition>(data));
          else if(data.index() == 5)
            return GetGtkCode(std::get<MessageType>(data));
          else if(data.index() == 6)
            return GetGtkCode(std::get<Events>(data));
          else if(data.index() == 7)
            return GetGtkCode(std::get<Policy>(data));
          else if(data.index() == 8)
            return GetGtkCode(std::get<Action>(data));
          return retValue;
        }

        auto BoxFuncPtr(BoxAddType type)
        {
          switch (type)
          {
            case START:
              return gtk_box_pack_start;
              break;

            case END:
              return gtk_box_pack_end;
              break;

            default:
              return gtk_box_pack_start;
          }
        }

        auto HeaderbarFuncPtr(BoxAddType type)
        {
          switch (type)
          {
            case START:
              return gtk_header_bar_pack_start;
              break;
            case END:
              return gtk_header_bar_pack_end;
              break;

              default:
                return gtk_header_bar_pack_start;
          }
        }

        static Convert &GetInstance()
        {
          static Convert instance;
          return instance;
        }

        Convert(const Convert&) = delete;

      private:
        Convert()
        {  }

        GtkFileChooserAction GetGtkCode(Action action)
        {
          switch (action)
          {
            case OPEN:
              return GTK_FILE_CHOOSER_ACTION_OPEN;
              break;
            case SAVE:
              return GTK_FILE_CHOOSER_ACTION_SAVE;
              break;
            case SELECT_FOLDER:
              return GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
              break;
            case CREATE_FOLDER:
              return GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER;
              break;

            default:
              return GTK_FILE_CHOOSER_ACTION_OPEN;
          }
        }

        GtkPolicyType GetGtkCode(Policy policy)
        {
          switch (policy)
          {
            case AUTOMATIC:
              return GTK_POLICY_AUTOMATIC;
              break;
            case NEVER:
              return GTK_POLICY_NEVER;
              break;
            case ALWAYS:
              return GTK_POLICY_ALWAYS;
              break;

            default:
              return GTK_POLICY_AUTOMATIC;
          }
        }

        GtkMessageType GetGtkCode(MessageType messagetype)
        {
          switch (messagetype)
          {
            case INFO:
              return GTK_MESSAGE_INFO;
              break;
            case WARNING:
              return GTK_MESSAGE_WARNING;
              break;
            case QUESTION:
              return GTK_MESSAGE_QUESTION;
              break;
            case ERROR:
              return GTK_MESSAGE_ERROR;
              break;
            case OTHER:
              return GTK_MESSAGE_OTHER;
              break;

            default:
              return GTK_MESSAGE_OTHER;
          }
        }

        GtkRevealerTransitionType GetGtkCode(Transition transition)
        {
          switch (transition)
          {
            case SLIDEUP:
              return GTK_REVEALER_TRANSITION_TYPE_SLIDE_UP;
              break;
            case SLIDEDOWN:
              return GTK_REVEALER_TRANSITION_TYPE_SLIDE_DOWN;
              break;
            case SLIDELEFT:
              return GTK_REVEALER_TRANSITION_TYPE_SLIDE_LEFT;
              break;
            case SLIDERIGHT:
              return GTK_REVEALER_TRANSITION_TYPE_SLIDE_RIGHT;
              break;
            case CROSSFADE:
              return GTK_REVEALER_TRANSITION_TYPE_CROSSFADE;
              break;

            default:
              return GTK_REVEALER_TRANSITION_TYPE_NONE;
          }
        }

        char *GetGtkCode(Events event)
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
            case CHANGED:
              return "changed";
              break;
            case ENTER:
              return "enter";
              break;

            default:
              return "changed";
          }
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

            default:
              return GTK_WINDOW_TOPLEVEL;
          }
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

            default:
              return GTK_WIN_POS_CENTER;
          }
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

            default:
              return GTK_ALIGN_CENTER;
          }
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

            default:
              return GTK_ORIENTATION_VERTICAL;
          }
        }
    };
  }
}
