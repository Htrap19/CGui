#pragma once

#include <gtk/gtk.h>

/*
	Convert(er)
*/

#include "./Converter/Convert.hh"

/*
	Base Classes and Interfaces
*/

#include "./Widgets/Container.hh"
#include "./Widgets/Editable.hh"
#include "./Widgets/Handler.hh"
#include "./Widgets/NativeDialog.hh"
#include "./Widgets/Orientable.hh"
#include "./Widgets/Scrollable.hh"
#include "./Widgets/StyleContext.hh"
#include "./Widgets/ToolShell.hh"
#include "./Widgets/TreeModal.hh"
#include "./Widgets/Widget.hh"
#include "./Widgets/WidgetCast.hh"
#include "./Widgets/FileChooser.hh"

/*
	Widgets
*/

#include "./Widgets/AboutDialog/AboutDialog.hh"
#include "./Widgets/Actionbar/Actionbar.hh"
#include "./Widgets/AspectFrame/AspectFrame.hh"
#include "./Widgets/Assistant/Assistant.hh"
#include "./Widgets/Box/Box.hh"
#include "./Widgets/Button/Button.hh"
#include "./Widgets/ButtonBox/ButtonBox.hh"
#include "./Widgets/CheckButton/CheckButton.hh"
#include "./Widgets/ComboBox/ComboBox.hh"
#include "./Widgets/ComboBoxText/ComboBoxText.hh"
#include "./Widgets/Dialog/Dialog.hh"
#include "./Widgets/Entry/Entry.hh"
#include "./Widgets/Entry/EntryBuffer/EntryBuffer.hh"
#include "./Widgets/EventBox/EventBox.hh"
#include "./Widgets/Expander/Expander.hh"
#include "./Widgets/FileChooserDialog/FileChooserDialog.hh"
#include "./Widgets/FileChooserNative/FileChooserNative.hh"
#include "./Widgets/FileChooserWidget/FileChooserWidget.hh"
#include "./Widgets/Fixed/Fixed.hh"
#include "./Widgets/FlowBox/FlowBox.hh"
#include "./Widgets/Frame/Frame.hh"
#include "./Widgets/Grid/Grid.hh"
#include "./Widgets/Headerbar/Headerbar.hh"
#include "./Widgets/Image/Image.hh"
#include "./Widgets/Infobar/Infobar.hh"
#include "./Widgets/Label/Label.hh"
#include "./Widgets/Layout/Layout.hh"
#include "./Widgets/Levelbar/Levelbar.hh"
#include "./Widgets/LinkButton/LinkButton.hh"
#include "./Widgets/ListBox/ListBox.hh"
#include "./Widgets/MessageDialog/MessageDialog.hh"
#include "./Widgets/Notebook/Notebook.hh"
#include "./Widgets/Overlay/Overlay.hh"
#include "./Widgets/Paned/Paned.hh"
#include "./Widgets/Progressbar/Progressbar.hh"
#include "./Widgets/RadioButton/RadioButton.hh"
#include "./Widgets/Range/Range.hh"
#include "./Widgets/Revealer/Revealer.hh"
#include "./Widgets/Scale/Scale.hh"
#include "./Widgets/ScaleButton/ScaleButton.hh"
#include "./Widgets/Scrollbar/Scrollbar.hh"
#include "./Widgets/ScrolledWindow/ScrolledWindow.hh"
#include "./Widgets/Searchbar/Searchbar.hh"
#include "./Widgets/SearchEntry/SearchEntry.hh"
#include "./Widgets/Separator/Separator.hh"
#include "./Widgets/SpinButton/SpinButton.hh"
#include "./Widgets/Spinner/Spinner.hh"
#include "./Widgets/Stack/Stack/Stack.hh"
#include "./Widgets/Stack/StackSidebar/StackSidebar.hh"
#include "./Widgets/Stack/StackSwitcher/StackSwitcher.hh"
#include "./Widgets/Statusbar/Statusbar.hh"
#include "./Widgets/Switch/Switch.hh"
#include "./Widgets/ToggleButton/ToggleButton.hh"
#include "./Widgets/Toolbar/Toolbar.hh"
#include "./Widgets/ToolItem/ToolItem.hh"
#include "./Widgets/ToolItemGroup/ToolItemGroup.hh"
#include "./Widgets/ToolPalette/ToolPalette.hh"
#include "./Widgets/VolumeButton/VolumeButton.hh"
#include "./Widgets/Window/Window.hh"

/*
	CssProvider
*/

#include "./CssProvider/CssProvider.hh"

/*
	Custom
*/

#include "./Custom/DeleteOnQuit/DeleteOnQuit.hh"
#include "./Custom/Initialize/Initialize.hh"
#include "./Custom/List/List.hh"

/*
	Pixbuf
*/

#include "./Pixbuf/Pixbuf.hh"

/*
	Misc
*/

#include "./Misc/Adjustment/Adjustment.hh"
#include "./Misc/SizeGroup/SizeGroup.hh"