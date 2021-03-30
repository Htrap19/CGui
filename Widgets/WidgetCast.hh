#pragma once

#include "Widget.hh"
#include "AboutDialog/AboutDialog.hh"
#include "Actionbar/Actionbar.hh"
#include "AspectFrame/AspectFrame.hh"
#include "Assistant/Assistant.hh"
#include "Box/Box.hh"
#include "Button/Button.hh"
#include "ButtonBox/ButtonBox.hh"
#include "CheckButton/CheckButton.hh"
#include "ComboBox/ComboBox.hh"
#include "ComboBoxText/ComboBoxText.hh"
#include "Dialog/Dialog.hh"
#include "Entry/Entry.hh"
#include "EventBox/EventBox.hh"
#include "Expander/Expander.hh"
#include "FileChooserWidget/FileChooserWidget.hh"
#include "FileChooserDialog/FileChooserDialog.hh"
#include "FileChooserNative/FileChooserNative.hh"
#include "Fixed/Fixed.hh"
#include "FlowBox/FlowBox.hh"
#include "Frame/Frame.hh"
#include "Grid/Grid.hh"
#include "Headerbar/Headerbar.hh"
#include "Image/Image.hh"
#include "Infobar/Infobar.hh"
#include "Label/Label.hh"
#include "Layout/Layout.hh"
#include "Levelbar/Levelbar.hh"
#include "LinkButton/LinkButton.hh"
#include "ListBox/ListBox.hh"
#include "MessageDialog/MessageDialog.hh"
#include "Notebook/Notebook.hh"
#include "Overlay/Overlay.hh"
#include "Paned/Paned.hh"
#include "Popover/Popover.hh"
#include "PopoverMenu/PopoverMenu.hh"
#include "Progressbar/Progressbar.hh"
#include "RadioButton/RadioButton.hh"
#include "Range/Range.hh"
#include "Revealer/Revealer.hh"
#include "Scale/Scale.hh"
#include "ScaleButton/ScaleButton.hh"
#include "Scrollbar/Scrollbar.hh"
#include "ScrolledWindow/ScrolledWindow.hh"
#include "Searchbar/Searchbar.hh"
#include "SearchEntry/SearchEntry.hh"
#include "Separator/Separator.hh"
#include "SpinButton/SpinButton.hh"
#include "Spinner/Spinner.hh"
#include "Stack/Stack/Stack.hh"
#include "Stack/StackSidebar/StackSidebar.hh"
#include "Stack/StackSwitcher/StackSwitcher.hh"
#include "Statusbar/Statusbar.hh"
#include "Switch/Switch.hh"
#include "TextView/TextView.hh"
#include "ToggleButton/ToggleButton.hh"
#include "Toolbar/Toolbar.hh"
#include "ToolItem/ToolItem.hh"
#include "ToolItemGroup/ToolItemGroup.hh"
#include "ToolPalette/ToolPalette.hh"
#include "TreeView/TreeView.hh"
#include "VolumeButton/VolumeButton.hh"
#include "Window/Window.hh"

namespace CGui
{
	class WidgetCast
	{
	public:
		template <typename WidgetType>
		static WidgetType Cast(const CGui::Widget& widget)
		{
			static_assert(false);
		}

		template <>
		static AboutDialog Cast<AboutDialog>(const CGui::Widget& widget);

		template <>
		static Actionbar Cast<Actionbar>(const CGui::Widget& widget);

		template <>
		static AspectFrame Cast<AspectFrame>(const CGui::Widget& widget);

		template <>
		static Assistant Cast<Assistant>(const CGui::Widget& widget);

		template <>
		static Box Cast<Box>(const CGui::Widget& widget);

		template <>
		static Button Cast<Button>(const CGui::Widget& widget);

		template <>
		static ButtonBox Cast<ButtonBox>(const CGui::Widget& widget);

		template <>
		static CheckButton Cast<CheckButton>(const CGui::Widget& widget);

		template <>
		static ComboBox Cast<ComboBox>(const CGui::Widget& widget);

		template <>
		static ComboBoxText Cast<ComboBoxText>(const CGui::Widget& widget);

		template <>
		static Dialog Cast<Dialog>(const CGui::Widget& widget);

		template <>
		static Entry Cast<Entry>(const CGui::Widget& widget);

		template <>
		static EventBox Cast<EventBox>(const CGui::Widget& widget);

		template <>
		static Expander Cast<Expander>(const CGui::Widget& widget);

		template <>
		static FileChooserWidget Cast<FileChooserWidget>(const CGui::Widget& widget);

		template <>
		static FileChooserDialog Cast<FileChooserDialog>(const CGui::Widget& widget);

		template <>
		static FileChooserNative Cast<FileChooserNative>(const CGui::Widget& widget);

		template <>
		static Fixed Cast<Fixed>(const CGui::Widget& widget);

		template <>
		static FlowBox Cast<FlowBox>(const CGui::Widget& widget);

		template <>
		static FlowBox::Child Cast<FlowBox::Child>(const CGui::Widget& widget);

		template <>
		static Frame Cast<Frame>(const CGui::Widget& widget);

		template <>
		static Grid Cast<Grid>(const CGui::Widget& widget);

		template <>
		static Headerbar Cast<Headerbar>(const CGui::Widget& widget);

		template <>
		static Image Cast<Image>(const CGui::Widget& widget);

		template <>
		static Infobar Cast<Infobar>(const CGui::Widget& widget);

		template <>
		static Label Cast<Label>(const CGui::Widget& widget);

		template <>
		static Layout Cast<Layout>(const CGui::Widget& widget);

		template <>
		static Levelbar Cast<Levelbar>(const CGui::Widget& widget);

		template <>
		static LinkButton Cast<LinkButton>(const CGui::Widget& widget);

		template <>
		static ListBox Cast<ListBox>(const CGui::Widget& widget);

		template <>
		static MessageDialog Cast<MessageDialog>(const CGui::Widget& widget);

		template <>
		static Notebook Cast<Notebook>(const CGui::Widget& widget);

		template <>
		static Overlay Cast<Overlay>(const CGui::Widget& widget);

		template <>
		static Paned Cast<Paned>(const CGui::Widget& widget);

		template <>
		static Popover Cast<Popover>(const CGui::Widget& widget);

		template <>
		static PopoverMenu Cast<PopoverMenu>(const CGui::Widget& widget);

		template <>
		static Progressbar Cast<Progressbar>(const CGui::Widget& widget);

		template <>
		static RadioButton Cast<RadioButton>(const CGui::Widget& widget);

		template <>
		static Range Cast<Range>(const CGui::Widget& widget);

		template <>
		static Revealer Cast<Revealer>(const CGui::Widget& widget);

		template <>
		static Scale Cast<Scale>(const CGui::Widget& widget);

		template <>
		static ScaleButton Cast<ScaleButton>(const CGui::Widget& widget);

		template <>
		static Scrollbar Cast<Scrollbar>(const CGui::Widget& widget);

		template <>
		static ScrolledWindow Cast<ScrolledWindow>(const CGui::Widget& widget);

		template <>
		static Searchbar Cast<Searchbar>(const CGui::Widget& widget);

		template <>
		static SearchEntry Cast<SearchEntry>(const CGui::Widget& widget);

		template <>
		static Separator Cast<Separator>(const CGui::Widget& widget);

		template <>
		static SpinButton Cast<SpinButton>(const CGui::Widget& widget);

		template <>
		static Spinner Cast<Spinner>(const CGui::Widget& widget);

		template <>
		static Stack Cast<Stack>(const CGui::Widget& widget);

		template <>
		static StackSidebar Cast<StackSidebar>(const CGui::Widget& widget);

		template <>
		static StackSwitcher Cast<StackSwitcher>(const CGui::Widget& widget);

		template <>
		static Statusbar Cast<Statusbar>(const CGui::Widget& widget);

		template <>
		static Switch Cast<Switch>(const CGui::Widget& widget);

		template <>
		static TextView Cast<TextView>(const CGui::Widget& widget);

		template <>
		static ToggleButton Cast<ToggleButton>(const CGui::Widget& widget);

		template <>
		static Toolbar Cast<Toolbar>(const CGui::Widget& widget);

		template <>
		static ToolItem Cast<ToolItem>(const CGui::Widget& widget);

		template <>
		static ToolItemGroup Cast<ToolItemGroup>(const CGui::Widget& widget);

		template <>
		static ToolPalette Cast<ToolPalette>(const CGui::Widget& widget);

		template <>
		static TreeView Cast<TreeView>(const CGui::Widget& widget);

		template <>
		static VolumeButton Cast<VolumeButton>(const CGui::Widget& widget);

		template <>
		static Window Cast<Window>(const CGui::Widget& widget);
	};

	template<>
	inline AboutDialog WidgetCast::Cast(const CGui::Widget& widget)
	{
		return AboutDialog(GTK_ABOUT_DIALOG(widget.GetWidget()));
	}

	template<>
	inline Actionbar WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Actionbar(GTK_ACTION_BAR(widget.GetWidget()));
	}

	template<>
	inline AspectFrame WidgetCast::Cast(const CGui::Widget& widget)
	{
		return AspectFrame(GTK_ASPECT_FRAME(widget.GetWidget()));
	}

	template<>
	inline Assistant WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Assistant(GTK_ASSISTANT(widget.GetWidget()));
	}

	template<>
	inline Box WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Box(GTK_BOX(widget.GetWidget()));
	}

	template<>
	inline Button WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Button(GTK_BUTTON(widget.GetWidget()));
	}

	template<>
	inline ButtonBox WidgetCast::Cast(const CGui::Widget& widget)
	{
		return ButtonBox(GTK_BUTTON_BOX(widget.GetWidget()));
	}

	template<>
	inline CheckButton WidgetCast::Cast(const CGui::Widget& widget)
	{
		return CheckButton(GTK_CHECK_BUTTON(widget.GetWidget()));
	}

	template<>
	inline ComboBox WidgetCast::Cast(const CGui::Widget& widget)
	{
		return ComboBox(GTK_COMBO_BOX(widget.GetWidget()));
	}

	template<>
	inline ComboBoxText WidgetCast::Cast(const CGui::Widget& widget)
	{
		return ComboBoxText(GTK_COMBO_BOX_TEXT(widget.GetWidget()));
	}

	template<>
	inline Dialog WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Dialog(GTK_DIALOG(widget.GetWidget()));
	}

	template<>
	inline Entry WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Entry(GTK_ENTRY(widget.GetWidget()));
	}

	template<>
	inline EventBox WidgetCast::Cast(const CGui::Widget& widget)
	{
		return EventBox(GTK_EVENT_BOX(widget.GetWidget()));
	}

	template<>
	inline Expander WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Expander(GTK_EXPANDER(widget.GetWidget()));
	}

	template<>
	inline FileChooserWidget WidgetCast::Cast(const CGui::Widget& widget)
	{
		return FileChooserWidget(GTK_FILE_CHOOSER_WIDGET(widget.GetWidget()));
	}

	template<>
	inline FileChooserDialog WidgetCast::Cast(const CGui::Widget& widget)
	{
		return FileChooserDialog(GTK_FILE_CHOOSER_DIALOG(widget.GetWidget()));
	}

	template<>
	inline FileChooserNative WidgetCast::Cast(const CGui::Widget& widget)
	{
		return FileChooserNative(GTK_FILE_CHOOSER_NATIVE(widget.GetWidget()));
	}

	template<>
	inline Fixed WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Fixed(GTK_FIXED(widget.GetWidget()));
	}

	template<>
	inline FlowBox WidgetCast::Cast(const CGui::Widget& widget)
	{
		return FlowBox(GTK_FLOW_BOX(widget.GetWidget()));
	}

	template<>
	inline FlowBox::Child WidgetCast::Cast(const CGui::Widget& widget)
	{
		return FlowBox::Child(GTK_FLOW_BOX_CHILD(widget.GetWidget()));
	}

	template<>
	inline Frame WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Frame(GTK_FRAME(widget.GetWidget()));
	}

	template<>
	inline Grid WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Grid(GTK_GRID(widget.GetWidget()));
	}

	template<>
	inline Headerbar WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Headerbar(GTK_HEADER_BAR(widget.GetWidget()));
	}

	template<>
	inline Image WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Image(GTK_IMAGE(widget.GetWidget()));
	}

	template<>
	inline Infobar WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Infobar(GTK_INFO_BAR(widget.GetWidget()));
	}

	template<>
	inline Label WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Label(GTK_LABEL(widget.GetWidget()));
	}

	template<>
	inline Layout WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Layout(GTK_LAYOUT(widget.GetWidget()));
	}

	template<>
	inline Levelbar WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Levelbar(GTK_LEVEL_BAR(widget.GetWidget()));
	}

	template<>
	inline LinkButton WidgetCast::Cast(const CGui::Widget& widget)
	{
		return LinkButton(GTK_LINK_BUTTON(widget.GetWidget()));
	}

	template<>
	inline ListBox WidgetCast::Cast(const CGui::Widget& widget)
	{
		return ListBox(GTK_LIST_BOX(widget.GetWidget()));
	}

	template<>
	inline MessageDialog WidgetCast::Cast(const CGui::Widget& widget)
	{
		return MessageDialog(GTK_MESSAGE_DIALOG(widget.GetWidget()));
	}

	template<>
	inline Notebook WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Notebook(GTK_NOTEBOOK(widget.GetWidget()));
	}

	template<>
	inline Overlay WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Overlay(GTK_OVERLAY(widget.GetWidget()));
	}

	template<>
	inline Paned WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Paned(GTK_PANED(widget.GetWidget()));
	}

	template<>
	inline Popover WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Popover(GTK_POPOVER(widget.GetWidget()));
	}

	template<>
	inline PopoverMenu WidgetCast::Cast(const CGui::Widget& widget)
	{
		return PopoverMenu(GTK_POPOVER_MENU(widget.GetWidget()));
	}

	template<>
	inline Progressbar WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Progressbar(GTK_PROGRESS_BAR(widget.GetWidget()));
	}

	template<>
	inline RadioButton WidgetCast::Cast(const CGui::Widget& widget)
	{
		return RadioButton(GTK_RADIO_BUTTON(widget.GetWidget()));
	}

	template<>
	inline Range WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Range(GTK_RANGE(widget.GetWidget()));
	}

	template<>
	inline Revealer WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Revealer(GTK_REVEALER(widget.GetWidget()));
	}

	template<>
	inline Scale WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Scale(GTK_SCALE(widget.GetWidget()));
	}

	template<>
	inline ScaleButton WidgetCast::Cast(const CGui::Widget& widget)
	{
		return ScaleButton(GTK_SCALE_BUTTON(widget.GetWidget()));
	}

	template<>
	inline Scrollbar WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Scrollbar(GTK_SCROLLBAR(widget.GetWidget()));
	}

	template<>
	inline ScrolledWindow WidgetCast::Cast(const CGui::Widget& widget)
	{
		return ScrolledWindow(GTK_SCROLLED_WINDOW(widget.GetWidget()));
	}

	template<>
	inline Searchbar WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Searchbar(GTK_SEARCH_BAR(widget.GetWidget()));
	}

	template<>
	inline SearchEntry WidgetCast::Cast(const CGui::Widget& widget)
	{
		return SearchEntry(GTK_SEARCH_ENTRY(widget.GetWidget()));
	}

	template<>
	inline Separator WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Separator(GTK_SEPARATOR(widget.GetWidget()));
	}

	template<>
	inline SpinButton WidgetCast::Cast(const CGui::Widget& widget)
	{
		return SpinButton(GTK_SPIN_BUTTON(widget.GetWidget()));
	}

	template<>
	inline Spinner WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Spinner(GTK_SPINNER(widget.GetWidget()));
	}

	template<>
	inline Stack WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Stack(GTK_STACK(widget.GetWidget()));
	}

	template<>
	inline StackSidebar WidgetCast::Cast(const CGui::Widget& widget)
	{
		return StackSidebar(GTK_STACK_SIDEBAR(widget.GetWidget()));
	}

	template<>
	inline StackSwitcher WidgetCast::Cast(const CGui::Widget& widget)
	{
		return StackSwitcher(GTK_STACK_SWITCHER(widget.GetWidget()));
	}

	template<>
	inline Statusbar WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Statusbar(GTK_STATUSBAR(widget.GetWidget()));
	}

	template<>
	inline Switch WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Switch(GTK_SWITCH(widget.GetWidget()));
	}

	template<>
	inline TextView WidgetCast::Cast(const CGui::Widget& widget)
	{
		return TextView(GTK_TEXT_VIEW(widget.GetWidget()));
	}

	template<>
	inline ToggleButton WidgetCast::Cast(const CGui::Widget& widget)
	{
		return ToggleButton(GTK_TOGGLE_BUTTON(widget.GetWidget()));
	}

	template<>
	inline Toolbar WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Toolbar(GTK_TOOLBAR(widget.GetWidget()));
	}

	template<>
	inline ToolItem WidgetCast::Cast(const CGui::Widget& widget)
	{
		return ToolItem(GTK_TOOL_ITEM(widget.GetWidget()));
	}

	template<>
	inline ToolItemGroup WidgetCast::Cast(const CGui::Widget& widget)
	{
		return ToolItemGroup(GTK_TOOL_ITEM_GROUP(widget.GetWidget()));
	}

	template<>
	inline ToolPalette WidgetCast::Cast(const CGui::Widget& widget)
	{
		return ToolPalette(GTK_TOOL_PALETTE(widget.GetWidget()));
	}

	template<>
	inline TreeView WidgetCast::Cast(const CGui::Widget& widget)
	{
		return TreeView(GTK_TREE_VIEW(widget.GetWidget()));
	}

	template<>
	inline VolumeButton WidgetCast::Cast(const CGui::Widget& widget)
	{
		return VolumeButton(GTK_VOLUME_BUTTON(widget.GetWidget()));
	}

	template<>
	inline Window WidgetCast::Cast(const CGui::Widget& widget)
	{
		return Window(GTK_WINDOW(widget.GetWidget()));
	}
}