#pragma once
#include <tokenizer/token.h>
#include <parser/Node.h>

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
	 *
	 * */
	class ParserTree{
		ParserTree(const Tokenizer::TokenState tokens);
	public:

		// @note initializing the parser tree.
		static ParserTree* InitializeParserTree(Tokenizer::TokenState tokenStates);
		
		// @note basic tree operations.
		/* void insert(Node* node); */

		/* void remove(Node* node); */
		
		// @note returns false if evaluation has an error occurred.
		bool evaluate();

		// @note traversal operations
		/* void inorderTraversal(); */
		/* void preorderTraversal(); */
		/* void postorderTraversal(); */
	
		// @note Note to Self: may change this later
		// @note Note to Self: Am still thinking of this, may come back once I get a clearer visual of the operations.
		/* void display(); */

	private:
		Tokenizer::TokenState _tokens; // @note contains the tokens setup by the tokenizer.
		Node* root;
	};

};
