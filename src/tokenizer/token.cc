#include <tokenizer/token.h>
#include <fstream>
#include <iostream>

namespace A_Compiler{
	Tokenizer::~Tokenizer(){}

	std::stack<std::string> Tokenizer::tokenize(const std::string& file, char delimeter){
		std::stack<std::string> tokens;
		
		std::ifstream ins(file);

		while(true){
			std::string token = tokenize<std::string>(ins);

			if(!ins)
				break;

			if(token.back() == ';'){ // @note checking if there is a semicolon at the end of token
				std::string lastToken = token.substr(0, token.size()-1);
				std::string semicolon = ";";
				/* tokens.push(Token(identifierState(lastToken), lastToken)); */
				/* tokens.push(Token(identifierState(semicolon), semicolon)); */
				tokens.push(lastToken);
				tokens.push(semicolon);
			}
			else if(token.back() == ','){ // @note checking if there is comma at the end of token
				std::string tokenWithComma = token.substr(0, token.size()-1);
				std::string commaToken = ",";
				/* tokens.push(Token(identifierState(tokenWithComma), tokenWithComma)); */
				/* tokens.push(Token(identifierState(commaToken), commaToken)); */
				tokens.push(tokenWithComma);
				tokens.push(commaToken);
			}
			else{
				/* tokens.push(Token(identifierState(token), token)); */
				tokens.push(token);
			}
		}
		return tokens;
	}

};
