#include "./Box.hh"

namespace CGui
{
  Box::Box(BoxType type, int spacing) : Container(this)
  {
	  widget = gtk_box_new(std::get<GtkOrientation>(Converter::Convert::GetInstance().ConvertToGtkCode(type)), spacing); 
	  this->SetContext(widget);
  }

  /*template<typename addtype> void Box::Add(BoxAddType type, addtype &w, bool expand, bool fill, unsigned int padding)
  {
    auto func = Converter::Convert::GetInstance().BoxFuncPtr(type);
    func(GTK_BOX(widget), w.GetWidget(), expand, fill, padding);
  }

  template <typename addtype> void Box::AddStart(addtype &w, bool expand, bool fill, unsigned int padding)
  { this->Add(START, w, expand, fill, padding); }

  template <typename addtype> void Box::AddEnd(addtype &w, bool expand, bool fill, unsigned int padding)
  { this->Add(END, w, expand, fill, padding); }

  // template<typename addtype, typename ... restaddtype> void Box::Add(BoxAddType type, addtype &w, restaddtype & ... rw, bool expand, bool fill, unsigned int padding)
  // {
  //   this->Add(type, &w, expand, fill, padding);
  //   this->Add(type, &rw..., expand, fill, padding);
  // }

  template <typename removetype> void Box::Remove(removetype &w)
  { gtk_container_remove(GTK_CONTAINER(widget), w.GetWidget()); }*/

  void Box::Homogeneous(bool homogeneous)
  { gtk_box_set_homogeneous(GTK_BOX(widget), homogeneous); }

  bool Box::Homogeneous()
  { return gtk_box_get_homogeneous(GTK_BOX(widget)); }
};
