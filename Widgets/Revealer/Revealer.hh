#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Revealer : public widget
  {
    public:
      Revealer(Transition transition, unsigned int duration);
      void Reveal(bool reveal);
      bool Reveal();
      template <typename addtype> void Add(addtype &w);
      template <typename removetype> void Remove(removetype &w);
      void Name(const char *name);
      const char *Name();
      void Align(Alignments halign, Alignments valign);
      void Sensitive(bool sensitive);
      void SizeRequest(unsigned int x, unsigned int y);
      void StyleClass(const char *classname);
      void Tooltip(const char *text);
      const char *Tooltip();
      void Hide();
      void Show();
      GtkWidget *GetWidget();
  };

  Revealer::Revealer(Transition transition, unsigned int duration)
  {
    widget = gtk_revealer_new();
    Converter::Convert convert;
    gtk_revealer_set_transition_type(GTK_REVEALER(widget), std::get<GtkRevealerTransitionType>(convert.ConvertToGtkCode(transition)));
    gtk_revealer_set_transition_duration(GTK_REVEALER(widget), duration);
  }

  void Revealer::Reveal(bool reveal)
  { gtk_revealer_set_reveal_child(GTK_REVEALER(widget), reveal); }

  bool Revealer::Reveal()
  { return gtk_revealer_get_reveal_child(GTK_REVEALER(widget)); }

  template <typename addtype> void Revealer::Add(addtype &w)
  { gtk_container_add(GTK_CONTAINER(widget), w.GetWidget()); }

  template <typename removetype> void Revealer::Remove(removetype &w)
  { gtk_container_remove(GTK_CONTAINER(widget), w.GetWidget()); }

  void Revealer::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(widget), name); }

  const char *Revealer::Name()
  { return gtk_widget_get_name(GTK_WIDGET(widget)); }

  void Revealer::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(widget), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Revealer::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive); }

  void Revealer::SizeRequest(unsigned int x, unsigned int y)
  { gtk_widget_set_size_request(GTK_WIDGET(widget), x, y); }

  void Revealer::StyleClass(const char *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(widget))), classname); }

  void Revealer::Tooltip(const char *text)
  { gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text); }

  const char *Revealer::Tooltip()
  { return gtk_widget_get_tooltip_text(GTK_WIDGET(widget)); }

  void Revealer::Hide()
  { gtk_widget_hide(GTK_WIDGET(widget)); }

  void Revealer::Show()
  { gtk_widget_show(GTK_WIDGET(widget)); }

  GtkWidget *Revealer::GetWidget()
  { return widget; }
};
