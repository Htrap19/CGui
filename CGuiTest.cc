#include "CGUI.hh"
#include <iostream>

static void Button_Clicked(GtkWidget *widget, gpointer data)
{
  std::cout << "Hello World" << std::endl;
}

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv); // Initialize gtk

  Window window(TOPLEVEL, "CGUI WINDOW", CEN); // Create a new Window

  Button button("Button"); // Create a new button
  button.Align(CENTER, CENTER); // align button to center horizontally and vertically
  button.SignalHandler(CLICKED, G_CALLBACK(Button_Clicked)); // add signal handler

  window.Add<Button>(button); // add button to window
  window.DefaultSize(640, 480); // window default size
  window.InternalWidth(10); // Internal window width
  window.ShowAll(); // Show all widgets

  gtk_main(); // End gtk
  return 0;
}
