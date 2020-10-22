#pragma once

#include "../Frame/Frame.hh"

namespace CGui
{
	class AspectFrame : public Frame
	{
	public:
		AspectFrame(const char* label, float xalign, float yalign, float ratio, bool obey_child);
		void Set(float xalign, float yalign, float ratio, bool obey_child);
		bool IsAspectFrame();
	};
}