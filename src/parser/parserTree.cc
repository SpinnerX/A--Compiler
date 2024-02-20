#include <parser/parserTree.h>


namespace A_Compiler{
	ParserTree::ParserTree(const Tokenizer::TokenState tokens) : _tokens(tokens) {}

	ParserTree* ParserTree::InitializeParserTree(Tokenizer::TokenState tokenState){
		return new ParserTree(tokenState);
	}
	
	bool ParserTree::evaluate(){
		for(auto& token : _tokens.tokens){
			switch (token.tokenType()) {
			case A_Compiler::TokenType::INTEGER: break;
			case A_Compiler::TokenType::DOUBLE: break;
			case A_Compiler::TokenType::FLOAT: break;
			default: break;
			}
		}

		return false;
	}
	
};
