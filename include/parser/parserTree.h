#pragma once
#include <tokenizer/token.h>

namespace A_Compiler{
	
	struct Node{
	};
	

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
	 *
	 * */
	class ParserTree{
	public:
		// @note initializing the parser tree.
		static ParserTree* InitializeParserTree(Tokenizer::TokenState tokenState);

	private:
		Tokenizer::TokenState _tokens; // @note contains the tokens setup by the tokenizer.
	};
};
