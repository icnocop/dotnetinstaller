//
//  sciter-gtk-main.mm
//  sciter
//
//  Created by andrew on 2014-12-05.
//  Copyright (c) 2014 Andrew Fedoniouk. All rights reserved.
//

#include <gtk/gtk.h>
#include <locale.h>

#include "sciter-x-window.hpp"
#include "aux-cvt.h"

using namespace aux;

static std::vector<sciter::string> _argv;

#ifndef SKIP_MAIN
int main (int argc, char *argv[])
{
  for(int n = 0; n < argc; ++n)
    _argv.push_back(utf2w(chars_of(argv[n])));
  //SciterSetOption(NULL, SCITER_SET_GFX_LAYER, GFX_LAYER_CAIRO);
  sciter::application::start();
  int r = uimain([]() -> int { return sciter::application::run(); });
  sciter::application::shutdown();
}
#endif


namespace sciter {

  GtkWidget* gview(HWINDOW hwnd) { return hwnd; }
  GtkWindow* gwindow(HWINDOW hwnd) { return hwnd ? GTK_WINDOW(gtk_widget_get_toplevel(hwnd)): nullptr; }

  namespace application {
    HINSTANCE hinstance()
    {
      return nullptr; // not used
    }

    const std::vector<sciter::string>& argv() {
      return _argv;
    }
  }

}
