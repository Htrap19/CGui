#pragma once

#include "../Widget.hh"
#include "../Container.hh"
#include "../TreeModel.hh"

namespace CGui
{
	class ComboBox : public virtual Widget, public virtual Container<ComboBox>
	{
	public:
		ComboBox(bool with_entry = false);
		ComboBox(TreeModel& tree_modal);
		ComboBox(GtkComboBox* combobox);
		void WrapWidth(int width);
		int WropWidth();
		void RowSpanColumn(int row_span);
		int RowSpanColumn();
		void ColumnSpanColumn(int column_span);
		int ColumnSpanColumn();
		void Active(int index);
		int Active();
		void ActiveIter(TreeModel::TreeIter& iter);
		bool ActiveIterG(TreeModel::TreeIter& iter);
		void IdColumn(int id);
		int IdColumn();
		bool ActiveId(const char* active_id);
		const char* ActiveId();
		void Modal(TreeModel& modal);
		TreeModel Modal();
		void PopUp();
		void PopDown();
		void ButtonSensitivity(SensitivityType type);
		SensitivityType ButtonSensitivity();
		bool HasEntry();
		void EntryTextColumn(int text_column);
		int EntryTextColumn();
		void PopupFixedWidth(bool fixed);
		bool PopupFixedWidth();
		bool IsComboBox();

	protected:
		ComboBox();
		void SetComboBox(GtkComboBox* box);
	};
}