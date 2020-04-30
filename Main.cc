// This the test file

#include <CGUI.hh>

using namespace CGui;

int main(int argc, char *argv[])
{
  Init init(argc, argv);

  Window window(TOPLEVEL, "Window", CEN);

  Box vbox(VER, 10);
  vbox.Align(CENTER, CENTER);

  Image image("./Image/gui-interface.png", 300, 300);
  image.Align(CENTER, BEGIN);

  Label label("Welcome to CGui, Make C++ UI Efficient");
  label.Align(CENTER, LAST);

  vbox.AddStart(image);
  vbox.AddStart(label);

  window.Add(vbox);
  window.InternalWidth(10);
  window.DefaultSize(640, 480);
  window.ShowAll();

  return 0;
}
