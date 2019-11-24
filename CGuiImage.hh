#pragma once

#include "CGuiWidget.hh"

class Image : public widget
{
  public:
    Image(const gchar *filename);
    Image(const gchar *filename, int width, int height, gboolean aspectRatio = true, GError **error = NULL);
    void Align(Alignments halign, Alignments valign);
    void SizeRequest(guint x, guint y);
    GtkWidget *GetWidget();

  private:
    GtkWidget *image;
};
