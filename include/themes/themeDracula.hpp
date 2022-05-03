#pragma once
#include "helixElement.hpp"

class ThemeDracula {
public:
  ColorPalette palette;

  ThemeDracula() {
    palette.insert({"background", "#282a36"});
    palette.insert({"currentLine", "#44475a"});
    palette.insert({"foreground", "#f8f8f2"});
    palette.insert({"comment", "#6272a4"});
    palette.insert({"cyan", "#8be9fd"});
    palette.insert({"green", "#50fa7b"});
    palette.insert({"orange", "#ffb86c"});
    palette.insert({"pink", "#ff79c6"});
    palette.insert({"purple", "#bd93f9"});
    palette.insert({"red", "#ff5555"});
    palette.insert({"yellow", "#f1fa8c"});
  }
};