" Vim syntax file
" Language: Ash
" Maintainer: Sam Tebbs
" Latest Revision: 30/04/15
" Source: http://vim.wikia.com/wiki/Creating_your_own_syntax_files

if exists("b:current_syntax")
	finish
endif

" Keywords that are followed by an identifier (seperated by whitespace)
syn keyword langKeywords const var func class namespace protocol import enum return super this
" nextGroup=id skipwhite

" Identifier and qualified name
syn match id '([a-zA-Z]([a-zA-Z]|[0-9])*)'
syn match id '([a-zA-Z]([a-zA-Z]|[0-9])*)(\.([a-zA-Z]([a-zA-Z]|[0-9])*))*'

" Modifiers
syn keyword mod public private protected final required native override standard static

" Char and string literals
syn match charLiteral '\'[^\\']\''
syn match str '[\"][^\\"]*[\"]'

" Boolean literals
syn keyword bool true false

" Primitive types
syn keyword langType int int8 int16 int64 uint uint8 uint16 uint64 float float64 bool char

" Class references
syn keyword classRef this super

" Operators
" syn keyword operator ? == != < <= > >= = : => += -= *= /= %= **= ^= &= <<= >>= ++ -- + - * / % ** ^ & !
syn keyword operator ? + =

" Match numeric literals
syn match numLiteral '\d\+'
syn match numLiteral '[-]\d\+'
" Floating point number with decimal no E or e (+,-)
syn match numLiteral '\d\+\.\d*'
syn match numLiteral '[-+]\d\+\.\d*'

" Floating point like number with E and no decimal point (+,-)
syn match numLiteral '[-+]\=\d[[:digit:]]*[eE][\-+]\=\d\+'
syn match numLiteral '\d[[:digit:]]*[eE][\-+]\=\d\+'

" Floating point like number with E and decimal point (+,-)
syn match numLiteral '[-+]\=\d[[:digit:]]*\.\d*[eE][\-+]\=\d\+'
syn match numLiteral '\d[[:digit:]]*\.\d*[eE][\-+]\=\d\+'

" Some syntax elements can only exist within a scope (braces)
syn region scope start="{" end="}" fold transparent

" Comments
syn match comment "//.*$"
syn match comment "\/\*+((([^\*])+)|([\*]+(?!\/)))[*]+\/"

let b:current_syntax = "ash"

" Link the rules to highlighting groups: http://vimdoc.sourceforge.net/htmldoc/syntax.html#syntax
" PreCondit = pink
" Operator = orange
hi def link langType	    Function
hi def link langKeywords	StorageClass
hi def link mod				StorageClass
hi def link operator		Keyword
hi def link numLiteral		Number
hi def link charLiteral		Character
hi def link bool			Boolean
hi def link str				String
hi def link comment			Comment
hi def link id				Identifier
hi def link classRef		PreCondit
