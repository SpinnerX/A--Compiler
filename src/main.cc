/*#include <cstring>
#include <filesystem>
#include <fstream>
#include <tokenizer/token.h>
#include <string>
#include <iostream>
#include <stack>
#include <iostream>
#include "Tokenizer.h"
using namespace std;

// @note reading from file.
// @note fetching contents from file.
std::string readFromFile(std::string file){
	constexpr auto readSize = size_t(4096);
	auto stream = std::ifstream(file.data());
	stream.exceptions(std::ios_base::badbit);

	if(!stream){
		printf("File doesn't exist\n");
		return "";
	}

	std::string out = {};
	std::string buf = std::string(readSize, '\0');

	while(stream.read(&buf[0], readSize)){
		out.append(buf, 0, stream.gcount());
	}

	out.append(buf, 0, stream.gcount());
	return out;
}


int main(int argc, char* argv[]){
	string tokenInput = "Default";
	A_Compiler::Tree tree;

	while(true){
		printf("> ");
		getline(cin, tokenInput);

		if(tokenInput == "exit" || tokenInput == "exit()") break;

		// A_Compiler::Exp* tree = A_Compiler::strToExp(tokenInput);
		// A_Compiler::Node* node = A_Compiler::strToExpression(tokenInput);
		A_Compiler::Tree tree(tokenInput);
		// A_Compiler::Node* node = tree.evaluate(tokenInput);

		tree.evaluate();

		// cout << node << '\n';

		// tree->print();
		// tree->release();
		// printf("\n");
	}


	return 0;
}*/

#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
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
	NAME, OP, LITERAL, IDENTIFER, EQ_OP, ADD_OP, SUB_OP, MUL_OP, DIV_OP,
	PARANTH_BEGIN, PARANTH_END // Beginning and ending paranthesis
};

struct Token{
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
	std::string payload;
	TYPE type;

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
	while(true){
		print(">", ' ');
		std::string tokenInput = "";
		getline(cin, tokenInput);

		if(tokenInput == "exit" || tokenInput == "exit()") break;

		print("Tokenized Expression = " + tokenInput);
		std::vector<Token> tokens = tokenize(tokenInput);

		cout << tokens << '\n';
	}
	

	return 0;
}
