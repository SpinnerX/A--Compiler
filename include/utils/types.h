#pragma once
#include <cstdint>

/*
 *
 * @file types.h
 *
 * @note containing types that'll be referenced throughout the compiler
 * @note metadata enum for classifying different tokens.
 *
 *
 * */


namespace A_Compiler{

	enum class DataTypes : uint8_t {
		DEFAULT=0,
		// @note variables
		// @note IDENTIFIER means that variables are identifiers and not any of the following, operators, keywords, conditonal/logical/bit operators, but variables.
		IDENTIFIER,
		COMMA,
		SEMICOLON,
		VARIABLE,

		// @note operators representation
		EQ_OPERATOR,
		ADD_OPERATOR,
		SUB_OPERATOR,
		MUL_OPERATOR,
		DIV_OPERATOR,

		//@note literal data types representation
		STRING_LITERAL_TYPE,
		INTEGER_LITERAL_TYPE,
		DOUBLE_LITERAL_TYPE,
		FLOAT_LITERAL_TYPE,

		// @note Keywords
		RETURN_KEYWORD,

		// @note conditional statements, logical operators, bitwise operators
		IF_CONDITIONAL_KEYWORD,
		ELSE_IF_CONDITIONAL_KEYWORD,
		ELSE_CONDITIONAL_KEYWORD,
		
		AND_LOGICAL,
		OR_LOGICAL,
		
		AND_BIT,
		OR_BIT,
		XOR_BIT,
		NOR_BIT,
	};
};