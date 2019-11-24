#pragma once

#include <gtk/gtk.h>
#include "CGuiButton.hh"
#include "CGuiImage.hh"
#include "CGuiLabel.hh"
#include "CGuiEntry.hh"
#include "CGuiBox.hh"
#include "CGuiWindow.hh"

// class Box : public widget
// {
//   public:
//     Box(BoxType type, gint spacing)
//     {
//       Convert convert;
//       box = gtk_box_new(std::get<GtkOrientation>(convert.ConvertToGtkCode(type)), spacing);
//     }
//
//     template<typename widget> void Add(BoxAddType type, widget &w, gboolean expand = false, gboolean fill = false, guint padding = 0)
//     {
//       switch (type)
//       {
//         case START:
//           gtk_box_pack_start(GTK_BOX(box), w.GetWidget(), expand, fill, padding);
//           break;
//
//         case END:
//           gtk_box_pack_end(GTK_BOX(box), w.GetWidget(), expand, fill, padding);
//           break;
//       }
//     }
//
//     void Align(Alignments halign, Alignments valign)
//     {
//       Convert convert;
//       gtk_widget_set_halign(GTK_WIDGET(box), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
//       gtk_widget_set_valign(GTK_WIDGET(box), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
//     }
//
//     void SizeRequest(guint x, guint y)
//     { gtk_widget_set_size_request(GTK_WIDGET(box), x, y); }
//
//     GtkWidget *GetWidget()
//     { return box; }
//
//   private:
//     GtkWidget *box;
// };

// class Window : public widget
// {
//   public:
//     Window(WindowType type, const gchar *title, WindowPos pos)
//     {
//       Convert convert;
//       window = gtk_window_new(std::get<GtkWindowType>(convert.ConvertToGtkCode(type)));
//       g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
//       gtk_window_set_title(GTK_WINDOW(window), title);
//
//       gtk_window_set_position(GTK_WINDOW(window), std::get<GtkWindowPosition>(convert.ConvertToGtkCode(pos)));
//     }
//
//     void Icon(const gchar *iconpath)
//     {
//       GError *error = NULL;
//       GdkPixbuf *icon = gdk_pixbuf_new_from_file(iconpath, &error);
//       if(!icon)
//       {
//         fprintf(stderr, "%s\n", error->message);
//         g_error_free(error);
//       }
//       gtk_window_set_icon(GTK_WINDOW(window), icon);
//     }
//
//     template <typename widget>void Add(widget &w)
//     { gtk_container_add(GTK_CONTAINER(window), w.GetWidget()); }
//
//     void InternalWidth(guint width)
//     { gtk_container_set_border_width(GTK_CONTAINER(window), width); }
//
//     void DefaultSize(guint xsize, guint ysize)
//     { gtk_window_set_default_size(GTK_WINDOW(window), xsize, ysize); }
//
//     void ShowAll()
//     { gtk_widget_show_all(window); }
//
//     void Align(Alignments halign, Alignments valign)
//     {
//       Convert convert;
//       gtk_widget_set_halign(GTK_WIDGET(window), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
//       gtk_widget_set_halign(GTK_WIDGET(window), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
//     }
//
//     void SizeRequest(guint x, guint y)
//     { gtk_widget_set_size_request(GTK_WIDGET(window), x, y); }
//
//     GtkWidget *GetWidget()
//     { return window; }
//
//   private:
//     GtkWidget *window;
// };
