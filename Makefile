CC = g++-8 -std=c++17
libgtk = `pkg-config gtk+-3.0 --cflags --libs`

PrecompiledHeaders: CGUI.hh ./Widgets/Box/Box.hh ./Widgets/Button/Button.hh ./Widgets/Entry/Entry.hh ./Widgets/Image/Image.hh ./Widgets/Label/Label.hh ./Widgets/Widget.hh ./Converter/Convert.hh ./Widgets/CssProvider/CssProvider.hh
	make PrecompileCGUI && make PrecompileCGuiWindow && make PrecompileCGuiBox && make PrecompileCGuiButton && make PrecompileCGuiEntry && make PrecompileCGuiImage && make PrecompileCGuiLabel && make PrecompileCGuiWidget && make PrecompileCGuiConvert && make PrecompileCGuiCssProvider && make PrecompileCGuiHeaderbar && make PrecompileCGuiCheckButton && make PrecompileCGuiProgressbar && make PrecompileCGuiRevealer && make PrecompileCGuiInfobar

PrecompileCGUI: CGUI.hh
	$(CC) CGUI.hh $(libgtk)

PrecompileCGuiWindow: ./Widgets/Window/Window.hh
	$(CC) ./Widgets/Window/Window.hh $(libgtk)

PrecompileCGuiBox: ./Widgets/Box/Box.hh
	$(CC) ./Widgets/Box/Box.hh $(libgtk)

PrecompileCGuiButton: ./Widgets/Button/Button.hh
	$(CC) ./Widgets/Button/Button.hh $(libgtk)

PrecompileCGuiEntry: ./Widgets/Entry/Entry.hh
	$(CC) ./Widgets/Entry/Entry.hh $(libgtk)

PrecompileCGuiImage: ./Widgets/Image/Image.hh
	$(CC) ./Widgets/Image/Image.hh $(libgtk)

PrecompileCGuiLabel: ./Widgets/Label/Label.hh
	$(CC) ./Widgets/Label/Label.hh $(libgtk)

PrecompileCGuiWidget: ./Widgets/Widget.hh
	$(CC) ./Widgets/Widget.hh $(libgtk)

PrecompileCGuiConvert: ./Converter/Convert.hh
	$(CC) ./Converter/Convert.hh $(libgtk)

PrecompileCGuiCssProvider: ./Widgets/CssProvider/CssProvider.hh
	$(CC) ./Widgets/CssProvider/CssProvider.hh $(libgtk)

PrecompileCGuiHeaderbar: ./Widgets/Headerbar/Headerbar.hh
	$(CC) ./Widgets/Headerbar/Headerbar.hh $(libgtk)

PrecompileCGuiCheckButton: ./Widgets/CheckButton/CheckButton.hh
	${CC} ./Widgets/CheckButton/CheckButton.hh ${libgtk}

PrecompileCGuiProgressbar: ./Widgets/Progressbar/Progressbar.hh
	${CC} ./Widgets/Progressbar/Progressbar.hh ${libgtk}

PrecompileCGuiRevealer: ./Widgets/Revealer/Revealer.hh
	${CC} ./Widgets/Revealer/Revealer.hh ${libgtk}

PrecompileCGuiInfobar: ./Widgets/Infobar/Infobar.hh
	${CC} ./Widgets/Infobar/Infobar.hh ${libgtk}
