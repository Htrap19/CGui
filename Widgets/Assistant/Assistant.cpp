#include "./Assistant.hh"
#include "../../Custom/Initialize/Initialize.hh"

namespace CGui
{
	unsigned int Assistant::m_RefCount;

	Assistant::Assistant() : Window::Container(this)
	{
		m_Widget = gtk_assistant_new();
		this->SetContext(m_Widget);
		Assistant::m_RefCount++;

		auto exit = [](GtkWidget * widget, Assistant * ins)
		{
			if (Assistant::m_RefCount <= 1)
				CGui::MainQuit();
			else
			{
				ins->Close();
				Assistant::m_RefCount--;
			}
		};

		g_signal_connect(G_OBJECT(m_Widget), Converter::Convert::GetInstance().GetGtkCode(Events::DELETE), G_CALLBACK((void(*)(GtkWidget*, Assistant*))exit), this);
	}

	Assistant::Assistant(GtkAssistant* assistant) : Window::Container(this)
	{
		m_Widget = GTK_WIDGET(assistant);
		this->SetContext(m_Widget);
	}

	void Assistant::CurrentPage(int page)
	{
		gtk_assistant_set_current_page(GTK_ASSISTANT(m_Widget), page);
	}

	int Assistant::CurrentPage()
	{
		return gtk_assistant_get_current_page(GTK_ASSISTANT(m_Widget));
	}

	int Assistant::NumPages()
	{
		return gtk_assistant_get_n_pages(GTK_ASSISTANT(m_Widget));
	}

	Widget Assistant::NthPage(int page)
	{
		return Widget(gtk_assistant_get_nth_page(GTK_ASSISTANT(m_Widget), page));
	}

	int Assistant::PrependPage(Widget& page)
	{
		return gtk_assistant_prepend_page(GTK_ASSISTANT(m_Widget), page.GetWidget());
	}

	int Assistant::AppendPage(Widget& page)
	{
		return gtk_assistant_append_page(GTK_ASSISTANT(m_Widget), page.GetWidget());
	}

	int Assistant::InsertPage(Widget& page, int position)
	{
		return gtk_assistant_insert_page(GTK_ASSISTANT(m_Widget), page.GetWidget(), position);
	}

	void Assistant::RemovePage(int position)
	{
		gtk_assistant_remove_page(GTK_ASSISTANT(m_Widget), position);
	}

	void Assistant::PageType(Widget& page, AssistantPageType type)
	{
		gtk_assistant_set_page_type(GTK_ASSISTANT(m_Widget), page.GetWidget(), (GtkAssistantPageType)type);
	}

	AssistantPageType Assistant::PageType(Widget& page)
	{
		return (AssistantPageType)gtk_assistant_get_page_type(GTK_ASSISTANT(m_Widget), page.GetWidget());
	}

	void Assistant::PageTitle(Widget& page, const char* title)
	{
		gtk_assistant_set_page_title(GTK_ASSISTANT(m_Widget), page.GetWidget(), title);
	}

	const char* Assistant::PageTitle(Widget& page)
	{
		return gtk_assistant_get_page_title(GTK_ASSISTANT(m_Widget), page.GetWidget());
	}

	void Assistant::PageComplete(Widget& page, bool complete)
	{
		gtk_assistant_set_page_complete(GTK_ASSISTANT(m_Widget), page.GetWidget(), complete);
	}

	bool Assistant::PageComplete(Widget& page)
	{
		return gtk_assistant_get_page_complete(GTK_ASSISTANT(m_Widget), page.GetWidget());
	}

	void Assistant::PageHasPadding(Widget& page, bool has_padding)
	{
		gtk_assistant_set_page_has_padding(GTK_ASSISTANT(m_Widget), page.GetWidget(), has_padding);
	}

	bool Assistant::PageHasPadding(Widget& page)
	{
		return gtk_assistant_get_page_has_padding(GTK_ASSISTANT(m_Widget), page.GetWidget());
	}

	void Assistant::AddActionWidget(Widget& child)
	{
		gtk_assistant_add_action_widget(GTK_ASSISTANT(m_Widget), child.GetWidget());
	}

	void Assistant::RemoveActionWidget(Widget& child)
	{
		gtk_assistant_remove_action_widget(GTK_ASSISTANT(m_Widget), child.GetWidget());
	}

	void Assistant::UpdateButtonsState()
	{
		gtk_assistant_update_buttons_state(GTK_ASSISTANT(m_Widget));
	}

	void Assistant::Commit()
	{
		gtk_assistant_commit(GTK_ASSISTANT(m_Widget));
	}

	void Assistant::NextPage()
	{
		gtk_assistant_next_page(GTK_ASSISTANT(m_Widget));
	}

	void Assistant::PrevPage()
	{
		gtk_assistant_previous_page(GTK_ASSISTANT(m_Widget));
	}
	bool Assistant::IsAssistant()
	{
		return GTK_IS_ASSISTANT(m_Widget);
	}
}