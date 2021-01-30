#include "./AspectFrame.hh"

namespace CGui
{
	AspectFrame::AspectFrame(GtkAspectFrame* aspect_frame) : Frame::Container(this)
	{
		widget = GTK_WIDGET(aspect_frame);
		this->SetContext(widget);
	}

	AspectFrame::AspectFrame(const char* label, float xalign, float yalign, float ratio, bool obey_child) : Frame::Container(this)
	{
		widget = gtk_aspect_frame_new(label, xalign, yalign, ratio, obey_child);
		this->SetContext(widget);
	}

	void AspectFrame::Set(float xalign, float yalign, float ratio, bool obey_child)
	{
		gtk_aspect_frame_set(GTK_ASPECT_FRAME(widget), xalign, yalign, ratio, obey_child);
	}

	bool AspectFrame::IsAspectFrame()
	{
		return GTK_IS_ASPECT_FRAME(widget);
	}
}