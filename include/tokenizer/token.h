#pragma once
#include <string>
#include <optional>
#include <vector>
#include <map>
#include <fstream>
#include <stack>
#include "utils/types.h"
#include <ostream>
#include <iostream>
#include <type_traits>

/*
 * @class Token
 * @type T This token will either be a type T or will try to make this token represent as a string.
 * @note each command considered as a token will be contained in Token.
 * @note should be reading from tokens one at a time
 * @note each token will have an enum for representing the type of token we read from input stream.
 *
 * @function read();
 * @note read is reading one input stream at a time.
 *
 * @note token format is "Type: Value"
 * @note Example: print "Hello"
 * @note Example Tokenize
 * [ID: print]
 * [STRING: "Hello"]
 *
 * @function token<T>();
 * @note returns the token we are reading (debugging)
 *
 *
 * @class Tokenizer
 =
 * @note reading in each Token one at a time.
*/

namespace A_Compiler{
	enum class OPERATIONS : uint8_t {
		ADDITION, SUBTRACTION, MULTIPLICATION, DIVISION
	};

	struct Token{
		std::string variable = "";
	};

	struct Token{
		Token* left;
		Token* right;
		char operators; //! @note +, -, *, /

		Token(char op, Token* l, Token* r)  : operators(op), left(l), right(r) {}


https://stackoverflow.com/questions/11703082/parsing-math-expression-in-c

	};
	
	// @note Tokenizer should only be tokenizing the file into tokens pushing to a stack
	// @note the parser will be what handles evaluating what everything is.
	// @note Meaning that the parser will help identify what each of the tokens are.
	class Tokenizer{
	public:
		Tokenizer() = default;
		~Tokenizer();


		std::string output() const { return outputToken; }

		std::stack<std::string> tokenize(const std::string& file, char delimeter='\n');




		friend std::ostream& operator<<(std::ostream& outs, const Tokenizer& t){
			std::stack<std::string> tokens = t.tokens;

			while(!tokens.empty()){
				std::string token = tokens.top();
				outs << token << '\n';
				tokens.pop();
			}
			return outs;
		}

		size_t size() const { return tokens.size(); }

	private:
		template<typename T>
		T tokenize(std::istream& ins){
			while (true) {
				if (ins.eof()) //We reached the end of file, or the user hit ctrl-d
					return T();
				T retval;
				ins >> retval;
				if (!ins) {
					ins.clear(); //Clear error code
					std::string s;
					ins >> s; //Remove the word that caused the error
					continue;
				}
				return retval;
			}
		}

		template<class T>
		T tokenize(const std::string prompt = "") {
			while (true) {
				if (std::cin.eof()) //We reached the end of file, or the user hit ctrl-d
					return T(); //Alternatively, we could throw an exception
				T retval;
				// std::cout << prompt;
				std::cin >> retval;
				if (!std::cin) {
					std::cin.clear(); //Clear error code
					std::string s;
					std::cin >> s; //Remove the word that caused the error
					continue;
				}
				return retval;
			}
		}

	private:


	private:
		static Tokenizer* instance;
		std::stack<std::string> tokens; // @note Containing all the tokens we read through inputs
		std::string outputToken;
	};
};
