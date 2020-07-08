#include "./Assistant.hh"
#include "../../Custom/Initialize/Initialize.hh"

namespace CGui
{
	unsigned int Assistant::m_ref_count;

	Assistant::Assistant()
	{
		widget = gtk_assistant_new();
		this->SetContext(widget);
		this->SetWindow(GTK_WINDOW(widget));
		Assistant::m_ref_count++;

		auto exit = [](GtkWidget * widget, Assistant * ins)
		{
			if (Assistant::m_ref_count <= 1)
				CGui::MainQuit();
			else
			{
				ins->Close();
				Assistant::m_ref_count--;
			}
		};

		g_signal_connect(G_OBJECT(widget), Converter::Convert::GetInstance().GetGtkCode(Signals::DELETE), G_CALLBACK((void(*)(GtkWidget*, Assistant*))exit), this);
	}

	void Assistant::CurrentPage(int page)
	{
		gtk_assistant_set_current_page(GTK_ASSISTANT(widget), page);
	}

	int Assistant::CurrentPage()
	{
		return gtk_assistant_get_current_page(GTK_ASSISTANT(widget));
	}

	int Assistant::NumPage()
	{
		return gtk_assistant_get_n_pages(GTK_ASSISTANT(widget));
	}

	Widget Assistant::NthPage(int page)
	{
		return Widget(gtk_assistant_get_nth_page(GTK_ASSISTANT(widget), page));
	}

	int Assistant::PrependPage(Widget& page)
	{
		return gtk_assistant_prepend_page(GTK_ASSISTANT(widget), page.GetWidget());
	}

	int Assistant::AppendPage(Widget& page)
	{
		return gtk_assistant_append_page(GTK_ASSISTANT(widget), page.GetWidget());
	}

	int Assistant::InsertPage(Widget& page, int position)
	{
		return gtk_assistant_insert_page(GTK_ASSISTANT(widget), page.GetWidget(), position);
	}

	void Assistant::RemovePage(int position)
	{
		gtk_assistant_remove_page(GTK_ASSISTANT(widget), position);
	}

	void Assistant::PageType(Widget& page, AssistantPageType type)
	{
		gtk_assistant_set_page_type(GTK_ASSISTANT(widget), page.GetWidget(), (GtkAssistantPageType)type);
	}

	AssistantPageType Assistant::PageType(Widget& page)
	{
		return (AssistantPageType)gtk_assistant_get_page_type(GTK_ASSISTANT(widget), page.GetWidget());
	}

	void Assistant::PageTitle(Widget& page, const char* title)
	{
		gtk_assistant_set_page_title(GTK_ASSISTANT(widget), page.GetWidget(), title);
	}

	const char* Assistant::PageTitle(Widget& page)
	{
		return gtk_assistant_get_page_title(GTK_ASSISTANT(widget), page.GetWidget());
	}

	void Assistant::PageComplete(Widget& page, bool complete)
	{
		gtk_assistant_set_page_complete(GTK_ASSISTANT(widget), page.GetWidget(), complete);
	}

	bool Assistant::PageComplete(Widget& page)
	{
		return gtk_assistant_get_page_complete(GTK_ASSISTANT(widget), page.GetWidget());
	}

	void Assistant::PageHasPadding(Widget& page, bool has_padding)
	{
		gtk_assistant_set_page_has_padding(GTK_ASSISTANT(widget), page.GetWidget(), has_padding);
	}

	bool Assistant::PageHasPadding(Widget& page)
	{
		return gtk_assistant_get_page_has_padding(GTK_ASSISTANT(widget), page.GetWidget());
	}

	void Assistant::AddActionWidget(Widget& child)
	{
		gtk_assistant_add_action_widget(GTK_ASSISTANT(widget), child.GetWidget());
	}

	void Assistant::RemoveActionWidget(Widget& child)
	{
		gtk_assistant_remove_action_widget(GTK_ASSISTANT(widget), child.GetWidget());
	}

	void Assistant::UpdateButtonsState()
	{
		gtk_assistant_update_buttons_state(GTK_ASSISTANT(widget));
	}

	void Assistant::Commit()
	{
		gtk_assistant_commit(GTK_ASSISTANT(widget));
	}

	void Assistant::NextPage()
	{
		gtk_assistant_next_page(GTK_ASSISTANT(widget));
	}

	void Assistant::PrevPage()
	{
		gtk_assistant_previous_page(GTK_ASSISTANT(widget));
	}
}