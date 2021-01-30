#include "./ComboBoxText.hh"

namespace CGui
{
	ComboBoxText::ComboBoxText(bool with_entry) : ComboBox(with_entry), ComboBox::Container(this)
	{
		gtk_widget_destroy(widget);
		if (with_entry)
			widget = gtk_combo_box_text_new_with_entry();
		else
			widget = gtk_combo_box_text_new();
		this->SetContext(widget);
	}

	ComboBoxText::ComboBoxText(GtkComboBoxText* combo_box_text) : ComboBox(true), ComboBox::Container(this)
	{
		gtk_widget_destroy(widget);
		widget = GTK_WIDGET(combo_box_text);
		this->SetContext(widget);
	}

	void ComboBoxText::Append(const char* id, const char* text)
	{
		gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(widget), id, text);
	}

	void ComboBoxText::Prepend(const char* id, const char* text)
	{
		gtk_combo_box_text_prepend(GTK_COMBO_BOX_TEXT(widget), id, text);
	}

	void ComboBoxText::Insert(int position, const char* id, const char* text)
	{
		gtk_combo_box_text_insert(GTK_COMBO_BOX_TEXT(widget), position, id, text);
	}

	void ComboBoxText::AppendText(const char* text)
	{
		gtk_combo_box_text_append_text(GTK_COMBO_BOX_TEXT(widget), text);
	}

	void ComboBoxText::PrependText(const char* text)
	{
		gtk_combo_box_text_prepend_text(GTK_COMBO_BOX_TEXT(widget), text);
	}

	void ComboBoxText::InsertText(int position, const char* text)
	{
		gtk_combo_box_text_insert_text(GTK_COMBO_BOX_TEXT(widget), position, text);
	}

	void ComboBoxText::Remove(int position)
	{
		gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(widget), position);
	}

	void ComboBoxText::RemoveAll()
	{
		gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(widget));
	}

	const char* ComboBoxText::ActiveText()
	{
		return gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget));
	}

	bool ComboBoxText::IsComboBoxText()
	{
		return GTK_IS_COMBO_BOX_TEXT(widget);
	}

}