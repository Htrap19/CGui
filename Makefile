CC = g++-8 -std=c++17
libgtk = `pkg-config gtk+-3.0 --cflags --libs`

PrecompiledHeaders: CGUI.hh CGuiBox.hh CGuiButton.hh CGuiEntry.hh CGuiImage.hh CGuiLabel.hh CGuiWidget.hh Convert.hh CGuiCssProvider.hh
	make PrecompileCGUI && make PrecompileCGuiWindow && make PrecompileCGuiBox && make PrecompileCGuiButton && make PrecompileCGuiEntry && make PrecompileCGuiImage && make PrecompileCGuiLabel && make PrecompileCGuiWidget && make PrecompileCGuiConvert && make PrecompileCGuiCssProvider && make PrecompileCGuiHeaderbar

PrecompileCGUI: CGUI.hh
	$(CC) CGUI.hh $(libgtk)

PrecompileCGuiWindow: CGuiWindow.hh
	$(CC) CGuiWindow.hh $(libgtk)

PrecompileCGuiBox: CGuiBox.hh
	$(CC) CGuiBox.hh $(libgtk)

PrecompileCGuiButton: CGuiButton.hh
	$(CC) CGuiButton.hh $(libgtk)

PrecompileCGuiEntry: CGuiEntry.hh
	$(CC) CGuiEntry.hh $(libgtk)

PrecompileCGuiImage: CGuiImage.hh
	$(CC) CGuiImage.hh $(libgtk)

PrecompileCGuiLabel: CGuiLabel.hh
	$(CC) CGuiLabel.hh $(libgtk)

PrecompileCGuiWidget: CGuiWidget.hh
	$(CC) CGuiWidget.hh $(libgtk)

PrecompileCGuiConvert: Convert.hh
	$(CC) Convert.hh $(libgtk)

PrecompileCGuiCssProvider: CGuiCssProvider.hh
	$(CC) CGuiCssProvider.hh $(libgtk)

PrecompileCGuiHeaderbar: CGuiHeaderbar.hh
	$(CC) CGuiHeaderbar.hh $(libgtk)
