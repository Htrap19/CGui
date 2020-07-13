#pragma once

#include <gtk/gtk.h>

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

	enum class Events { EVENT, BUTTON_PRESS, BUTTON_RELEASE, SCROLL, MOTION_NOTIFY, EXPOSE, KEY_PRESS, KEY_RELEASE, ENTER_NOTIFY, LEAVE_NOTIFY, CONFIGURE, FOCUS_IN, FOCUS_OUT, MAP, UNMAP, PROPERTY_NOTIFY, SELECTION_CLEAR, SELECTION_REQUEST, SELECTION_NOTIFY, PROXIMITY_IN, PROXIMITY_OUT, VISIBLITY_NOTIFY, CLIENT, NO_EXPOSE, WINDOW_STATE, SELECTION_RECEIVED, SELECTION_GET, DRAG_BEGIN, DRAG_END, DRAG_DATA_DELETE, DRAG_MOTION, DRAG_DROP, DRAG_DATA_GET, DRAG_DATA_RECEIVED };

	enum class Signals { CLICKED, DELETE, TOGGLED, CHANGED, ENTER, ACTIVATE, DESTROY, RESPONSE, CLOSE, CANCEL };

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
	enum class WrapMode { WORD, CHAR, WORD_CHAR };

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

	struct WidgetMargin
	{
		int start, end, top, bottom;
	};

	struct WidgetExpand
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

	struct LabelAlignData
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

			static const char* RetName(const char* name)
			{
				return name;
			}

			const char* GetGtkCode(Signals signals)
			{
				switch (signals)
				{
				case Signals::CLICKED:
					return "clicked";
					break;

				case Signals::DELETE:
					return "delete-event";
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
