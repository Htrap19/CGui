#pragma once

#include "CGuiWidget.hh"

class Entry : public widget
{
  public:
    Entry();
    Entry(const gchar *placeholdertext);
    void Align(Alignments halign, Alignments valign);
    void SizeRequest(guint x, guint y);
    GtkWidget *GetWidget();

  private:
    GtkWidget *entry;
};
