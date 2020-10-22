#pragma once

#include <gtk/gtk.h>

namespace CGui
{
	class EntryBuffer
	{
	public:
		EntryBuffer(const char* initial_chars, int n_initial_chars);
		EntryBuffer(GtkEntryBuffer* buffer);
		void Text(const char* chars, int n_chars);
		const char* Text();
		unsigned long long Bytes();
		unsigned int Length();
		void MaxLength(int length);
		int MaxLength();
		void InsertText(int position, const char* chars, int n_chars);
		void DeleteText(int position, int n_chars);
		void EmitInsertText(int position, const char* chars, int n_chars);
		void EmitDeleteText(int position, int n_chars);
		bool IsEntryBuffer();

		GtkEntryBuffer* GetEntryBuffer();

	protected:
		GtkEntryBuffer* m_entry_buffer;
	};
}