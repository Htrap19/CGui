#include "./FileChooserWidget.hh"

namespace CGui
{
	FileChooserWidget::FileChooserWidget(GtkFileChooserWidget* file_chooser) : Orientable(this)
	{
		this->SetFileChooserWidget(file_chooser);
	}

	FileChooserWidget::FileChooserWidget(FileChooserAction action) : Orientable(this)
	{
		m_Widget = gtk_file_chooser_widget_new((GtkFileChooserAction)action);
		this->SetContext(m_Widget);
		this->SetFileChooser(GTK_FILE_CHOOSER(m_Widget));
	}

	bool FileChooserWidget::IsFileChooserWidget()
	{
		return GTK_IS_FILE_CHOOSER_WIDGET(m_Widget);
	}

	FileChooserWidget::FileChooserWidget() : Orientable(this)
	{
	}

	void FileChooserWidget::SetFileChooserWidget(GtkFileChooserWidget* filechooser)
	{
		m_Widget = GTK_WIDGET(filechooser);
		this->SetContext(m_Widget);
		this->SetFileChooser(GTK_FILE_CHOOSER(m_Widget));
	}
};
