#pragma once

#include "./Revealer.hh"

namespace CGui
{
  Revealer::Revealer(Transition transition, unsigned int duration)
  {
    widget = gtk_revealer_new();
    gtk_revealer_set_transition_type(GTK_REVEALER(widget), std::get<GtkRevealerTransitionType>(Converter::Convert::GetInstance().ConvertToGtkCode(transition)));
    gtk_revealer_set_transition_duration(GTK_REVEALER(widget), duration);
    this->SetContainer(widget);
  }

  void Revealer::Reveal(bool reveal)
  { gtk_revealer_set_reveal_child(GTK_REVEALER(widget), reveal); }

  bool Revealer::Reveal()
  { return gtk_revealer_get_reveal_child(GTK_REVEALER(widget)); }
};
