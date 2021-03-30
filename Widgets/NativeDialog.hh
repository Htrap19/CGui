#pragma once

#include <gtk/gtk.h>
#include "./Window/Window.hh"

namespace CGui
{
	class NativeDialog
	{
	public:
		NativeDialog(GtkNativeDialog* dialog)
		{
			this->SetNativeDialog(dialog);
		}

		virtual void Show()
		{
			gtk_native_dialog_show(m_NativeDialog);
		}

		virtual void Hide()
		{
			gtk_native_dialog_hide(m_NativeDialog);
		}

		virtual void Destroy()
		{
			gtk_native_dialog_destroy(m_NativeDialog);
		}

		virtual bool Visible()
		{
			return gtk_native_dialog_get_visible(m_NativeDialog);
		}

		virtual void Modal(bool modal)
		{
			gtk_native_dialog_set_modal(m_NativeDialog, modal);
		}

		virtual bool Modal()
		{
			return gtk_native_dialog_get_modal(m_NativeDialog);
		}

		virtual void Title(const char* title)
		{
			gtk_native_dialog_set_title(m_NativeDialog, title);
		}

		virtual const char* Title()
		{
			return gtk_native_dialog_get_title(m_NativeDialog);
		}

		virtual void TransientFor(Window& window)
		{
			gtk_native_dialog_set_transient_for(m_NativeDialog, GTK_WINDOW(window.GetWidget()));
		}

		virtual Window TransientFor()
		{
			return Window(gtk_native_dialog_get_transient_for(m_NativeDialog));
		}

		virtual ResponseType Run()
		{
			return (ResponseType)gtk_native_dialog_run(m_NativeDialog);
		}

		bool IsNativeDialog()
		{
			return GTK_IS_NATIVE_DIALOG(m_NativeDialog);
		}

	protected:
		NativeDialog() : m_NativeDialog{nullptr}
		{
		}

		void SetNativeDialog(GtkNativeDialog* dialog)
		{
			this->m_NativeDialog = dialog;
		}

		GtkNativeDialog* m_NativeDialog;
	};
}