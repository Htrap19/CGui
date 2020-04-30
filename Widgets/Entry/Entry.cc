#pragma once

#include "./Entry.hh"

namespace CGui
{
  Entry::Entry() : EventHandler(this)
  { widget = gtk_entry_new(); }

  Entry::Entry(const gchar *placeholdertext) : EventHandler(this)
  {
    widget = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(widget), placeholdertext);
  }

  void Entry::Editable(bool editable)
  { gtk_editable_set_editable(GTK_EDITABLE(widget), editable); }

  bool Entry::Editable()
  { return gtk_editable_get_editable(GTK_EDITABLE(widget)); }

  void Entry::Visibility(bool visibility)
  { gtk_entry_set_visibility(GTK_ENTRY(widget), visibility); }

  bool Entry::Visibility()
  { return gtk_entry_get_visibility(GTK_ENTRY(widget)); }

  void Entry::Text(const char *text)
  { gtk_entry_set_text(GTK_ENTRY(widget), text); }

  const char *Entry::Text()
  { return gtk_entry_get_text(GTK_ENTRY(widget)); }

  long unsigned int Entry::Changed(void(*func)())
  { return this->SignalHandler(CHANGED, func); }

  long unsigned int Entry::Changed(void(*func)(Entry*))
  { return this->SignalHandler(CHANGED, func); }

  template <typename ... Args> long unsigned int Entry::Changed(void(*func)(Entry*, Args*...), Args & ... args)
  { return this->SignalHandler(CHANGED, func, args...); }

  template <typename ... Args> long unsigned int Entry::Changed(void(*func)(Args*...), Args & ... args)
  { return this->SignalHandler(CHANGED, func, args...); }
};
