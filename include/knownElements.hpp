#pragma once
#include "helixElement.hpp"

E warning = E("warning"); //Editor warnings.
E error = E("error"); // Editor errors, like mis-typing a command.
E info = E("info"); // Code diagnostic info in gutter (LSP).
// ? Difference between info and hint ?
E hint = E("hint"); // Code diagnostics hint in gutter (LSP).
E diagnostic = E("diagnostic"); // Code diagnostics in editing area (LSP).

/*
# UI ==============================
# For styling helix itself.
*/

E ui_background = E("ui.background"); // Default background color.
E ui_window = E("ui.window"); // Window border between splits.

E ui_gutter = E("ui.gutter"); // Left gutter for diagnostics and breakpoints.

E ui_text = E("ui.text"); // Default text color.
E ui_text_focus = E("ui.text.focus"); // Selection highlight in buffer-picker or file-picker.
E ui_text_info = E("ui_text_info"); // Info popup contents (space mode menu).

E ui_cursor = E("ui.cursor"); // Fallback cursor colour, non-primary cursors when there are multiple (shift-c).
E ui_cursor_primary = E("ui.cursor.primary"); // The primary cursor when there are multiple (shift-c).
E ui_cursor_insert = E("ui.cursor.insert"); // The cursor in insert mode (i).
E ui_cursor_select = E("ui.cursor.select"); // The cursor in select mode (v).
E ui_cursor_match = E("ui.cursor.match"); // The matching parentheses of that under the cursor.

E ui_selection = E("ui.selection"); // All currently selected text.
E ui_selection_primary = E("ui.selection.primary"); // The primary selection when there are multiple.

E ui_linenr = E("ui.linenr"); // Line numbers.
E ui_linenr_selected = E("ui.linenr.selected"); // Current line number.

E ui_virtual = E("ui.virtual"); // Namespace for additions to the editing area.
E ui_virtual_ruler = E("ui.virtual.ruler"); // Vertical rulers (colored columns in editing area).
E ui_virtual_whitespace = E("ui.virtual.whitespace"); // Whitespace markers in editing area.
// NOTE: Indent guides aren"t yet added at the time of writing, but will be soon.
E ui_virtual_indent_guide = E("ui.virtual.indent-guide"); // Indentation guides.

E ui_statusline = E("ui.statusline"); // Status line.
E ui_statusline_inactive = E("ui.statusline.inactive"); // Status line in unfocused windows.

E ui_help = E("ui.help"); // `:command` descriptions above the command line.

E ui_highlight = E("ui.highlight"); // selected contents of symbol pickers (spc-s, spc-S) and current line in buffer picker (spc-b).

E ui_menu = E("ui.menu"); // Autocomplete menu.
E ui_menu_selected = E("ui.menu.selected"); // Selected autocomplete item.

E ui_popup = E("ui_popup"); // Documentation popups (space-k).
E ui_popup_info = E("ui.popup.info"); // Info popups box (space mode menu).

/*
# SYNTAX HIGHLIGHTING ==============================
# All the keys here are Treesitter scopes.
*/

E property = E("property"); // Regex group names.
E special = E("special"); // Special symbols e.g `?` in Rust, `...` in Hare.
E module = E("module"); // Unclear, used for Heex module.
E attribute = E("attribute"); // Class attributes, html tag attributes.

E type = E("type"); // Variable type, like integer or string, including program defined classes, structs etc..
E type_builtin = E("type.builtin"); // Primitive types of the language (string, int, float).
E type_enum_variant = E("type.enum.variant"); // A variant of an enum.

E constructor = E("constructor"); // Constructor method for a class or struct.

E constant = E("constant"); // Constant value
E constant_builtin = E("constant.builtin"); // Special constants like `true`, `false`, `none`, etc.
E constant_builtin_boolean = E("constant.builtin.boolean"); // True or False.
E constant_character = E("constant.character"); // Constant of character type.
E constant_character_escape = E("constant.character.escape"); // escape codes like \n.
E constant_numeric = E("constant.numeric");
E constant_number  = E("constant.number"); // constant integer or float value.
E constant_number_integer = E("constant.number.integer"); // constant integer value.
E constant_number_float = E("constant.number.float"); // constant float value.

E string_ = E("string"); // String literal.
E string_regexp = E("string.regexp"); // Regular expression literal.
E string_special = E("string.special"); // Strings containing a path, URL, etc.
E string_special_path = E("string.special.path"); // String containing a file path.
E string_special_url = E("string.special.url"); // String containing a web URL.
E string_special_symbol = E("string.special.symbol"); // Erlang/Elixir atoms, Ruby symbols, Clojure keywords.

E comment = E("comment"); // This is a comment.
E comment_line = E("comment.line"); // Line comments, like this.
E comment_block = E("comment.block");// Block comments, like this */ /*in some languages.
E comment_block_documentation = E("comment.block.documentation"); // Doc comments, e.g '///' in rust.

E variable = E("variable"); // Variable names.
E variable_builtin = E("variable.builtin"); // Language reserved variables: `this`, `self`, `super`, etc.
E variable_parameter = E("variable.parameter"); //{ } // Funtion parameters.
E variable_other_member = E("variable.other.member"); // Fields of composite data types (e.g. structs, unions).
E variable_function = E("variable.function"); // ?

E label = E("label"); // Loop labels in rust.

E punctuation = E("punctuation"); // (){}[]:;,.
E punctuation_delimeter = E("punctuation.delimeter"); // Commas and colons.
E punctuation_bracket = E("punctuation.bracket"); // Parentheses, angle brackets, etc.

E keyword = E("keyword"); // Language reserved keywords.
E keyword_control =E("keyword.control"); // Control keywords.
E keyword_control_conditional = E("keyword.control.conditional"); // 'if', 'else', 'elif'.
E keyword_control_repeat = E("keyword.control.repeat"); // 'for', 'while', 'loop'.
E keyword_control_import = E("keyword.control.import"); // 'import', 'export' ('use'?).
E keyword_control_return = E("keyword.control.return"); // 'return' in most languages.
E keyword_control_exception = E("keyword.control.exception"); // 'raise' in python.
E keyword_operator = E("keyword.operator"); // 'or', 'and', 'in'.
E keyword_directive = E("keyword.directive"); // Preprocessor directives (#if in C).
E keyword_function = E("keyword.function"); // The keyword to define a funtion: 'def', 'fun', 'fn'.

E operator_ = E("operator"); // Logical (&&, ||) and - I assume - Mathematical (+, %) operators

E function_ = E("function");
E function_builtin = E("function.builtin");
E function_method  = E("function.method"); // // Class / Struct methods.
E function_macro   = E("function.macro"); // // Like macros in rust.
E function_special = E("function.special"); // // Preprocessor in C.

E tag = E("tag"); // As in <body> for html.

E namespace_ = E("namespace"); // * Namespace keyword in java, C#, etc.

/*
# Markup ==============================
# Colors for markup languages, like Markdown or XML.
*/

E markup_heading_1 = E("markup.heading.1"); // Markdown heading 1 color.
E markup_heading_2 = E("markup.heading.2"); // Markdown heading 2 color.
E markup_heading_3 = E("markup.heading.3"); // Markdown heading 3 color.
E markup_heading_4 = E("markup.heading.4"); // Markdown heading 4 color.
E markup_heading_5 = E("markup.heading.5"); // Markdown heading 5 color.
E markup_heading_6 = E("markup.heading.6"); // Markdown heading 6 color.
E markup_heading_marker = E("markup.heading.marker"); // Hashtag color on Markdown headings.

E markup_list = E("markup.list");
E markup_list_numbered   = E("markup.list.numbered"); // Numbered list.
E markup_list_unnumbered = E("markup.list.unnumbered"); // Bullet point list.

E markup_bold   = E("markup.bold"); // Bold text.
E markup_italic = E("markup.italic"); // Italicised text.

E markup_link = E("markup.link");
E markup_link_url   = E("markup.link.url"); // Urls pointed to by links.
E markup_link_label = E("markup.link.label"); // Non-URL link references.
E markup_link_text  = E("markup.link.text"); // URL and image descriptions in links.

E markup_quote = E("markup.quote"); // `> Quotes` in Markdown.

/*
# Markup - Interface ==============================
# "These scopes are used for theming the editor interface."
*/

E markup_normal = E("markup.normal");
E markup_normal_completion = E("markup.normal.completion"); //For completion doc popup ui.
E markup_normal_raw = E("markup.normal.raw"); // # For hover popup ui.

E markup_heading_completion = E("markup.heading.completion"); // Headings for completion doc popup ui.
E markup_heading_raw = E("markup.heading.raw"); // Headings for hover popup ui.

E markup_raw = E("markup.raw"); // Code block in Markdown.
E markup_raw_block = E("markup.raw.block"); // Multiline (```) codeblock in Markdown.
E markup_raw_inline = E("markup.raw.inline"); //`Inline code block` in Markdown.

E markup_raw_inline_completion = E("markup.raw.inline.completion"); // ?
E markup_raw_inline_hover = E("markup.raw.inline.hover"); // ?
  
/*
# Diff ==============================
# Version control changes.
*/  

E diff_plus  = E("diff.plus"); // Additions.
E diff_minus = E("diff.minus"); // Deletions.
E diff_delta = E("diff.delta"); // Modifications.
E diff_delta_moved = E("diff.delta.moved"); // Renamed or moved files / changes.