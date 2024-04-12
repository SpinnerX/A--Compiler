#pragma once
#include <string>
#include <optional>
#include <vector>
#include <map>
#include <fstream>
#include <stack>
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
	// class Exp{
	// public:
	// //  Exp(){}
	// 	virtual void print(){}
	// 	virtual void release(){}
	// };
	// class Term: public Exp {
	// 	std::string val;
	// public:
	// 	Term(std::string v):val(v){}
	// 	void print(){
	// 		std::cout << ' ' << val << ' ';
	// 	}
	// 	void release(){}
	// };

	// class Node: public Exp{
	// 	Exp *l_exp;
	// 	Exp *r_exp;
	// 	char op; // +, -, *, /
	// public:
	// 	Node(char op, Exp* left, Exp* right):op(op),l_exp(left), r_exp(right){}
	// 	~Node(){
	// 	}
	// 	void print(){
	// 		std::cout << '(' << op << ' ';
	// 		l_exp->print();
	// 		r_exp->print();
	// 		std::cout << ')';
	// 	}
	// 	void release(){
	// 		l_exp->release();
	// 		r_exp->release();
	// 		delete l_exp;
	// 		delete r_exp;
	// 	}
	// };

	// inline Exp* strToExp(std::string &str){
	// 	int level = 0;//inside parentheses check
	// 	//case + or -
	// 	//most right '+' or '-' (but not inside '()') search and split
	// 	for(int i=str.size()-1;i>=0;--i){
	// 		char c = str[i];
	// 		if(c == ')'){
	// 			++level;
	// 			continue;
	// 		}
	// 		if(c == '('){
	// 			--level;
	// 			continue;
	// 		}
	// 		if(level>0) continue;
	// 		if((c == '+' || c == '-') && i!=0 ){//if i==0 then s[0] is sign
	// 			std::string left(str.substr(0,i));
	// 			std::string right(str.substr(i+1));
	// 			return new Node(c, strToExp(left), strToExp(right));
	// 		}
	// 	}
	// 	//case * or /
	// 	//most right '*' or '/' (but not inside '()') search and split
	// 	for(int i=str.size()-1;i>=0;--i){
	// 		char c = str[i];
	// 		if(c == ')'){
	// 			++level;
	// 			continue;
	// 		}
	// 		if(c == '('){
	// 			--level;
	// 			continue;
	// 		}
	// 		if(level>0) continue;
	// 		if(c == '*' || c == '/'){
	// 			std::string left(str.substr(0,i));
	// 			std::string right(str.substr(i+1));
	// 			return new Node(c, strToExp(left), strToExp(right));
	// 		}
	// 	}
	// 	if(str[0]=='('){
	// 	//case ()
	// 	//pull out inside and to strToExp
	// 		for(int i=0;i<str.size();++i){
	// 			if(str[i]=='('){
	// 				++level;
	// 				continue;
	// 			}
	// 			if(str[i]==')'){
	// 				--level;
	// 				if(level==0){
	// 					std::string exp(str.substr(1, i-1));
	// 					return strToExp(exp);
	// 				}
	// 				continue;
	// 			}
	// 		}
	// 	}
	// 	return new Term(str);
	// }
};
