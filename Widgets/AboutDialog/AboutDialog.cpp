#include "./AboutDialog.hh"

namespace CGui
{
	AboutDialog::AboutDialog() : Window::Container(this)
	{
		m_Widget = gtk_about_dialog_new();
		this->SetContext(m_Widget);
	}

	AboutDialog::AboutDialog(GtkAboutDialog* dialog) : Window::Container(this)
	{
		m_Widget = GTK_WIDGET(dialog);
		this->SetContext(m_Widget);
	}

	AboutDialog::AboutDialog(Window& parent) : Window::Container(this)
	{
		m_Widget = gtk_about_dialog_new();
		this->SetContext(m_Widget);
		this->TransientFor(parent);
	}

	void AboutDialog::ProgramName(const char* name)
	{
		gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(m_Widget), name);
	}

	const char* AboutDialog::ProgramName()
	{
		return gtk_about_dialog_get_program_name(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::Version(const char* version)
	{
		gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(m_Widget), version);
	}

	const char* AboutDialog::Version()
	{
		return gtk_about_dialog_get_version(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::Copyright(const char* copyright)
	{
		gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(m_Widget), copyright);
	}

	const char* AboutDialog::Copyright()
	{
		return gtk_about_dialog_get_copyright(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::Comments(const char* comments)
	{
		gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(m_Widget), comments);
	}

	const char* AboutDialog::Comments()
	{
		return gtk_about_dialog_get_comments(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::License(const char* license)
	{
		gtk_about_dialog_set_license(GTK_ABOUT_DIALOG(m_Widget), license);
	}

	const char* AboutDialog::License()
	{
		return gtk_about_dialog_get_license(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::WrapLicense(bool wrap)
	{
		gtk_about_dialog_set_wrap_license(GTK_ABOUT_DIALOG(m_Widget), wrap);
	}

	bool AboutDialog::WrapLicense()
	{
		return gtk_about_dialog_get_wrap_license(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::LicenseType(CGui::License license)
	{
		gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(m_Widget), (GtkLicense)license);
	}

	CGui::License AboutDialog::LicenseType()
	{
		return (CGui::License)gtk_about_dialog_get_license_type(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::Website(const char* website)
	{
		gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(m_Widget), website);
	}

	const char* AboutDialog::Website()
	{
		return gtk_about_dialog_get_website(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::WebsiteLabel(const char* label)
	{
		gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(m_Widget), label);
	}

	const char* AboutDialog::WebsiteLabel()
	{
		return gtk_about_dialog_get_website_label(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::Authors(const char** authors)
	{
		if (authors[sizeof(authors) - 1] != NULL)
			authors[sizeof(authors)] = NULL;

		gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(m_Widget), authors);
	}

	const char* const* AboutDialog::Authors()
	{
		return gtk_about_dialog_get_authors(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::Artists(const char** artists)
	{
		if (artists[sizeof(artists) - 1] != NULL)
			artists[sizeof(artists)] = NULL;

		gtk_about_dialog_set_artists(GTK_ABOUT_DIALOG(m_Widget), artists);
	}

	const char* const* AboutDialog::Artists()
	{
		return gtk_about_dialog_get_artists(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::Documenters(const char** documenters)
	{
		if (documenters[sizeof(documenters) - 1] != NULL)
			documenters[sizeof(documenters)] = NULL;

		gtk_about_dialog_set_documenters(GTK_ABOUT_DIALOG(m_Widget), documenters);
	}

	const char* const* AboutDialog::Documenters()
	{
		return gtk_about_dialog_get_documenters(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::TranslatorCredits(const char* credits)
	{
		gtk_about_dialog_set_translator_credits(GTK_ABOUT_DIALOG(m_Widget), credits);
	}

	const char* AboutDialog::TranslatorCredits()
	{
		return gtk_about_dialog_get_translator_credits(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::Logo(Pixbuf& logo)
	{
		gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(m_Widget), logo.GetWidget());
	}

	Pixbuf AboutDialog::Logo()
	{
		return Pixbuf(gtk_about_dialog_get_logo(GTK_ABOUT_DIALOG(m_Widget)));
	}

	void AboutDialog::LogoIconname(const char* iconname)
	{
		gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(m_Widget), iconname);
	}

	const char* AboutDialog::LogoIconname()
	{
		return gtk_about_dialog_get_logo_icon_name(GTK_ABOUT_DIALOG(m_Widget));
	}

	void AboutDialog::AddCreditSection(const char* section_name, const char** people)
	{
		if (people[sizeof(people) - 1] != NULL)
			people[sizeof(people)] = NULL;

		gtk_about_dialog_add_credit_section(GTK_ABOUT_DIALOG(m_Widget), section_name, people);
	}

	bool AboutDialog::IsAboutDialog()
	{
		return GTK_IS_ABOUT_DIALOG(m_Widget);
	}

}