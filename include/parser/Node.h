#pragma once
#include <tokenizer/token.h>

namespace A_Compiler{
	
	/*
	 *
	 * @class Node
	 * @note Considering either making this be a pure virtual function to work with both parsing and ast's
	 * @note though may reconsider once I learn more about the two...
	 *
	 * @note node will contain the following information variable name, variable type(literal, keyword, etc.)
	 * @note Node will also be containing either the full expression (such as z = x + y)
	 *
	 * @param parent
	 * @note storing information about their position relative to their parent nodes.
	 * */
	struct Node{
		TokenType type = TokenType::NONE;
		std::string varName; // @note containing variable name
		std::string exp; // @note expression
		Node* left = nullptr;
		Node* right = nullptr;
		Node* parent = nullptr;
	};

};
