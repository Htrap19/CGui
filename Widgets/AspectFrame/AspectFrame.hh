#pragma once

#include "../Frame/Frame.hh"

namespace CGui
{
	class AspectFrame : public virtual Frame
	{
	public:
		AspectFrame(GtkAspectFrame* aspect_frame);
		AspectFrame(const char* label, float xalign, float yalign, float ratio, bool obey_child);
		void Set(float xalign, float yalign, float ratio, bool obey_child);
		bool IsAspectFrame();
	};
}