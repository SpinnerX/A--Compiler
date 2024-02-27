#pragma once
#include <iomanip>


namespace A_Compiler{
	
	/*
	 * 
	 * @function isParenthesisBalanced(const string&)
	 * @note checks if the paranthesis match.
	 * @example z = ((X+Y) * 2) is valid but z = ((X+Y) * 2; is invalid.
	 * 
	 * @function isBracketsBalanced(const std::string&)
	 * @note checks if brackets are balanced (the same with the function above, but for brackets)
	 * 
	 * 
	 */

	bool isInt(const std::string& s);

	bool isParenthesisBalanced(const std::string& input);

	bool isBracketsBalanced(const std::string& s);
};
