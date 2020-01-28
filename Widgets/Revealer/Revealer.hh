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
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *revealer;
  };

  Revealer::Revealer(Transition transition, unsigned int duration)
  {
    revealer = gtk_revealer_new();
    Converter::Convert convert;
    gtk_revealer_set_transition_type(GTK_REVEALER(revealer), std::get<GtkRevealerTransitionType>(convert.ConvertToGtkCode(transition)));
    gtk_revealer_set_transition_duration(GTK_REVEALER(revealer), duration);
  }

  void Revealer::Reveal(bool reveal)
  { gtk_revealer_set_reveal_child(GTK_REVEALER(revealer), reveal); }

  bool Revealer::Reveal()
  { return gtk_revealer_get_reveal_child(GTK_REVEALER(revealer)); }

  template <typename addtype> void Revealer::Add(addtype &w)
  { gtk_container_add(GTK_CONTAINER(revealer), w.GetWidget()); }

  template <typename removetype> void Revealer::Remove(removetype &w)
  { gtk_container_remove(GTK_CONTAINER(revealer), w.GetWidget()); }

  void Revealer::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(revealer), name); }

  const char *Revealer::Name()
  { return gtk_widget_get_name(GTK_WIDGET(revealer)); }

  void Revealer::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(revealer), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(revealer), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Revealer::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(revealer), sensitive); }

  void Revealer::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(revealer), x, y); }

  void Revealer::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(revealer))), classname); }

  void Revealer::Show()
  { gtk_widget_show(GTK_WIDGET(revealer)); }

  GtkWidget *Revealer::GetWidget()
  { return revealer; }
};
