#include "./EntryBuffer.hh"

namespace CGui
{
	EntryBuffer::EntryBuffer(const char* initial_chars, int n_initial_chars)
	{
		m_entry_buffer = gtk_entry_buffer_new(initial_chars, n_initial_chars);
	}

	EntryBuffer::EntryBuffer(GtkEntryBuffer* buffer)
	{
		this->m_entry_buffer = buffer;
	}

	void EntryBuffer::Text(const char* chars, int n_chars)
	{
		gtk_entry_buffer_set_text(GTK_ENTRY_BUFFER(m_entry_buffer), chars, n_chars);
	}

	const char* EntryBuffer::Text()
	{
		return gtk_entry_buffer_get_text(GTK_ENTRY_BUFFER(m_entry_buffer));
	}

	unsigned long long EntryBuffer::Bytes()
	{
		return gtk_entry_buffer_get_bytes(GTK_ENTRY_BUFFER(m_entry_buffer));
	}

	unsigned int EntryBuffer::Length()
	{
		return gtk_entry_buffer_get_length(GTK_ENTRY_BUFFER(m_entry_buffer));
	}

	void EntryBuffer::MaxLength(int length)
	{
		gtk_entry_buffer_set_max_length(GTK_ENTRY_BUFFER(m_entry_buffer), length);
	}

	int EntryBuffer::MaxLength()
	{
		return gtk_entry_buffer_get_max_length(GTK_ENTRY_BUFFER(m_entry_buffer));
	}

	void EntryBuffer::InsertText(int position, const char* chars, int n_chars)
	{
		gtk_entry_buffer_insert_text(GTK_ENTRY_BUFFER(m_entry_buffer), position, chars, n_chars);
	}

	void EntryBuffer::DeleteText(int position, int n_chars)
	{
		gtk_entry_buffer_delete_text(GTK_ENTRY_BUFFER(m_entry_buffer), position, n_chars);
	}

	void EntryBuffer::EmitInsertText(int position, const char* chars, int n_chars)
	{
		gtk_entry_buffer_emit_inserted_text(GTK_ENTRY_BUFFER(m_entry_buffer), position, chars, n_chars);
	}

	void EntryBuffer::EmitDeleteText(int position, int n_chars)
	{
		gtk_entry_buffer_emit_deleted_text(GTK_ENTRY_BUFFER(m_entry_buffer), position, n_chars);
	}

	GtkEntryBuffer* EntryBuffer::GetEntryBuffer()
	{
		return m_entry_buffer;
	}
}