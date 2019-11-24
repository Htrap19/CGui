#pragma once

#include "Convert.hh"

class widget
{
  public:
    virtual GtkWidget *GetWidget() = 0;
    virtual void Align(Alignments halign, Alignments valign) = 0;
    virtual void SizeRequest(guint x, guint y) = 0;
};
