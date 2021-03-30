#pragma once

#include <iostream>
#include <gtk/gtk.h>
#include "../Vector/Vector.hh"
#include "../../Pixbuf/Pixbuf/Pixbuf.hh"
#include "../../Widgets/Menifest.hh"

namespace CGui
{
	Vector<Widget> GSListToWidgetVector(GSList* begin);
	Vector<Widget> GListToWidgetVector(GList* begin);
	Vector<Pixbuf> GListToPixbufVector(GList* begin);
	Vector<RadioButton> WidgetVectorToRadioButton(Vector<Widget>&& vec);
	Vector<Window> WidgetVectorToWindow(Vector<Widget>&& vec);
	Vector<TreeViewColumn> WidgetVectorToTreeViewColumn(Vector<Widget>&& vec);
	Vector<std::string> GSListToStringVector(GSList* begin);
	Vector<std::string> GListToStringVector(GList* begin);
}