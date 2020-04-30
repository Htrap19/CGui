#pragma once

#include "./ScrolledWindow.hh"

namespace CGui
{
  ScrolledWindow::ScrolledWindow(Policy hpolicy, Policy vpolicy)
  {
    widget = gtk_scrolled_window_new(NULL, NULL);
    this->ScrollPolicy(hpolicy, vpolicy);
    this->SetContainer(widget);
  }

  void ScrolledWindow::ScrollPolicy(Policy hpolicy, Policy vpolicy)
  { gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(widget), std::get<GtkPolicyType>(Converter::Convert::GetInstance().ConvertToGtkCode(hpolicy)), std::get<GtkPolicyType>(Converter::Convert::GetInstance().ConvertToGtkCode(vpolicy))); }
};
