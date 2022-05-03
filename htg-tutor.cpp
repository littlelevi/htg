#include "knownElements.hpp"
#include "helixElement.hpp"

int main () {
  
// ============================== Usage ==============================
// Every variable coresponds to helix element hierarchy.
// To Style element use its name and  replace '.' with '_'
// Some variables must have '_' at end the because they are language registered names.
// ===================================================================
// Defining colors
// ===================================================================

string white = "#ffffff";
string black = "#000000";

// ===================================================================
// Using variables and strings
// ===================================================================
// This Will print comment
printComment("=== Using Variable and strings ===");

markup_heading_1("#ffffff");  
markup_heading_2(white);

markup_heading_3("#ffffff", "#ffffff");
markup_heading_4(white, black);
  
markup_heading_5(make_pair(white, white));
  
// ===================================================================
// Valid modifiers
// ===================================================================
/*   
mod::bold, 
mod::dim, 
mod::italic, 
mod::underlined, 
mod::slow_blink, 
mod::rapid_blink,
mod::reversed,
mod::hidden,
mod::crossed_out
*/

// ===================================================================
// Using style modifiers
// ===================================================================

printComment("=== Using style modifier ===");

markup_normal(white, {mod::bold});
markup_normal_completion(white, white, {mod::dim});

// ============================== Best Practices==============================
//
// The best practice to use a map palette, it ensures that the color used in this way
// will be generated in [palette] section.
//
// ===========================================================================

// ===================================================================
// Registering color in the map Pallete
// ===================================================================

palette.insert({"white", "#ffffff"});
palette.insert({"black", "#000000"});

// ===================================================================
// Need another Pallete ? Why Not !
// ===================================================================
ColorPalette gruvbox;

gruvbox.insert({"orange", "#fe8019"});
gruvbox.insert({"rusty", "#d65d0e"});
//gruvbox.insert ...

// --- Add whole gruvbox pallete to main Pallete
//palette.merge(gruvbox);

// ---- Or just only one color under different name
palette.insert({"dirty_red" ,gruvbox.at("rusty")});

// ---- Or just copy whole color from grubbox as it is
palette.insert(gruvbox.extract("orange"));

// ===================================================================
// Using color names from palette
// ===================================================================

printComment("=== Using Named Keys from palette ===");

ui_text(palette.at("white"), {mod::bold});
ui_background (palette.at("white"), palette.at("black"));
function_ (palette.at("white"),palette.at("black"), {mod::italic});

// ===================================================================
// Ann finnaly copying one style to another and print it
// ===================================================================
markup_list(white, white, {mod::italic, mod::bold, mod::bold});
markup_list_numbered(markup_list);
markup_list_numbered();

// As you might guess, this will generete collor pallete
generetePalette();
return 0;
}