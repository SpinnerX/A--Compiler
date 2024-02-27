# A-Compiler
Developing my own compiler for experiementing with compiler design. Developing a language for myself, called Argon++.


### Tokenizer (Some Information)
* Job is to read tokens one at a time from input stream, passing tokens to the parser.

### Parser
* Job for parser is parsing the input tokens if they are inputted as an expression.

### Compiling Usage
* File extension is going to be `main.acc` \
* When compiling with a++ it'll be: `a++ main.acc`




### Iterations
* Tokenization (Lexer) -> Parser(Analyzer) -> AST



## Syntax Usage for Argon++

### Variables Expressions and Print Statement
* These are different variations of variables expressions.
* `int x = 10;` \
* `int z = (x + y) * 2;` \
* These are variations of print statements
* `print "Hello World"` \
* `print f"X = {x}"` \
* `print(f"X = {10}")`



