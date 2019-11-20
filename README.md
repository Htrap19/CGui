# CGui

### Open Source Library for C++ UI based on GTK 3

## Requirments
* A Linux distribution
* GTK 3 or above
* 8th generation of C++ compiler(g++-8) with C++ version 17

## Code Structure
```C++
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
Result:-
![ExampleOne]()

## Compilation
```
git clone https://github.com/Developmentprogramming/CGui.git
cd CGui
g++-8 Main.cc -o Main `pkg-config gtk+-3.0 --cflags --libs`
```
## Contribution
**Email: developmentprogramming154@gmail.com**

## Owner Info
**Name: Parth Lodhia** <br>
**Age: 16** <br>
**Email: parthlodhia154@gmail.cm**
