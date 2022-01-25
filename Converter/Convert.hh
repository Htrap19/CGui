#pragma once

#include <gtk/gtk.h>
#include <vector>

#ifndef nameof
#define nameof(name) CGui::Converter::Convert::RetName(#name)
#endif

namespace CGui
{
	enum class WindowType { TOPLEVEL, POPUP };
	enum class WindowPos { NONE, CENTER, MOUSE, CENTER_ALWAYS, CENTER_ON_PARENT };

	enum class Orientation { HORIZONTAL, VERTICAL };
	enum class PackType { START, END };
	struct ChildPackingInfo
	{
		PackType pack_type;
		bool expand;
		bool fill;
		unsigned int padding;
	};

	enum class Alignments { FILL, BEGIN, LAST, CENTER, BASELINE };
	struct AlignmentsData
	{
		Alignments halign;
		Alignments valign;
	};

	enum class Events { EVENT, DELETE, BUTTON_PRESS, BUTTON_RELEASE, SCROLL, MOTION_NOTIFY, EXPOSE, KEY_PRESS, KEY_RELEASE, ENTER_NOTIFY, LEAVE_NOTIFY, CONFIGURE, FOCUS_IN, FOCUS_OUT, MAP, UNMAP, PROPERTY_NOTIFY, SELECTION_CLEAR, SELECTION_REQUEST, SELECTION_NOTIFY, PROXIMITY_IN, PROXIMITY_OUT, VISIBLITY_NOTIFY, CLIENT, NO_EXPOSE, WINDOW_STATE, SELECTION_RECEIVED, SELECTION_GET, DRAG_BEGIN, DRAG_END, DRAG_DATA_DELETE, DRAG_MOTION, DRAG_DROP, DRAG_DATA_GET, DRAG_DATA_RECEIVED };

	enum class Signals { CLICKED, TOGGLED, CHANGED, ENTER, ACTIVATE, DESTROY, RESPONSE, CLOSE, CANCEL };

	enum class ReliefStyle { NORMAL = 0, NONE = 2 };

	enum class PositionType { LEFT, RIGHT, TOP, BOTTOM };

	enum class RevealerTransition { NONE, CROSSFADE, SLIDE_RIGHT, SLIDE_LEFT, SLIDE_UP, SLIDE_DOWN };

	enum class MessageType { INFO, WARNING, QUESTION, ERROR, OTHER };

	enum class Policy { ALWAYS, AUTOMATIC, NEVER, EXTERNAL };
	struct PolicyInfo
	{
		Policy hpolicy;
		Policy vpolicy;
	};

	enum class FileChooserAction { OPEN, SAVE, SELECT_FOLDER, CREATE_FOLDER };

	enum class Priority : unsigned short { FALLBACK = 1, THEME = 200, SETTINGS = 400, APPLICATION = 600, USER = 800 };

	enum class BaselinePosition { TOP, CENTER, BOTTOM };

	enum class EntryIconPosition { PRIMARY, SECONDARY };
	enum class InputPurpose { FREE_FORM, ALPHA, DIGITS, NUMBER, PHONE, URL, EMAIL, NAME, PASSWORD, PIN, TERMINAL };
	enum class InputHints { NONE, SPELLCHECK, NO_SPELLCHECK, WORD_COMPLETION, LOWERCASE, UPPERCASE_CHARS, UPPERCASE_WORDS, UPPERCASE_SENTENCES, INHIBIT_OSK, VERTICAL_WRITING, EMOJI, NO_EMOJI };

	enum class IconSize { INVALID, MENU, SMALL_TOOLBAR, LARGE_TOOLBAR, BUTTON, DND, DIALOG };
	enum class ImageType { EMPTY, PIXBUF, STOCK, ICON_SET, ANIMATION, ICON_NAME, GICON, SURFACE };
	struct IconInfo
	{
		const char* icon_name;
		IconSize size;
	};

	enum class PixbufRotation : unsigned short { NONE = 0, COUNTERCLOCKWISE = 90, UPSIDEDOWN = 180, CLOCKWISE = 270 };
	enum class InterpType { NEAREST, TITLES, BILINEAR, HYPER };

	enum class Justification { LEFT, RIGHT, CENTER, FILL };
	enum class EllipsizeMode { NONE, START, MIDDLE, END };
	enum class WrapMode { NONE, WORD, CHAR, WORD_CHAR };

	enum class CornerType { TOP_LEFT, BOTTOM_LEFT, TOP_RIGHT, BOTTOM_RIGHT };
	enum class ShadowType { NONE, IN, OUT, ETCHED_IN, ETCHED_OUT };

	enum class StateFlags { NORMAL, ACTIVE, PRELIGHT, SELECTED, INSENSITIVE, INCONSISTENT, FOCUSED, BACKDROP, DIR_LTR, DIR_RTL, LINK, VISITED, CHECKED, DROP_ACTIVE };

	struct CoordinatesInfo
	{
		int x, y;
	};

	enum class TextDirection { NONE, LTR, RTL };
	enum class DirectionType { TAB_FORWARD, TAB_BACKWARD, UP, DOWN, LEFT, RIGHT };

	template <typename Key, typename Value>
	struct KeyValueData
	{
		Key key;
		Value value;
		unsigned int index;
	};

	struct PreferredHeightData
	{
		int minimum_height;
		int natural_height;
	};

	struct PreferredWidthData
	{
		int minimum_width;
		int natural_width;
	};

	struct PreferredBaselineData
	{
		int minimum_baseline;
		int natural_baseline;
	};

	struct HeightAndBaslineData
	{
		PreferredHeightData height;
		PreferredBaselineData baseline;
	};

	struct Requisition
	{
		int width, height;
	};

	struct PreferredSizeData
	{
		Requisition minimum_size, natural_size;
	};

	struct Margin
	{
		int start, end, top, bottom;
	};

	struct Expand
	{
		bool hexpand, vexpand;
	};

	enum class SizeRequestMode { HEIGHT_FOR_WIDTH, WIDTH_FOR_HEIGHT, CONSTANT_SIZE };

	enum class Gravity { NORTH_WEST = 1, NORTH, NORTH_EAST, WEST, CENTER, EAST, SOUTH_WEST, SOUTH, SOUTH_EAST, STATIC };

	struct WindowPositionData
	{
		int root_x;
		int root_y;
	};

	enum class DialogFlags { MODAL = 1 << 0, DESTORY_WITH_PARENT = 1 << 1, USE_HEADER_BAR = 1 << 2 };

	enum class ButtonsType { NONE, OK, CLOSE, CANCEL, YES_NO, OK_CANCEL };

	enum class ResponseType { NONE = -1, REJECT = -2, ACCEPT = -3, DELETE = -4, OK = -5, CANCEL = -6, CLOSE = -7, YES = -8, NO = -9, APPLY = -10, HELP = -11 };

	enum class AssistantPageType { CONTENT, INTRO, CONFIRM, SUMMARY, PROGRESS, CUSTOM };

	enum class ButtonBoxStyle { SPREAD = 1, EDGE, START, END, CENTER, EXPAND };

	enum class StackTransitionType { NONE, CROSSFADE, SLIDE_RIGHT, SLIDE_LEFT, SLIDE_UP, SLIDE_DOWN, SLIDE_LEFT_RIGHT, SLIDE_UP_DOWN, OVER_UP, OVER_DOWN, OVER_LEFT, OVER_RIGHT, UNDER_UP, UNDER_DOWN, UNDER_LEFT, UNDER_RIGHT, OVER_UP_DOWN, OVER_DOWM_UP, OVER_LEFT_RIGHT, OVER_RIGHT_LEFT };

	struct AlignData
	{
		float xalign, yalign;
	};

	enum class LevelbarMode { CONTINUOUS, DISCRETE };

	struct LevelbarOffsetData
	{
		bool found;
		double value;
	};

	struct SelectionBoundsData
	{
		bool found;
		int start_pos, end_pos;
	};

	enum class License { UNKNOWN, CUSTOM, GPL_2_0, GPL_3_0, LGPL_2_1, LGPL_3_0, BSD, MIT_X11, ARTISTIC, GPL_2_0_ONLY, GPL_3_0_ONLY, AGPL_3_0, AGPL_3_0_ONLY, BSD_3, APACHE_2_0, MPL_2_0 };

	enum class SensitivityType { AUTO, ON, OFF };

	struct SliderRangeData
	{
		int slider_start, slider_end;
	};

	enum class ScrollablePolicy { MINIMUM = 0, NATURAL };

	struct Border
	{
		signed short left;
		signed short right;
		signed short top;
		signed short bottom;
	};

	enum class ToolbarStyle { ICONS, TEXT, BOTH, BOTH_HORIZ };

	enum class SizeGroupMode { NONE, VERTICAL, HORIZONTAL, BOTH };

	enum class DestDefaults { MOTION = 1 << 0, HIGHLIGHT = 1 << 1, DROP = 1 << 2, ALL = 0x07 };

	enum class ToolPaletteDragTargets { ITEMS = (1 << 0), GROUPS = (1 << 1) };

	enum class DragAction { DEFAULT = 1 << 0, COPY = 1 << 1, MOVE = 1 << 2, LINK = 1 << 3, PRIVATE = 1 << 4, ASK = 1 << 5 };

	enum class SpinButtonUpdatePolicy { ALWAYS, IF_VALID };

	enum class SpinType { STEP_FORWARD, STEP_BACKWARD, PAGE_FORWARD, PAGE_BACKWARD, HOME, END, USER_DEFINED };

	struct IncrementsData
	{
		double step, page;
	};

	struct RangeData
	{
		double min, max;
	};

	enum class SelectionMode { NONE, SINGLE, BROWSE, MULTIPLE };

	struct IndicesAndDepthData
	{
		int* indices;
		int* depth;
	};

	enum class TreeModelFlags { ITERS_PERSIST = 1 << 0, LIST_ONLY = 1 << 1 };

	enum class AccelFlags { VISIBLE = 1 << 0, LOCKED = 1 << 1, MASK = 0x07 };

	enum class ModifierType { SHIFT_MASK = 1 << 0, LOCK_MASK = 1 << 1, CONTROL_MASK = 1 << 2, MOD1_MASK = 1 << 3, MOD2_MASK = 1 << 4, MOD3_MASK = 1 << 5, MOD4_MASK = 1 << 6, MOD5_MASK = 1 << 7, BUTTON1_MASK = 1 << 8, BUTTON2_MASK = 1 << 9, BUTTON3_MASK = 1 << 10, BUTTON4_MASK = 1 << 11, BUTTON5_MASK = 1 << 12, MODIFIER_RESERVED_13_MASK = 1 << 13, MODIFIER_RESERVED_14_MASK = 1 << 14, MODIFIER_RESERVED_15_MASK = 1 << 15, MODIFIER_RESERVED_16_MASK = 1 << 16, MODIFIER_RESERVED_17_MASK = 1 << 17, MODIFIER_RESERVED_18_MASK = 1 << 18, MODIFIER_RESERVED_19_MASK = 1 << 19, MODIFIER_RESERVED_20_MASK = 1 << 20, MODIFIER_RESERVED_21_MASK = 1 << 21, MODIFIER_RESERVED_22_MASK = 1 << 22, MODIFIER_RESERVED_23_MASK = 1 << 23, MODIFIER_RESERVED_24_MASK = 1 << 24, MODIFIER_RESERVED_25_MASK = 1 << 25, SUPER_MASK = 1 << 26, HYPER_MASK = 1 << 27, META_MASK = 1 << 28, MODIFIER_RESERVED_29_MASK = 1 << 29, RELEASE_MASK = 1 << 30, MODIFIER_MASK = 0x5c001fff };

	struct AcceleratorParseData
	{
		unsigned int accelerator_key;
		ModifierType accelerator_mods;
	};

	struct AcceleratorParseWithKeyCode
	{
		unsigned int accelerator_key;
		unsigned int* accelerator_codes;
		ModifierType accelerator_mods;
	};

	struct Rectangle
	{
		CoordinatesInfo coord_info;
		Requisition requisition;
	};

	enum class TextWindowType { PRVIATE, WIDGET, TEXT, LEFT, RIGHT, TOP, BOTTOM };

	struct PointingToData
	{
		bool was_set;
		Rectangle rect;
	};

	enum class PopoverConstraint { NONE, WINDOW };

	enum class Type { INVALID = G_TYPE_INVALID, NONE = G_TYPE_NONE, INTERFACE = G_TYPE_INTERFACE, CHAR = G_TYPE_CHAR, UCHAR = G_TYPE_UCHAR, BOOLEAN = G_TYPE_BOOLEAN, INT = G_TYPE_INT, UINT = G_TYPE_UINT, LONG = G_TYPE_LONG, ULONG = G_TYPE_ULONG, INT64 = G_TYPE_INT64, UINT64 = G_TYPE_UINT64, ENUM = G_TYPE_ENUM, FLAGS = G_TYPE_FLAGS, FLOAT = G_TYPE_FLOAT, DOUBLE = G_TYPE_DOUBLE, STRING = G_TYPE_STRING, POINTER = G_TYPE_POINTER, BOXED = G_TYPE_BOXED, PARAM = G_TYPE_PARAM, OBJECT = G_TYPE_OBJECT, VARIANT = G_TYPE_VARIANT, PIXBUF = 100 };

	static std::vector<GType> MakeGType(std::vector<Type> types)
	{
		std::vector<GType> gtypes;
		for (auto& type : types)
		{
			if (type == Type::PIXBUF)
				gtypes.push_back((GType)gdk_pixbuf_get_type());
			else
				gtypes.push_back((GType)type);
		}
		return std::move(gtypes);
	}

	enum class CellRendererState { SELECTED = 1 << 0, PRELIT = 1 << 1, INSENSITIVE = 1 << 2, SORTED = 1 << 3, FOCUSED = 1 << 4, EXPANDABLE = 1 << 5, EXPANDED = 1 << 6 };

	enum class CellRenderersTypes { TEXT };

	struct PaddingData
	{
		int xpad;
		int ypad;
	};

	enum class TreeViewColumnSizing { GROW_ONLY, AUTOSIZE, FIXED };

	enum class SortType { ASCENDING, DESCENDING };

	struct CellPositionData
	{
		int x_offset, width;
		bool belongs_to;
	};

	enum class TreeViewDropPosition { DROP_BEFORE, DROP_AFTER, DROP_INTO_OR_BEFORE, DROP_INTO_OR_AFTER };

	enum class TreeViewGridLines { NONE, HORIZONTAL, VERTICAL, BOTH };

	class Value
	{
	public:
		static bool type_compatible(Type src_type, Type dest_type)
		{
			return g_value_type_compatible((GType)src_type, (GType)dest_type);
		}

		static bool type_transformable(Type src_type, Type dest_type)
		{
			return g_value_type_transformable((GType)src_type, (GType)dest_type);
		}

		static bool transform(Value src_value, Value dest_value)
		{
			return g_value_transform(src_value.GetGValue(), dest_value.GetGValue());
		}

		Value(const Value& src)
		{
			g_value_copy(const_cast<Value&>(src).GetGValue(), ins);
		}

		Value(const Value&& src) noexcept
		{
			auto src_object = const_cast<Value&&>(src).GetGValue();
			this->ins = src_object;
			src_object = nullptr;
		}

		Value(GValue* value)
		{
			this->ins = value;
		}

		Value(Type type)
		{
			this->ins = g_value_init(ins, (GType)type);
		}

		Value(void* instance)
		{
			g_value_init_from_instance(ins, instance);
		}

		~Value()
		{
			this->unset();
		}

		void reset()
		{
			this->ins = g_value_reset(ins);
		}

		void unset()
		{
			g_value_unset(ins);
		}

		void instance(void* instance)
		{
			g_value_set_instance(ins, instance);
		}

		bool fits_pointer(const Value& value)
		{
			return g_value_fits_pointer(const_cast<Value&>(value).GetGValue());
		}

		bool peek_pointer(const Value& value)
		{
			return g_value_peek_pointer(const_cast<Value&>(value).GetGValue());
		}

		GValue* GetGValue()
		{
			return ins;
		}

		const char* strdup_value_contents()
		{
			return g_strdup_value_contents(ins);
		}

	private:
		GValue* ins;
	};

	namespace Converter
	{
		class Convert
		{
		public:
			/*std::variant<GtkAlign, GtkOrientation, GtkWindowType, GtkWindowPosition, GtkRevealerTransitionType, GtkMessageType, GtkPolicyType, GtkFileChooserAction, const char*> ConvertToGtkCode(std::variant<Alignments, BoxType, WindowType, WindowPos, Transition, MessageType, Events, Policy, Action> data)
			{
				std::variant<GtkAlign, GtkOrientation, GtkWindowType, GtkWindowPosition, GtkRevealerTransitionType, GtkMessageType, GtkPolicyType, GtkFileChooserAction, const char*> retValue;
				if (data.index() == 0)
					return GetGtkCode(std::get<Alignments>(data));
				else if (data.index() == 1)
					return GetGtkCode(std::get<BoxType>(data));
				else if (data.index() == 2)
					return GetGtkCode(std::get<WindowType>(data));
				else if (data.index() == 3)
					return GetGtkCode(std::get<WindowPos>(data));
				else if (data.index() == 4)
					return GetGtkCode(std::get<RevealerTransition>(data));
				else if (data.index() == 5)
					return GetGtkCode(std::get<MessageType>(data));
				else if (data.index() == 6)
					return GetGtkCode(std::get<Events>(data));
				else if (data.index() == 7)
					return GetGtkCode(std::get<Policy>(data));
				else if (data.index() == 8)
					return GetGtkCode(std::get<Action>(data));
				return retValue;
			}*/

			GdkRectangle ConvertFromRectangle(Rectangle rect)
			{
				GdkRectangle retValue;
				retValue.x = rect.coord_info.x;
				retValue.y = rect.coord_info.y;
				retValue.width = rect.requisition.width;
				retValue.height = rect.requisition.height;

				return retValue;
			}

			static const char* RetName(const char* name)
			{
				return name;
			}

			const char* GetGtkCode(CellRenderersTypes type)
			{
				switch (type)
				{
				case CGui::CellRenderersTypes::TEXT:
					return "text";
					break;

				default:
					return "text";
					break;
				}
			}

			const char* GetGtkCode(Signals signals)
			{
				switch (signals)
				{
				case Signals::CLICKED:
					return "clicked";
					break;

				case Signals::TOGGLED:
					return "toggled";
					break;

				case Signals::CHANGED:
					return "changed";
					break;

				case Signals::ENTER:
					return "enter";
					break;

				case Signals::ACTIVATE:
					return "activate";
					break;

				case Signals::DESTROY:
					return "destroy";
					break;

				case Signals::RESPONSE:
					return "response";
					break;

				case Signals::CLOSE:
					return "close";
					break;

				case Signals::CANCEL:
					return "cancel";
					break;

				default:
					return NULL;
				}
			}

			const char* GetGtkCode(Events event)
			{
				switch (event)
				{
				case Events::EVENT:
					return "event";
					break;

				case Events::DELETE:
					return "delete-event";
					break;

				case Events::BUTTON_PRESS:
					return "button_press_event";
					break;

				case Events::BUTTON_RELEASE:
					return "button_release_event";
					break;

				case Events::SCROLL:
					return "scroll_event";
					break;

				case Events::MOTION_NOTIFY:
					return "motion_notify_event";
					break;

				case Events::EXPOSE:
					return "expose_event";
					break;

				case Events::KEY_PRESS:
					return "key_press_event";
					break;

				case Events::KEY_RELEASE:
					return "key_release_event";
					break;

				case Events::ENTER_NOTIFY:
					return "enter_notify_event";
					break;

				case Events::LEAVE_NOTIFY:
					return "leave_notify_event";
					break;

				case Events::CONFIGURE:
					return "configure_event";
					break;

				case Events::FOCUS_IN:
					return "focus_in_event";
					break;

				case Events::FOCUS_OUT:
					return "focus_out_event";
					break;

				case Events::MAP:
					return "map_event";
					break;

				case Events::UNMAP:
					return "unmap_event";
					break;

				case Events::PROPERTY_NOTIFY:
					return "property_notify_event";
					break;

				case Events::SELECTION_CLEAR:
					return "selection_clear_event";
					break;

				case Events::SELECTION_REQUEST:
					return "selection_request_event";
					break;

				case Events::SELECTION_NOTIFY:
					return "selection_notify_event";
					break;

				case Events::PROXIMITY_IN:
					return "proximity_in_event";
					break;

				case Events::PROXIMITY_OUT:
					return "proximity_out_event";
					break;

				case Events::VISIBLITY_NOTIFY:
					return "visibility_notify_event";
					break;

				case Events::CLIENT:
					return "client_event";
					break;

				case Events::NO_EXPOSE:
					return "no_expose_event";
					break;

				case Events::WINDOW_STATE:
					return "window_state_event";
					break;

				case Events::SELECTION_RECEIVED:
					return "selection_received";
					break;

				case Events::SELECTION_GET:
					return "selection_get";
					break;

				case Events::DRAG_BEGIN:
					return "drag_begin_event";
					break;

				case Events::DRAG_END:
					return "drag_end_event";
					break;

				case Events::DRAG_DATA_DELETE:
					return "drag_data_delete";
					break;

				case Events::DRAG_MOTION:
					return "drag_motion";
					break;

				case Events::DRAG_DROP:
					return "drag_drop";
					break;

				case Events::DRAG_DATA_GET:
					return "drag_data_get";
					break;

				case Events::DRAG_DATA_RECEIVED:
					return "drag_data_received";
					break;

				default:
					return NULL;
				}
			}

			auto BoxFuncPtr(PackType type)
			{
				switch (type)
				{
				case PackType::START:
					return gtk_box_pack_start;
					break;

				case PackType::END:
					return gtk_box_pack_end;
					break;

				default:
					return gtk_box_pack_start;
				}
			}

			auto HeaderbarFuncPtr(PackType type)
			{
				switch (type)
				{
				case PackType::START:
					return gtk_header_bar_pack_start;
					break;
				case PackType::END:
					return gtk_header_bar_pack_end;
					break;

				default:
					return gtk_header_bar_pack_start;
				}
			}

			auto ActionbarFuncPtr(PackType type)
			{
				switch (type)
				{
				case PackType::START:
					return gtk_action_bar_pack_start;
					break;

				case PackType::END:
					return gtk_action_bar_pack_end;
					break;

				default:
					return gtk_action_bar_pack_start;
					break;
				}
			}

			static Convert& GetInstance()
			{
				static Convert instance;
				return instance;
			}

			Convert(const Convert&) = delete;
			Convert(const Convert&&) = delete;
			Convert& operator=(const Convert&) = delete;

		private:
			Convert()
			{  }

			/*GtkFileChooserAction GetGtkCode(Action action)
			{
				switch (action)
				{
				case Action::OPEN:
					return GTK_FILE_CHOOSER_ACTION_OPEN;
					break;
				case Action::SAVE:
					return GTK_FILE_CHOOSER_ACTION_SAVE;
					break;
				case Action::SELECT_FOLDER:
					return GTK_FILE_CHOOSER_ACTION_SELECT_FOLDER;
					break;
				case Action::CREATE_FOLDER:
					return GTK_FILE_CHOOSER_ACTION_CREATE_FOLDER;
					break;

				default:
					return GTK_FILE_CHOOSER_ACTION_OPEN;
				}
			}

			GtkPolicyType GetGtkCode(Policy policy)
			{
				switch (policy)
				{
				case Policy::AUTOMATIC:
					return GTK_POLICY_AUTOMATIC;
					break;
				case Policy::NEVER:
					return GTK_POLICY_NEVER;
					break;
				case Policy::ALWAYS:
					return GTK_POLICY_ALWAYS;
					break;

				default:
					return GTK_POLICY_AUTOMATIC;
				}
			}

			GtkMessageType GetGtkCode(MessageType messagetype)
			{
				switch (messagetype)
				{
				case MessageType::INFO:
					return GTK_MESSAGE_INFO;
					break;
				case MessageType::WARNING:
					return GTK_MESSAGE_WARNING;
					break;
				case MessageType::QUESTION:
					return GTK_MESSAGE_QUESTION;
					break;
				case MessageType::ERROR:
					return GTK_MESSAGE_ERROR;
					break;
				case MessageType::OTHER:
					return GTK_MESSAGE_OTHER;
					break;

				default:
					return GTK_MESSAGE_OTHER;
				}
			}

			GtkRevealerTransitionType GetGtkCode(RevealerTransition transition)
			{
				switch (transition)
				{
				case RevealerTransition::SLIDE_UP:
					return GTK_REVEALER_TRANSITION_TYPE_SLIDE_UP;
					break;
				case RevealerTransition::SLIDE_DOWN:
					return GTK_REVEALER_TRANSITION_TYPE_SLIDE_DOWN;
					break;
				case RevealerTransition::SLIDE_LEFT:
					return GTK_REVEALER_TRANSITION_TYPE_SLIDE_LEFT;
					break;
				case RevealerTransition::SLIDE_RIGHT:
					return GTK_REVEALER_TRANSITION_TYPE_SLIDE_RIGHT;
					break;
				case RevealerTransition::CROSSFADE:
					return GTK_REVEALER_TRANSITION_TYPE_CROSSFADE;
					break;

				default:
					return GTK_REVEALER_TRANSITION_TYPE_NONE;
				}
			}

			const char *GetGtkCode(Events event)
			{
				switch (event)
				{
				case Events::CLICKED:
					return "clicked";
					break;
				case Events::DELETE:
					return "delete-event";
					break;
				case Events::TOGGLED:
					return "toggled";
					break;
				case Events::CHANGED:
					return "changed";
					break;
				case Events::ENTER:
					return "enter";
					break;
				case Events::ACTIVATE:
					return "activate";
					break;

				default:
					return "changed";
				}
			}

			GtkWindowType GetGtkCode(WindowType data)
			{
				switch (data)
				{
				case WindowType::TOPLEVEL:
					return GTK_WINDOW_TOPLEVEL;
				break;
				case WindowType::POPUP:
					return GTK_WINDOW_POPUP;
				break;

				default:
					return GTK_WINDOW_TOPLEVEL;
				}
			}

			GtkWindowPosition GetGtkCode(WindowPos data)
			{
				switch (data)
				{
				case WindowPos::CENTER:
					return GTK_WIN_POS_CENTER;
					break;
				case WindowPos::MOUSE:
					return GTK_WIN_POS_MOUSE;
					break;
				case WindowPos::CENTER_ALWAYS:
					return GTK_WIN_POS_CENTER_ALWAYS;

				default:
					return GTK_WIN_POS_CENTER;
				}
			}

			GtkAlign GetGtkCode(Alignments data)
			{
				switch (data)
				{
				case Alignments::BEGIN:
					return GTK_ALIGN_START;
				break;
				case Alignments::FILL:
					return GTK_ALIGN_FILL;
				break;
				case Alignments::LAST:
					return GTK_ALIGN_END;
				break;
				case Alignments::CENTER:
					return GTK_ALIGN_CENTER;
				break;

				default:
					return GTK_ALIGN_CENTER;
				}
			}

			GtkOrientation GetGtkCode(BoxType data)
			{
				switch (data)
				{
				case BoxType::VER:
					return GTK_ORIENTATION_VERTICAL;
				break;
				case BoxType::HOR:
					return GTK_ORIENTATION_HORIZONTAL;
				break;

				default:
					return GTK_ORIENTATION_VERTICAL;
				}
			}*/
		};
	}
}
