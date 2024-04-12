#pragma once
#include <lexer/token.h>
#include <parser/Node.h>
#include <set>

namespace A_Compiler{
	
	/*
	 *
	 * @class ParserTree
	 * @note parser tree/syntax tree is going to parse the tokens
	 * @note by parsing, we are evaluating the syntax of the expressions tokenized.
	 * 
	 * @function InitializeParserTree
	 * @note Intiating the parse tree by passing in the tokens that have been tokenized from the tokenizer.
	 *
	 * @function parse
	 * @note Still considering. Am thinking about either returning bool or the parsed evaluated expression from the tokens
	 * 
	 * @function evaluate
	 * @note evaluates the parsed expression into the form of an AST.
	 
	z = (x + y) * 2;
		=
	/		\
[(x + y)]	[*]
	/	\	/
[x]		[y]	[2]

	 * */
	// class ParserTree{
	// public:
	// 	ParserTree();
	// 	// @note returns false if evaluation has an error occurred.
	// 	Node* evaluate(std::stack<std::string>& tokens);


	// private:
	// 	// @note checking if the string is an integer, double/float
	// 	bool isStringInteger(std::string token);

	// private:
	// 	Node* root=nullptr;
	// 	// @note operators lookup table
	// 	std::map<std::string, DataTypes> opLookupTable;
	// 	// @note literal data types look up table for keywords such as (int, double, float, etc.)
	// 	std::map<std::string, DataTypes> dataTypesKeywordsLookupTable;
	// };

};
