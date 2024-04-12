#include <parser/parserTree.h>
#include <iostream>

namespace A_Compiler{
	
// 	ParserTree::ParserTree(){
// 		opLookupTable = std::map<std::string, DataTypes>();
// 		opLookupTable.insert({"=", DataTypes::OPERATOR_EQ});
// 		opLookupTable.insert({"+", DataTypes::OPERATOR_ADD});
// 		opLookupTable.insert({"-", DataTypes::OPERATOR_SUB});
// 		opLookupTable.insert({"*", DataTypes::OPERATOR_MUL});
// 		opLookupTable.insert({"/", DataTypes::OPERATOR_DIV});

// 		dataTypesKeywordsLookupTable = std::map<std::string, DataTypes>();
// 		dataTypesKeywordsLookupTable.insert({"int", DataTypes::INTEGER});
// 		dataTypesKeywordsLookupTable.insert({"double", DataTypes::DOUBLE});
// 		dataTypesKeywordsLookupTable.insert({"float", DataTypes::FLOAT});
// 		dataTypesKeywordsLookupTable.insert({"string", DataTypes::STRING});
// 	}
	
// 	// @note this function will be returning an expression
// 	// @note For testing purposes, we are adding a condition if we reached a semicolon to see if at least one expression can be evaluated first before continuing with multiple expressions.
// 	Node* ParserTree::evaluate(std::stack<std::string>& tokens){
// 		Node* expression = new Node();
		
// 		Node* left = nullptr;
// 		Node* right = nullptr;
		
// 		std::string prev = "";
// 		std::string nextToken1 = "";
// 		std::string nextToken2 = "";

// 		while(!tokens.empty()){
// 			std::string token = tokens.top(); // @note Grabbing our current token
// 			tokens.pop();
// 			// @note when we reached an operator =.
// 			// @note we will check the previous token if it is a literal value(numeral, etc)
// 			if(token == "="){
// 				std::cout << "Previous token is \"" << prev << "\"\n";
// 				std::string id = tokens.top(); // @note giving us our next token
// 				tokens.pop();
// 				std::string typeId = tokens.top(); // @note giving us our next token from the current token we are at.
// 				tokens.pop();
// 				expression->value = prev;
// 				expression->id = id;
// 				expression->typeId = typeId;
// 				expression->op = DataTypes::OPERATOR_EQ;
// 			}
			
// 			prev = token; // @note Getting our previous token we have viewed.

// 		}
// 		return expression;
// 	}
	
// 	bool ParserTree::isStringInteger(std::string token){
// 		return !token.empty() && std::find_if(token.begin(), token.end(), [](unsigned char c) { return !std::isdigit(c); }) == token.end();
// 	}

};
