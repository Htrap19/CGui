#include "./FileChooserWidget.hh"

namespace CGui
{
	FileChooserWidget::FileChooserWidget(GtkFileChooserWidget* file_chooser) : Orientable(this)
	{
		this->SetFileChooserWidget(file_chooser);
	}

	FileChooserWidget::FileChooserWidget(FileChooserAction action) : Orientable(this)
	{
		widget = gtk_file_chooser_widget_new((GtkFileChooserAction)action);
		this->SetContext(widget);
		this->SetFileChooser(GTK_FILE_CHOOSER(widget));
	}

	bool FileChooserWidget::IsFileChooserWidget()
	{
		return GTK_IS_FILE_CHOOSER_WIDGET(widget);
	}

	FileChooserWidget::FileChooserWidget() : Orientable(this)
	{
	}

	void FileChooserWidget::SetFileChooserWidget(GtkFileChooserWidget* filechooser)
	{
		widget = GTK_WIDGET(filechooser);
		this->SetContext(widget);
		this->SetFileChooser(GTK_FILE_CHOOSER(widget));
	}
};
