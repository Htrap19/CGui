#include "./VectorUtilities.hh"
#include "../../Widgets/Widget.hh"
#include "../../Widgets/Window/Window.hh"
#include "../../Widgets/RadioButton/RadioButton.hh"
#include "../../Widgets/TreeView/TreeViewColumn/TreeViewColumn.hh"

namespace CGui
{

	CGui::Vector<CGui::Widget> GSListToWidgetVector(GSList* begin)
	{
		Vector<Widget> vec;
		for (GSList* it = begin; it != nullptr; it = it->next)
		{
			vec.EmplaceBack(GTK_WIDGET(it->data));
		}

		return std::move(vec);
	}

	CGui::Vector<CGui::Widget> GListToWidgetVector(GList* begin)
	{
		Vector<Widget> vec;
		for (GList* it = begin; it != nullptr; it = it->next)
		{
			vec.EmplaceBack(GTK_WIDGET(it->data));
		}

		return std::move(vec);
	}

	CGui::Vector<CGui::Pixbuf> GListToPixbufVector(GList* begin)
	{
		Vector<Pixbuf> pbufs;
		for (GList* it = begin; it != nullptr; it = it->next)
		{
			pbufs.EmplaceBack(GDK_PIXBUF(it->data));
		}

		return std::move(pbufs);
	}

	CGui::Vector<CGui::RadioButton> WidgetVectorToRadioButton(Vector<Widget>&& vec)
	{
		Vector<RadioButton> ret;
		for (auto& widget : vec)
		{
			ret.EmplaceBack(GTK_RADIO_BUTTON(widget.GetWidget()));
		}
		return std::move(ret);
	}

	CGui::Vector<std::string> GSListToStringVector(GSList* begin)
	{
		Vector<std::string> strs;
		for (GSList* li = begin; li != nullptr; li = li->next)
		{
			strs.EmplaceBack((char*)li->data);
		}
		return std::move(strs);
	}

	CGui::Vector<std::string> GListToStringVector(GList* begin)
	{
		Vector<std::string> strs;
		for (GList* li = begin; li != nullptr; li = li->next)
		{
			strs.EmplaceBack((char*)li->data);
		}
		return std::move(strs);
	}

	CGui::Vector<CGui::Window> WidgetVectorToWindow(Vector<Widget>&& vec)
	{
		Vector<Window> ret;
		for (auto& widget : vec)
		{
			ret.EmplaceBack(GTK_WINDOW(widget.GetWidget()));
		}
		return std::move(ret);
	}

	CGui::Vector<CGui::TreeViewColumn> WidgetVectorToTreeViewColumn(Vector<Widget>&& vec)
	{
		Vector<TreeViewColumn> ret;
		for (auto& widget : vec)
		{
			ret.EmplaceBack(GTK_TREE_VIEW_COLUMN(widget.GetWidget()));
		}
		return std::move(ret);
	}

}