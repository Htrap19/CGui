# CGui(Beta)

### Open Source Library for C++ UI based on GTK 3

## Requirments
* A Linux distribution
* GTK 3 or above
* 8th generation of C++ compiler(g++-8) with C++ version 17

## Code Structure
```C++
// Label example
#include <CGUI.hh>

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv); // Initialize gtk
  
  // Some code
  Window window(TOPLEVEL, "CGUI WINDOW", CEN); // Create a new Window
  
  Label label("Text");
  label.Align(CENTER, CENTER); // align the label to center horizontally and vertically
  
  window.Add<Label>(label); // add label to window
  window.DefaultSize(640, 480); // window default size
  window.InternalWidth(10); // Internal window width
  window.ShowAll(); // Show all widgets 
  
  gtk_main(); // End gtk

  return 0;
}
```
Result:-<br>
![ExampleOne](https://github.com/Developmentprogramming/CGui/blob/master/Examples/ExampleOne.png)

```C++
//Image Example
#include <CGUI.hh>

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv); // Initialize gtk
  
  // Some Code
  Window window(TOPLEVEL, "CGUI WINDOW", CEN); // Create a new Window
  
  Image image("./Image/yaktocat.png", 400, 400); // create a new image at scale of 400X400
  image.Align(CENTER, CENTER); // align the image to center horizontally and vertically
  
  window.Add<Image>(image); // add image to window
  window.DefaultSize(640, 480); // window default size
  window.InternalWidth(10); // Internal window width
  window.ShowAll(); // Show all widgets 
  
  gtk_main(); // End gtk
  return 0;
}
```
Result:- <br>
![ExampleTwo](https://github.com/Developmentprogramming/CGui/blob/master/Examples/ExampleTwo.png)

```C++ 
// Button example
#include <CGUI.hh>
#include <iostream>

static void Button_Clicked(GtkWidget *widget, gpointer data)
{
  std::cout << "Hello World" << std::endl;
}

int main(int argc, char *argv[])
{
  gtk_init(&argc, &argv); // Initialize gtk
  
  // Some Code
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
```

## Compilation
```
git clone https://github.com/Developmentprogramming/CGui.git
cd CGui
g++-8 -std=c++17 Main.cc -o Main `pkg-config gtk+-3.0 --cflags --libs`
```
## Contribution
**Email: developmentprogramming154@gmail.com**

## Owner Info
**Name: Parth Lodhia** <br>
**Age: 17** <br>
**Email: parthlodhia154@gmail.cm**
