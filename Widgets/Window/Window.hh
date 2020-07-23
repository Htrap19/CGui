#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../Headerbar/Headerbar.hh"
#include "../../Pixbuf/Pixbuf/Pixbuf.hh"

namespace CGui
{
	class Window : public Widget, public Container<Window>
	{
	public:
		Window(WindowType type, const char* title, WindowPos pos);
		Window(GtkWindow* window);
		void Icon(const char* filename);
		void DefaultSize(unsigned int width, unsigned int height);
		Requisition DefaultSize();
		void Headerbar(CGui::Headerbar& hb);
		CGui::Headerbar Headerbar();
		void Resizable(bool resizable);
		bool Resizable();
		void Title(const char* title);
		const char* Title();
		void Maximize();
		bool IsMaximized();
		void Unmaximize();
		void Fullscreen();
		void Unfullscreen();
		void IConify();
		void Deiconify();
		void Position(WindowPos pos);
		WindowPositionData Position();
		bool ActivateFocus();
		bool ActivateDefault();
		void Modal(bool modal);
		bool Modal();
		void Gravity(CGui::Gravity gravity);
		CGui::Gravity Gravity();
		void TransientFor(Window& parent);
		Window TransientFor();
		void AttachedTo(Widget& attach_widget);
		Widget AttachedTo();
		void DestroyWithParent(bool destroy);
		bool DestroywithParent();
		void HideHeaderbarWhenMaximized(bool hide);
		bool HideHeaderbarWhenMaximized();
		bool IsActive();
		bool HasToplevelFocus();
		Single::List<Window*> ListToplevels();
		void Focus(Widget& focus);
		Widget Focus();
		void DefaultWidget(Widget& default_widget);
		Widget DefaultWidget();
		void Present();
		void Close();
		void Stick();
		void Unstick();
		void KeepAbove(bool keep_above);
		void KeepBelow(bool keep_below);
		void Decorated(bool decorated);
		bool Decorated();
		void Deletable(bool deleteable);
		bool Deletable();
		void SkipTaskbarHint(bool skip);
		bool SkipTaskbarHint();
		void SkipPagerHint(bool skip);
		bool SkipPagerHint();
		void UrgencyHint(bool urgency);
		bool UrgencyHint();
		void AcceptFocus(bool accept);
		bool AcceptFocus();
		void FocusOnMap(bool focus);
		bool FocusOnMap();
		void StartupId(const char* startup_id);
		void Icon(Pixbuf& icon);
		Pixbuf Icon();
		void IconList(Single::List<Pixbuf*>& list);
		Single::List<Pixbuf*> IconList();
		void Iconname(const char* iconname);
		const char* Iconname();
		Requisition Size();
		WindowType Type();
		void Move(int x, int y);
		void Resize(int width, int height);
		void FocusVisible(bool visible);
		bool FocusVisible();
		void HasUserRefCount(bool has);

		static void DefaultIconList(Single::List<Pixbuf*>& list);
		static Single::List<Pixbuf*> DefaultIconList();
		static void DefaultIconname(const char* name);
		static const char* DefaultIconname();
		static void AutoStartupNotification(bool setting);
		static void InteractiveDebugging(bool enable);

		void ErrorMessage();
		bool HasError();

	protected:
		GError* error;
		Window();

		void SetWindow(GtkWindow* window);

	private:
		static unsigned int m_ref_count;
	};
}
