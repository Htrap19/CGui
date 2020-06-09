#include "./FileChooser.hh"

namespace CGui
{
  FileChooser::FileChooser(Action action)
  {
	  widget = gtk_file_chooser_widget_new(std::get<GtkFileChooserAction>(Converter::Convert::GetInstance().ConvertToGtkCode(action)));
	  this->SetContext(widget);
  }

  void FileChooser::ChooseAction(Action action)
  { gtk_file_chooser_set_action(GTK_FILE_CHOOSER(widget), std::get<GtkFileChooserAction>(Converter::Convert::GetInstance().ConvertToGtkCode(action))); }
};
