# CGui(Beta)

### Open Source Library for C++ UI based on GTK 3

## Requirments
* A Linux distribution
* GTK 3 or above
* 8th generation of C++ compiler(g++-8) with C++ version 17

## Installation
Install dependencies for CGui<br>
```
sudo apt-get install g++-8 libgtk-3-dev
```
Clone this repository
```
git clone https://github.com/Developmentprogramming/CGui.git
```
Start the installtion process
```
cd CGui/Installer/bin
chmod +x ./Installer
./Installer
```
![Installer](https://github.com/Developmentprogramming/CGui/blob/master/Examples/Installer.png)<br>
Now choose the path where you want to install, and check the **Universal Access** to get access of this library from any where on your system.<br>
And at last click on install and wait until it finsihes.<br>
**Note: This installer itself is made using this library(CGui).**<br><br>
If you want to install in **Preferred Path** location then you must run this installer with root access, and if you want to install it in the **Current Path** location or any other user's location then no need for root access.

## Precompiling headers(Only for development purpose)
```
git clone https://github.com/Developmentprogramming/CGui.git
cd CGui
make -i PrecompiledHeaders
```

## Compilation
For compile any file, use the following command line:<br>
```
g++-8 -std=c++17 file.cc `pkg-config gtk+-3.0 --cflags --libs`
```
1. Change the **file.cc** with your cpp file.<br>
2. ```g++-8``` for g++ 8th generation compiler<br>
3. ```-std=c++17``` for c++ standard version 17<br>
4. ``` `pkg-config gtk+-3.0 --cflags --libs` ``` for invoking all the GTK+ files

Compile the test file and run it(Only for testing the CGui is working): <br>
```
g++-8 -std=c++17 Main.cc -o Main `pkg-config gtk+-3.0 --cflags --libs`
./Main
```
Result:<br>
![MainResult](https://github.com/Developmentprogramming/CGui/blob/master/Examples/MainResult.png)<br>

If you see this message **Welcome to CGui**.<br>
Congratulations!!!, it's working... .

## Code Structure
```C++
// Label example
#include <CGUI.hh>

using namespace CGui;

int main(int argc, char *argv[])
{
  Init init(argc, argv); // Initialize CGui
  
  // Some code
  Window window(TOPLEVEL, "CGUI WINDOW", CEN); // Create a new Window
  
  Label label("Text");
  label.Align(CENTER, CENTER); // align the label to center horizontally and vertically
  
  window.Add<Label>(label); // add label to window
  window.DefaultSize(640, 480); // window default size
  window.InternalWidth(10); // Internal window width
  window.ShowAll(); // Show all widgets

  return 0;
}
```
Result:-<br>
![ExampleOne](https://github.com/Developmentprogramming/CGui/blob/master/Examples/ExampleOne.png)

```C++
//Image Example
#include <CGUI.hh>

using namespace CGui;

int main(int argc, char *argv[])
{
  Init init(argc, argv); // Initialize CGui
  
  // Some Code
  Window window(TOPLEVEL, "CGUI WINDOW", CEN); // Create a new Window
  
  Image image("./Image/yaktocat.png", 400, 400); // create a new image at scale of 400X400
  image.Align(CENTER, CENTER); // align the image to center horizontally and vertically
  
  window.Add<Image>(image); // add image to window
  window.DefaultSize(640, 480); // window default size
  window.InternalWidth(10); // Internal window width
  window.ShowAll(); // Show all widgets 
  
  return 0;
}
```
Result:- <br>
![ExampleTwo](https://github.com/Developmentprogramming/CGui/blob/master/Examples/ExampleTwo.png)

```C++ 
// Button example
#include <CGUI.hh>
#include <iostream>

using namespace CGui;

static void Button_Clicked()
{
  std::cout << "Hello World" << std::endl;
}

int main(int argc, char *argv[])
{
  Init init(argc, argv); // Initialize CGui
  
  // Some Code
  Window window(TOPLEVEL, "CGUI WINDOW", CEN); // Create a new Window
  
  Button button("Button"); // Create a new button
  button.Align(CENTER, CENTER); // align button to center horizontally and vertically
  button.Clicked(Button_Clicked);
  
  window.Add<Button>(button); // add button to window
  window.DefaultSize(640, 480); // window default size
  window.InternalWidth(10); // Internal window width
  window.ShowAll(); // Show all widgets
  
  return 0;
}
```
Result:- <br>
![ExampleThree](https://github.com/Developmentprogramming/CGui/blob/master/Examples/ExampleThree.png)<br>
On Button clicked:- <br>
![ExampleThreeButtonClicked](https://github.com/Developmentprogramming/CGui/blob/master/Examples/ExampleThreeButtonClicked.png)

## Contribution
**Email: developmentprogramming154@gmail.com**

## Owner Info
**Name: Parth Lodhia** <br>
**Age: 17** <br>
**Email: parthlodhia154@gmail.com**
