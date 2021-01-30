#pragma once

#include "../Dialog/Dialog.hh"
#include "../../Converter/Convert.hh"
#include "../../Pixbuf/Pixbuf/Pixbuf.hh"

namespace CGui
{
	class AboutDialog : public virtual Dialog
	{
	public:
		AboutDialog();
		AboutDialog(GtkAboutDialog* dialog);
		AboutDialog(Window& parent);
		void ProgramName(const char* name);
		const char* ProgramName();
		void Version(const char* version);
		const char* Version();
		void Copyright(const char* copyright);
		const char* Copyright();
		void Comments(const char* comments);
		const char* Comments();
		void License(const char* license);
		const char* License();
		void WrapLicense(bool wrap);
		bool WrapLicense();
		void LicenseType(CGui::License license);
		CGui::License LicenseType();
		void Website(const char* website);
		const char* Website();
		void WebsiteLabel(const char* label);
		const char* WebsiteLabel();
		void Authors(const char** authors);
		const char* const* Authors();
		void Artists(const char** artists);
		const char* const* Artists();
		void Documenters(const char** documenters);
		const char* const* Documenters();
		void TranslatorCredits(const char* credits);
		const char* TranslatorCredits();
		void Logo(Pixbuf& logo);
		Pixbuf Logo();
		void LogoIconname(const char* iconname);
		const char* LogoIconname();
		void AddCreditSection(const char* section_name, const char** people);
		bool IsAboutDialog();
	};
}