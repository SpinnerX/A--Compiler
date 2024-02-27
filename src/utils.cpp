#include <utils.h>


namespace A_Compiler{
	bool isInt(const std::string& s){
		return !s.empty() && std::find_if(s.begin(), s.end(), [](unsigned char ch) { return !std::isdigit(ch); }) == s.end();
	}

	bool isParenthesisBalanced(const std::string &input){
		return (input == "(" || input == ")");
	}

	bool isBracketsBalanced(const std::string &s){
		return (s == "{" || s == "}");
	}
};
