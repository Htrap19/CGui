#ifndef CGUI_HH
#define CGUI_HH

#include <gtk/gtk.h>
#include <any>
#include "Convert.hh"

using namespace Converter;

class widget
{
  public:
    virtual GtkWidget *GetWidget() = 0;
    virtual void Align(Alignments halign, Alignments valign) = 0;
    virtual void SizeRequest(guint x, guint y) = 0;
};

class Button : public widget
{
  public:
    Button()
    { button = gtk_button_new(); }

    Button(const gchar *text)
    { button = gtk_button_new_with_label(text); }

    GtkWidget *GetWidget()
    { return button; }

    void Align(Alignments halign, Alignments valign)
    {
      Convert convert;
      gtk_widget_set_halign(GTK_WIDGET(button), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
      gtk_widget_set_valign(GTK_WIDGET(button), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
    }

    void SignalHandler(Events event, GCallback callbackFunction, gpointer data = NULL)
    {
      Convert convert;
      g_signal_connect(G_OBJECT(button), std::get<gchar *>(convert.ConvertToGtkCode(event)), callbackFunction, data);
    }

    void SizeRequest(guint x, guint y)
    { gtk_widget_set_size_request(GTK_WIDGET(button), x, y); }

  private:
    GtkWidget *button;
};

class Image : public widget
{
  public:
    Image(const gchar *filename)
    { image = gtk_image_new_from_file(filename); }

    Image(const gchar *filename, int width, int height, gboolean aspectRatio = true, GError **error = NULL)
    {
      GdkPixbuf *pixbuf = gdk_pixbuf_new_from_file_at_scale(filename, width, height, aspectRatio, error);
      image = gtk_image_new_from_pixbuf(pixbuf);
    }

    void Align(Alignments halign, Alignments valign)
    {
      Convert convert;
      gtk_widget_set_halign(GTK_WIDGET(image), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
      gtk_widget_set_valign(GTK_WIDGET(image), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
    }

    void SizeRequest(guint x, guint y)
    { gtk_widget_set_size_request(GTK_WIDGET(image), x, y); }

    GtkWidget *GetWidget()
    { return image; }

  private:
    GtkWidget *image;
};

class Label : public widget
{
  public:
    Label(const gchar *text)
    {
      label = gtk_label_new(text);
    }

    void Align(Alignments halign, Alignments valign)
    {
      Convert convert;
      gtk_widget_set_halign(GTK_WIDGET(label), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
      gtk_widget_set_valign(GTK_WIDGET(label), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
    }

    void SizeRequest(guint x, guint y)
    { gtk_widget_set_size_request(GTK_WIDGET(label), x, y); }

    GtkWidget *GetWidget()
    { return label; }

  private:
    GtkWidget *label;
};

class Entry : public widget
{
  public:
    Entry(const gchar *placeholdertext)
    {
      entry = gtk_entry_new();
      gtk_entry_set_placeholder_text(GTK_ENTRY(entry), placeholdertext);
    }

    void Align(Alignments halign, Alignments valign)
    {
      Convert convert;
      gtk_widget_set_halign(GTK_WIDGET(entry), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
      gtk_widget_set_halign(GTK_WIDGET(entry), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
    }

    void SizeRequest(guint x, guint y)
    { gtk_widget_set_size_request(GTK_WIDGET(entry), x, y); }

    GtkWidget *GetWidget()
    { return entry; }

  private:
    GtkWidget *entry;
};

class Box : public widget
{
  public:
    Box(BoxType type, gint spacing)
    {
      Convert convert;
      box = gtk_box_new(std::get<GtkOrientation>(convert.ConvertToGtkCode(type)), spacing);
    }

    template<typename widget> void Add(BoxAddType type, widget &w, gboolean expand = false, gboolean fill = false, guint padding = 0)
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

    void Align(Alignments halign, Alignments valign)
    {
      Convert convert;
      gtk_widget_set_halign(GTK_WIDGET(box), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
      gtk_widget_set_halign(GTK_WIDGET(box), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
    }

    void SizeRequest(guint x, guint y)
    { gtk_widget_set_size_request(GTK_WIDGET(box), x, y); }

    GtkWidget *GetWidget()
    { return box; }

  private:
    GtkWidget *box;
};

class Window : public widget
{
  public:
    Window(WindowType type, const gchar *title, WindowPos pos)
    {
      Convert convert;
      window = gtk_window_new(std::get<GtkWindowType>(convert.ConvertToGtkCode(type)));
      g_signal_connect(G_OBJECT(window), "delete-event", G_CALLBACK(gtk_main_quit), NULL);
      gtk_window_set_title(GTK_WINDOW(window), title);

      gtk_window_set_position(GTK_WINDOW(window), std::get<GtkWindowPosition>(convert.ConvertToGtkCode(pos)));
    }

    template <typename widget>void Add(widget &w)
    { gtk_container_add(GTK_CONTAINER(window), w.GetWidget()); }

    void InternalWidth(guint width)
    { gtk_container_set_border_width(GTK_CONTAINER(window), width); }

    void DefaultSize(guint xsize, guint ysize)
    { gtk_window_set_default_size(GTK_WINDOW(window), xsize, ysize); }

    void ShowAll()
    { gtk_widget_show_all(window); }

    void Align(Alignments halign, Alignments valign)
    {
      Convert convert;
      gtk_widget_set_halign(GTK_WIDGET(window), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
      gtk_widget_set_halign(GTK_WIDGET(window), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
    }

    void SizeRequest(guint x, guint y)
    { gtk_widget_set_size_request(GTK_WIDGET(window), x, y); }

    GtkWidget *GetWidget()
    { return window; }

  private:
    GtkWidget *window;
};

#endif
