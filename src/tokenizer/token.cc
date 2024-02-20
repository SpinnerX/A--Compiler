#include <tokenizer/token.h>
#include <fstream>
#include <iostream>

namespace A_Compiler{

	// @note If the identifier was to be something like "int" then we pass into this function returning TokenType::INTEGER
	static TokenType identifierState(const std::string& str){
		if(str == "int") return TokenType::INTEGER;
		else if(str == "double") return TokenType::DOUBLE;
		else if(str == "float") return TokenType::FLOAT;
		else if(str == "return") return TokenType::RETURN;
		else if(str == "=") return TokenType::OPERATOR;
		else if(str == ";") return TokenType::SEMICOLON;
		return TokenType::NONE;
	}
	
	// @note this is just for debugging purposes.
	// @note returns the string type of the token type.
	static std::string identifierToString(TokenType& type){
		if(type == TokenType::INTEGER) return "TokenType::INTEGER";
		else if(type == TokenType::DOUBLE) return "TokenType::DOUBLE";
		else if(type == TokenType::FLOAT) return "TokenType::FLOAT";
		else if(type == TokenType::RETURN) return "TokenType::RETURN";
		else if(type == TokenType::OPERATOR) return "TokenType::OPERATOR";
		else if(type == TokenType::SEMICOLON) return "TokenType::SEMICOLON";
		else if(type == TokenType::COMMA) return "TokenType::COMMA";
		return "TokenType::IDENTIFIER";
	}

	Token::Token(){}
	
	Token::Token(const TokenType& t, const std::string& v) : type(t), tokenValue(v){}
	
	Tokenizer::Tokenizer(const std::string& name) : _filename(name){}
	
	Tokenizer::~Tokenizer(){}

	Tokenizer* Tokenizer::InitializeTokenizer(const std::string& filename){
		// @note TODO: initiating lookup table for keywords, data types, and operators.

		return new Tokenizer(filename);
	}

	Tokenizer::TokenState Tokenizer::tokenize(const std::string& file, char delimeter){
		std::vector<Token> tokens;
		
		std::ifstream ins(file);

		while(true){
			std::string token = tokenize<std::string>(ins);

			if(!ins)
				break;

			if(token.back() == ';'){ // @note checking if there is a semicolon at the end of token
				std::string lastToken = token.substr(0, token.size()-1);
				std::string semicolon = ";";
				tokens.push_back(Token(identifierState(lastToken), lastToken));
				tokens.push_back(Token(identifierState(semicolon), semicolon));
			}
			else if(token.back() == ','){ // @note checking if there is comma at the end of token
				std::string tokenWithComma = token.substr(0, token.size()-1);
				std::string commaToken = ",";
				tokens.push_back(Token(identifierState(tokenWithComma), tokenWithComma));
				tokens.push_back(Token(identifierState(commaToken), commaToken));
			}
			else{
				tokens.push_back(Token(identifierState(token), token));
			}
		}

		return {.isGood=true, .tokens=tokens};
	}

	std::string Tokenizer::getTokenType(TokenType&& type) const {
		return identifierToString(type);
	}
};
