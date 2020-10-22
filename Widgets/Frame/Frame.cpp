#include "./Frame.hh"

namespace CGui
{
	Frame::Frame(const char* label) : Container(this)
	{
		widget = gtk_frame_new(label);
		this->SetContext(widget);
	}

	void Frame::Label(const char* label)
	{
		gtk_frame_set_label(GTK_FRAME(widget), label);
	}

	const char* Frame::Label()
	{
		return gtk_frame_get_label(GTK_FRAME(widget));
	}

	void Frame::LabelWidget(Widget& label)
	{
		gtk_frame_set_label_widget(GTK_FRAME(widget), label.GetWidget());
	}

	Widget Frame::LabelWidget()
	{
		return Widget(gtk_frame_get_label_widget(GTK_FRAME(widget)));
	}

	void Frame::LabelAlign(float xalign, float yalign)
	{
		gtk_frame_set_label_align(GTK_FRAME(widget), xalign, yalign);
	}

	LabelAlignData Frame::LabelAlign()
	{
		float xalign, yalign;

		gtk_frame_get_label_align(GTK_FRAME(widget), &xalign, &yalign);
		return { xalign, yalign };
	}

	void Frame::Shadow(ShadowType type)
	{
		gtk_frame_set_shadow_type(GTK_FRAME(widget), (GtkShadowType)type);
	}

	ShadowType Frame::Shadow()
	{
		return (ShadowType)gtk_frame_get_shadow_type(GTK_FRAME(widget));
	}

	bool Frame::IsFrame()
	{
		return GTK_IS_FRAME(widget);
	}

	Frame::Frame() : Container(this)
	{

	}

	void Frame::SetFrame(GtkFrame* frame)
	{
		this->widget = GTK_WIDGET(frame);
		this->SetContext(widget);
	}
}