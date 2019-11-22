#include "CGUI.hh"

static void Helloworld(GtkWidget *widget, gpointer data)
{
  g_print("Hello World\n");
}

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv);

  Window window(TOPLEVEL, "Gtk Window", CEN);
  Label label("Text");
  label.SizeRequest(100, 100);
  label.Align(LAST, CENTER);
  Label label2("Test2");
  Entry entry("Enter something");

  Image image("./Image/yaktocat.png", 400, 400);
  image.Align(CENTER, CENTER);

  Button button("Button");
  button.Align(BEGIN, CENTER);
  button.SignalHandler(CLICKED, G_CALLBACK(Helloworld));

  Box vbox(VER, 10);
  vbox.Add<Image>(START, image);
  vbox.Add<Label>(START, label);
  vbox.Add<Entry>(END, entry);
  vbox.Add<Label>(START, label2);
  vbox.Add<Button>(START, button);
  window.Add<Box>(vbox);
  window.InternalWidth(10);
  window.DefaultSize(640, 480);
  window.ShowAll();

  gtk_main();
  return 0;
}
