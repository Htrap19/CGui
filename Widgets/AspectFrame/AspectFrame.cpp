#include "./AspectFrame.hh"

namespace CGui
{
	AspectFrame::AspectFrame(const char* label, float xalign, float yalign, float ratio, bool obey_child)
	{
		widget = gtk_aspect_frame_new(label, xalign, yalign, ratio, obey_child);
		this->SetFrame(GTK_FRAME(widget));
	}

	void AspectFrame::Set(float xalign, float yalign, float ratio, bool obey_child)
	{
		gtk_aspect_frame_set(GTK_ASPECT_FRAME(widget), xalign, yalign, ratio, obey_child);
	}
}