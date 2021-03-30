#include "./SizeGroup.hh"
#include "../../Custom/VectorsUtilities/VectorUtilities.hh"

namespace CGui
{
	SizeGroup::SizeGroup(SizeGroupMode mode)
	{
		m_SizeGroup = gtk_size_group_new((GtkSizeGroupMode)mode);
	}

	SizeGroup::SizeGroup(GtkSizeGroup* group)
	{
		this->m_SizeGroup = group;
	}

	void SizeGroup::Mode(SizeGroupMode mode)
	{
		gtk_size_group_set_mode(m_SizeGroup, (GtkSizeGroupMode)mode);
	}

	SizeGroupMode SizeGroup::Mode()
	{
		return (SizeGroupMode)gtk_size_group_get_mode(m_SizeGroup);
	}

	void SizeGroup::AddWidget(Widget& widget)
	{
		gtk_size_group_add_widget(m_SizeGroup, widget.GetWidget());
	}

	void SizeGroup::RemoveWidget(Widget& widget)
	{
		gtk_size_group_remove_widget(m_SizeGroup, widget.GetWidget());
	}

	Vector<Widget> SizeGroup::Widgets()
	{
		auto g_list = gtk_size_group_get_widgets(m_SizeGroup);
		Vector<Widget> widgets(std::move(GSListToWidgetVector(g_list)));
		g_slist_free(g_list);
		return std::move(widgets);
	}

	bool SizeGroup::IsSizeGroup()
	{
		return GTK_IS_SIZE_GROUP(m_SizeGroup);
	}

}