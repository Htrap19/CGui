#pragma once

#include "./FileChooserDialog.hh"

namespace CGui
{
  FileChooserDialog::FileChooserDialog(Action action, Window &window, const char *title)
  {
    Dialog dialog(window, true, title);
    FileChooser chooser(action);

    dialog.Add(chooser);
    dialog.InternalWidth(10);
  }
};
