#include "./ScrolledWindow.hh"

namespace CGui
{
	ScrolledWindow::ScrolledWindow(GtkScrolledWindow* scrolled_window) : Container(this)
	{
		widget = GTK_WIDGET(scrolled_window);
		this->SetContext(widget);
	}
	
	ScrolledWindow::ScrolledWindow(CGui::Policy hpolicy, CGui::Policy vpolicy) : Container(this)
	{
		widget = gtk_scrolled_window_new(NULL, NULL);
		this->Policy(hpolicy, vpolicy);
		this->SetContext(widget);
	}

	ScrolledWindow::ScrolledWindow(Adjustment hadjustment, Adjustment vadjustment) : Container(this)
	{
		widget = gtk_scrolled_window_new(hadjustment.GetAdjustment(), vadjustment.GetAdjustment());
		this->SetContext(widget);
	}

	ScrolledWindow::ScrolledWindow(Adjustment hadjustment, CGui::Policy hpolicy, Adjustment vadjustment, CGui::Policy vpolicy) : Container(this)
	{
		widget = gtk_scrolled_window_new(hadjustment.GetAdjustment(), vadjustment.GetAdjustment());
		this->SetContext(widget);
		this->Policy(hpolicy, vpolicy);
	}

	void ScrolledWindow::HAdjustment(Adjustment hadjustment)
	{
		gtk_scrolled_window_set_hadjustment(GTK_SCROLLED_WINDOW(widget), hadjustment.GetAdjustment());
	}

	Adjustment ScrolledWindow::HAdjustment()
	{
		return Adjustment(gtk_scrolled_window_get_hadjustment(GTK_SCROLLED_WINDOW(widget)));
	}

	void ScrolledWindow::VAdjustment(Adjustment vadjustment)
	{
		gtk_scrolled_window_set_vadjustment(GTK_SCROLLED_WINDOW(widget), vadjustment.GetAdjustment());
	}

	Adjustment ScrolledWindow::VAdjustment()
	{
		return Adjustment(gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(widget)));
	}

	Widget ScrolledWindow::VScrollbar()
	{
		return Widget(gtk_scrolled_window_get_vscrollbar(GTK_SCROLLED_WINDOW(widget)));
	}

	Widget ScrolledWindow::HScrollbar()
	{
		return Widget(gtk_scrolled_window_get_hscrollbar(GTK_SCROLLED_WINDOW(widget)));
	}

	void ScrolledWindow::Policy(CGui::Policy hpolicy, CGui::Policy vpolicy)
	{
		gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(widget), (GtkPolicyType)hpolicy, (GtkPolicyType)vpolicy);
	}

	PolicyInfo ScrolledWindow::Policy()
	{
		GtkPolicyType hp, vp;
		gtk_scrolled_window_get_policy(GTK_SCROLLED_WINDOW(widget), &hp, &vp);

		return { (CGui::Policy)hp, (CGui::Policy)vp };
	}

	void ScrolledWindow::Placement(CornerType type)
	{
		gtk_scrolled_window_set_placement(GTK_SCROLLED_WINDOW(widget), (GtkCornerType)type);
	}

	CornerType ScrolledWindow::Placement()
	{
		return (CornerType)gtk_scrolled_window_get_placement(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::UnsetPlacement()
	{
		gtk_scrolled_window_unset_placement(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::Shadow(ShadowType type)
	{
		gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(widget), (GtkShadowType)type);
	}

	ShadowType ScrolledWindow::Shadow()
	{
		return (ShadowType)gtk_scrolled_window_get_shadow_type(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::KineticScrolling(bool scrolling)
	{
		gtk_scrolled_window_set_kinetic_scrolling(GTK_SCROLLED_WINDOW(widget), scrolling);
	}

	bool ScrolledWindow::KineticScrolling()
	{
		return gtk_scrolled_window_get_kinetic_scrolling(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::CaptureButtonPress(bool capture_button_press)
	{
		gtk_scrolled_window_set_capture_button_press(GTK_SCROLLED_WINDOW(widget), capture_button_press);
	}

	bool ScrolledWindow::CaptureButtonPress()
	{
		return gtk_scrolled_window_get_capture_button_press(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::OverlayScrolling(bool overlay_scrolling)
	{
		gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(widget), overlay_scrolling);
	}

	bool ScrolledWindow::OverlayScrolling()
	{
		return gtk_scrolled_window_get_overlay_scrolling(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::MinContentWidth(int width)
	{
		gtk_scrolled_window_set_min_content_width(GTK_SCROLLED_WINDOW(widget), width);
	}

	int ScrolledWindow::MinContentWidth()
	{
		return gtk_scrolled_window_get_min_content_width(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::MinContentHeight(int height)
	{
		gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(widget), height);
	}

	int ScrolledWindow::MinContentHeight()
	{
		return gtk_scrolled_window_get_min_content_height(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::MaxContentWidth(int width)
	{
		gtk_scrolled_window_set_max_content_width(GTK_SCROLLED_WINDOW(widget), width);
	}

	int ScrolledWindow::MaxContentWidth()
	{
		return gtk_scrolled_window_get_max_content_width(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::MaxContentHeight(int height)
	{
		gtk_scrolled_window_set_max_content_height(GTK_SCROLLED_WINDOW(widget), height);
	}

	int ScrolledWindow::MaxContentHeight()
	{
		return gtk_scrolled_window_get_max_content_height(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::PropagateNaturalWidth(bool propagate_width)
	{
		gtk_scrolled_window_set_propagate_natural_width(GTK_SCROLLED_WINDOW(widget), propagate_width);
	}

	bool ScrolledWindow::PropagateNaturalWidth()
	{
		return gtk_scrolled_window_get_propagate_natural_width(GTK_SCROLLED_WINDOW(widget));
	}

	void ScrolledWindow::PropagateNaturalHeight(bool propagate_height)
	{
		gtk_scrolled_window_set_propagate_natural_height(GTK_SCROLLED_WINDOW(widget), propagate_height);
	}

	bool ScrolledWindow::PropagateNaturalHeight()
	{
		return gtk_scrolled_window_get_propagate_natural_height(GTK_SCROLLED_WINDOW(widget));
	}
	bool ScrolledWindow::IsScrolledWindow()
	{
		return GTK_IS_SCROLLED_WINDOW(widget);
	}
};
