#include "./Widget.hh"
#include "../Custom/VectorsUtilities/VectorUtilities.hh"

namespace CGui
{
	Widget::Widget(Widget&& other)
	{
		m_Widget = other.m_Widget;
		other.m_Widget = nullptr;
	}

	Widget::Widget(GtkWidget* w)
	{
		this->SetWidget(w);
	}

	Widget::Widget(void* w)
	{
		if (GTK_IS_WIDGET(w))
			this->SetWidget(GTK_WIDGET(w));
	}

	Widget::Widget() : m_Widget(nullptr)
	{
	}

	void Widget::SetWidget(GtkWidget* widget) const
	{
		this->m_Widget = widget;
		this->SetContext(widget);
	}

	GtkWidget* Widget::GetWidget() const
	{
		return m_Widget;
	}

	CGui::Alignments Widget::HAlign() const
	{
		return (Alignments)gtk_widget_get_halign(GTK_WIDGET(m_Widget));
	}

	void Widget::HAlign(Alignments align) const
	{
		gtk_widget_set_halign(GTK_WIDGET(m_Widget), (GtkAlign)align);
	}

	CGui::Alignments Widget::VAlign() const
	{
		return (Alignments)gtk_widget_get_valign(GTK_WIDGET(m_Widget));
	}

	void Widget::VAlign(Alignments align) const
	{
		gtk_widget_set_valign(GTK_WIDGET(m_Widget), (GtkAlign)align);
	}

	CGui::AlignmentsData Widget::Align() const
	{
		return { this->HAlign(), this->VAlign() };
	}

	void Widget::Align(Alignments halign, Alignments valign) const
	{
		this->HAlign(halign);
		this->VAlign(valign);
	}

	CGui::Alignments Widget::VAlignWithBaseline() const
	{
		return (Alignments)gtk_widget_get_valign_with_baseline(GTK_WIDGET(m_Widget));
	}

	const char* Widget::Name() const
	{
		return gtk_widget_get_name(GTK_WIDGET(m_Widget));
	}

	void Widget::Name(const char* name) const
	{
		gtk_widget_set_name(GTK_WIDGET(m_Widget), name);
	}

	bool Widget::AppPaintable() const
	{
		return gtk_widget_get_app_paintable(GTK_WIDGET(m_Widget));
	}

	void Widget::AppPaintable(bool paintable) const
	{
		gtk_widget_set_app_paintable(GTK_WIDGET(m_Widget), paintable);
	}

	bool Widget::Sensitive() const
	{
		return gtk_widget_get_sensitive(GTK_WIDGET(m_Widget));
	}

	void Widget::Sensitive(bool sensitive) const
	{
		gtk_widget_set_sensitive(GTK_WIDGET(m_Widget), sensitive);
	}

	bool Widget::IsSensitive() const
	{
		return gtk_widget_is_sensitive(GTK_WIDGET(m_Widget));
	}

	void Widget::SizeRequest(unsigned int x, unsigned int y) const
	{
		gtk_widget_set_size_request(GTK_WIDGET(m_Widget), x, y);
	}

	const char* Widget::Tooltip() const
	{
		return gtk_widget_get_tooltip_text(GTK_WIDGET(m_Widget));
	}

	void Widget::Tooltip(const char* text) const
	{
		gtk_widget_set_tooltip_text(GTK_WIDGET(m_Widget), text);
	}

	void Widget::Hide() const
	{
		gtk_widget_hide(GTK_WIDGET(m_Widget));
	}

	void Widget::Show() const
	{
		gtk_widget_show(GTK_WIDGET(m_Widget));
	}

	void Widget::ShowNow() const
	{
		gtk_widget_show_now(GTK_WIDGET(m_Widget));
	}

	void Widget::Map() const
	{
		gtk_widget_map(GTK_WIDGET(m_Widget));
	}

	void Widget::UnMap() const
	{
		gtk_widget_unmap(GTK_WIDGET(m_Widget));
	}

	void Widget::Realize() const
	{
		gtk_widget_realize(GTK_WIDGET(m_Widget));
	}

	void Widget::UnRealize() const
	{
		gtk_widget_unrealize(GTK_WIDGET(m_Widget));
	}

	int Widget::ScaleFactor() const
	{
		return gtk_widget_get_scale_factor(GTK_WIDGET(m_Widget));
	}

	bool Widget::IsFocus() const
	{
		return gtk_widget_is_focus(GTK_WIDGET(m_Widget));
	}

	void Widget::GrabFocus() const
	{
		gtk_widget_grab_focus(GTK_WIDGET(m_Widget));
	}

	void Widget::GrabDefault() const
	{
		gtk_widget_grab_default(GTK_WIDGET(m_Widget));
	}

	CGui::Widget Widget::Parent() const
	{
		return Widget(gtk_widget_get_parent(GTK_WIDGET(m_Widget)));
	}

	void Widget::Parent(Widget& w) const
	{
		gtk_widget_set_parent(GTK_WIDGET(m_Widget), w.GetWidget());
	}

	void Widget::Unparent() const
	{
		gtk_widget_unparent(GTK_WIDGET(m_Widget));
	}

	bool Widget::IsAncestor(Widget& ancestor) const
	{
		return gtk_widget_is_ancestor(GTK_WIDGET(m_Widget), ancestor.GetWidget());
	}

	CGui::Widget Widget::Toplevel() const
	{
		return Widget(gtk_widget_get_toplevel(GTK_WIDGET(m_Widget)));
	}

	bool Widget::InDestruction() const
	{
		return gtk_widget_in_destruction(GTK_WIDGET(m_Widget));
	}

	bool Widget::Activate() const
	{
		return gtk_widget_activate(GTK_WIDGET(m_Widget));
	}

	CGui::CoordinatesInfo Widget::TranslateCoordinates(Widget& w, int src_x, int src_y) const
	{
		int dest_x, dest_y;
		gtk_widget_translate_coordinates(GTK_WIDGET(m_Widget), w.GetWidget(), src_x, src_y, &dest_x, &dest_y);
		return { dest_x, dest_y };
	}

	bool Widget::HideOnDelete() const
	{
		return gtk_widget_hide_on_delete(GTK_WIDGET(m_Widget));
	}

	CGui::TextDirection Widget::Direction() const
	{
		return (TextDirection)gtk_widget_get_direction(GTK_WIDGET(m_Widget));
	}

	void Widget::Direction(TextDirection direction) const
	{
		gtk_widget_set_direction(GTK_WIDGET(m_Widget), (GtkTextDirection)direction);
	}

	CGui::TextDirection Widget::DefaultDirection() const
	{
		return (TextDirection)gtk_widget_get_default_direction();
	}

	void Widget::DefaultDirection(TextDirection direction) const
	{
		gtk_widget_set_default_direction((GtkTextDirection)direction);
	}

	void Widget::RedrawOnAllocate(bool redraw) const
	{
		gtk_widget_set_redraw_on_allocate(GTK_WIDGET(m_Widget), redraw);
	}

	void Widget::ChildFocus(DirectionType type) const
	{
		gtk_widget_child_focus(GTK_WIDGET(m_Widget), (GtkDirectionType)type);
	}

	bool Widget::ChildVisible() const
	{
		return gtk_widget_get_child_visible(GTK_WIDGET(m_Widget));
	}

	void Widget::ChildVisible(bool visible) const
	{
		gtk_widget_set_child_visible(GTK_WIDGET(m_Widget), visible);
	}

	bool Widget::NoShowAll() const
	{
		return gtk_widget_get_no_show_all(GTK_WIDGET(m_Widget));
	}

	void Widget::NoShowAll(bool no_show_all) const
	{
		gtk_widget_set_no_show_all(GTK_WIDGET(m_Widget), no_show_all);
	}

	CGui::Vector<CGui::Widget> Widget::ListMnemonicLabels() const
	{
		auto g_list = gtk_widget_list_mnemonic_labels(GTK_WIDGET(m_Widget));
		Vector<Widget> labels(std::move(GListToWidgetVector(g_list)));
		g_list_free(g_list);
		return std::move(labels);
	}

	void Widget::AddMnemonicLabel(Widget& label) const
	{
		gtk_widget_add_mnemonic_label(GTK_WIDGET(m_Widget), label.GetWidget());
	}

	void Widget::RemoveMnemonicLabel(Widget& label) const
	{
		gtk_widget_remove_mnemonic_label(GTK_WIDGET(m_Widget), label.GetWidget());
	}

	void Widget::ErrorBell() const
	{
		gtk_widget_error_bell(GTK_WIDGET(m_Widget));
	}

	bool Widget::KeynavFailed(DirectionType type) const
	{
		return gtk_widget_keynav_failed(GTK_WIDGET(m_Widget), (GtkDirectionType)type);
	}

	const char* Widget::TooltipMarkup() const
	{
		return gtk_widget_get_tooltip_markup(GTK_WIDGET(m_Widget));
	}

	void Widget::TooltipMarkup(const char* markup) const
	{
		gtk_widget_set_tooltip_markup(GTK_WIDGET(m_Widget), markup);
	}

	CGui::Widget Widget::TooltipWindow() const
	{
		return Widget(GTK_WIDGET(gtk_widget_get_tooltip_window(GTK_WIDGET(m_Widget))));
	}

	void Widget::TooltipWindow(Widget& window) const
	{
		if (GTK_IS_WINDOW(window.GetWidget()))
			gtk_widget_set_tooltip_window(GTK_WIDGET(m_Widget), GTK_WINDOW(window.GetWidget()));
	}

	bool Widget::HasTooltip() const
	{
		return gtk_widget_get_has_tooltip(GTK_WIDGET(m_Widget));
	}

	void Widget::HasTooltip(bool has_tooltip) const
	{
		gtk_widget_set_has_tooltip(GTK_WIDGET(m_Widget), has_tooltip);
	}

	int Widget::AllocatedWidth() const
	{
		return gtk_widget_get_allocated_width(GTK_WIDGET(m_Widget));
	}

	int Widget::AllocatedHeight() const
	{
		return gtk_widget_get_allocated_height(GTK_WIDGET(m_Widget));
	}

	int Widget::AllocatedBaseline() const
	{
		return gtk_widget_get_allocated_baseline(GTK_WIDGET(m_Widget));
	}

	bool Widget::CanDefault() const
	{
		return gtk_widget_get_can_default(GTK_WIDGET(m_Widget));
	}

	void Widget::CanDefault(bool can_default) const
	{
		gtk_widget_set_can_default(GTK_WIDGET(m_Widget), can_default);
	}

	bool Widget::HasDefault() const
	{
		return gtk_widget_has_default(GTK_WIDGET(m_Widget));
	}

	bool Widget::CanFocus() const
	{
		return gtk_widget_get_can_focus(GTK_WIDGET(m_Widget));
	}

	void Widget::CanFocus(bool can_focus) const
	{
		gtk_widget_set_can_focus(GTK_WIDGET(m_Widget), can_focus);
	}

	bool Widget::HasFocus() const
	{
		return gtk_widget_has_focus(GTK_WIDGET(m_Widget));
	}

	bool Widget::HasVisibleFocus() const
	{
		return gtk_widget_has_visible_focus(GTK_WIDGET(m_Widget));
	}

	bool Widget::HasGrab() const
	{
		return gtk_widget_has_grab(GTK_WIDGET(m_Widget));
	}

	bool Widget::IsDrawable() const
	{
		return gtk_widget_is_drawable(GTK_WIDGET(m_Widget));
	}

	bool Widget::IsToplevel() const
	{
		return gtk_widget_is_toplevel(GTK_WIDGET(m_Widget));
	}

	bool Widget::FocusOnClick() const
	{
		return gtk_widget_get_focus_on_click(GTK_WIDGET(m_Widget));
	}

	void Widget::FocusOnClick(bool focus_on_click) const
	{
		gtk_widget_set_focus_on_click(GTK_WIDGET(m_Widget), focus_on_click);
	}

	bool Widget::Visible() const
	{
		return gtk_widget_get_visible(GTK_WIDGET(m_Widget));
	}

	void Widget::Visible(bool visible) const
	{
		gtk_widget_set_visible(GTK_WIDGET(m_Widget), visible);
	}

	bool Widget::IsVisible() const
	{
		return gtk_widget_is_visible(GTK_WIDGET(m_Widget));
	}

	CGui::StateFlags Widget::State() const
	{
		return (StateFlags)gtk_widget_get_state_flags(GTK_WIDGET(m_Widget));
	}

	void Widget::State(StateFlags flag, bool clear) const
	{
		gtk_widget_set_state_flags(GTK_WIDGET(m_Widget), (GtkStateFlags)flag, clear);
	}

	void Widget::UnsetState(StateFlags flag) const
	{
		gtk_widget_unset_state_flags(GTK_WIDGET(m_Widget), (GtkStateFlags)flag);
	}

	bool Widget::ReceviesDefault() const
	{
		return gtk_widget_get_receives_default(GTK_WIDGET(m_Widget));
	}

	void Widget::ReceviesDefault(bool recevies_default) const
	{
		gtk_widget_set_receives_default(GTK_WIDGET(m_Widget), recevies_default);
	}

	bool Widget::SupportMultiDevice() const
	{
		return gtk_widget_get_support_multidevice(GTK_WIDGET(m_Widget));
	}

	void Widget::SupportMultiDevice(bool support_multi_device) const
	{
		gtk_widget_set_support_multidevice(GTK_WIDGET(m_Widget), support_multi_device);
	}

	bool Widget::Realized() const
	{
		return gtk_widget_get_realized(GTK_WIDGET(m_Widget));
	}

	void Widget::Realized(bool realized) const
	{
		gtk_widget_set_realized(GTK_WIDGET(m_Widget), realized);
	}

	bool Widget::Mapped() const
	{
		return gtk_widget_get_mapped(GTK_WIDGET(m_Widget));
	}

	void Widget::Mapped(bool mapped) const
	{
		gtk_widget_set_mapped(GTK_WIDGET(m_Widget), mapped);
	}

	double Widget::Opacity() const
	{
		return gtk_widget_get_opacity(GTK_WIDGET(m_Widget));
	}

	void Widget::Opacity(double opacity) const
	{
		gtk_widget_set_opacity(GTK_WIDGET(m_Widget), opacity);
	}

	CGui::PreferredHeightData Widget::PreferredHeight() const
	{
		int min_h, nat_h;
		gtk_widget_get_preferred_height(GTK_WIDGET(m_Widget), &min_h, &nat_h);

		return { min_h, nat_h };
	}

	CGui::PreferredWidthData Widget::PreferredWidth() const
	{
		int min_w, nat_h;
		gtk_widget_get_preferred_width(GTK_WIDGET(m_Widget), &min_w, &nat_h);

		return { min_w, nat_h };
	}

	CGui::PreferredHeightData Widget::PreferredHeightForWidth(int width) const
	{
		int min_h, nat_h;
		gtk_widget_get_preferred_height_for_width(GTK_WIDGET(m_Widget), width, &min_h, &nat_h);

		return { min_h, nat_h };
	}

	CGui::PreferredWidthData Widget::PreferredWidthForHeight(int height) const
	{
		int min_w, nat_w;
		gtk_widget_get_preferred_width_for_height(GTK_WIDGET(m_Widget), height, &min_w, &nat_w);

		return { min_w, nat_w };
	}

	CGui::HeightAndBaslineData Widget::PreferredHeightAndBaselineForWidth(int width) const
	{
		int min_h, nat_h, min_b, nat_b;
		gtk_widget_get_preferred_height_and_baseline_for_width(GTK_WIDGET(m_Widget), width, &min_h, &nat_h, &min_b, &nat_b);

		return { { min_h, nat_b }, { min_b, nat_b } };
	}

	CGui::SizeRequestMode Widget::RequestMode() const
	{
		return (SizeRequestMode)gtk_widget_get_request_mode(GTK_WIDGET(m_Widget));
	}

	CGui::PreferredSizeData Widget::PreferredSize() const
	{
		GtkRequisition minimum_size, natural_size;
		gtk_widget_get_preferred_size(GTK_WIDGET(m_Widget), &minimum_size, &natural_size);

		return { { minimum_size.width, minimum_size.height }, { natural_size.width, natural_size.height } };
	}

	int Widget::MarginStart() const
	{
		return gtk_widget_get_margin_start(GTK_WIDGET(m_Widget));
	}

	void Widget::MarginStart(int margin) const
	{
		gtk_widget_set_margin_start(GTK_WIDGET(m_Widget), margin);
	}

	int Widget::MarginEnd() const
	{
		return gtk_widget_get_margin_end(GTK_WIDGET(m_Widget));
	}

	void Widget::MarginEnd(int margin) const
	{
		gtk_widget_set_margin_end(GTK_WIDGET(m_Widget), margin);
	}

	int Widget::MarginTop() const
	{
		return gtk_widget_get_margin_top(GTK_WIDGET(m_Widget));
	}

	void Widget::MarginTop(int margin) const
	{
		gtk_widget_set_margin_top(GTK_WIDGET(m_Widget), margin);
	}

	int Widget::MarginBottom() const
	{
		return gtk_widget_get_margin_bottom(GTK_WIDGET(m_Widget));
	}

	void Widget::MarginBottom(int margin) const
	{
		gtk_widget_set_margin_bottom(GTK_WIDGET(m_Widget), margin);
	}

	CGui::Margin Widget::Margin() const
	{
		return { this->MarginStart(), this->MarginEnd(), this->MarginTop(), this->MarginBottom() };
	}

	void Widget::Margin(CGui::Margin margin) const
	{
		this->MarginStart(margin.start);
		this->MarginEnd(margin.end);
		this->MarginTop(margin.top);
		this->MarginBottom(margin.bottom);
	}

	bool Widget::HExpand() const
	{
		return gtk_widget_get_hexpand(GTK_WIDGET(m_Widget));
	}

	void Widget::HExpand(bool expand) const
	{
		gtk_widget_set_hexpand(GTK_WIDGET(m_Widget), expand);
	}

	bool Widget::HExpandSet() const
	{
		return gtk_widget_get_hexpand_set(GTK_WIDGET(m_Widget));
	}

	void Widget::HExpandSet(bool set) const
	{
		gtk_widget_set_hexpand_set(GTK_WIDGET(m_Widget), set);
	}

	bool Widget::VExpand() const
	{
		return gtk_widget_get_vexpand(GTK_WIDGET(m_Widget));
	}

	void Widget::VExpand(bool expand) const
	{
		gtk_widget_set_vexpand(GTK_WIDGET(m_Widget), expand);
	}

	bool Widget::VExpandSet() const
	{
		return gtk_widget_get_vexpand_set(GTK_WIDGET(m_Widget));
	}

	void Widget::VExpandSet(bool set) const
	{
		gtk_widget_set_vexpand_set(GTK_WIDGET(m_Widget), set);
	}

	CGui::Expand Widget::Expand() const
	{
		return { this->HExpand(), this->VExpand() };
	}

	void Widget::Expand(CGui::Expand expand) const
	{
		this->HExpand(expand.hexpand);
		this->VExpand(expand.vexpand);
	}

	void Widget::Expand(bool hexpand, bool vexpand) const
	{
		this->HExpand(hexpand);
		this->VExpand(vexpand);
	}

	void Widget::QueueComputeExpand() const
	{
		gtk_widget_queue_compute_expand(GTK_WIDGET(m_Widget));
	}

	bool Widget::ComputeExpand(Orientation orientation) const
	{
		return gtk_widget_compute_expand(GTK_WIDGET(m_Widget), (GtkOrientation)orientation);
	}

	void Widget::ResetStyle() const
	{
		gtk_widget_reset_style(GTK_WIDGET(m_Widget));
	}

	void Widget::Destroy() const
	{
		gtk_widget_destroy(GTK_WIDGET(m_Widget));
	}

	void Widget::ShowAll() const
	{
		gtk_widget_show_all(GTK_WIDGET(m_Widget));
	}

	bool Widget::IsWidget() const
	{
		return GTK_IS_WIDGET(m_Widget);
	}

	Widget::~Widget()
	{

	}

}