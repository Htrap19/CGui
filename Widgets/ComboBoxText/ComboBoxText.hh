#pragma once

#include "../ComboBox/ComboBox.hh"

namespace CGui
{
	class ComboBoxText : public ComboBox
	{
	public:
		ComboBoxText(bool with_entry = false);
		void Append(const char* id, const char* text);
		void Prepend(const char* id, const char* text);
		void Insert(int position, const char* id, const char* text);
		void AppendText(const char* text);
		void PrependText(const char* text);
		void InsertText(int position, const char* text);
		void Remove(int position);
		void RemoveAll();
		const char* ActiveText();
		bool IsComboBoxText();
	};
}