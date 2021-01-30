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
			gtk_native_dialog_show(dialog);
		}

		virtual void Hide()
		{
			gtk_native_dialog_hide(dialog);
		}

		virtual void Destroy()
		{
			gtk_native_dialog_destroy(dialog);
		}

		virtual bool Visible()
		{
			return gtk_native_dialog_get_visible(dialog);
		}

		virtual void Modal(bool modal)
		{
			gtk_native_dialog_set_modal(dialog, modal);
		}

		virtual bool Modal()
		{
			return gtk_native_dialog_get_modal(dialog);
		}

		virtual void Title(const char* title)
		{
			gtk_native_dialog_set_title(dialog, title);
		}

		virtual const char* Title()
		{
			return gtk_native_dialog_get_title(dialog);
		}

		virtual void TransientFor(Window& window)
		{
			gtk_native_dialog_set_transient_for(dialog, GTK_WINDOW(window.GetWidget()));
		}

		virtual Window TransientFor()
		{
			return Window(gtk_native_dialog_get_transient_for(dialog));
		}

		virtual ResponseType Run()
		{
			return (ResponseType)gtk_native_dialog_run(dialog);
		}

		bool IsNativeDialog()
		{
			return GTK_IS_NATIVE_DIALOG(dialog);
		}

	protected:
		NativeDialog() : dialog{NULL}
		{
		}

		void SetNativeDialog(GtkNativeDialog* dialog)
		{
			this->dialog = dialog;
		}

		GtkNativeDialog* dialog;
	};
}