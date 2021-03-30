#include "./ComboBox.hh"

namespace CGui
{
	ComboBox::ComboBox(bool with_entry) : Container(this), Handler(this)
	{
		if (with_entry)
			m_Widget = gtk_combo_box_new_with_entry();
		else
			m_Widget = gtk_combo_box_new();
		this->SetContext(m_Widget);
	}

	ComboBox::ComboBox(TreeModel& tree_modal, bool with_entry) : Container(this), Handler(this)
	{
		if (with_entry)
			m_Widget = gtk_combo_box_new_with_model_and_entry(tree_modal.GetWidget());
		else
			m_Widget = gtk_combo_box_new_with_model(tree_modal.GetWidget());
		this->SetContext(m_Widget);
	}

	ComboBox::ComboBox(GtkComboBox* combobox) : Container(this), Handler(this)
	{
		this->SetComboBox(GTK_COMBO_BOX(combobox));
	}

	void ComboBox::WrapWidth(int width)
	{
		gtk_combo_box_set_wrap_width(GTK_COMBO_BOX(m_Widget), width);
	}

	int ComboBox::WropWidth()
	{
		return gtk_combo_box_get_wrap_width(GTK_COMBO_BOX(m_Widget));
	}

	void ComboBox::RowSpanColumn(int row_span)
	{
		gtk_combo_box_set_row_span_column(GTK_COMBO_BOX(m_Widget), row_span);
	}

	int ComboBox::RowSpanColumn()
	{
		return gtk_combo_box_get_row_span_column(GTK_COMBO_BOX(m_Widget));
	}

	void ComboBox::ColumnSpanColumn(int column_span)
	{
		gtk_combo_box_set_column_span_column(GTK_COMBO_BOX(m_Widget), column_span);
	}

	int ComboBox::ColumnSpanColumn()
	{
		return gtk_combo_box_get_column_span_column(GTK_COMBO_BOX(m_Widget));
	}

	void ComboBox::Active(int index)
	{
		gtk_combo_box_set_active(GTK_COMBO_BOX(m_Widget), index);
	}

	int ComboBox::Active()
	{
		return gtk_combo_box_get_active(GTK_COMBO_BOX(m_Widget));
	}

	void ComboBox::ActiveIter(TreeModel::TreeIter& iter)
	{
		gtk_combo_box_set_active_iter(GTK_COMBO_BOX(m_Widget), iter.GetWidget());
	}

	bool ComboBox::ActiveIterG(TreeModel::TreeIter& iter)
	{
		return gtk_combo_box_get_active_iter(GTK_COMBO_BOX(m_Widget), iter.GetWidget());
	}

	void ComboBox::IdColumn(int id)
	{
		gtk_combo_box_set_id_column(GTK_COMBO_BOX(m_Widget), id);
	}

	int ComboBox::IdColumn()
	{
		return gtk_combo_box_get_id_column(GTK_COMBO_BOX(m_Widget));
	}

	bool ComboBox::ActiveId(const char* active_id)
	{
		return gtk_combo_box_set_active_id(GTK_COMBO_BOX(m_Widget), active_id);
	}

	const char* ComboBox::ActiveId()
	{
		return gtk_combo_box_get_active_id(GTK_COMBO_BOX(m_Widget));
	}

	void ComboBox::Model(TreeModel& modal)
	{
		gtk_combo_box_set_model(GTK_COMBO_BOX(m_Widget), modal.GetWidget());
	}

	TreeModel ComboBox::Model()
	{
		return TreeModel(gtk_combo_box_get_model(GTK_COMBO_BOX(m_Widget)));
	}

	void ComboBox::PopUp()
	{
		gtk_combo_box_popup(GTK_COMBO_BOX(m_Widget));
	}

	void ComboBox::PopDown()
	{
		gtk_combo_box_popdown(GTK_COMBO_BOX(m_Widget));
	}

	void ComboBox::ButtonSensitivity(SensitivityType type)
	{
		gtk_combo_box_set_button_sensitivity(GTK_COMBO_BOX(m_Widget), (GtkSensitivityType)type);
	}

	SensitivityType ComboBox::ButtonSensitivity()
	{
		return (SensitivityType)gtk_combo_box_get_button_sensitivity(GTK_COMBO_BOX(m_Widget));
	}

	bool ComboBox::HasEntry()
	{
		return gtk_combo_box_get_has_entry(GTK_COMBO_BOX(m_Widget));
	}

	void ComboBox::EntryTextColumn(int text_column)
	{
		gtk_combo_box_set_entry_text_column(GTK_COMBO_BOX(m_Widget), text_column);
	}

	int ComboBox::EntryTextColumn()
	{
		return gtk_combo_box_get_entry_text_column(GTK_COMBO_BOX(m_Widget));
	}

	void ComboBox::PopupFixedWidth(bool fixed)
	{
		gtk_combo_box_set_popup_fixed_width(GTK_COMBO_BOX(m_Widget), fixed);
	}

	bool ComboBox::PopupFixedWidth()
	{
		return gtk_combo_box_get_popup_fixed_width(GTK_COMBO_BOX(m_Widget));
	}

	bool ComboBox::IsComboBox()
	{
		return GTK_IS_COMBO_BOX(m_Widget);
	}

	ComboBox::ComboBox() : Container(this), Handler(this)
	{
	}

	void ComboBox::SetComboBox(GtkComboBox* box)
	{
		m_Widget = GTK_WIDGET(box);
		this->SetContext(m_Widget);
	}

}