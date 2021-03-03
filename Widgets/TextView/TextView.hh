#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Scrollable.hh"
#include "../../Converter/Convert.hh"
#include "../../Custom/List/List.hh"
#include "./TextBuffer/TextBuffer.hh"
#include "./TextMark/TextMark.hh"

namespace CGui
{
	class TextView : public virtual Widget, public virtual Container<TextView>, public virtual Scrollable
	{
	public:
		class TextChildAnchor
		{
		public:
			TextChildAnchor();
			Single::List<Widget> Widgets();
			bool Deleted();

			GtkTextChildAnchor* GetWidget() const;

		private:
			GtkTextChildAnchor* anchor;
		};

		TextView();
		TextView(GtkTextView* text_view);
		TextView(TextBuffer& buffer);
		void Buffer(TextBuffer& buffer);
		TextBuffer Buffer();
		void ScrollToMark(TextMark& mark, double within_margin, bool use_align, double xalign, double yalign);
		void ScrollMarkOnScreen(TextMark& mark);
		void MoveMarkOnScreen(TextMark& mark);
		bool PlaceCursorOnScreen();
		Rectangle VisibleRect();
		CoordinatesInfo BufferToWindowCoords(TextWindowType type, int buffer_x, int buffer_y);
		CoordinatesInfo WindowToBufferCoords(TextWindowType type, int window_x, int window_y);
		void BorderWindowSize(TextWindowType type, int size);
		int BorderWindowSize(TextWindowType type);
		void AddChildAtAnchor(Widget& child, TextChildAnchor& anchor);
		void AddChildInWindow(Widget& child, TextWindowType which_window, int xpos, int ypos);
		void MoveChild(Widget& child, int xpos, int ypos);
		void WrapMode(WrapMode mode);
		CGui::WrapMode WrapMode();
		void Editable(bool editable);
		bool Editable();
		void CursorVisible(bool visible);
		bool CursorVisble();
		void ResetCursorBlink();
		void Overwrite(bool overwrite);
		bool Overwrite();
		void PixelsAboveLine(int pixels);
		int PixelsAboveLine();
		void PixelsBelowLines(int pixels);
		int PixelsBelowLines();
		void PixelsInsideWrap(int pixels);
		int PixelsInsideWrap();
		void Justification(CGui::Justification justification);
		CGui::Justification Justification();
		void LeftMargin(int margin);
		int LeftMargin();
		void RightMargin(int margin);
		int RightMargin();
		void TopMargin(int margin);
		int TopMargin();
		void BottomMargin(int margin);
		int BottomMargin();
		void Indent(int indent);
		int Indent();
		void AcceptsTabs(bool accepts);
		bool AcceptsTabs();
		void InputPerpose(CGui::InputPurpose purpose);
		CGui::InputPurpose InputPurpose();
		void InputHints(CGui::InputHints hints);
		CGui::InputHints InputHints();
		void Monospace(bool monospace);
		bool Monospace();

		bool IsTextView();
	};
}