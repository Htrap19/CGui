#include "./Notebook.hh"

namespace CGui
{
	Notebook::Notebook() : Container(this)
	{
		m_Widget = gtk_notebook_new();
		this->SetContext(m_Widget);
	}

	Notebook::Notebook(GtkNotebook* notebook) : Container(this)
	{
		m_Widget = GTK_WIDGET(notebook);
		this->SetContext(m_Widget);
	}

	void Notebook::AppendPage(Widget& child, Widget& tab_label)
	{
		gtk_notebook_append_page(GTK_NOTEBOOK(m_Widget), child.GetWidget(), tab_label.GetWidget());
	}

	void Notebook::AppendPageMenu(Widget& child, Widget& tab_label, Widget& menu_label)
	{
		gtk_notebook_append_page_menu(GTK_NOTEBOOK(m_Widget), child.GetWidget(), tab_label.GetWidget(), menu_label.GetWidget());
	}

	void Notebook::PrependPage(Widget& child, Widget& tab_label)
	{
		gtk_notebook_prepend_page(GTK_NOTEBOOK(m_Widget), child.GetWidget(), tab_label.GetWidget());
	}

	void Notebook::PrependPageMenu(Widget& child, Widget& tab_label, Widget& menu_label)
	{
		gtk_notebook_prepend_page_menu(GTK_NOTEBOOK(m_Widget), child.GetWidget(), tab_label.GetWidget(), menu_label.GetWidget());
	}

	void Notebook::InsertPage(Widget& child, Widget& tab_label, int position)
	{
		gtk_notebook_insert_page(GTK_NOTEBOOK(m_Widget), child.GetWidget(), tab_label.GetWidget(), position);
	}

	void Notebook::InsertPageMenu(Widget& child, Widget& tab_label, Widget& menu_label, int position)
	{
		gtk_notebook_insert_page_menu(GTK_NOTEBOOK(m_Widget), child.GetWidget(), tab_label.GetWidget(), menu_label.GetWidget(), position);
	}

	void Notebook::RemovePage(int page_num)
	{
		gtk_notebook_remove_page(GTK_NOTEBOOK(m_Widget), page_num);
	}

	void Notebook::DetachTab(Widget& child)
	{
		gtk_notebook_detach_tab(GTK_NOTEBOOK(m_Widget), child.GetWidget());
	}

	int Notebook::PageNum(Widget& child)
	{
		return gtk_notebook_page_num(GTK_NOTEBOOK(m_Widget), child.GetWidget());
	}

	void Notebook::NextPage()
	{
		gtk_notebook_next_page(GTK_NOTEBOOK(m_Widget));
	}

	void Notebook::PrevPage()
	{
		gtk_notebook_prev_page(GTK_NOTEBOOK(m_Widget));
	}

	void Notebook::ReorderChild(Widget& child, int position)
	{
		gtk_notebook_reorder_child(GTK_NOTEBOOK(m_Widget), child.GetWidget(), position);
	}

	void Notebook::TabPos(PositionType type)
	{
		gtk_notebook_set_tab_pos(GTK_NOTEBOOK(m_Widget), (GtkPositionType)type);
	}

	PositionType Notebook::TabPos()
	{
		return (PositionType)gtk_notebook_get_tab_pos(GTK_NOTEBOOK(m_Widget));
	}

	void Notebook::ShowTabs(bool show_tabs)
	{
		gtk_notebook_set_show_tabs(GTK_NOTEBOOK(m_Widget), show_tabs);
	}

	bool Notebook::ShowTabs()
	{
		return gtk_notebook_get_show_tabs(GTK_NOTEBOOK(m_Widget));
	}

	void Notebook::ShowBorder(bool show_border)
	{
		gtk_notebook_set_show_border(GTK_NOTEBOOK(m_Widget), show_border);
	}

	bool Notebook::ShowBorder()
	{
		return gtk_notebook_get_show_border(GTK_NOTEBOOK(m_Widget));
	}

	void Notebook::Scrollable(bool scrollable)
	{
		gtk_notebook_set_scrollable(GTK_NOTEBOOK(m_Widget), scrollable);
	}

	void Notebook::PopupEnable()
	{
		gtk_notebook_popup_enable(GTK_NOTEBOOK(m_Widget));
	}

	void Notebook::PopupDisable()
	{
		gtk_notebook_popup_disable(GTK_NOTEBOOK(m_Widget));
	}

	void Notebook::CurrentPage(int page_num)
	{
		gtk_notebook_set_current_page(GTK_NOTEBOOK(m_Widget), page_num);
	}

	int Notebook::CurrentPage()
	{
		return gtk_notebook_get_current_page(GTK_NOTEBOOK(m_Widget));
	}

	Widget Notebook::NthPages(int page_num)
	{
		return Widget(gtk_notebook_get_nth_page(GTK_NOTEBOOK(m_Widget), page_num));
	}

	int Notebook::NumPage()
	{
		return gtk_notebook_get_n_pages(GTK_NOTEBOOK(m_Widget));
	}

	void Notebook::MenuLabel(Widget& child, Widget& menu_label)
	{
		gtk_notebook_set_menu_label(GTK_NOTEBOOK(m_Widget), child.GetWidget(), menu_label.GetWidget());
	}

	Widget Notebook::MenuLabel(Widget& child)
	{
		return Widget(gtk_notebook_get_menu_label(GTK_NOTEBOOK(m_Widget), child.GetWidget()));
	}

	void Notebook::MenuLabelText(Widget& child, const char* menu_label)
	{
		gtk_notebook_set_menu_label_text(GTK_NOTEBOOK(m_Widget), child.GetWidget(), menu_label);
	}

	const char* Notebook::MenuLabelText(Widget& child)
	{
		return gtk_notebook_get_menu_label_text(GTK_NOTEBOOK(m_Widget), child.GetWidget());
	}

	void Notebook::TabLabel(Widget& child, Widget& tab_label)
	{
		gtk_notebook_set_tab_label(GTK_NOTEBOOK(m_Widget), child.GetWidget(), tab_label.GetWidget());
	}

	Widget Notebook::TabLabel(Widget& child)
	{
		return Widget(gtk_notebook_get_tab_label(GTK_NOTEBOOK(m_Widget), child.GetWidget()));
	}

	void Notebook::TabLabelText(Widget& child, const char* tab_label)
	{
		gtk_notebook_set_tab_label_text(GTK_NOTEBOOK(m_Widget), child.GetWidget(), tab_label);
	}

	const char* Notebook::TabLabelText(Widget& child)
	{
		return gtk_notebook_get_tab_label_text(GTK_NOTEBOOK(m_Widget), child.GetWidget());
	}

	void Notebook::TabReorderable(Widget& child, bool reorderable)
	{
		gtk_notebook_set_tab_reorderable(GTK_NOTEBOOK(m_Widget), child.GetWidget(), reorderable);
	}

	bool Notebook::TabReorderable(Widget& child)
	{
		return gtk_notebook_get_tab_reorderable(GTK_NOTEBOOK(m_Widget), child.GetWidget());
	}

	void Notebook::TabDetachable(Widget& child, bool detachable)
	{
		gtk_notebook_set_tab_detachable(GTK_NOTEBOOK(m_Widget), child.GetWidget(), detachable);
	}

	bool Notebook::TabDetachable(Widget& child)
	{
		return gtk_notebook_get_tab_detachable(GTK_NOTEBOOK(m_Widget), child.GetWidget());
	}

	void Notebook::GroupName(const char* name)
	{
		gtk_notebook_set_group_name(GTK_NOTEBOOK(m_Widget), name);
	}

	const char* Notebook::GroupName()
	{
		return gtk_notebook_get_group_name(GTK_NOTEBOOK(m_Widget));
	}

	void Notebook::ActionWidget(Widget& child, PackType type)
	{
		gtk_notebook_set_action_widget(GTK_NOTEBOOK(m_Widget), child.GetWidget(), (GtkPackType)type);
	}

	Widget Notebook::ActionWidget(PackType type)
	{
		return Widget(gtk_notebook_get_action_widget(GTK_NOTEBOOK(m_Widget), (GtkPackType)type));
	}

	bool Notebook::IsNotebook()
	{
		return GTK_IS_NOTEBOOK(m_Widget);
	}

}