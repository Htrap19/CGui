#pragma once

#include "../Widget.hh"
#include "../Window/Window.hh"

namespace CGui
{
	class Assistant : public virtual Window
	{
	public:
		Assistant();
		Assistant(GtkAssistant* assistant);
		void CurrentPage(int page);
		int CurrentPage();
		int NumPages();
		Widget NthPage(int page);
		int PrependPage(Widget& page);
		int AppendPage(Widget& page);
		int InsertPage(Widget& page, int position);
		void RemovePage(int position);
		void PageType(Widget& page, AssistantPageType type);
		AssistantPageType PageType(Widget& page);
		void PageTitle(Widget& page, const char* title);
		const char* PageTitle(Widget& page);
		void PageComplete(Widget& page, bool complete);
		bool PageComplete(Widget& page);
		void PageHasPadding(Widget& page, bool has_padding);
		bool PageHasPadding(Widget& page);
		void AddActionWidget(Widget& child);
		void RemoveActionWidget(Widget& child);
		void UpdateButtonsState();
		void Commit();
		void NextPage();
		void PrevPage();
		bool IsAssistant();

	private:
		static unsigned int m_RefCount;
	};
}