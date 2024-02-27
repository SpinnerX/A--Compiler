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


enum class DataTypes : uint8_t {
	DEFAULT=0,
	// @note variables
	// @note IDENTIFIER means that variables are identifiers and not any of the following, operators, keywords, conditonal/logical/bit operators, but variables.
	IDENTIFIER,
	COMMA,
	SEMICOLON,

	// @note operators
	OPERATOR_EQ,
	OPERATOR_ADD,
	OPERATOR_SUB,
	OPERATOR_MUL,
	OPERATOR_DIV,

	//@note literal data types
	STRING,
	INTEGER,
	DOUBLE,
	FLOAT,

	// @note Keywords
	RETURN,

	// @note conditional statements, logical operators, bitwise operators
	CONDITIONAL_IF,
	CONDITIONAL_ELSE_IF,
	CONDITIONAL_ELSE,
	
	LOGICAL_AND,
	LOGICAL_OR,
	
	BIT_AND,
	BIT_OR,
	BIT_XOR,
	BIT_NOR
};
