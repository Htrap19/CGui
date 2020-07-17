#include "./SizeGroup.hh"

namespace CGui
{
	SizeGroup::SizeGroup(SizeGroupMode mode)
	{
		m_sizegroup = gtk_size_group_new((GtkSizeGroupMode)mode);
	}

	SizeGroup::SizeGroup(GtkSizeGroup* group)
	{
		this->m_sizegroup = group;
	}

	void SizeGroup::Mode(SizeGroupMode mode)
	{
		gtk_size_group_set_mode(m_sizegroup, (GtkSizeGroupMode)mode);
	}

	SizeGroupMode SizeGroup::Mode()
	{
		return (SizeGroupMode)gtk_size_group_get_mode(m_sizegroup);
	}

	void SizeGroup::AddWidget(Widget& widget)
	{
		gtk_size_group_add_widget(m_sizegroup, widget.GetWidget());
	}

	void SizeGroup::RemoveWidget(Widget& widget)
	{
		gtk_size_group_remove_widget(m_sizegroup, widget.GetWidget());
	}

	Single::List<Widget> SizeGroup::Widgets()
	{
		auto g_list = gtk_size_group_get_widgets(m_sizegroup);
		Single::List<Widget> ret;

		for (GSList* it = g_list; it != NULL; it = it->next)
		{
			ret.Insert(Widget(GTK_WIDGET(it->data)));
		}

		g_slist_free(g_list);

		return ret;
	}

}