#pragma once

#include "CGuiWidget.hh"

class Label : public widget
{
  public:
    Label(const gchar *text);
    void Align(Alignments halign, Alignments valign);
    void SizeRequest(guint x, guint y);
    GtkWidget *GetWidget();

  private:
    GtkWidget *label;
};
