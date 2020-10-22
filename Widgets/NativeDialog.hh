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

		void Show()
		{
			gtk_native_dialog_show(dialog);
		}

		void Hide()
		{
			gtk_native_dialog_hide(dialog);
		}

		void Destroy()
		{
			gtk_native_dialog_destroy(dialog);
		}

		bool Visible()
		{
			return gtk_native_dialog_get_visible(dialog);
		}

		void Modal(bool modal)
		{
			gtk_native_dialog_set_modal(dialog, modal);
		}

		bool Modal()
		{
			return gtk_native_dialog_get_modal(dialog);
		}

		void Title(const char* title)
		{
			gtk_native_dialog_set_title(dialog, title);
		}

		const char* Title()
		{
			return gtk_native_dialog_get_title(dialog);
		}

		void TransientFor(Window& window)
		{
			gtk_native_dialog_set_transient_for(dialog, GTK_WINDOW(window.GetWidget()));
		}

		Window TransientFor()
		{
			return Window(gtk_native_dialog_get_transient_for(dialog));
		}

		ResponseType Run()
		{
			return (ResponseType)gtk_native_dialog_run(dialog);
		}

		bool IsNativeDialog()
		{
			return GTK_IS_NATIVE_DIALOG(dialog);
		}

	protected:
		NativeDialog()
		{
		}

		void SetNativeDialog(GtkNativeDialog* dialog)
		{
			this->dialog = dialog;
		}

		GtkNativeDialog* dialog;
	};
}