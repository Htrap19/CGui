#include "./AspectFrame.hh"

namespace CGui
{
	AspectFrame::AspectFrame(GtkAspectFrame* aspect_frame) : Frame::Container(this)
	{
		m_Widget = GTK_WIDGET(aspect_frame);
		this->SetContext(m_Widget);
	}

	AspectFrame::AspectFrame(const char* label, float xalign, float yalign, float ratio, bool obey_child) : Frame::Container(this)
	{
		m_Widget = gtk_aspect_frame_new(label, xalign, yalign, ratio, obey_child);
		this->SetContext(m_Widget);
	}

	void AspectFrame::Set(float xalign, float yalign, float ratio, bool obey_child)
	{
		gtk_aspect_frame_set(GTK_ASPECT_FRAME(m_Widget), xalign, yalign, ratio, obey_child);
	}

	bool AspectFrame::IsAspectFrame()
	{
		return GTK_IS_ASPECT_FRAME(m_Widget);
	}
}