#pragma once

#include "../Widget.hh"
#include "../../Converter/Convert.hh"

namespace CGui
{
	class Label : public virtual Widget
	{
	public:
		Label(GtkLabel* label);
		Label(const char* text, bool mnemonic = false);
		void Text(const char* text, bool mnemonic = false);
		const char* Text();
		void TextLabel(const char* label);
		const char* TextLabel();
		void Markup(const char* str, bool mnemonic = false);
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
		CoordinatesInfo LayoutOffsets();
		unsigned int MnemonicKeyval();
		void SelectRegion(int start_offset, int end_offset);
		void MnemonicWidget(Widget& widget);
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
