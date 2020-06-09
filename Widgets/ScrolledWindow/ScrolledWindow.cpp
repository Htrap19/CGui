#include "./ScrolledWindow.hh"

namespace CGui
{
  ScrolledWindow::ScrolledWindow(Policy hpolicy, Policy vpolicy) : Container(this)
  {
    widget = gtk_scrolled_window_new(NULL, NULL);
    this->ScrollPolicy(hpolicy, vpolicy);
	this->SetContext(widget);
  }

  void ScrolledWindow::ScrollPolicy(Policy hpolicy, Policy vpolicy)
  { gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(widget), (GtkPolicyType)hpolicy, (GtkPolicyType)vpolicy); }
};
