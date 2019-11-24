// This the test file

#include "CGUI.hh"

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  Window window(TOPLEVEL, "CGuiWindow", CEN);

  Box vbox(VER, 10);
  vbox.Align(CENTER, CENTER);

  Image image("./Image/gui-interface.png", 300, 300);
  image.Align(CENTER, BEGIN);

  Label label("Welcome to CGui, Make C++ UI Efficient");
  label.Align(CENTER, LAST);

  vbox.Add<Image>(START, image);
  vbox.Add<Label>(END, label);

  window.Add<Box>(vbox);
  window.InternalWidth(10);
  window.DefaultSize(640, 480);
  window.ShowAll();

  gtk_main();
  return 0;
}
