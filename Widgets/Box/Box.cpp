#include "./Box.hh"

namespace CGui
{
	Box::Box(BoxType type, int spacing) : Container(this)
	{
		widget = gtk_box_new((GtkOrientation)type, spacing); 
		this->SetContext(widget);
	}

	void Box::Add(BoxAddType type, Widget& w, bool expand, bool fill, unsigned int padding)
	{
		auto func = Converter::Convert::GetInstance().BoxFuncPtr(type);
		func(GTK_BOX(widget), w.GetWidget(), expand, fill, padding);
		children.Insert((void*)& w);
	}

	void Box::AddStart(Widget& w, bool expand, bool fill, unsigned int padding)
	{
		this->Add(BoxAddType::START, w, expand, fill, padding);
	}

	void Box::AddEnd(Widget& w, bool expand, bool fill, unsigned int padding)
	{
		this->Add(BoxAddType::END, w, expand, fill, padding);
	}

	// template<typename addtype, typename ... restaddtype> void Box::Add(BoxAddType type, addtype &w, restaddtype & ... rw, bool expand, bool fill, unsigned int padding)
	// {
	//   this->Add(type, &w, expand, fill, padding);
	//   this->Add(type, &rw..., expand, fill, padding);
	// }

	void Box::Homogeneous(bool homogeneous)
	{ gtk_box_set_homogeneous(GTK_BOX(widget), homogeneous); }

	bool Box::Homogeneous()
	{ return gtk_box_get_homogeneous(GTK_BOX(widget)); }
};
