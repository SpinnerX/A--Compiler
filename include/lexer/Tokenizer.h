#pragma once
#include <iostream>
#include <string>
#include <cstdlib>
#include "utils/types.h"
#include <vector>

namespace A_Compiler{

    /**
    @note 1.) Parser
        - Tokens, Tokenizer, Lexer, ParserToAST (using ParserTree, Semantic Analysis)
    @note 2.) AST
        - ASTNode, AST (DFS, )
    */

    /**
    @name Token
    @note Contains information about each token we read
    @param literal_type
    @note A token should tell us if this is a variable, literal-value, or an operator 

    @note Only information we care about with the token class
    @note These are what tokens will be represented
    @param keyword
    @param identifier
    @param assigned_op

    @example
    int x = 12;
    keyword_int = int
    identifier = x;
    assign_eq = "="
    value = "12"

    */

    // template<typename T>
    struct Token{
        DataTypes token_t;
        std::string value;
    };

    class Tokenizer{
    public:

    std::vector<DataTypes *> getTokens() const { return data_ts; }

    //! @note probably reading the tokens user types in, like the commands.
    bool read(const std::string& tokens){

        return true;
    }


    private:
        std::vector<DataTypes *> data_ts;
    };

};