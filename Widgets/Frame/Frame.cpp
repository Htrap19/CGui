#include "./Frame.hh"

namespace CGui
{
	Frame::Frame(const char* label) : Container(this)
	{
		m_Widget = gtk_frame_new(label);
		this->SetContext(m_Widget);
	}

	Frame::Frame(GtkFrame* frame) : Container(this)
	{
		this->SetFrame(frame);
	}

	void Frame::Label(const char* label)
	{
		gtk_frame_set_label(GTK_FRAME(m_Widget), label);
	}

	const char* Frame::Label()
	{
		return gtk_frame_get_label(GTK_FRAME(m_Widget));
	}

	void Frame::LabelWidget(Widget& label)
	{
		gtk_frame_set_label_widget(GTK_FRAME(m_Widget), label.GetWidget());
	}

	Widget Frame::LabelWidget()
	{
		return Widget(gtk_frame_get_label_widget(GTK_FRAME(m_Widget)));
	}

	void Frame::LabelAlign(float xalign, float yalign)
	{
		gtk_frame_set_label_align(GTK_FRAME(m_Widget), xalign, yalign);
	}

	AlignData Frame::LabelAlign()
	{
		float xalign, yalign;

		gtk_frame_get_label_align(GTK_FRAME(m_Widget), &xalign, &yalign);
		return { xalign, yalign };
	}

	void Frame::Shadow(ShadowType type)
	{
		gtk_frame_set_shadow_type(GTK_FRAME(m_Widget), (GtkShadowType)type);
	}

	ShadowType Frame::Shadow()
	{
		return (ShadowType)gtk_frame_get_shadow_type(GTK_FRAME(m_Widget));
	}

	bool Frame::IsFrame()
	{
		return GTK_IS_FRAME(m_Widget);
	}

	Frame::Frame() : Container(this)
	{

	}

	void Frame::SetFrame(GtkFrame* frame)
	{
		this->m_Widget = GTK_WIDGET(frame);
		this->SetContext(m_Widget);
	}
}