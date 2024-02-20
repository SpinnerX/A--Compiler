#pragma once
#include <string>
#include <optional>
#include <vector>
#include <map>
#include <fstream>

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
 * @note reading in each Token one at a time.
*/

namespace A_Compiler{
	// @note contains different types of tokens we read from file
	enum class TokenType : uint8_t {
		NONE=0,
		// Literal-DataTypes
		INTEGER,
		STRING,
		CHARACTER,
		DOUBLE,
		FLOAT,
		OPERATOR,
		SEMICOLON,
		COMMA,
		RETURN,
		IDENTIFIER
	};


	class Token{
	public:
		Token();
		Token(const TokenType& t, const std::string& v);
		
		TokenType tokenType() const { return type; }
		std::optional<std::string> value() const { return tokenValue; }
	
	private:
		TokenType type = TokenType::NONE;
		std::optional<std::string> tokenValue;
	};

	class Tokenizer{
		Tokenizer(const std::string& name);
	public:
		struct TokenState{
			bool isGood = false;
			std::vector<Token> tokens;
		};

		Tokenizer() = default;
		~Tokenizer();
		static Tokenizer* InitializeTokenizer(const std::string& filename);

		TokenState tokenize(const std::string& file, char delimeter='\n');

		std::string getTokenType(TokenType&& type) const;

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
	private:
		std::vector<Token> tokens; // @note Containing all the tokens we read through inputs
		std::string _filename; // @note filename we are passing into the tokenizer.
		std::map<std::string, TokenType> tokenIdentifiers; // @note containing the corresponding operators/keywords along with their enum.
	};
};
