#pragma once

#include "../Widget.hh"

namespace CGui
{
  class Box : public widget
  {
    public:
      Box(BoxType type, int spacing);
      void Name(const char *name);
      const char *Name();
      template<typename addtype> void Add(BoxAddType type, addtype &w, bool expand = false, bool fill = false, unsigned int padding = 0);
      template<typename removetype> void Remove(removetype &w);
      // template<typename addtype, typename ... restaddtype> void Add(BoxAddType, addtype &w, restaddtype & ... rw, bool expand = false, bool fill = false, unsigned int padding = 0);
      void Homogeneous(bool homogeneous);
      bool Homogeneous();
      void Sensitive(bool sensitive);
      void Align(Alignments halign, Alignments valign);
      void SizeRequest(guint x, guint y);
      void StyleClass(const gchar *classname);
      void Show();
      GtkWidget *GetWidget();

    private:
      GtkWidget *box;
  };

  Box::Box(BoxType type, int spacing)
  {
    Converter::Convert convert;
    box = gtk_box_new(std::get<GtkOrientation>(convert.ConvertToGtkCode(type)), spacing);
  }

  void Box::Name(const char *name)
  { gtk_widget_set_name(GTK_WIDGET(box), name); }

  const char *Box::Name()
  { return gtk_widget_get_name(GTK_WIDGET(box)); }

  template<typename addtype> void Box::Add(BoxAddType type, addtype &w, bool expand, bool fill, unsigned int padding)
  {
    Converter::Convert convert;
    convert.AddIntoBox(box, w, type, expand, fill, padding);
  }

  // template<typename addtype, typename ... restaddtype> void Box::Add(BoxAddType type, addtype &w, restaddtype & ... rw, bool expand, bool fill, unsigned int padding)
  // {
  //   this->Add(type, &w, expand, fill, padding);
  //   this->Add(type, &rw..., expand, fill, padding);
  // }

  template <typename removetype> void Box::Remove(removetype &w)
  { gtk_container_remove(GTK_CONTAINER(box), w.GetWidget()); }

  void Box::Homogeneous(bool homogeneous)
  { gtk_box_set_homogeneous(GTK_BOX(box), homogeneous); }

  bool Box::Homogeneous()
  { return gtk_box_get_homogeneous(GTK_BOX(box)); }

  void Box::Sensitive(bool sensitive)
  { gtk_widget_set_sensitive(GTK_WIDGET(box), sensitive); }

  void Box::Align(Alignments halign, Alignments valign)
  {
    Converter::Convert convert;
    gtk_widget_set_halign(GTK_WIDGET(box), std::get<GtkAlign>(convert.ConvertToGtkCode(halign)));
    gtk_widget_set_valign(GTK_WIDGET(box), std::get<GtkAlign>(convert.ConvertToGtkCode(valign)));
  }

  void Box::SizeRequest(guint x, guint y)
  { gtk_widget_set_size_request(GTK_WIDGET(box), x, y); }

  void Box::StyleClass(const gchar *classname)
  { gtk_style_context_add_class(GTK_STYLE_CONTEXT(gtk_widget_get_style_context(GTK_WIDGET(box))), classname); }

  void Box::Show()
  { gtk_widget_show(GTK_WIDGET(box)); }

  GtkWidget *Box::GetWidget()
  { return box; }
}
