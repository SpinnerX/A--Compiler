#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
// #include "lexer/Tokenizer.h"
using namespace std;
// using namespace A_Compiler;

/**

API Brainstorming

while(Compiler::IsRunning()){
	//! @note Replacing std::cin or std::getline with our own version of read
	//! @note Then we can use this Read function 
	//! @note Initially this will do all of the work and we will just retrieve the tokens our tokenizer generates.

	auto& tokens = Tokenizer::Read(tokens);

}

*/

enum class TYPE : uint8_t {
	NAME, OP, LITERAL, IDENTIFER, COMMA_END_STATEMENT,
	EQ_OP, ADD_OP, SUB_OP, MUL_OP, DIV_OP,
	PARANTH_BEGIN, PARANTH_END // Beginning and ending paranthesis
};

struct Token{
	Token() = default;
	Token(TYPE t, const std::string p) : type(t), payload(p) {}

	TYPE type;
	std::string payload;
};

template<typename T>
void print(const T& value, char delimieter='\n'){
	std::cout << value << delimieter;
}

template<typename T>
void print(std::ostream& outs, const T& value, char delimieter='\n'){
	outs << value << delimieter;
}

struct ASTNode{
	ASTNode* left = nullptr;
	ASTNode* right = nullptr;


	ASTNode(){
		delete left;
		delete right;
	}
};

class AST{
public:
	//! @note Use this to evaluate our tokens and it's information
	//! @note Using evaluate() to build our AST now that we have what we need with our tokenized expressions.
	bool evaluate(std::vector<Token>& tokens){

		return true;
	}

private:
	ASTNode* root;
};

std::vector<Token> tokenize(const std::string& tokenInput){
	std::unordered_map<char, TYPE> operators;
	operators.insert({'=', TYPE::EQ_OP});
	operators.insert({'+', TYPE::ADD_OP});
	operators.insert({'-', TYPE::SUB_OP});
	operators.insert({'*', TYPE::MUL_OP});
	operators.insert({'/', TYPE::DIV_OP});


	std::vector<Token> tokens;
	std::string var="", literal_numeral="", operator_id="", begin_paranth="", end_paranth="";

	//! @note To check if it is a variable we can use std::isalpha to check for that variable name
	//! @note We are checking if we are coming across variables
	//! @note Operation is if we do not come across alphabetical values we are coming across numeral values
	//! @note Each string variable correspond to different types that we are parsing.
	for(char ch : tokenInput){
		//! @note After we parse the expression, if we reach a whitespace, then we add that token to our vector

		if(ch == '('){
			begin_paranth = ch;
		}

		if(std::isalpha((unsigned int)ch)){
			var += ch;
		}
		else if(std::isdigit(ch)){
			literal_numeral += ch;
		}
		else if(operators.contains(ch)){
			operator_id = ch;
		}

		if(ch == ')'){
			end_paranth = ch;
		}

		//! @note One thing to consider is that we did not consider what if we reached the end of the expression and there is no space afterwards.
		//! @note Then we can check if we reach the null character, or we simply reached tokenInput.back() which is the last element.
		if(ch == ' ' || ch == tokenInput.back()){
			if(!begin_paranth.empty()){
				tokens.push_back(Token(TYPE::PARANTH_BEGIN, begin_paranth));
				begin_paranth.clear();
			}

			if(!var.empty()){
				tokens.push_back(Token(TYPE::IDENTIFER, var));
				var.clear();
			}
			
			if(!operator_id.empty()){
				char id = operator_id.at(0);
				tokens.push_back(Token(operators[id], operator_id));
				operator_id.clear();
			}

			if(!literal_numeral.empty()){
				tokens.push_back(Token(TYPE::LITERAL, literal_numeral));
				literal_numeral.clear();
			}

			if(!end_paranth.empty()){
				tokens.push_back(Token(TYPE::PARANTH_END, end_paranth));
				end_paranth.clear();
			}
		}
	}

	return tokens;
}

Token readToken(const std::string& tokenInput){
	std::unordered_map<char, TYPE> operators;
	operators.insert({'=', TYPE::EQ_OP});
	operators.insert({'+', TYPE::ADD_OP});
	operators.insert({'-', TYPE::SUB_OP});
	operators.insert({'*', TYPE::MUL_OP});
	operators.insert({'/', TYPE::DIV_OP});


	Token token;
	std::string var="", literal_numeral="", operator_id="", begin_paranth="", end_paranth="";

	//! @note To check if it is a variable we can use std::isalpha to check for that variable name
	//! @note We are checking if we are coming across variables
	//! @note Operation is if we do not come across alphabetical values we are coming across numeral values
	//! @note Each string variable correspond to different types that we are parsing.
	for(char ch : tokenInput){
		//! @note After we parse the expression, if we reach a whitespace, then we add that token to our vector

		if(ch == '('){
			begin_paranth = ch;
		}

		if(std::isalpha((unsigned int)ch)){
			var += ch;
		}
		else if(std::isdigit(ch)){
			literal_numeral += ch;
		}
		else if(operators.contains(ch)){
			operator_id = ch;
		}

		if(ch == ')'){
			end_paranth = ch;
		}

		//! @note One thing to consider is that we did not consider what if we reached the end of the expression and there is no space afterwards.
		//! @note Then we can check if we reach the null character, or we simply reached tokenInput.back() which is the last element.
		if(ch == ' ' || ch == tokenInput.back()){
			if(!begin_paranth.empty()){
				token = Token(TYPE::PARANTH_BEGIN, begin_paranth);
				begin_paranth.clear();
			}

			if(!var.empty()){
				token = Token(TYPE::IDENTIFER, var);
				var.clear();
			}
			
			if(!operator_id.empty()){
				char id = operator_id.at(0);
				token = Token(operators[id], operator_id);
				operator_id.clear();
			}

			if(!literal_numeral.empty()){
				token = Token(TYPE::LITERAL, literal_numeral);
				literal_numeral.clear();
			}

			if(!end_paranth.empty()){
				token = Token(TYPE::PARANTH_END, end_paranth);
				end_paranth.clear();
			}
		}
	}

	return token;
}

std::vector<Token> tokenize(std::ifstream& tokenInputFile){
	std::vector<Token> tokens;
	while(true){
		if (tokenInputFile.eof()){ //We reached the end of file, or the user hit ctrl-d
			return std::vector<Token>();
		}

		std::string line;
		tokenInputFile >> line;

		if (!tokenInputFile) {
			tokenInputFile.clear(); //Clear error code
			std::string s;
			tokenInputFile >> s; //Remove the word that caused the error
			continue;
		}
		// std::string line;
		// tokenInputFile >> line;
		// print("line = " + line);

		// print(line);

		tokens  = tokenize(line);
	}
	return tokens;
}

std::string typeToString(TYPE type){
	switch (type) {
	case TYPE::NAME: return "NAME";
	case TYPE::IDENTIFER: return "IDENTIFIER";
	case TYPE::OP: return "OP";
	case TYPE::LITERAL: return "LITERAL";
	case TYPE::EQ_OP: return "EQ_OP";
	case TYPE::ADD_OP: return "ADD_OP";
	case TYPE::SUB_OP: return "SUB_OP";
	case TYPE::MUL_OP: return "MUL_OP";
	case TYPE::DIV_OP: return "DIV_OP";
	case TYPE::PARANTH_BEGIN: return "BEGIN PARANTH";
	case TYPE::PARANTH_END: return "END PARANTH";
	case TYPE::COMMA_END_STATEMENT: return "COMMA END";
	default: return "Default Sent Only!";
	}
	return "No Type found!";
}

std::ostream& operator<<(std::ostream& outs, const std::vector<Token>& tokens){
	
	for(const Token& token : tokens){
		print(outs, "[Payload] 	" + token.payload, '\n');
		print(outs, "[TYPE] 		" + typeToString(token.type), '\n');
	}

	return outs;
}


int main(int argc, char** argv){

	if(argc != 1){
		print(">>>> Argon Compiler");
		std::string filename = "main.acc";
		std::ifstream ins(filename);
		std::vector<Token> tokens = tokenize(ins);

		std::cout << tokens << '\n';
	}
	else{
		while(true){
			print(">", ' ');
			std::string tokenInput = "";
			getline(cin, tokenInput);

			if(tokenInput == "exit" || tokenInput == "exit()") break;

			print("Tokenized Expression = " + tokenInput);
			std::vector<Token> tokens = tokenize(tokenInput);

			cout << tokens << '\n';
		}
	}
	

	return 0;
}
