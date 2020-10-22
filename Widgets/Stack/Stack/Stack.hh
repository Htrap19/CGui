#pragma once

#include "../../Widget.hh"
#include "../../Container.hh"

namespace CGui
{
	class Stack : public Widget, public Container<Stack>
	{
	public:
		Stack();
		Stack(GtkStack* stack);
		void AddNamed(Widget& child, const char* name);
		void AddTitled(Widget& child, const char* name, const char* title);
		Widget ChildByName(const char* name);
		void VisibleChild(Widget& child);
		Widget VisibleChild();
		void VisibleChildName(const char* name);
		const char* VisibleChildName();
		void VisibleChildFull(const char* name, StackTransitionType transition);
		void Homogeneous(bool homogeneous);
		bool Homogeneous();
		void HHomogeneous(bool hhomogeneous);
		bool HHomogeneous();
		void VHomogeneous(bool vhomogeneous);
		bool VHomogeneous();
		void TransitionDuration(unsigned int duration);
		unsigned int TransitionDuration();
		void TransitionType(StackTransitionType type);
		StackTransitionType TransitionType();
		bool TransitionRunning();
		void InterpolateSize(bool interpolate);
		bool InterpolateSize();
		bool IsStack();
	};
}