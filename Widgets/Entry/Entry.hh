#pragma once

#include "../Widget.hh"
#include "../EventHandler.hh"
#include "../../Converter/Convert.hh"
#include "../../Pixbuf/Pixbuf/Pixbuf.hh"

namespace CGui
{
	class Entry : public Widget, public EventHandler<Entry>
	{
	public:
		Entry();
		Entry(const char* placeholdertext);
		void Editable(bool editable);
		bool Editable();
		void Visibility(bool visibility);
		bool Visibility();
		void MaxLength(int max);
		int MaxLength();
		void OverwriteMode(bool overwrite);
		bool OverwriteMode();
		void Alignment(float alignment);
		float Alignment();
		void InvisibleChar(char ch);
		void UnsetInvisibleChar();
		char InvisibleChar();
		void WidthChar(int n_ch);
		int WidthChar();
		void MaxWidthChar(int n_ch);
		int MaxWidthChar();
		void HasFrame(bool frame);
		bool HasFrame();
		void ProgressFraction(double fraction);
		double ProgressFraction();
		void ProgressPulse();
		void ProgressPulseStep(double fraction);
		double ProgressPulseStep();
		void Icon(EntryIconPosition pos, Pixbuf& pixbuf);
		Pixbuf& Icon();
		void IconActivatable(EntryIconPosition pos, bool activatable);
		bool IconActivatable(EntryIconPosition pos);
		void IconSensitive(EntryIconPosition pos, bool sensitive);
		bool IconSensitive(EntryIconPosition pos);
		void IconTooltipText(EntryIconPosition pos, const char* tooltip);
		const char* IconTooltipText(EntryIconPosition pos);
		void Purpose(InputPurpose purpose);
		InputPurpose Purpose();
		void Hints(InputHints hints);
		InputHints Hints();
		void GrabFocusWithoutSelecting();
		void Text(const char* text);
		const char* Text();
		unsigned short TextLength();
		long unsigned int Changed(void(*func)());
		long unsigned int Changed(void(*func)(Entry*));
		template <typename ... Args> long unsigned int Changed(void(*func)(Entry*, Args* ...), Args& ... args);
		template <typename ... Args> long unsigned int Changed(void(*func)(Args* ...), Args& ... args);

	protected:
		Pixbuf* m_pixbuf;
	};

	template <typename ... Args> long unsigned int Entry::Changed(void(*func)(Entry*, Args* ...), Args& ... args)
	{
		return this->SignalHandler(Events::CHANGED, func, args...);
	}

	template <typename ... Args> long unsigned int Entry::Changed(void(*func)(Args* ...), Args& ... args)
	{
		return this->SignalHandler(Events::CHANGED, func, args...);
	}
}