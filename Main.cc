#include "CGUI.hh"

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  Window window(TOPLEVEL, "Gtk Window", CEN);
  Label label("Text");
  label.SizeRequest(100, 100);
  label.Align(LAST, CENTER);
  Label label2("Test2");
  Entry entry("Enter something");
  Box vbox(VER, 10);
  vbox.Add<Label>(START, label);
  vbox.Add<Entry>(END, entry);
  vbox.Add<Label>(START, label2);
  window.Add<Box>(vbox);
  window.InternalWidth(10);
  window.DefaultSize(640, 480);
  window.ShowAll();

  gtk_main();
  return 0;
}
