#pragma once

#include "../Converter/Convert.hh"
#include "./StyleContext.hh"
#include "../Custom/List/List.hh"

namespace CGui
{
	class Widget : public StyleContext
	{
	public:
		Widget() : m_parent{ NULL }, m_toplevel{ NULL }, m_custom_tooltip_window{ NULL }
		{

		}

		Widget(GtkWidget* w) : m_parent{ NULL }, m_toplevel{ NULL }, m_custom_tooltip_window{ NULL }
		{
			this->SetWidget(w);
		}

		virtual void SetWidget(GtkWidget* widget)
		{
			this->widget = widget;
		}

		virtual GtkWidget* GetWidget()
		{
			return widget;
		}

		virtual void HAlign(Alignments align)
		{
			gtk_widget_set_halign(GTK_WIDGET(widget), (GtkAlign)align);
		}

		virtual Alignments HAlign()
		{
			return (Alignments)gtk_widget_get_halign(GTK_WIDGET(widget));
		}

		virtual void VAlign(Alignments align)
		{
			gtk_widget_set_valign(GTK_WIDGET(widget), (GtkAlign)align);
		}

		virtual Alignments VAlign()
		{
			return (Alignments)gtk_widget_get_valign(GTK_WIDGET(widget));
		}

		virtual void Align(Alignments halign, Alignments valign)
		{
			this->HAlign(halign);
			this->VAlign(valign);
		}

		virtual AlignmentsData Align()
		{
			return { this->HAlign(), this->VAlign() };
		}

		virtual Alignments VAlignWithBaseline()
		{
			return (Alignments)gtk_widget_get_valign_with_baseline(GTK_WIDGET(widget));
		}

		virtual void Name(const char* name)
		{
			gtk_widget_set_name(GTK_WIDGET(widget), name);
		}

		virtual const char* Name()
		{
			return gtk_widget_get_name(GTK_WIDGET(widget));
		}

		virtual void AppPaintable(bool paintable)
		{
			gtk_widget_set_app_paintable(GTK_WIDGET(widget), paintable);
		}

		virtual bool AppPaintable()
		{
			return gtk_widget_get_app_paintable(GTK_WIDGET(widget));
		}

		virtual void Sensitive(bool sensitive)
		{
			gtk_widget_set_sensitive(GTK_WIDGET(widget), sensitive);
		}

		virtual bool IsSensitive()
		{
			return gtk_widget_is_sensitive(GTK_WIDGET(widget));
		}

		virtual bool Sensitive()
		{
			return gtk_widget_get_sensitive(GTK_WIDGET(widget));
		}

		virtual void SizeRequest(unsigned int x, unsigned int y)
		{
			gtk_widget_set_size_request(GTK_WIDGET(widget), x, y);
		}

		virtual void Tooltip(const char* text)
		{
			gtk_widget_set_tooltip_text(GTK_WIDGET(widget), text);
		}

		virtual const char* Tooltip()
		{
			return gtk_widget_get_tooltip_text(GTK_WIDGET(widget));
		}

		virtual void Hide()
		{
			gtk_widget_hide(GTK_WIDGET(widget));
		}

		virtual void Show()
		{
			gtk_widget_show(GTK_WIDGET(widget));
		}

		virtual void ShowNow()
		{
			gtk_widget_show_now(GTK_WIDGET(widget));
		}

		virtual void Map()
		{
			gtk_widget_map(GTK_WIDGET(widget));
		}

		virtual void UnMap()
		{
			gtk_widget_unmap(GTK_WIDGET(widget));
		}

		virtual void Realize()
		{
			gtk_widget_realize(GTK_WIDGET(widget));
		}

		virtual void UnRealize()
		{
			gtk_widget_unrealize(GTK_WIDGET(widget));
		}

		virtual int ScaleFactor()
		{
			return gtk_widget_get_scale_factor(GTK_WIDGET(widget));
		}

		virtual void IsFocus()
		{
			gtk_widget_is_focus(GTK_WIDGET(widget));
		}

		virtual void GrabFocus()
		{
			gtk_widget_grab_focus(GTK_WIDGET(widget));
		}

		virtual void GrabDefault()
		{
			gtk_widget_grab_default(GTK_WIDGET(widget));
		}

		virtual void Parent(Widget& w)
		{
			gtk_widget_set_parent(GTK_WIDGET(widget), w.GetWidget());
		}

		virtual Widget& Parent()
		{
			if (m_parent != NULL)
				delete m_parent;
			m_parent = new Widget(gtk_widget_get_parent(GTK_WIDGET(widget)));
			return *m_parent;
		}

		virtual void Unparent()
		{
			gtk_widget_unparent(GTK_WIDGET(widget));
		}

		virtual bool IsAncestor(Widget & ancestor)
		{
			return gtk_widget_is_ancestor(GTK_WIDGET(widget), ancestor.GetWidget());
		}

		virtual Widget& Toplevel()
		{
			if (m_toplevel != NULL)
				delete m_toplevel;
			m_toplevel = new Widget(gtk_widget_get_toplevel(GTK_WIDGET(widget)));
			return *m_toplevel;
		}

		virtual bool InDestruction()
		{
			return gtk_widget_in_destruction(GTK_WIDGET(widget));
		}

		virtual bool Activate()
		{
			return gtk_widget_activate(GTK_WIDGET(widget));
		}

		virtual CoordinatesInfo TranslateCoordinates(Widget & w, int src_x, int src_y)
		{
			int dest_x, dest_y;
			gtk_widget_translate_coordinates(GTK_WIDGET(widget), w.GetWidget(), src_x, src_y, &dest_x, &dest_y);
			return { dest_x, dest_y };
		}

		virtual bool HideOnDelete()
		{
			return gtk_widget_hide_on_delete(GTK_WIDGET(widget));
		}

		virtual void Direction(TextDirection direction)
		{
			gtk_widget_set_direction(GTK_WIDGET(widget), (GtkTextDirection)direction);
		}

		virtual TextDirection Direction()
		{
			return (TextDirection)gtk_widget_get_direction(GTK_WIDGET(widget));
		}

		virtual void DefaultDirection(TextDirection direction)
		{
			gtk_widget_set_default_direction((GtkTextDirection)direction);
		}

		virtual TextDirection DefaultDirection()
		{
			return (TextDirection)gtk_widget_get_default_direction();
		}

		virtual void RedrawOnAllocate(bool redraw)
		{
			gtk_widget_set_redraw_on_allocate(GTK_WIDGET(widget), redraw);
		}

		virtual void ChildFocus(DirectionType type)
		{
			gtk_widget_child_focus(GTK_WIDGET(widget), (GtkDirectionType)type);
		}

		virtual void ChildVisible(bool visible)
		{
			gtk_widget_set_child_visible(GTK_WIDGET(widget), visible);
		}

		virtual bool ChildVisible()
		{
			return gtk_widget_get_child_visible(GTK_WIDGET(widget));
		}

		virtual void NoShowAll(bool no_show_all)
		{
			gtk_widget_set_no_show_all(GTK_WIDGET(widget), no_show_all);
		}

		virtual bool NoShowAll()
		{
			return gtk_widget_get_no_show_all(GTK_WIDGET(widget));
		}

		virtual Single::List<Widget*>& ListMnemonicLabels()
		{
			auto g_list = gtk_widget_list_mnemonic_labels(GTK_WIDGET(widget));

			if (m_list_mnemonic_labels.Size() >= 1)
			{
				m_list_mnemonic_labels.ForEach([](Widget * data) -> void
					{
						delete data;
					});
			}

			for (GList* it = g_list; it != NULL; it = it->next)
			{
				m_list_mnemonic_labels.Insert(new Widget(GTK_WIDGET(it->data)));
			}

			return m_list_mnemonic_labels;
		}

		virtual void AddMnemonicLabel(Widget & label)
		{
			gtk_widget_add_mnemonic_label(GTK_WIDGET(widget), label.GetWidget());
		}

		virtual void RemoveMnemonicLabel(Widget & label)
		{
			gtk_widget_remove_mnemonic_label(GTK_WIDGET(widget), label.GetWidget());
		}

		virtual void ErrorBell()
		{
			gtk_widget_error_bell(GTK_WIDGET(widget));
		}

		virtual bool KeynavFailed(DirectionType type)
		{
			return gtk_widget_keynav_failed(GTK_WIDGET(widget), (GtkDirectionType)type);
		}

		virtual void TooltipMarkup(const char* markup)
		{
			gtk_widget_set_tooltip_markup(GTK_WIDGET(widget), markup);
		}

		virtual const char* TooltipMarkup()
		{
			return gtk_widget_get_tooltip_markup(GTK_WIDGET(widget));
		}

		virtual void TooltipWindow(Widget & window)
		{
			if (GTK_IS_WINDOW(window.GetWidget()))
				gtk_widget_set_tooltip_window(GTK_WIDGET(widget), GTK_WINDOW(window.GetWidget()));
		}

		virtual Widget& TooltipWindow()
		{
			if (m_custom_tooltip_window != NULL)
				delete m_custom_tooltip_window;
			m_custom_tooltip_window = new Widget(GTK_WIDGET(gtk_widget_get_tooltip_window(GTK_WIDGET(widget))));
			return *m_custom_tooltip_window;
		}

		virtual void HasTooltip(bool has_tooltip)
		{
			gtk_widget_set_has_tooltip(GTK_WIDGET(widget), has_tooltip);
		}

		virtual bool HasTooltip()
		{
			return gtk_widget_get_has_tooltip(GTK_WIDGET(widget));
		}

		virtual int AllocatedWidth()
		{
			return gtk_widget_get_allocated_width(GTK_WIDGET(widget));
		}

		virtual int AllocatedHeight()
		{
			return gtk_widget_get_allocated_height(GTK_WIDGET(widget));
		}

		virtual int AllocatedBaseline()
		{
			return gtk_widget_get_allocated_baseline(GTK_WIDGET(widget));
		}

		virtual void CanDefault(bool can_default)
		{
			gtk_widget_set_can_default(GTK_WIDGET(widget), can_default);
		}

		virtual bool CanDefault()
		{
			return gtk_widget_get_can_default(GTK_WIDGET(widget));
		}

		virtual bool HasDefault()
		{
			return gtk_widget_has_default(GTK_WIDGET(widget));
		}

		virtual void CanFocus(bool can_focus)
		{
			gtk_widget_set_can_focus(GTK_WIDGET(widget), can_focus);
		}

		virtual bool CanFocus()
		{
			return gtk_widget_get_can_focus(GTK_WIDGET(widget));
		}

		virtual bool HasFocus()
		{
			return gtk_widget_has_focus(GTK_WIDGET(widget));
		}

		virtual bool HasVisibleFocus()
		{
			return gtk_widget_has_visible_focus(GTK_WIDGET(widget));
		}

		virtual bool HasGrab()
		{
			return gtk_widget_has_grab(GTK_WIDGET(widget));
		}

		virtual bool IsDrawable()
		{
			return gtk_widget_is_drawable(GTK_WIDGET(widget));
		}

		virtual bool IsToplevel()
		{
			return gtk_widget_is_toplevel(GTK_WIDGET(widget));
		}

		virtual void FocusOnClick(bool focus_on_click)
		{
			gtk_widget_set_focus_on_click(GTK_WIDGET(widget), focus_on_click);
		}

		virtual bool FocusOnClick()
		{
			return gtk_widget_get_focus_on_click(GTK_WIDGET(widget));
		}

		virtual void Visible(bool visible)
		{
			gtk_widget_set_visible(GTK_WIDGET(widget), visible);
		}

		virtual bool IsVisible()
		{
			return gtk_widget_is_visible(GTK_WIDGET(widget));
		}

		virtual bool Visible()
		{
			return gtk_widget_get_visible(GTK_WIDGET(widget));
		}

		virtual void State(StateFlags flag, bool clear)
		{
			gtk_widget_set_state_flags(GTK_WIDGET(widget), (GtkStateFlags)flag, clear);
		}

		virtual void UnsetState(StateFlags flag)
		{
			gtk_widget_unset_state_flags(GTK_WIDGET(widget), (GtkStateFlags)flag);
		}

		virtual StateFlags State()
		{
			return (StateFlags)gtk_widget_get_state_flags(GTK_WIDGET(widget));
		}

		virtual void ReceviesDefault(bool recevies_default)
		{
			gtk_widget_set_receives_default(GTK_WIDGET(widget), recevies_default);
		}

		virtual bool ReceviesDefault()
		{
			return gtk_widget_get_receives_default(GTK_WIDGET(widget));
		}

		virtual void SupportMultiDevice(bool support_multi_device)
		{
			gtk_widget_set_support_multidevice(GTK_WIDGET(widget), support_multi_device);
		}

		virtual bool SupportMultiDevice()
		{
			return gtk_widget_get_support_multidevice(GTK_WIDGET(widget));
		}

		virtual void Realized(bool realized)
		{
			gtk_widget_set_realized(GTK_WIDGET(widget), realized);
		}

		virtual bool Realized()
		{
			return gtk_widget_get_realized(GTK_WIDGET(widget));
		}

		virtual void Mapped(bool mapped)
		{
			gtk_widget_set_mapped(GTK_WIDGET(widget), mapped);
		}

		virtual bool Mapped()
		{
			return gtk_widget_get_mapped(GTK_WIDGET(widget));
		}

		virtual void Opacity(double opacity)
		{
			gtk_widget_set_opacity(GTK_WIDGET(widget), opacity);
		}

		virtual double Opacity()
		{
			return gtk_widget_get_opacity(GTK_WIDGET(widget));
		}

		virtual PreferredHeightData PreferredHeight()
		{
			int min_h, nat_h;
			gtk_widget_get_preferred_height(GTK_WIDGET(widget), &min_h, &nat_h);

			return { min_h, nat_h };
		}

		virtual PreferredWidthData PreferredWidth()
		{
			int min_w, nat_h;
			gtk_widget_get_preferred_width(GTK_WIDGET(widget), &min_w, &nat_h);

			return { min_w, nat_h };
		}

		virtual PreferredHeightData PreferredHeightForWidth(int width)
		{
			int min_h, nat_h;
			gtk_widget_get_preferred_height_for_width(GTK_WIDGET(widget), width, &min_h, &nat_h);

			return { min_h, nat_h };
		}

		virtual PreferredWidthData PreferredWidthForHeight(int height)
		{
			int min_w, nat_w;
			gtk_widget_get_preferred_width_for_height(GTK_WIDGET(widget), height, &min_w, &nat_w);

			return { min_w, nat_w };
		}

		virtual HeightAndBaslineData PreferredHeightAndBaselineForWidth(int width)
		{
			int min_h, nat_h, min_b, nat_b;
			gtk_widget_get_preferred_height_and_baseline_for_width(GTK_WIDGET(widget), width, &min_h, &nat_h, &min_b, &nat_b);

			return { { min_h, nat_b }, { min_b, nat_b } };
		}

		virtual SizeRequestMode RequestMode()
		{
			return (SizeRequestMode)gtk_widget_get_request_mode(GTK_WIDGET(widget));
		}

		virtual PreferredSizeData PreferredSize()
		{
			GtkRequisition minimum_size, natural_size;
			gtk_widget_get_preferred_size(GTK_WIDGET(widget), &minimum_size, &natural_size);

			return { { minimum_size.width, minimum_size.height }, { natural_size.width, natural_size.height } };
		}

		virtual void MarginStart(int margin)
		{
			gtk_widget_set_margin_start(GTK_WIDGET(widget), margin);
		}

		virtual int MarginStart()
		{
			return gtk_widget_get_margin_start(GTK_WIDGET(widget));
		}

		virtual void MarginEnd(int margin)
		{
			gtk_widget_set_margin_end(GTK_WIDGET(widget), margin);
		}

		virtual int MarginEnd()
		{
			return gtk_widget_get_margin_end(GTK_WIDGET(widget));
		}

		virtual void MarginTop(int margin)
		{
			gtk_widget_set_margin_top(GTK_WIDGET(widget), margin);
		}

		virtual int MarginTop()
		{
			return gtk_widget_get_margin_top(GTK_WIDGET(widget));
		}

		virtual void MarginBottom(int margin)
		{
			gtk_widget_set_margin_bottom(GTK_WIDGET(widget), margin);
		}

		virtual int MarginBottom()
		{
			return gtk_widget_get_margin_bottom(GTK_WIDGET(widget));
		}

		virtual void Margin(WidgetMargin margin)
		{
			this->MarginStart(margin.start);
			this->MarginEnd(margin.end);
			this->MarginTop(margin.top);
			this->MarginBottom(margin.bottom);
		}

		virtual WidgetMargin Margin()
		{
			return { this->MarginStart(), this->MarginEnd(), this->MarginTop(), this->MarginBottom() };
		}

		virtual void HExpand(bool expand)
		{
			gtk_widget_set_hexpand(GTK_WIDGET(widget), expand);
		}

		virtual bool HExpand()
		{
			return gtk_widget_get_hexpand(GTK_WIDGET(widget));
		}

		virtual void HExpandSet(bool set)
		{
			gtk_widget_set_hexpand_set(GTK_WIDGET(widget), set);
		}

		virtual bool HExpandSet()
		{
			return gtk_widget_get_hexpand_set(GTK_WIDGET(widget));
		}

		virtual void VExpand(bool expand)
		{
			gtk_widget_set_vexpand(GTK_WIDGET(widget), expand);
		}

		virtual bool VExpand()
		{
			return gtk_widget_get_vexpand(GTK_WIDGET(widget));
		}

		virtual void VExpandSet(bool set)
		{
			gtk_widget_set_vexpand_set(GTK_WIDGET(widget), set);
		}

		virtual bool VExpandSet()
		{
			return gtk_widget_get_vexpand_set(GTK_WIDGET(widget));
		}

		virtual void Expand(bool hexpand, bool vexpand)
		{
			this->HExpand(hexpand);
			this->VExpand(vexpand);
		}

		virtual void Expand(WidgetExpand expand)
		{
			this->HExpand(expand.hexpand);
			this->VExpand(expand.vexpand);
		}

		virtual WidgetExpand Expand()
		{
			return { this->HExpand(), this->VExpand() };
		}

		virtual void QueueComputeExpand()
		{
			gtk_widget_queue_compute_expand(GTK_WIDGET(widget));
		}

		virtual bool ComputeExpand(Orientation orientation)
		{
			return gtk_widget_compute_expand(GTK_WIDGET(widget), (GtkOrientation)orientation);
		}

		virtual void ResetStyle()
		{
			gtk_widget_reset_style(GTK_WIDGET(widget));
		}

		virtual void Destroy()
		{
			gtk_widget_destroy(GTK_WIDGET(widget));
		}

		virtual void ShowAll()
		{
			gtk_widget_show_all(GTK_WIDGET(widget));
		}

		virtual ~Widget()
		{
			delete m_parent;
			delete m_toplevel;
			m_list_mnemonic_labels.ForEach([](Widget * data) -> void
				{
					delete data;
				});
			delete m_custom_tooltip_window;
		}

	protected:
		GtkWidget* widget;
		Widget* m_parent;
		Widget* m_toplevel;
		Single::List<Widget*> m_list_mnemonic_labels;
		Widget* m_custom_tooltip_window;
	};
}