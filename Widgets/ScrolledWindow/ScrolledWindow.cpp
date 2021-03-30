#include "./ScrolledWindow.hh"

namespace CGui
{
	ScrolledWindow::ScrolledWindow(GtkScrolledWindow* scrolled_window) : Container(this)
	{
		m_Widget = GTK_WIDGET(scrolled_window);
		this->SetContext(m_Widget);
	}
	
	ScrolledWindow::ScrolledWindow(CGui::Policy hpolicy, CGui::Policy vpolicy) : Container(this)
	{
		m_Widget = gtk_scrolled_window_new(NULL, NULL);
		this->Policy(hpolicy, vpolicy);
		this->SetContext(m_Widget);
	}

	ScrolledWindow::ScrolledWindow(Adjustment hadjustment, Adjustment vadjustment) : Container(this)
	{
		m_Widget = gtk_scrolled_window_new(hadjustment.GetAdjustment(), vadjustment.GetAdjustment());
		this->SetContext(m_Widget);
	}

	ScrolledWindow::ScrolledWindow(Adjustment hadjustment, CGui::Policy hpolicy, Adjustment vadjustment, CGui::Policy vpolicy) : Container(this)
	{
		m_Widget = gtk_scrolled_window_new(hadjustment.GetAdjustment(), vadjustment.GetAdjustment());
		this->SetContext(m_Widget);
		this->Policy(hpolicy, vpolicy);
	}

	void ScrolledWindow::HAdjustment(Adjustment hadjustment)
	{
		gtk_scrolled_window_set_hadjustment(GTK_SCROLLED_WINDOW(m_Widget), hadjustment.GetAdjustment());
	}

	Adjustment ScrolledWindow::HAdjustment()
	{
		return Adjustment(gtk_scrolled_window_get_hadjustment(GTK_SCROLLED_WINDOW(m_Widget)));
	}

	void ScrolledWindow::VAdjustment(Adjustment vadjustment)
	{
		gtk_scrolled_window_set_vadjustment(GTK_SCROLLED_WINDOW(m_Widget), vadjustment.GetAdjustment());
	}

	Adjustment ScrolledWindow::VAdjustment()
	{
		return Adjustment(gtk_scrolled_window_get_vadjustment(GTK_SCROLLED_WINDOW(m_Widget)));
	}

	Widget ScrolledWindow::VScrollbar()
	{
		return Widget(gtk_scrolled_window_get_vscrollbar(GTK_SCROLLED_WINDOW(m_Widget)));
	}

	Widget ScrolledWindow::HScrollbar()
	{
		return Widget(gtk_scrolled_window_get_hscrollbar(GTK_SCROLLED_WINDOW(m_Widget)));
	}

	void ScrolledWindow::Policy(CGui::Policy hpolicy, CGui::Policy vpolicy)
	{
		gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(m_Widget), (GtkPolicyType)hpolicy, (GtkPolicyType)vpolicy);
	}

	PolicyInfo ScrolledWindow::Policy()
	{
		GtkPolicyType hp, vp;
		gtk_scrolled_window_get_policy(GTK_SCROLLED_WINDOW(m_Widget), &hp, &vp);

		return { (CGui::Policy)hp, (CGui::Policy)vp };
	}

	void ScrolledWindow::Placement(CornerType type)
	{
		gtk_scrolled_window_set_placement(GTK_SCROLLED_WINDOW(m_Widget), (GtkCornerType)type);
	}

	CornerType ScrolledWindow::Placement()
	{
		return (CornerType)gtk_scrolled_window_get_placement(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::UnsetPlacement()
	{
		gtk_scrolled_window_unset_placement(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::Shadow(ShadowType type)
	{
		gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(m_Widget), (GtkShadowType)type);
	}

	ShadowType ScrolledWindow::Shadow()
	{
		return (ShadowType)gtk_scrolled_window_get_shadow_type(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::KineticScrolling(bool scrolling)
	{
		gtk_scrolled_window_set_kinetic_scrolling(GTK_SCROLLED_WINDOW(m_Widget), scrolling);
	}

	bool ScrolledWindow::KineticScrolling()
	{
		return gtk_scrolled_window_get_kinetic_scrolling(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::CaptureButtonPress(bool capture_button_press)
	{
		gtk_scrolled_window_set_capture_button_press(GTK_SCROLLED_WINDOW(m_Widget), capture_button_press);
	}

	bool ScrolledWindow::CaptureButtonPress()
	{
		return gtk_scrolled_window_get_capture_button_press(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::OverlayScrolling(bool overlay_scrolling)
	{
		gtk_scrolled_window_set_overlay_scrolling(GTK_SCROLLED_WINDOW(m_Widget), overlay_scrolling);
	}

	bool ScrolledWindow::OverlayScrolling()
	{
		return gtk_scrolled_window_get_overlay_scrolling(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::MinContentWidth(int width)
	{
		gtk_scrolled_window_set_min_content_width(GTK_SCROLLED_WINDOW(m_Widget), width);
	}

	int ScrolledWindow::MinContentWidth()
	{
		return gtk_scrolled_window_get_min_content_width(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::MinContentHeight(int height)
	{
		gtk_scrolled_window_set_min_content_height(GTK_SCROLLED_WINDOW(m_Widget), height);
	}

	int ScrolledWindow::MinContentHeight()
	{
		return gtk_scrolled_window_get_min_content_height(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::MaxContentWidth(int width)
	{
		gtk_scrolled_window_set_max_content_width(GTK_SCROLLED_WINDOW(m_Widget), width);
	}

	int ScrolledWindow::MaxContentWidth()
	{
		return gtk_scrolled_window_get_max_content_width(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::MaxContentHeight(int height)
	{
		gtk_scrolled_window_set_max_content_height(GTK_SCROLLED_WINDOW(m_Widget), height);
	}

	int ScrolledWindow::MaxContentHeight()
	{
		return gtk_scrolled_window_get_max_content_height(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::PropagateNaturalWidth(bool propagate_width)
	{
		gtk_scrolled_window_set_propagate_natural_width(GTK_SCROLLED_WINDOW(m_Widget), propagate_width);
	}

	bool ScrolledWindow::PropagateNaturalWidth()
	{
		return gtk_scrolled_window_get_propagate_natural_width(GTK_SCROLLED_WINDOW(m_Widget));
	}

	void ScrolledWindow::PropagateNaturalHeight(bool propagate_height)
	{
		gtk_scrolled_window_set_propagate_natural_height(GTK_SCROLLED_WINDOW(m_Widget), propagate_height);
	}

	bool ScrolledWindow::PropagateNaturalHeight()
	{
		return gtk_scrolled_window_get_propagate_natural_height(GTK_SCROLLED_WINDOW(m_Widget));
	}
	bool ScrolledWindow::IsScrolledWindow()
	{
		return GTK_IS_SCROLLED_WINDOW(m_Widget);
	}
};
