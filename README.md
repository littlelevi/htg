# HTG

Helix template generator is simple C++ template system allowing to output
valid Helix template code directly from C++ source.

## Usage

Copy yourself fresh empty template from `emptyTemplate.cpp` under desired name.
The file contains a ready-made set of Helix elements, ready for styling.

There are two additional files in the project directory. The first one is theme `dracula.cpp`
which was used as a test field for this app.
The second is `htg-tutor.cpp` which is roughly the same as this README and shows htg features.

Every variable corresponds to helix element that allows for independent styling
Some variables must end with `'_'` because their names are language registered keywords.

# Brief Introduction for non C++ programers

Becase lack of knowledge is never a reason to waste time

## Defining colors

```
string white = "#ffffff";
string black = "#000000";
```

## This will output comment

```printComment("=== This will output comment ===");```

## Using variables and strings

```
markup_heading_1("#ffffff");  // ==> "string" = {fg = "#ffffff"}
markup_heading_2(white);      // ==> "string" = {fg = "#ffffff"}

markup_heading_3("#ffffff", "#ffffff");  // ==> "string" = {fg = "#ffffff", bg = "#ffffff"}
markup_heading_4(white, black);          // ==> "string" = {fg = "#ffffff", bg = "#000000"}

markup_heading_5(make_pair(white, white)); // ==> "string" = {fg = "#ffffff", bg = "#ffffff"}
```

## Valid modifiers

```
mod::bold, 
mod::dim, 
mod::italic, 
mod::underlined, 
mod::slow_blink, 
mod::rapid_blink,
mod::reversed,
mod::hidden,
mod::crossed_out
```

## Using style modifiers

```
markup_normal(white, {mod::bold}); // ==> "string" = {fg = "#ffffff", bg = "#000000", modifiers = ["bold"]}
markup_normal_completion(white, white, {mod::dim, mod::italic});  // ==> "string" = {fg = "#ffffff", modifiers = ["bold", "dim"]}
```

## Best Practices

The best practice is to use a map palette, it ensures that the color used in this way
will be properly generated in `[palette]` section.

## Registering color in the Pallete map

```
palette.insert({"white", "#ffffff"});
palette.insert({"black", "#000000"});
```

## Need another Pallete ? Why Not !?

```
ColorPalette gruvbox;

gruvbox.insert({"orange", "#fe8019"});
gruvbox.insert({"rusty",  "#d65d0e"});
```

### Add whole gruvbox pallete to main Pallete

```palette.merge(gruvbox);```

### Or just only one color under different name

```palette.insert({"dirty_red" ,gruvbox.at("rusty")});```

### Or just whole color as it is

```palette.insert(gruvbox.extract("orange"));```

## Using color names from palette

```
ui_text(palette.at("white"), {mod::bold});
ui_background (palette.at("white"), palette.at("black"));
function_ (palette.at("white"),palette.at("black"), {mod::italic});
```

## And finally copying one style to another and print it

```
markup_list(white, white, {mod::italic, mod::bold, mod::bold});
markup_list_numbered(markup_list);
```

### As you might guess, this will generete `[pallete]` section

```generetePalette();```

## Independend Styles

HTG allows for independent styles that wont beoutputet in final helix template


```
Style Boring_style = Style("#ffffff", "#000000");
ui_background = Boring_style;
```
## Installation

Run theme binary to find errors.
HTG uses Makefiles for quick theme compilation and installation
By default `make` will compile and install `dracula` theme.

`make TARGET=<yourCppTheme>` will compile and ouput file as  `<yourCppTheme>-htg.toml`
and will automatically copy it to `./.config/helix/themes/` directory keeping compiling
and testing cycle as much fast as in case of hand written files.