# CGui(Beta)

### Open Source Library for C++ UI based on GTK 3

## Requirments
* Window 7, 8.1, 10 or Linux distribution
* GTK+ 3.22 or later
* gcc on Linux or MSVC on Window
* Git

For further more experience use the C++ standard 17 or later.

## Tested on
* Windows 10 with Visual Studio 2019
* Ubuntu 18.02 LTS, and Ubuntu 20.04 LTS

## Installation
### Windows with visual studio
[Install gtk on windows with vcpkg](https://www.gtk.org/docs/installations/windows/#using-gtk-from-vcpkg-packages)

Clone this repository

```
git clone https://github.com/Developmentprogramming/CGui.git
```

1. Open the visual studio and create a new **cpp empty console project(CGui)**.
2. Copy the cloned repository to the **cpp empty console project(CGui)** except Makefile, Main.cc, Examples/, Image/ Readme.md.
3. Right click **cpp empty console project(CGui)**->Properties->Configuration Properties->General->Configuration Type and select **Static library**.
4. Create a new **cpp empty console project2(your_project_name)**.
5. Add a reference of **cpp empty console project(CGui)** to **cpp empty console project2(your_project_name)**.
6. Right click **cpp empty console project2(your_project_name)**->Properties->Configuration Properties->C/C++->General->Additional include directories and add the path of **cpp empty console project(CGui)**.

### Linux
Install dependencies for CGui<br>
```
sudo apt-get install g++-8 libgtk-3-dev git make
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

#### Precompiling headers(Only for development purpose)
```
git clone https://github.com/Developmentprogramming/CGui.git
cd CGui
make -i PrecompiledHeaders
```

#### Compilation
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
  Window window(WindowType::TOPLEVEL, "CGUI WINDOW", WindowPos::CENTER); // Create a new Window
  
  Label label("Text");
  label.Align(Alignments::CENTER, Alignments::CENTER); // align the label to center horizontally and vertically
  
  window.Add(label); // add label to window
  window.DefaultSize(640, 480); // window default size
  window.InternalWidth(10); // Internal window width
  window.ShowAll(); // Show all widgets
  
  init.Render(); // Start the main loop

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
  Window window(WindowType::TOPLEVEL, "CGUI WINDOW", WindowPos::CEN); // Create a new Window
  
  Pixbuf pixbuf("./Image/yaktocat.png", 400, 400);
  Image image(pixbuf); // create a new image of size of 400X400
  image.Align(Alignments::CENTER, Alignments::CENTER); // align the image to center horizontally and vertically
  
  window.Add(image); // add image to window
  window.DefaultSize(640, 480); // window default size
  window.InternalWidth(10); // Internal window width
  window.ShowAll(); // Show all widgets 
  
  init.Render(); // Start the main loop
  
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
  Window window(WindowType::TOPLEVEL, "CGUI WINDOW", WindowPos::CENTER); // Create a new Window
  
  Button button("Button"); // Create a new button
  button.Align(Alignments::CENTER, Alignments::CENTER); // align button to center horizontally and vertically
  button.Clicked(Button_Clicked);
  
  window.Add(button); // add button to window
  window.DefaultSize(640, 480); // window default size
  window.InternalWidth(10); // Internal window width
  window.ShowAll(); // Show all widgets
  
  init.Render(); // Start the main loop
  
  return 0;
}
```
Result:- <br>
![ExampleThree](https://github.com/Developmentprogramming/CGui/blob/master/Examples/ExampleThree.png)<br>
On Button clicked:- <br>
![ExampleThreeButtonClicked](https://github.com/Developmentprogramming/CGui/blob/master/Examples/ExampleThreeButtonClicked.png)

## Contribution
**Email: developmentprogramming154@gmail.com**

## Developer Info
**Name: Parth Lodhia** <br>
**Age: 17** <br>
**Email: parthlodhia154@gmail.com**
