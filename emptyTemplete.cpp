#include "knownElements.hpp"
#include "helixElement.hpp"

int main () {

warning(); //Editor warnings.
error(); // Editor errors, like mis-typing a command.
info(); // Code diagnostic info in gutter (LSP).
// ? Difference between info and hint ?
hint(); // Code diagnostics hint in gutter (LSP).
diagnostic(); // Code diagnostics in editing area (LSP).

/*
# UI ==============================
# For styling helix itself.
*/

ui_background(); // Default background color.
ui_window(); // Window border between splits.

ui_gutter(); // Left gutter for diagnostics and breakpoints.

ui_text(); // Default text color.
ui_text_focus(); // Selection highlight in buffer-picker or file-picker.
ui_text_info(); // Info popup contents (space mode menu).

ui_cursor(); // Fallback cursor colour, non-primary cursors when there are multiple (shift-c).
ui_cursor_primary(); // The primary cursor when there are multiple (shift-c).
ui_cursor_insert(); // The cursor in insert mode (i).
ui_cursor_select(); // The cursor in select mode (v).
ui_cursor_match(); // The matching parentheses of that under the cursor.

ui_selection(); // All currently selected text.
ui_selection_primary(); // The primary selection when there are multiple.

ui_linenr(); // Line numbers.
ui_linenr_selected(); // Current line number.

ui_virtual(); // Namespace for additions to the editing area.
ui_virtual_ruler(); // Vertical rulers (colored columns in editing area).
ui_virtual_whitespace(); // Whitespace markers in editing area.
// NOTE: Indent guides aren"t yet added at the time of writing, but will be soon.
ui_virtual_indent_guide(); // Indentation guides.

ui_statusline(); // Status line.
ui_statusline_inactive(); // Status line in unfocused windows.

ui_help(); // `:command` descriptions above the command line.

ui_highlight(); // selected contents of symbol pickers (spc-s, spc-S) and current line in buffer picker (spc-b).

ui_menu(); // Autocomplete menu.
ui_menu_selected(); // Selected autocomplete item.

ui_popup(); // Documentation popups (space-k).
ui_popup_info(); // Info popups box (space mode menu).

/*
# SYNTAX HIGHLIGHTING ==============================
# All the keys here are Treesitter scopes.
*/

property(); // Regex group names.
special(); // Special symbols e.g `?` in Rust, `...` in Hare.
module(); // Unclear, used for Heex module.
attribute(); // Class attributes, html tag attributes.

type(); // Variable type, like integer or string, including program defined classes, structs etc..
type_builtin(); // Primitive types of the language (string, int, float).
type_enum_variant(); // A variant of an enum.

constructor(); // Constructor method for a class or struct.

constant(); // Constant value
constant_builtin(); // Special constants like `true`, `false`, `none`, etc.
constant_builtin_boolean(); // True or False.
constant_character(); // Constant of character type.
constant_character_escape(); // escape codes like \n.
constant_numeric();
constant_number (); // constant integer or float value.
constant_number_integer(); // constant integer value.
constant_number_float(); // constant float value.

string_(); // String literal.
string_regexp(); // Regular expression literal.
string_special(); // Strings containing a path, URL, etc.
string_special_path(); // String containing a file path.
string_special_url(); // String containing a web URL.
string_special_symbol(); // Erlang/Elixir atoms, Ruby symbols, Clojure keywords.

comment(); // This is a comment.
comment_line(); // Line comments, like this.
comment_block();// Block comments, like this */ /*in some languages.
comment_block_documentation(); // Doc comments, e.g '///' in rust.

variable(); // Variable names.
variable_builtin(); // Language reserved variables: `this`, `self`, `super`, etc.
variable_parameter(); //{ } // Funtion parameters.
variable_other_member(); // Fields of composite data types (e.g. structs, unions).
variable_function(); // ?

label(); // Loop labels in rust.

punctuation();
punctuation_delimeter(); // Commas and colons.
punctuation_bracket(); // Parentheses, angle brackets, etc.

keyword(); // Language reserved keywords.
keyword_control(); // Control keywords.
keyword_control_conditional(); // 'if', 'else', 'elif'.
keyword_control_repeat(); // 'for', 'while', 'loop'.
keyword_control_import(); // 'import', 'export' ('use'?).
keyword_control_return(); // 'return' in most languages.
keyword_control_exception(); // 'raise' in python.
keyword_operator(); // 'or', 'and', 'in'.
keyword_directive(); // Preprocessor directives (#if in C).
keyword_function(); // The keyword to define a funtion: 'def', 'fun', 'fn'.

operator_(); // Logical (&&, ||) and - I assume - Mathematical (+, %) operators

function_();
function_builtin();
function_method (); // // Class / Struct methods.
function_macro  (); // // Like macros in rust.
function_special(); // // Preprocessor in C.

tag(); // As in <body> for html.

namespace_(); // * Namespace keyword in java, C#, etc.

/*
# Markup ==============================
# Colors for markup languages, like Markdown or XML.
*/

markup_heading_1(); // Markdown heading 1 color.
markup_heading_2(); // Markdown heading 2 color.
markup_heading_3(); // Markdown heading 3 color.
markup_heading_4(); // Markdown heading 4 color.
markup_heading_5(); // Markdown heading 5 color.
markup_heading_6(); // Markdown heading 6 color.
markup_heading_marker(); // Hashtag color on Markdown headings.

markup_list();
markup_list_numbered  (); // Numbered list.
markup_list_unnumbered(); // Bullet point list.

markup_bold  (); // Bold text.
markup_italic(); // Italicised text.

markup_link();
markup_link_url  (); // Urls pointed to by links.
markup_link_label(); // Non-URL link references.
markup_link_text (); // URL and image descriptions in links.

markup_quote(); // `> Quotes` in Markdown.

/*
# Markup - Interface ==============================
# "These scopes are used for theming the editor interface."
*/

markup_normal();
markup_normal_completion(); //For completion doc popup ui.
markup_normal_raw(); // # For hover popup ui.

markup_heading_completion(); // Headings for completion doc popup ui.
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

diff_plus (); // Additions.
diff_minus(); // Deletions.
diff_delta(); // Modifications.
diff_delta_moved(); // Renamed or moved files / changes.

return 0;
}