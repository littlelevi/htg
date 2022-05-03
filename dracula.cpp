#include "knownElements.hpp"
#include "helixElement.hpp"
#include "themeDracula.hpp"

int main () {

ThemeDracula dracula;


Style WIDGET = Style(dracula.palette.at("foreground"),"#13141E");

printComment ("=== Dracula from htg ===");

printComment  (" -- Diagnostic -- ");
warning(); //Editor warnings.
error(dracula.palette.at("red")); // Editor errors, like mis-typing a command.
info(dracula.palette.at("cyan")); // Code diagnostic info in gutter (LSP).
// ? Difference between info and hint ?
hint(dracula.palette.at("orange")); // Code diagnostics hint in gutter (LSP).
diagnostic(dracula.palette.at("cyan")); // Code diagnostics in editing area (LSP).

/*
# UI ==============================
# For styling helix itself.
*/
 
printComment ("-- UI --");

ui_background(dracula.palette.at("foreground"), dracula.palette.at("background")); // Default background color.
ui_window(); // Window border between splits.

ui_gutter(dracula.palette.at("background")); // Left gutter for diagnostics and breakpoints.

ui_text(dracula.palette.at("foreground")); // Default text color.
ui_text_focus(dracula.palette.at("cyan"), {mod::bold}); // Selection highlight in buffer-picker or file-picker.
ui_text_info = WIDGET; // Info popup contents (space mode menu).

ui_cursor(ui_cursor_primary); // Fallback cursor colour, non-primary cursors when there are multiple (shift-c).
ui_cursor_primary(dracula.palette.at("background"), dracula.palette.at("pink")); // The primary cursor when there are multiple (shift-c).
ui_cursor_insert(ui_cursor_primary); // The cursor in insert mode (i).
ui_cursor_select(ui_cursor_primary); // The cursor in select mode (v).
ui_cursor_match(dracula.palette.at("foreground"), dracula.palette.at("pink"), {mod::rapid_blink}); // The matching parentheses of that under the cursor.

ui_selection(ui_cursor_primary); // All currently selected text.
ui_selection_primary(ui_cursor_primary); // The primary selection when there are multiple.

ui_linenr(dracula.palette.at("comment")); // Line numbers.
ui_linenr_selected(dracula.palette.at("foreground")); // Current line number.
 
ui_virtual(); // Namespace for additions to the editing area.
ui_virtual_ruler(dracula.palette.at("orange")); // Vertical rulers (colored columns in editing area).
ui_virtual_whitespace(); // Whitespace markers in editing area.
// NOTE: Indent guides aren"t yet added at the time of writing, but will be soon.
ui_virtual_indent_guide(); // Indentation guides.

ui_statusline = WIDGET; // Status line.
ui_statusline_inactive(); // Status line in unfocused windows.

ui_help = WIDGET; // `:command` descriptions above the command line.

ui_highlight(dracula.palette.at("cyan"), dracula.palette.at("background")); // selected contents of symbol pickers (spc-s, spc-S) and current line in buffer picker (spc-b).

ui_menu = WIDGET; // Autocomplete menu.
ui_menu_selected(dracula.palette.at("cyan"), dracula.palette.at("background")); // Selected autocomplete item.

ui_popup = WIDGET; // Documentation popups (space-k).
ui_popup_info = WIDGET; // Info popups box (space mode menu).

/*
# SYNTAX HIGHLIGHTING ==============================
# All the keys here are Treesitter scopes.
*/
  
printComment ("-- Syntax Highlighting --");

property(); // Regex group names.
special(); // Special symbols e.g `?` in Rust, `...` in Hare.
module(); // Unclear, used for Heex module.
attribute(); // Class attributes, html tag attributes.

type(dracula.palette.at("cyan"), {mod::italic}); // Variable type, like integer or string, including program defined classes, structs etc..
type_builtin(type); // Primitive types of the language (string, int, float).
type_enum_variant(type); // A variant of an enum.

constructor(function_); // Constructor method for a class or struct.

constant(dracula.palette.at("pink")); // Constant value
constant_builtin(constant); // Special constants like `true`, `false`, `none`, etc.
constant_builtin_boolean(constant); // True or False.
constant_character(constant); // Constant of character type.
constant_character_escape(constant); // escape codes like \n.
constant_numeric(constant);
constant_number (constant); // constant integer or float value.
constant_number_integer(constant); // constant integer value.
constant_number_float(constant); // constant float value.

string_(dracula.palette.at("yellow")); // String literal.
string_regexp(dracula.palette.at("red")); // Regular expression literal.
string_special(string_); // Strings containing a path, URL, etc.
string_special_path(string_special); // String containing a file path.
string_special_url(string_special); // String containing a web URL.
string_special_symbol(string_special); // Erlang/Elixir atoms, Ruby symbols, Clojure keywords.

comment(dracula.palette.at("comment")); // This is a comment.
comment_line(comment); // Line comments, like this.
comment_block(comment);// Block comments, like this */ /*in some languages.
comment_block_documentation(dracula.palette.at("orange"), {mod::italic}); // Doc comments, e.g '///' in rust.

variable(dracula.palette.at("foreground")); // Variable names.
variable_builtin(); // Language reserved variables: `this`, `self`, `super`, etc.
variable_parameter(dracula.palette.at("orange"), {mod::italic}); //{ } // Funtion parameters.
variable_other_member(); // Fields of composite data types (e.g. structs, unions).
variable_function(); // ?

label(); // Loop labels in rust.

punctuation(dracula.palette.at("pink"));
punctuation_delimeter(punctuation); // Commas and colons.
punctuation_bracket(dracula.palette.at("pink")); // Parentheses, angle brackets, etc.

printComment("== Keywords ==");
        
keyword(dracula.palette.at("pink")); // Language reserved keywords.
keyword_control(keyword); // Control keywords.
keyword_control_conditional(keyword); // 'if', 'else', 'elif'.
keyword_control_repeat(keyword); // 'for', 'while', 'loop'.
keyword_control_import(keyword); // 'import', 'export' ('use'?).
keyword_control_return(keyword); // 'return' in most languages.
keyword_control_exception(keyword); // 'raise' in python.
keyword_operator(keyword); // 'or', 'and', 'in'.
keyword_directive(keyword); // Preprocessor directives (#if in C).
keyword_function(keyword); // The keyword to define a funtion: 'def', 'fun', 'fn'.

operator_(dracula.palette.at("red")); // Logical (&&, ||) and - I assume - Mathematical (+, %) operators

printComment("== Functions ==");
  
function_(dracula.palette.at("green"));
function_builtin(function_);
function_method (function_); // // Class / Struct methods.
function_macro  (function_); // // Like macros in rust.
function_special(function_); // // Preprocessor in C.

tag(dracula.palette.at("pink")); // As in <body> for html.

namespace_(); // * Namespace keyword in java, C#, etc.

/*
# Markup ==============================
# Colors for markup languages, like Markdown or XML.
*/

printComment("== Markup ==");
  
markup_heading_1(dracula.palette.at("orange"),{mod::bold}); // Markdown heading 1 color.
markup_heading_2(markup_heading_1); // Markdown heading 2 color.
markup_heading_3(markup_heading_1); // Markdown heading 3 color.
markup_heading_4(markup_heading_1); // Markdown heading 4 color.
markup_heading_5(markup_heading_1); // Markdown heading 5 color.
markup_heading_6(markup_heading_1); // Markdown heading 6 color.
markup_heading_marker(markup_heading_1); // Hashtag color on Markdown headings.

markup_list(dracula.palette.at("cyan"));
markup_list_numbered(markup_list); // Numbered list.
markup_list_unnumbered(markup_list); // Bullet point list.

markup_bold  (dracula.palette.at("orange"), {mod::bold}); // Bold text.
markup_italic(dracula.palette.at("yellow"), {mod::italic}); // Italicised text.

markup_link(dracula.palette.at("cyan"));
markup_link_url  (); // Urls pointed to by links.
markup_link_label(); // Non-URL link references.
markup_link_text (dracula.palette.at("pink")); // URL and image descriptions in links.

markup_quote(dracula.palette.at("yellow"), {mod::italic}); // `> Quotes` in Markdown.

/*
# Markup - Interface ==============================
# "These scopes are used for theming the editor interface."
*/

printComment("== Markup Interface ==");
  
markup_normal();
markup_normal_completion = WIDGET; //For completion doc popup ui.
markup_normal_raw = WIDGET; // # For hover popup ui.

markup_heading_completion({mod::bold}); // Headings for completion doc popup ui.
markup_heading_raw(); // Headings for hover popup ui.

markup_raw(); // Code block in Markdown.
markup_raw_block(); // Multiline (```) codeblock in Markdown.
markup_raw_inline(); //`Inline code block` in Markdown.

markup_raw_inline_completion(); // ?
markup_raw_inline_hover(); // ?
  
/*
# Diff ==============================
# Version control changes.
*/  

printComment("== Diff ==");

diff_plus (dracula.palette.at("green")); // Additions.
diff_minus(dracula.palette.at("red")); // Deletions.
diff_delta(dracula.palette.at("orange")); // Modifications.
diff_delta_moved(diff_delta); // Renamed or moved files / changes.

return 0;
}