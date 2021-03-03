#pragma once

#include "../Converter/Convert.hh"
#include "./StyleContext.hh"
#include "../Custom/List/List.hh"

namespace CGui
{
	class Widget : public StyleContext
	{
	public:
		Widget() : widget{NULL}
		{

		}

		Widget(void* w)
		{
			if (GTK_IS_WIDGET(w))
				this->SetWidget(GTK_WIDGET(w));
		}

		Widget(GtkWidget* w)
		{
			this->SetWidget(w);
		}

		virtual void SetWidget(GtkWidget* widget) const
		{
			this->widget = widget;
			this->SetContext(widget);
		}

		virtual GtkWidget* GetWidget() const
		{
			return widget;
		}

		virtual void HAlign(Alignments align) const
		{
			gtk_widget_set_halign(GTK_WIDGET(widget), (GtkAlign)align);
		}

		virtual Alignments HAlign() const
		{
			return (Alignments)gtk_widget_get_halign(GTK_WIDGET(widget));
		}

		virtual void VAlign(Alignments align) const
		{
			gtk_widget_set_valign(GTK_WIDGET(widget), (GtkAlign)align);
		}

		virtual Alignments VAlign() const
		{
			return (Alignments)gtk_widget_get_valign(GTK_WIDGET(widget));
		}

		virtual void Align(Alignments halign, Alignments valign) const
		{
			this->HAlign(halign);
			this->VAlign(valign);
		}

		virtual AlignmentsData Align() const
		{
			return { this->HAlign(), this->VAlign() };
		}

		virtual Alignments VAlignWithBaseline() const
		{
			return (Alignments)gtk_widget_get_valign_with_baseline(GTK_WIDGET(widget));
		}

		virtual void Name(const char* name) const
		{
			gtk_widget_set_name(GTK_WIDGET(widget), name);
		}

		virtual const char* Name() const
		{
			return gtk_widget_get_name(GTK_WIDGET(widget));
		}

		virtual void AppPaintable(bool paintable) const
		{
			gtk_widget_set_app_paintable(GTK_WIDGET(widget), paintable);
		}

		virtual bool AppPaintable() const
		{
			return gtk_widget_get_app_paintable(GTK_WIDGET(widget));
		}

		virtual void Sensitive(bool sensitive) const
		{
			gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive);
		}

		virtual bool IsSensitive() const
		{
			return gtk_widget_is_sensitive(GTK_WIDGET(widget));
		}

		virtual bool Sensitive() const
		{
			return gtk_widget_get_sensitive(GTK_WIDGET(widget));
		}

		virtual void SizeRequest(unsigned int x, unsigned int y) const
		{
			gtk_widget_set_size_request(GTK_WIDGET(widget), x, y);
		}

		virtual void Tooltip(const char* text) const
		{
			gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text);
		}

		virtual const char* Tooltip() const
		{
			return gtk_widget_get_tooltip_text(GTK_WIDGET(widget));
		}

		virtual void Hide() const
		{
			gtk_widget_hide(GTK_WIDGET(widget));
		}

		virtual void Show() const
		{
			gtk_widget_show(GTK_WIDGET(widget));
		}

		virtual void ShowNow() const
		{
			gtk_widget_show_now(GTK_WIDGET(widget));
		}

		virtual void Map() const
		{
			gtk_widget_map(GTK_WIDGET(widget));
		}

		virtual void UnMap() const
		{
			gtk_widget_unmap(GTK_WIDGET(widget));
		}

		virtual void Realize() const
		{
			gtk_widget_realize(GTK_WIDGET(widget));
		}

		virtual void UnRealize() const
		{
			gtk_widget_unrealize(GTK_WIDGET(widget));
		}

		virtual int ScaleFactor() const
		{
			return gtk_widget_get_scale_factor(GTK_WIDGET(widget));
		}

		virtual bool IsFocus() const 
		{
			return gtk_widget_is_focus(GTK_WIDGET(widget));
		}

		virtual void GrabFocus() const
		{
			gtk_widget_grab_focus(GTK_WIDGET(widget));
		}

		virtual void GrabDefault() const
		{
			gtk_widget_grab_default(GTK_WIDGET(widget));
		}

		virtual void Parent(Widget& w) const
		{
			gtk_widget_set_parent(GTK_WIDGET(widget), w.GetWidget());
		}

		virtual Widget Parent() const
		{
			return Widget(gtk_widget_get_parent(GTK_WIDGET(widget)));
		}

		virtual void Unparent() const
		{
			gtk_widget_unparent(GTK_WIDGET(widget));
		}

		virtual bool IsAncestor(Widget& ancestor) const
		{
			return gtk_widget_is_ancestor(GTK_WIDGET(widget), ancestor.GetWidget());
		}

		virtual Widget Toplevel() const
		{
			return Widget(gtk_widget_get_toplevel(GTK_WIDGET(widget)));
		}

		virtual bool InDestruction() const
		{
			return gtk_widget_in_destruction(GTK_WIDGET(widget));
		}

		virtual bool Activate() const
		{
			return gtk_widget_activate(GTK_WIDGET(widget));
		}

		virtual CoordinatesInfo TranslateCoordinates(Widget& w, int src_x, int src_y) const
		{
			int dest_x, dest_y;
			gtk_widget_translate_coordinates(GTK_WIDGET(widget), w.GetWidget(), src_x, src_y, &dest_x, &dest_y);
			return { dest_x, dest_y };
		}

		virtual bool HideOnDelete() const
		{
			return gtk_widget_hide_on_delete(GTK_WIDGET(widget));
		}

		virtual void Direction(TextDirection direction) const
		{
			gtk_widget_set_direction(GTK_WIDGET(widget), (GtkTextDirection)direction);
		}

		virtual TextDirection Direction() const
		{
			return (TextDirection)gtk_widget_get_direction(GTK_WIDGET(widget));
		}

		virtual void DefaultDirection(TextDirection direction) const
		{
			gtk_widget_set_default_direction((GtkTextDirection)direction);
		}

		virtual TextDirection DefaultDirection() const
		{
			return (TextDirection)gtk_widget_get_default_direction();
		}

		virtual void RedrawOnAllocate(bool redraw) const
		{
			gtk_widget_set_redraw_on_allocate(GTK_WIDGET(widget), redraw);
		}

		virtual void ChildFocus(DirectionType type) const
		{
			gtk_widget_child_focus(GTK_WIDGET(widget), (GtkDirectionType)type);
		}

		virtual void ChildVisible(bool visible) const
		{
			gtk_widget_set_child_visible(GTK_WIDGET(widget), visible);
		}

		virtual bool ChildVisible() const
		{
			return gtk_widget_get_child_visible(GTK_WIDGET(widget));
		}

		virtual void NoShowAll(bool no_show_all) const
		{
			gtk_widget_set_no_show_all(GTK_WIDGET(widget), no_show_all);
		}

		virtual bool NoShowAll() const
		{
			return gtk_widget_get_no_show_all(GTK_WIDGET(widget));
		}

		virtual Single::List<Widget> ListMnemonicLabels() const
		{
			auto g_list = gtk_widget_list_mnemonic_labels(GTK_WIDGET(widget));
			Single::List<Widget> ret;

			for (GList* it = g_list; it != NULL; it = it->next)
			{
				ret.Insert(Widget(GTK_WIDGET(it->data)));
			}

			g_list_free(g_list);
			return ret;
		}

		virtual void AddMnemonicLabel(Widget& label) const
		{
			gtk_widget_add_mnemonic_label(GTK_WIDGET(widget), label.GetWidget());
		}

		virtual void RemoveMnemonicLabel(Widget& label) const
		{
			gtk_widget_remove_mnemonic_label(GTK_WIDGET(widget), label.GetWidget());
		}

		virtual void ErrorBell() const
		{
			gtk_widget_error_bell(GTK_WIDGET(widget));
		}

		virtual bool KeynavFailed(DirectionType type) const
		{
			return gtk_widget_keynav_failed(GTK_WIDGET(widget), (GtkDirectionType)type);
		}

		virtual void TooltipMarkup(const char* markup) const
		{
			gtk_widget_set_tooltip_markup(GTK_WIDGET(widget), markup);
		}

		virtual const char* TooltipMarkup() const
		{
			return gtk_widget_get_tooltip_markup(GTK_WIDGET(widget));
		}

		virtual void TooltipWindow(Widget& window) const
		{
			if (GTK_IS_WINDOW(window.GetWidget()))
				gtk_widget_set_tooltip_window(GTK_WIDGET(widget), GTK_WINDOW(window.GetWidget()));
		}

		virtual Widget TooltipWindow() const
		{
			return Widget(GTK_WIDGET(gtk_widget_get_tooltip_window(GTK_WIDGET(widget))));
		}

		virtual void HasTooltip(bool has_tooltip) const
		{
			gtk_widget_set_has_tooltip(GTK_WIDGET(widget), has_tooltip);
		}

		virtual bool HasTooltip() const
		{
			return gtk_widget_get_has_tooltip(GTK_WIDGET(widget));
		}

		virtual int AllocatedWidth() const
		{
			return gtk_widget_get_allocated_width(GTK_WIDGET(widget));
		}

		virtual int AllocatedHeight() const
		{
			return gtk_widget_get_allocated_height(GTK_WIDGET(widget));
		}

		virtual int AllocatedBaseline() const
		{
			return gtk_widget_get_allocated_baseline(GTK_WIDGET(widget));
		}

		virtual void CanDefault(bool can_default) const
		{
			gtk_widget_set_can_default(GTK_WIDGET(widget), can_default);
		}

		virtual bool CanDefault() const
		{
			return gtk_widget_get_can_default(GTK_WIDGET(widget));
		}

		virtual bool HasDefault() const
		{
			return gtk_widget_has_default(GTK_WIDGET(widget));
		}

		virtual void CanFocus(bool can_focus) const
		{
			gtk_widget_set_can_focus(GTK_WIDGET(widget), can_focus);
		}

		virtual bool CanFocus() const
		{
			return gtk_widget_get_can_focus(GTK_WIDGET(widget));
		}

		virtual bool HasFocus() const
		{
			return gtk_widget_has_focus(GTK_WIDGET(widget));
		}

		virtual bool HasVisibleFocus() const
		{
			return gtk_widget_has_visible_focus(GTK_WIDGET(widget));
		}

		virtual bool HasGrab() const
		{
			return gtk_widget_has_grab(GTK_WIDGET(widget));
		}

		virtual bool IsDrawable() const
		{
			return gtk_widget_is_drawable(GTK_WIDGET(widget));
		}

		virtual bool IsToplevel() const
		{
			return gtk_widget_is_toplevel(GTK_WIDGET(widget));
		}

		virtual void FocusOnClick(bool focus_on_click) const
		{
			gtk_widget_set_focus_on_click(GTK_WIDGET(widget), focus_on_click);
		}

		virtual bool FocusOnClick() const
		{
			return gtk_widget_get_focus_on_click(GTK_WIDGET(widget));
		}

		virtual void Visible(bool visible) const
		{
			gtk_widget_set_visible(GTK_WIDGET(widget), visible);
		}

		virtual bool IsVisible() const
		{
			return gtk_widget_is_visible(GTK_WIDGET(widget));
		}

		virtual bool Visible() const
		{
			return gtk_widget_get_visible(GTK_WIDGET(widget));
		}

		virtual void State(StateFlags flag, bool clear) const
		{
			gtk_widget_set_state_flags(GTK_WIDGET(widget), (GtkStateFlags)flag, clear);
		}

		virtual void UnsetState(StateFlags flag) const
		{
			gtk_widget_unset_state_flags(GTK_WIDGET(widget), (GtkStateFlags)flag);
		}

		virtual StateFlags State() const
		{
			return (StateFlags)gtk_widget_get_state_flags(GTK_WIDGET(widget));
		}

		virtual void ReceviesDefault(bool recevies_default) const
		{
			gtk_widget_set_receives_default(GTK_WIDGET(widget), recevies_default);
		}

		virtual bool ReceviesDefault() const
		{
			return gtk_widget_get_receives_default(GTK_WIDGET(widget));
		}

		virtual void SupportMultiDevice(bool support_multi_device) const
		{
			gtk_widget_set_support_multidevice(GTK_WIDGET(widget), support_multi_device);
		}

		virtual bool SupportMultiDevice() const
		{
			return gtk_widget_get_support_multidevice(GTK_WIDGET(widget));
		}

		virtual void Realized(bool realized) const
		{
			gtk_widget_set_realized(GTK_WIDGET(widget), realized);
		}

		virtual bool Realized() const
		{
			return gtk_widget_get_realized(GTK_WIDGET(widget));
		}

		virtual void Mapped(bool mapped) const
		{
			gtk_widget_set_mapped(GTK_WIDGET(widget), mapped);
		}

		virtual bool Mapped() const
		{
			return gtk_widget_get_mapped(GTK_WIDGET(widget));
		}

		virtual void Opacity(double opacity) const
		{
			gtk_widget_set_opacity(GTK_WIDGET(widget), opacity);
		}

		virtual double Opacity() const
		{
			return gtk_widget_get_opacity(GTK_WIDGET(widget));
		}

		virtual PreferredHeightData PreferredHeight() const
		{
			int min_h, nat_h;
			gtk_widget_get_preferred_height(GTK_WIDGET(widget), &min_h, &nat_h);

			return { min_h, nat_h };
		}

		virtual PreferredWidthData PreferredWidth() const
		{
			int min_w, nat_h;
			gtk_widget_get_preferred_width(GTK_WIDGET(widget), &min_w, &nat_h);

			return { min_w, nat_h };
		}

		virtual PreferredHeightData PreferredHeightForWidth(int width) const
		{
			int min_h, nat_h;
			gtk_widget_get_preferred_height_for_width(GTK_WIDGET(widget), width, &min_h, &nat_h);

			return { min_h, nat_h };
		}

		virtual PreferredWidthData PreferredWidthForHeight(int height) const
		{
			int min_w, nat_w;
			gtk_widget_get_preferred_width_for_height(GTK_WIDGET(widget), height, &min_w, &nat_w);

			return { min_w, nat_w };
		}

		virtual HeightAndBaslineData PreferredHeightAndBaselineForWidth(int width) const
		{
			int min_h, nat_h, min_b, nat_b;
			gtk_widget_get_preferred_height_and_baseline_for_width(GTK_WIDGET(widget), width, &min_h, &nat_h, &min_b, &nat_b);

			return { { min_h, nat_b }, { min_b, nat_b } };
		}

		virtual SizeRequestMode RequestMode() const
		{
			return (SizeRequestMode)gtk_widget_get_request_mode(GTK_WIDGET(widget));
		}

		virtual PreferredSizeData PreferredSize() const
		{
			GtkRequisition minimum_size, natural_size;
			gtk_widget_get_preferred_size(GTK_WIDGET(widget), &minimum_size, &natural_size);

			return { { minimum_size.width, minimum_size.height }, { natural_size.width, natural_size.height } };
		}

		virtual void MarginStart(int margin) const
		{
			gtk_widget_set_margin_start(GTK_WIDGET(widget), margin);
		}

		virtual int MarginStart() const
		{
			return gtk_widget_get_margin_start(GTK_WIDGET(widget));
		}

		virtual void MarginEnd(int margin) const
		{
			gtk_widget_set_margin_end(GTK_WIDGET(widget), margin);
		}

		virtual int MarginEnd() const
		{
			return gtk_widget_get_margin_end(GTK_WIDGET(widget));
		}

		virtual void MarginTop(int margin) const
		{
			gtk_widget_set_margin_top(GTK_WIDGET(widget), margin);
		}

		virtual int MarginTop() const
		{
			return gtk_widget_get_margin_top(GTK_WIDGET(widget));
		}

		virtual void MarginBottom(int margin) const
		{
			gtk_widget_set_margin_bottom(GTK_WIDGET(widget), margin);
		}

		virtual int MarginBottom() const
		{
			return gtk_widget_get_margin_bottom(GTK_WIDGET(widget));
		}

		virtual void Margin(CGui::Margin margin) const
		{
			this->MarginStart(margin.start);
			this->MarginEnd(margin.end);
			this->MarginTop(margin.top);
			this->MarginBottom(margin.bottom);
		}

		virtual CGui::Margin Margin() const
		{
			return { this->MarginStart(), this->MarginEnd(), this->MarginTop(), this->MarginBottom() };
		}

		virtual void HExpand(bool expand) const
		{
			gtk_widget_set_hexpand(GTK_WIDGET(widget), expand);
		}

		virtual bool HExpand() const
		{
			return gtk_widget_get_hexpand(GTK_WIDGET(widget));
		}

		virtual void HExpandSet(bool set) const
		{
			gtk_widget_set_hexpand_set(GTK_WIDGET(widget), set);
		}

		virtual bool HExpandSet() const
		{
			return gtk_widget_get_hexpand_set(GTK_WIDGET(widget));
		}

		virtual void VExpand(bool expand) const
		{
			gtk_widget_set_vexpand(GTK_WIDGET(widget), expand);
		}

		virtual bool VExpand() const
		{
			return gtk_widget_get_vexpand(GTK_WIDGET(widget));
		}

		virtual void VExpandSet(bool set) const
		{
			gtk_widget_set_vexpand_set(GTK_WIDGET(widget), set);
		}

		virtual bool VExpandSet() const
		{
			return gtk_widget_get_vexpand_set(GTK_WIDGET(widget));
		}

		virtual void Expand(bool hexpand, bool vexpand) const
		{
			this->HExpand(hexpand);
			this->VExpand(vexpand);
		}

		virtual void Expand(CGui::Expand expand) const
		{
			this->HExpand(expand.hexpand);
			this->VExpand(expand.vexpand);
		}

		virtual CGui::Expand Expand() const
		{
			return { this->HExpand(), this->VExpand() };
		}

		virtual void QueueComputeExpand() const
		{
			gtk_widget_queue_compute_expand(GTK_WIDGET(widget));
		}

		virtual bool ComputeExpand(Orientation orientation) const
		{
			return gtk_widget_compute_expand(GTK_WIDGET(widget), (GtkOrientation)orientation);
		}

		virtual void ResetStyle() const
		{
			gtk_widget_reset_style(GTK_WIDGET(widget));
		}

		virtual void Destroy() const
		{
			gtk_widget_destroy(GTK_WIDGET(widget));
		}

		virtual void ShowAll() const
		{
			gtk_widget_show_all(GTK_WIDGET(widget));
		}

		bool IsWidget() const
		{
			return GTK_IS_WIDGET(widget);
		}

		virtual ~Widget()
		{ }

	protected:
		mutable GtkWidget* widget;
	};
}