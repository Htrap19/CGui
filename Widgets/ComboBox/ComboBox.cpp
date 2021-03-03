#include "./ComboBox.hh"

namespace CGui
{
	ComboBox::ComboBox(bool with_entry) : Container(this)
	{
		if (with_entry)
			widget = gtk_combo_box_new_with_entry();
		else
			widget = gtk_combo_box_new();
		this->SetContext(widget);
	}

	ComboBox::ComboBox(TreeModel& tree_modal) : Container(this)
	{
		widget = gtk_combo_box_new_with_model(tree_modal.GetWidget());
		this->SetContext(widget);
	}

	ComboBox::ComboBox(GtkComboBox* combobox) : Container(this)
	{
		this->SetComboBox(GTK_COMBO_BOX(combobox));
	}

	void ComboBox::WrapWidth(int width)
	{
		gtk_combo_box_set_wrap_width(GTK_COMBO_BOX(widget), width);
	}

	int ComboBox::WropWidth()
	{
		return gtk_combo_box_get_wrap_width(GTK_COMBO_BOX(widget));
	}

	void ComboBox::RowSpanColumn(int row_span)
	{
		gtk_combo_box_set_row_span_column(GTK_COMBO_BOX(widget), row_span);
	}

	int ComboBox::RowSpanColumn()
	{
		return gtk_combo_box_get_row_span_column(GTK_COMBO_BOX(widget));
	}

	void ComboBox::ColumnSpanColumn(int column_span)
	{
		gtk_combo_box_set_column_span_column(GTK_COMBO_BOX(widget), column_span);
	}

	int ComboBox::ColumnSpanColumn()
	{
		return gtk_combo_box_get_column_span_column(GTK_COMBO_BOX(widget));
	}

	void ComboBox::Active(int index)
	{
		gtk_combo_box_set_active(GTK_COMBO_BOX(widget), index);
	}

	int ComboBox::Active()
	{
		return gtk_combo_box_get_active(GTK_COMBO_BOX(widget));
	}

	void ComboBox::ActiveIter(TreeModel::TreeIter& iter)
	{
		gtk_combo_box_set_active_iter(GTK_COMBO_BOX(widget), iter.GetWidget());
	}

	bool ComboBox::ActiveIterG(TreeModel::TreeIter& iter)
	{
		return gtk_combo_box_get_active_iter(GTK_COMBO_BOX(widget), iter.GetWidget());
	}

	void ComboBox::IdColumn(int id)
	{
		gtk_combo_box_set_id_column(GTK_COMBO_BOX(widget), id);
	}

	int ComboBox::IdColumn()
	{
		return gtk_combo_box_get_id_column(GTK_COMBO_BOX(widget));
	}

	bool ComboBox::ActiveId(const char* active_id)
	{
		return gtk_combo_box_set_active_id(GTK_COMBO_BOX(widget), active_id);
	}

	const char* ComboBox::ActiveId()
	{
		return gtk_combo_box_get_active_id(GTK_COMBO_BOX(widget));
	}

	void ComboBox::Modal(TreeModel& modal)
	{
		gtk_combo_box_set_model(GTK_COMBO_BOX(widget), modal.GetWidget());
	}

	TreeModel ComboBox::Modal()
	{
		return TreeModel(gtk_combo_box_get_model(GTK_COMBO_BOX(widget)));
	}

	void ComboBox::PopUp()
	{
		gtk_combo_box_popup(GTK_COMBO_BOX(widget));
	}

	void ComboBox::PopDown()
	{
		gtk_combo_box_popdown(GTK_COMBO_BOX(widget));
	}

	void ComboBox::ButtonSensitivity(SensitivityType type)
	{
		gtk_combo_box_set_button_sensitivity(GTK_COMBO_BOX(widget), (GtkSensitivityType)type);
	}

	SensitivityType ComboBox::ButtonSensitivity()
	{
		return (SensitivityType)gtk_combo_box_get_button_sensitivity(GTK_COMBO_BOX(widget));
	}

	bool ComboBox::HasEntry()
	{
		return gtk_combo_box_get_has_entry(GTK_COMBO_BOX(widget));
	}

	void ComboBox::EntryTextColumn(int text_column)
	{
		gtk_combo_box_set_entry_text_column(GTK_COMBO_BOX(widget), text_column);
	}

	int ComboBox::EntryTextColumn()
	{
		return gtk_combo_box_get_entry_text_column(GTK_COMBO_BOX(widget));
	}

	void ComboBox::PopupFixedWidth(bool fixed)
	{
		gtk_combo_box_set_popup_fixed_width(GTK_COMBO_BOX(widget), fixed);
	}

	bool ComboBox::PopupFixedWidth()
	{
		return gtk_combo_box_get_popup_fixed_width(GTK_COMBO_BOX(widget));
	}

	bool ComboBox::IsComboBox()
	{
		return GTK_IS_COMBO_BOX(widget);
	}

	ComboBox::ComboBox() : Container(this)
	{
	}

	void ComboBox::SetComboBox(GtkComboBox* box)
	{
		widget = GTK_WIDGET(box);
		this->SetContext(widget);
	}

}