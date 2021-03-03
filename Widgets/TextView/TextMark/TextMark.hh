#pragma once

#include <gtk/gtk.h>

#include "../../Menifest.hh"

namespace CGui
{
	class TextMark
	{
	public:
		TextMark(const char* name, bool left_gravity);
		TextMark(GtkTextMark* mark);
		void Visible(bool visible);
		bool Visible();
		bool Deleted();
		const char* Name();
		TextBuffer Buffer();
		bool LeftGravity();

		GtkTextMark* GetWidget() const;

		bool IsTextMark();

	private:
		GtkTextMark* mark;
	};
}