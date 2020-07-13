#include "./AboutDialog.hh"

namespace CGui
{
	AboutDialog::AboutDialog()
	{
		widget = gtk_about_dialog_new();
		this->SetDialog(GTK_DIALOG(widget));
	}

	void AboutDialog::ProgramName(const char* name)
	{
		gtk_about_dialog_set_program_name(GTK_ABOUT_DIALOG(widget), name);
	}

	const char* AboutDialog::ProgramName()
	{
		return gtk_about_dialog_get_program_name(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::Version(const char* version)
	{
		gtk_about_dialog_set_version(GTK_ABOUT_DIALOG(widget), version);
	}

	const char* AboutDialog::Version()
	{
		return gtk_about_dialog_get_version(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::Copyright(const char* copyright)
	{
		gtk_about_dialog_set_copyright(GTK_ABOUT_DIALOG(widget), copyright);
	}

	const char* AboutDialog::Copyright()
	{
		return gtk_about_dialog_get_copyright(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::Comments(const char* comments)
	{
		gtk_about_dialog_set_comments(GTK_ABOUT_DIALOG(widget), comments);
	}

	const char* AboutDialog::Comments()
	{
		return gtk_about_dialog_get_comments(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::License(const char* license)
	{
		gtk_about_dialog_set_license(GTK_ABOUT_DIALOG(widget), license);
	}

	const char* AboutDialog::License()
	{
		return gtk_about_dialog_get_license(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::WrapLicense(bool wrap)
	{
		gtk_about_dialog_set_wrap_license(GTK_ABOUT_DIALOG(widget), wrap);
	}

	bool AboutDialog::WrapLicense()
	{
		return gtk_about_dialog_get_wrap_license(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::LicenseType(CGui::License license)
	{
		gtk_about_dialog_set_license_type(GTK_ABOUT_DIALOG(widget), (GtkLicense)license);
	}

	CGui::License AboutDialog::LicenseType()
	{
		return (CGui::License)gtk_about_dialog_get_license_type(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::Website(const char* website)
	{
		gtk_about_dialog_set_website(GTK_ABOUT_DIALOG(widget), website);
	}

	const char* AboutDialog::Website()
	{
		return gtk_about_dialog_get_website(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::WebsiteLabel(const char* label)
	{
		gtk_about_dialog_set_website_label(GTK_ABOUT_DIALOG(widget), label);
	}

	const char* AboutDialog::WebsiteLabel()
	{
		return gtk_about_dialog_get_website_label(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::Authors(const char* authors[])
	{
		if (authors[sizeof(authors) - 1] != NULL)
			authors[sizeof(authors)] = NULL;

		gtk_about_dialog_set_authors(GTK_ABOUT_DIALOG(widget), authors);
	}

	const char* const* AboutDialog::Authors()
	{
		return gtk_about_dialog_get_authors(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::Artists(const char* artists[])
	{
		if (artists[sizeof(artists) - 1] != NULL)
			artists[sizeof(artists)] = NULL;

		gtk_about_dialog_set_artists(GTK_ABOUT_DIALOG(widget), artists);
	}

	const char* const* AboutDialog::Artists()
	{
		return gtk_about_dialog_get_artists(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::Documenters(const char* documenters[])
	{
		if (documenters[sizeof(documenters) - 1] != NULL)
			documenters[sizeof(documenters)] = NULL;

		gtk_about_dialog_set_documenters(GTK_ABOUT_DIALOG(widget), documenters);
	}

	const char* const* AboutDialog::Documenters()
	{
		return gtk_about_dialog_get_documenters(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::TranslatorCredits(const char* credits)
	{
		gtk_about_dialog_set_translator_credits(GTK_ABOUT_DIALOG(widget), credits);
	}

	const char* AboutDialog::TranslatorCredits()
	{
		return gtk_about_dialog_get_translator_credits(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::Logo(Pixbuf& logo)
	{
		gtk_about_dialog_set_logo(GTK_ABOUT_DIALOG(widget), logo.GetWidget());
	}

	Pixbuf AboutDialog::Logo()
	{
		return Pixbuf(gtk_about_dialog_get_logo(GTK_ABOUT_DIALOG(widget)));
	}

	void AboutDialog::LogoIconname(const char* iconname)
	{
		gtk_about_dialog_set_logo_icon_name(GTK_ABOUT_DIALOG(widget), iconname);
	}

	const char* AboutDialog::LogoIconname()
	{
		return gtk_about_dialog_get_logo_icon_name(GTK_ABOUT_DIALOG(widget));
	}

	void AboutDialog::AddCreditSection(const char* section_name, const char* people[])
	{
		if (people[sizeof(people) - 1] != NULL)
			people[sizeof(people)] = NULL;

		gtk_about_dialog_add_credit_section(GTK_ABOUT_DIALOG(widget), section_name, people);
	}

}