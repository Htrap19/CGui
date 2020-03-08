#include <CGUI.hh>
#include <filesystem>
#include <thread>
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace CGui;

std::string home = std::string( getenv("HOME") );

void applyppath(Entry *entry)
{ entry->Text("/usr/local/include"); }

void applycpath(Entry *entry)
{ entry->Text(std::string( std::filesystem::current_path() ).c_str()); }

void quitinstaller(Window *window)
{ window->Quit(); }

void fill(Progressbar *progressbar, Button *ibutton, long unsigned int *id, Button *cbutton, Window *window)
{
  progressbar->Increment(0.03);

  if(progressbar->Fraction() == 1.0)
  {
    progressbar->Text("Finished");
    ibutton->Sensitive(true);
    ibutton->Text("Done");
    ibutton->DisconnectHandler(*id);
    ibutton->Clicked(quitinstaller, *window);
    cbutton->Hide();
  }
}

void MakePrecompiledHeadersCmd(std::string &hhpath)
{
  std::string cmd = "g++-8 -std=c++17 " + hhpath + " `pkg-config gtk+-3.0 --cflags --libs`";
  std::system(cmd.c_str());
}

void MakePrecompiledHeaders(std::string &dir, Progressbar *progressbar, Button *ibutton, long unsigned int *id, Button *cbutton, Window *window)
{
  for(auto &hpath: std::filesystem::directory_iterator(dir.c_str()))
  {
    std::filesystem::path dp = dir + "/" + std::string( hpath.path().filename() );
    progressbar->Text(std::string( hpath.path().filename() ).c_str());
    if(std::filesystem::is_directory(hpath.symlink_status()))
      for(auto &hfile: std::filesystem::directory_iterator(std::filesystem::absolute(dp)))
      {
        if(std::filesystem::path(hfile).extension() == ".hh")
        {
          std::string absolutepath = std::filesystem::absolute(hfile.path());
          MakePrecompiledHeadersCmd(absolutepath);
        }
      }
    else if(std::filesystem::is_regular_file(hpath.symlink_status()) && dp.extension() == ".hh")
    {
      std::string absolutefilepath = std::filesystem::absolute(hpath.path());
      MakePrecompiledHeadersCmd(absolutefilepath);
    }
    fill(progressbar, ibutton, id, cbutton, window);
  }
}

void copy(std::string diterator, std::string &desp, Infobar *infobar, Progressbar *progressbar, Button *ibutton, long unsigned int *id, Button *cbutton, Window *window)
{
  infobar->Reveal(true);
  std::filesystem::create_directory(desp.c_str());
  for(auto &s: std::filesystem::directory_iterator(diterator.c_str()))
  {
    std::filesystem::path dp = desp + "/" + std::string( s.path().filename() );
    if(std::filesystem::is_directory(s.symlink_status()))
    {
      std::filesystem::create_directory(dp);
      for(auto &hfile: std::filesystem::directory_iterator(s.path()))
      {
        if(hfile.path().extension() == ".hh")
        {
          progressbar->Text(std::string( hfile.path().filename() ).c_str());
          std::filesystem::copy(hfile, dp.c_str());
          fill(progressbar, ibutton, id, cbutton, window);
        }
      }
    }
    else if(std::filesystem::is_regular_file(s.symlink_status()))
    {
      if(s.path().extension() == ".hh")
      {
        progressbar->Text(std::string( s.path().filename() ).c_str());
        std::filesystem::copy(s, dp.c_str());
        fill(progressbar, ibutton, id, cbutton, window);
      }
    }
  }
  infobar->Reveal(false);
}

void UpdateProfileFile(std::string &lib_path)
{
  std::ifstream profile_file(home + "/profile");
  if(profile_file.is_open())
  {
    std::string line;
    std::string fulltext;
    while(getline(profile_file, line))
      fulltext += line + '\n';

    std::ofstream update(home + "/profile");
    if(update.is_open())
    {
      update << fulltext;
      update << "#Added by CGui \nexport CPLUS_INCLUDE_PATH=" + lib_path;
      update.close();
    }
    profile_file.close();
  }
  std::string cmd = "export CPLUS_INCLUDE_PATH=" + lib_path;
  std::system(cmd.c_str());
}

void CopyFiles(Progressbar *progressbar, Infobar *infobar, CheckButton *ucheckbutton, Button *ibutton, long unsigned int *id, Button *cbutton, Window *window, const char *destination_path)
{
  Label progress_text("Copying CGui Widgets");
  progress_text.Show();
  infobar->Add(progress_text);
  // Widgets
  std::string wdir = std::string(destination_path) + std::string("/Widgets");
  copy("../../Widgets", wdir, infobar, progressbar, ibutton, id, cbutton, window);

  // CssProvider
  progress_text.Text("Copying Css Provider");
  progress_text.Show();
  std::string cssdir = std::string( destination_path ) + std::string("/CssProvider");
  copy("../../CssProvider", cssdir, infobar, progressbar, ibutton, id, cbutton, window);

  // Converter
  progress_text.Text("Copying Converter");
  progress_text.Show();
  std::string condir = std::string( destination_path ) + std::string( "/Converter" );
  copy("../../Converter", condir, infobar, progressbar, ibutton, id, cbutton, window);

  // CGUI header file
  progress_text.Text("Copying CGui");
  progress_text.Show();

  infobar->Reveal(true);
  std::filesystem::path source = "../../CGUI.hh";
  std::filesystem::copy(source, destination_path);
  infobar->Reveal(false);

  // Precompiled Headers
  progress_text.Text("Setting up for use, this may take a minute or more");
  progress_text.Show();

  infobar->Reveal(true);
  MakePrecompiledHeaders(wdir, progressbar, ibutton, id, cbutton, window);
  MakePrecompiledHeaders(cssdir, progressbar, ibutton, id, cbutton, window);
  MakePrecompiledHeaders(condir, progressbar, ibutton, id, cbutton, window);
  std::string cguifilecmd = std::string( destination_path );
  MakePrecompiledHeaders(cguifilecmd, progressbar, ibutton, id, cbutton, window);
  infobar->Reveal(false);

  if(ucheckbutton->Checked())
  {
    std::string write = destination_path;
    UpdateProfileFile(write);
  }
}

void start_installation(Button *sender, Revealer *revealer, Progressbar *progressbar, Entry *entry, Button *pbutton, Button *cbutton, CheckButton *ucheckbutton, CheckButton *icheckbutton, Infobar *ibar, Button *installb, Button *quitb, long unsigned int *id, Window *window)
{
  revealer->Reveal(true);
  entry->Sensitive(false);
  pbutton->Sensitive(false);
  cbutton->Sensitive(false);
  ucheckbutton->Sensitive(false);
  icheckbutton->Sensitive(false);
  installb->Sensitive(false);
  quitb->Text("Cancel");
  quitb->StyleClass("cancel_button");
  CopyFiles(progressbar, ibar, ucheckbutton, installb, id, quitb, window, entry->Text());
}

int main(int argc, char *argv[])
{
  Init init(argc, argv); // Initialize the CGUI

  long unsigned int id;

  Window window(TOPLEVEL, "CGui Installer", CEN);
  window.DefaultSize(640, 480);
  window.Icon("../Images/installer.png");

  // Initialize style
  CssProvider("../Styles/Style.css");

  // Window custom headerbar
  Headerbar win_headerbar("CGUI Installer");

  // Install button
  Button install_button("Install");
  install_button.Align(LAST, CENTER);
  install_button.StyleClass("installbutton");

  // Quit button
  Button quit_button("Quit");
  quit_button.Align(BEGIN, CENTER);
  quit_button.Clicked<Window>(quitinstaller, window);

  win_headerbar.Add<Button>(END, install_button);
  win_headerbar.Add<Button>(START, quit_button);

  window.NewHeaderbar(win_headerbar);

  // main vertical box container
  Box vbox(VER, 10);

  Infobar note_infobar;
  note_infobar.Align(FILL, CENTER);
  note_infobar.Reveal(false);
  note_infobar.StyleClass("noteinfobar");

  // Path label
  Label path_label("Path");
  path_label.Align(BEGIN, CENTER);

  // Path entry
  Entry path_entry("Path");
  path_entry.Align(FILL, CENTER);
  path_entry.Text(std::string( std::filesystem::current_path() ).c_str());

  // Path's button horizontal box container
  Box buttons_hbox(HOR, 10);

  // Preferred Button
  Button pref_button("Preferred Path");
  pref_button.Align(BEGIN, CENTER);
  pref_button.Clicked<Entry>(applyppath, path_entry);

  // Current Button
  Button curr_button("Current Path");
  curr_button.Align(BEGIN, CENTER);
  curr_button.Clicked<Entry>(applycpath, path_entry);

  buttons_hbox.Add<Button>(START, pref_button);
  buttons_hbox.Add<Button>(START, curr_button);

  CheckButton univ_checkbutton("Universal Access");
  univ_checkbutton.Align(BEGIN, CENTER);
  univ_checkbutton.Checked(true);

  CheckButton inst_cguic("Install Gui Compiler (Coming soon)");
  inst_cguic.Align(BEGIN, CENTER);
  inst_cguic.Sensitive(false);
  inst_cguic.Tooltip("Coming soon");

  Revealer progressbar_revealer(SLIDEUP, 500);
  progressbar_revealer.Align(FILL, CENTER);

  Progressbar inst_progressbar("Installing");
  inst_progressbar.Align(FILL, CENTER);

  progressbar_revealer.Add<Progressbar>(inst_progressbar);

  id = install_button.Clicked(start_installation, progressbar_revealer, inst_progressbar, path_entry, pref_button, curr_button, univ_checkbutton, inst_cguic, note_infobar, install_button, quit_button, id, window);

  vbox.Add<Infobar>(START, note_infobar);
  vbox.Add<Label>(START, path_label);
  vbox.Add<Entry>(START, path_entry);
  vbox.Add<Box>(START, buttons_hbox);
  vbox.Add<CheckButton>(START, univ_checkbutton);
  vbox.Add<CheckButton>(START, inst_cguic);
  // vbox.Add<Infobar, Label, Entry, Box, CheckButton, CheckButton>(START, note_infobar, path_label, path_entry, buttons_hbox, univ_checkbutton, inst_cguic);
  vbox.Add<Revealer>(END, progressbar_revealer);

  window.Add<Box>(vbox);
  window.InternalWidth(10);
  window.Resizable(false);
  window.ShowAll();

  return 0;
}
