#include "./Box.hh"

namespace CGui
{
	Box::Box(GtkBox* box) : Container(this), Orientable(this)
	{
		this->SetBox(box);
	}

	Box::Box(CGui::Orientation type, int spacing) : Container(this), Orientable(this)
	{
		widget = gtk_box_new((GtkOrientation)type, spacing);
		this->SetContext(widget);
	}

	void Box::Add(PackType type, Widget& w, bool expand, bool fill, unsigned int padding)
	{
		auto func = Converter::Convert::GetInstance().BoxFuncPtr(type);
		func(GTK_BOX(widget), w.GetWidget(), expand, fill, padding);
	}

	void Box::AddStart(Widget& w, bool expand, bool fill, unsigned int padding)
	{
		this->Add(PackType::START, w, expand, fill, padding);
	}

	void Box::AddEnd(Widget& w, bool expand, bool fill, unsigned int padding)
	{
		this->Add(PackType::END, w, expand, fill, padding);
	}

	void Box::Homogeneous(bool homogeneous)
	{
		gtk_box_set_homogeneous(GTK_BOX(widget), homogeneous);
	}

	bool Box::Homogeneous()
	{
		return gtk_box_get_homogeneous(GTK_BOX(widget));
	}

	void Box::Spacing(int spacing)
	{
		gtk_box_set_spacing(GTK_BOX(widget), spacing);
	}

	int Box::Spacing()
	{
		return gtk_box_get_spacing(GTK_BOX(widget));
	}

	void Box::ReorderChild(Widget& w, int position)
	{
		gtk_box_reorder_child(GTK_BOX(widget), w.GetWidget(), position);
	}

	void Box::ChildPacking(Widget& w, PackType type, bool expand, bool fill, unsigned int padding)
	{
		gtk_box_set_child_packing(GTK_BOX(widget), w.GetWidget(), expand, fill, padding, (GtkPackType)type);
	}

	ChildPackingInfo Box::QueryChildPacking(Widget& w)
	{
		GtkPackType type;
		gboolean expand, fill;
		unsigned int padding;

		gtk_box_query_child_packing(GTK_BOX(widget), w.GetWidget(), &expand, &fill, &padding, &type);

		return { (PackType)type, (bool)expand, (bool)fill, padding };
	}

	void Box::BaselinePosition(CGui::BaselinePosition position)
	{
		gtk_box_set_baseline_position(GTK_BOX(widget), (GtkBaselinePosition)position);
	}

	CGui::BaselinePosition Box::BaselinePosition()
	{
		return (CGui::BaselinePosition)gtk_box_get_baseline_position(GTK_BOX(widget));
	}

	void Box::CenterWidget(Widget& w)
	{
		gtk_box_set_center_widget(GTK_BOX(widget), w.GetWidget());
	}

	Widget Box::CenterWidget()
	{
		return Widget(gtk_box_get_center_widget(GTK_BOX(widget)));
	}

	bool Box::IsBox()
	{
		return GTK_IS_BOX(widget);
	}

	Box::Box() : Container(this), Orientable(this)
	{ }

	void Box::SetBox(GtkBox* box)
	{
		this->widget = GTK_WIDGET(box);
		this->SetContext(widget);
	}
};
