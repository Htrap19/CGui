#pragma once

#include "../Converter/Convert.hh"
#include "../Custom/Vector/Vector.hh"
#include "./StyleContext.hh"

namespace CGui
{
	class Widget : public StyleContext
	{
	public:
		Widget();
		Widget(void* w);
		Widget(GtkWidget* w);
		Widget(Widget&& other);
		Widget(const Widget& other) = default;
		virtual void SetWidget(GtkWidget* widget) const;
		virtual GtkWidget* GetWidget() const;
		virtual void HAlign(Alignments align) const;
		virtual Alignments HAlign() const;
		virtual void VAlign(Alignments align) const;
		virtual Alignments VAlign() const;
		virtual void Align(Alignments halign, Alignments valign) const;
		virtual AlignmentsData Align() const;
		virtual Alignments VAlignWithBaseline() const;
		virtual void Name(const char* name) const;
		virtual const char* Name() const;
		virtual void AppPaintable(bool paintable) const;
		virtual bool AppPaintable() const;
		virtual void Sensitive(bool sensitive) const;
		virtual bool IsSensitive() const;
		virtual bool Sensitive() const;
		virtual void SizeRequest(unsigned int x, unsigned int y) const;
		virtual void Tooltip(const char* text) const;
		virtual const char* Tooltip() const;
		virtual void Hide() const;
		virtual void Show() const;
		virtual void ShowNow() const;
		virtual void Map() const;
		virtual void UnMap() const;
		virtual void Realize() const;
		virtual void UnRealize() const;
		virtual int ScaleFactor() const;
		virtual bool IsFocus() const;
		virtual void GrabFocus() const;
		virtual void GrabDefault() const;
		virtual void Parent(Widget& w) const;
		virtual Widget Parent() const;
		virtual void Unparent() const;
		virtual bool IsAncestor(Widget& ancestor) const;
		virtual Widget Toplevel() const;
		virtual bool InDestruction() const;
		virtual bool Activate() const;
		virtual CoordinatesInfo TranslateCoordinates(Widget& w, int src_x, int src_y) const;
		virtual bool HideOnDelete() const;
		virtual void Direction(TextDirection direction) const;
		virtual TextDirection Direction() const;
		virtual void DefaultDirection(TextDirection direction) const;
		virtual TextDirection DefaultDirection() const;
		virtual void RedrawOnAllocate(bool redraw) const;
		virtual void ChildFocus(DirectionType type) const;
		virtual void ChildVisible(bool visible) const;
		virtual bool ChildVisible() const;
		virtual void NoShowAll(bool no_show_all) const;
		virtual bool NoShowAll() const;
		virtual Vector<Widget> ListMnemonicLabels() const;
		virtual void AddMnemonicLabel(Widget& label) const;
		virtual void RemoveMnemonicLabel(Widget& label) const;
		virtual void ErrorBell() const;
		virtual bool KeynavFailed(DirectionType type) const;
		virtual void TooltipMarkup(const char* markup) const;
		virtual const char* TooltipMarkup() const;
		virtual void TooltipWindow(Widget& window) const;
		virtual Widget TooltipWindow() const;
		virtual void HasTooltip(bool has_tooltip) const;
		virtual bool HasTooltip() const;
		virtual int AllocatedWidth() const;
		virtual int AllocatedHeight() const;
		virtual int AllocatedBaseline() const;
		virtual void CanDefault(bool can_default) const;
		virtual bool CanDefault() const;
		virtual bool HasDefault() const;
		virtual void CanFocus(bool can_focus) const;
		virtual bool CanFocus() const;
		virtual bool HasFocus() const;
		virtual bool HasVisibleFocus() const;
		virtual bool HasGrab() const;
		virtual bool IsDrawable() const;
		virtual bool IsToplevel() const;
		virtual void FocusOnClick(bool focus_on_click) const;
		virtual bool FocusOnClick() const;
		virtual void Visible(bool visible) const;
		virtual bool IsVisible() const;
		virtual bool Visible() const;
		virtual void State(StateFlags flag, bool clear) const;
		virtual void UnsetState(StateFlags flag) const;
		virtual StateFlags State() const;
		virtual void ReceviesDefault(bool recevies_default) const;
		virtual bool ReceviesDefault() const;
		virtual void SupportMultiDevice(bool support_multi_device) const;
		virtual bool SupportMultiDevice() const;
		virtual void Realized(bool realized) const;
		virtual bool Realized() const;
		virtual void Mapped(bool mapped) const;
		virtual bool Mapped() const;
		virtual void Opacity(double opacity) const;
		virtual double Opacity() const;
		virtual PreferredHeightData PreferredHeight() const;
		virtual PreferredWidthData PreferredWidth() const;
		virtual PreferredHeightData PreferredHeightForWidth(int width) const;
		virtual PreferredWidthData PreferredWidthForHeight(int height) const;
		virtual HeightAndBaslineData PreferredHeightAndBaselineForWidth(int width) const;
		virtual SizeRequestMode RequestMode() const;
		virtual PreferredSizeData PreferredSize() const;
		virtual void MarginStart(int margin) const;
		virtual int MarginStart() const;
		virtual void MarginEnd(int margin) const;
		virtual int MarginEnd() const;
		virtual void MarginTop(int margin) const;
		virtual int MarginTop() const;
		virtual void MarginBottom(int margin) const;
		virtual int MarginBottom() const;
		virtual void Margin(CGui::Margin margin) const;
		virtual CGui::Margin Margin() const;
		virtual void HExpand(bool expand) const;
		virtual bool HExpand() const;
		virtual void HExpandSet(bool set) const;
		virtual bool HExpandSet() const;
		virtual void VExpand(bool expand) const;
		virtual bool VExpand() const;
		virtual void VExpandSet(bool set) const;
		virtual bool VExpandSet() const;
		virtual void Expand(bool hexpand, bool vexpand) const;
		virtual void Expand(CGui::Expand expand) const;
		virtual CGui::Expand Expand() const;
		virtual void QueueComputeExpand() const;
		virtual bool ComputeExpand(Orientation orientation) const;
		virtual void ResetStyle() const;
		virtual void Destroy() const;
		virtual void ShowAll() const;
		bool IsWidget() const;
		virtual ~Widget();

	protected:
		mutable GtkWidget* m_Widget;
	};
}