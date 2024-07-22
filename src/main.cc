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
#include <set>
#include <stack>
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
	Token() = default;
	Token(TYPE t, const std::string p) : type(t), payload(p) {}

	bool operator==(const TYPE other) const {
		return (type == other);
	}

	TYPE type;
	std::string payload;
};

//! @note Used for debugging purposes
//! @note  Making sure that we are assigning the correct Enum to our tokens
static std::string typeToString(TYPE type){
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

template<typename T>
void print(const T& value, char delimieter='\n'){
	std::cout << value << delimieter;
}

template<typename T>
void print(std::ostream& outs, const T& value, char delimieter='\n'){
	outs << value << delimieter;
}

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

/**
@expression is --> (2 + 2) * 10
@note This is initially how the AST is going to be parsing our syntax.

		+
	   / \
	  (  [*]
	 /     \
	[+]    10
   /  \
   2  2
   /
   )
*/

struct ASTNode{
	Token token;
	ASTNode* parent = nullptr;
	ASTNode* left = nullptr;
	ASTNode* right = nullptr;

	ASTNode(const Token& t) : token(t){}

	~ASTNode(){
		delete left;
		delete right;
	}

	bool operator==(TYPE other) {
		return (token.type == other);
	}
};

/**
//! @name AST
	@param evaulate
	@note Evaluating our tokens to produce the correct output based on the math expressions

	@param getOutput
 	@note Returns the initial output from the expressions we are parsing.

*/

class AST{
public:
	AST(std::vector<Token>& other) : tokens(other), index(0), root(nullptr) {
		operators.insert(TYPE::ADD_OP);
		operators.insert(TYPE::SUB_OP);
		operators.insert(TYPE::MUL_OP);
		operators.insert(TYPE::DIV_OP);
	}

	//! @note Evaluating tokens into our AST
	//! @note Reading in the tokens parsed from the tokenizer
	//! @note Then we build the AST through these tokens
	//! @note Use this to evaluate our tokens and it's information
	//! @note Using evaluate() to build our AST now that we have what we need with our tokenized expressions.
	//! @note Boolean returned, for keeping track of our initial state of this function, if the evaluation was valid or not.
	//! @note How we are going to evaluate our operators precedence is by constantly iterate to the left until we hit a nullptr or an operator
	//! @note When an operator occurs then we iterate the right node and that keeps repeating.
	bool buildAST(){
		print("Evaluate() was called!\n");
		int size = tokens.size();

		if(tokens.size() == 1){
			root = new ASTNode(tokens[0]);
			size = 1;
			return true;
		}

		while(index < size){
			//! @note We are getting our current node in std::vector<Token>
			Token& token = tokens[index++];

			//! @note We need to check if root is nullptr
			//! @note Initializing the root before we continue with the AST
			//! @note a TODO is probably adjusting the AST to accept incrementations and decrementations like (i++, or i--)
			if(root == nullptr){
				root = new ASTNode(token);
			}

			//! @note Going left if there are no operators
			if(!operators.contains(token.type)){
				if(root->left == nullptr){
					root->left = new ASTNode(token);
					// print("Left is value = " + token.payload);
				}
				root = root->left;
			}
			else{ //! @note Going right
				if(root->right == nullptr){
					//! @note Adding the operators (+, -, *, /)
					root->parent = new ASTNode(token);
					// print("Current Parent = " + root->parent->token.payload);


					Token rightToken = tokens[index++];
					root->right = new ASTNode(rightToken);
					// print("Right is value = " + rightToken.payload);
				}
				root = root->right;
			}
		}

		return true;
	}

	ASTNode* getAST() const { return root; }

private:
	//! @note Getting our current node that we are traversing in the AST
	ASTNode* CurrentNode(){
		//! @note
		Token& token = tokens[index++];
		ASTNode* newNode = new ASTNode(token);
		newNode->token = token;
		return newNode;
	}

private:
	ASTNode* root;
	uint32_t size;
	std::vector<Token> tokens;
	uint32_t index;
	std::set<TYPE> operators;
};


class Parser{
public:
	Parser() = default;

	template<typename T>
	T getOutput(){

		return T();
	}
};

//! @note Making it easier to print out the tokens
std::ostream& operator<<(std::ostream& outs, const std::vector<Token>& tokens){
	for(const Token& token : tokens){
		print(outs, "[Payload] 	" + token.payload, '\n');
		print(outs, "[TYPE] 		" + typeToString(token.type), '\n');
	}

	return outs;
}


int main(int argc, char** argv){
	AST* ast = nullptr;

	while(true){
		print(">", ' ');
		std::string tokenInput = "";
		getline(cin, tokenInput);

		if(tokenInput == "exit" || tokenInput == "exit()") break;

		// print("Tokenized Expression = " + tokenInput);
		std::vector<Token> tokens = tokenize(tokenInput);
		print("Token Size is " + std::to_string(tokens.size()));
		
		ast = new AST(tokens);

		if(!ast->evaluate()){
			print("evaluate() state was invalid and returned false!");
		}
		else{
			// print(ast->getOutput<int>());
			// print("Output ==> " + std::to_string(ast->output()));
			ast->test();
			// ast->printAST();
		}

		// cout << tokens << '\n';
	}
	

	return 0;
}
