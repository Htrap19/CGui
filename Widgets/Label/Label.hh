#pragma once

#include "../Widget.hh"

namespace CGui
{
	class Label : public virtual Widget
	{
	public:
		Label(GtkLabel* label);
		Label(const char* text);
		void Text(const char* text);
		const char* Text();
		void Markup(const char* str);
		void Pattern(const char* pattern);
		void Justify(Justification justify);
		Justification Justify();
		void XAlign(float x_align);
		float XAlign();
		void YAlign(float y_align);
		float YAlign();
		void Ellipsize(EllipsizeMode mode);
		EllipsizeMode Ellipsize();
		void WidthChars(int n_chars);
		int WidthChars();
		void MaxWidthChars(int n_chars);
		int MaxWidthChars();
		void LineWrap(bool wrap);
		bool LineWrap();
		void LineWrapMode(WrapMode mode);
		WrapMode LineWrapMode();
		void Lines(int lines);
		int Lines();
		std::pair<int, int> LayoutOffsets();
		void SelectRegion(int start_offset, int end_offset);
		void Selectable(bool selectable);
		bool Selectable();
		void UseMarkup(bool use_markup);
		bool UseMarkup();
		void UseUnderline(bool use_underline);
		bool UseUnderline();
		void SingleLineMode(bool mode);
		bool SingleLineMode();
		void Angle(double angle);
		double Angle();
		const char* CurrentUri();
		void TrackVisitedLinks(bool track_links);
		bool TrackVisitedLinks();
		bool IsLabel();
	};
};
