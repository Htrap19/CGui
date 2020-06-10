#include "./FileChooser.hh"

namespace CGui
{
	FileChooser::FileChooser(Action action)
	{
		widget = gtk_file_chooser_widget_new((GtkFileChooserAction)action);
		this->SetContext(widget);
	}

	void FileChooser::ChooseAction(Action action)
	{
		gtk_file_chooser_set_action(GTK_FILE_CHOOSER(widget), (GtkFileChooserAction)action);
	}
};
