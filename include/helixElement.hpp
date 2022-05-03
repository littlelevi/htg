#pragma once
#include <exception>
#include <initializer_list>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

using ColorBundle = pair<string, string>;
using ColorPalette = map<string, string>;

enum mod {
  bold,
  dim,
  italic,
  underlined,
  slow_blink,
  rapid_blink,
  reversed,
  hidden,
  crossed_out,
};

const string red = "\033[31m";

struct BadColorLength : public exception {
  const char *what() const throw() { return "Bad color length -> "; }
};

struct NoBang : public exception {
  const char *what() const throw() {
    return "Color lacks '#' at the beginning -> ";
  }
};

struct UndefinedColor : public exception {
  const char *what() const throw() {
    return "Undefined Color, empty \"...\" -> ";
  }
};

ColorPalette palette;

void generetePalette() {
  cout << '\n' << "[palette]" << endl;
  for (const auto &color : palette) {
    cout << color.first << " = " << color.second << endl;
  }
}

void printComment(string comment) {
  cout << '\n' << "# " << comment << '\n' << endl;
}

class Style {
public:
  string foreground;
  string background;
  vector<string> modifiers;

public:
  Style() {}
  Style(string fg) : foreground(fg) {}
  Style(string fg, string bg) : foreground(fg), background(bg) {}

  Style(string fg, string bg, initializer_list<mod> mod)
      : foreground(fg), background(bg) {
    loopOverMods(mod);
  }

  Style(initializer_list<mod> mod) { loopOverMods(mod); }

  void loopOverMods(initializer_list<mod> &mod) {
    for (auto i : mod) {
      switch (i) {
      case bold:
        modifiers.push_back("bold");
        break;
      case dim:
        modifiers.push_back("dim");
        break;
      case italic:
        modifiers.push_back("italic");
        break;
      case underlined:
        modifiers.push_back("underlined");
        break;
      case slow_blink:
        modifiers.push_back("slow_blink");
        break;
      case rapid_blink:
        modifiers.push_back("rapid_blink");
        break;
      case reversed:
        modifiers.push_back("reversed");
        break;
      case hidden:
        modifiers.push_back("hidden");
        break;
      case crossed_out:
        modifiers.push_back("crossed_out");
      }
    }
  }
};

class E : Style {
public:
  string scope;

  void checkGrammar(string &fg, string &bg) {
    if (fg.empty() || bg.empty()) {
      throw UndefinedColor();
    }

    if (!fg.empty() || !bg.empty()) {
      if (fg.at(0) != '#' || bg.at(0) != '#') {
        throw NoBang();
      }
    }

    if (fg.length() != 7 || bg.length() != 7) {
      throw BadColorLength();
    }
  }

  void checkGrammar(string &fg) {
    if (fg.empty()) {
      throw UndefinedColor();
    }

    if (!fg.empty()) {
      if (fg.at(0) != '#') {
        throw NoBang();
      }
    }

    if (fg.length() != 7) {
      throw BadColorLength();
    }
  }

  void printMod() {
    for (auto it = modifiers.begin(); it != modifiers.end(); ++it) {

      if (it == modifiers.end() - 1) {
        cout << "\"" << *it << "\"";
      } else {
        cout << "\"" << *it << "\""
             << ", ";
      }
    }
  }

  void print() {
    cout << scope << " = {" << foreground << background;

    if (!modifiers.empty() && foreground.empty() && background.empty()) {
      cout << "modifiers = [";
      printMod();
      cout << "]";
    }

    else if (!modifiers.empty()) {
      cout << ", modifiers = [";
      printMod();
      cout << "]";
    }
    cout << "}" << endl;
  }

public:
  E(std::string scope) : scope("\"" + scope + "\"") {}
  E &operator=(const Style &s) {
    foreground = "fg = \"" + s.foreground + "\", ";
    background = "bg = \"" + s.background + "\"";
    modifiers = s.modifiers;
    print();
    return *this;
  }

  void operator()() { print(); }

  void operator()(string fg, string bg) {
    try {
      checkGrammar(fg, bg);
    } catch (exception &e) {
      cout << red << "Error: " << e.what();
    }
    foreground = "fg = \"" + fg + "\", ";
    background = "bg = \"" + bg + "\"";
    print();
  }

  void operator()(const E &e) {
    foreground = e.foreground;
    background = e.background;
    modifiers = e.modifiers;
    print();
  }

  void operator()(ColorBundle color) {
    try {
      checkGrammar(color.first, color.second);
    } catch (exception &e) {
      cout << red << "Error: " << e.what();
    }

    foreground = "fg = \"" + color.first + "\", ";
    background = "bg = \"" + color.second + "\"";
    print();
  }

  void operator()(ColorBundle color, initializer_list<mod> mod) {
    try {
      checkGrammar(color.first, color.second);
    } catch (exception &e) {
      cout << red << "Error: " << e.what();
    }
    foreground = "fg = \"" + color.first + "\", ";
    background = "bg = \"" + color.second + "\"";
    loopOverMods(mod);

    print();
  }

  void operator()(string fg) {

    try {
      checkGrammar(fg);
    } catch (exception &e) {
      cout << red << "Error: " << e.what();
    }

    foreground = "fg = \"" + fg + "\"";
    print();
  }
  void operator()(string fb, string bg, initializer_list<mod> mod) {

    try {
      checkGrammar(fb, bg);
    } catch (exception &e) {
      cout << red << "Error: " << e.what();
    }

    foreground = "fg = \"" + fb + "\", ";
    background = "bg = \"" + bg + "\"";
    loopOverMods(mod);
    print();
  }

  void operator()(string fb, initializer_list<mod> mod) {

    try {
      checkGrammar(fb);
    } catch (exception &e) {
      cout << red << "Error: " << e.what();
    }

    foreground = "fg = \"" + fb + "\"";
    background.clear();
    loopOverMods(mod);
    print();
  }

  void operator()(initializer_list<mod> mod) {

    foreground.clear();
    background.clear();
    loopOverMods(mod);
    print();
  }
};