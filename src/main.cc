#include <filesystem>
#include <fstream>
#include <tokenizer/token.h>
#include <parser/parserTree.h>
#include <string>
#include <iostream>
#include <stack>

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
	if(argc < 0){
		printf("Usage: acc file expected!\n");
		return -1;
	}
	
	/* std::string file(argv[1]); */
	std::string file = "main.acc";

	std::filesystem::path filepath(file);

	if(filepath.empty() || filepath.extension() != ".acc"){
		printf("Usage: File with acc file not found\n");
		printf("File Extension = %s\n", filepath.extension().c_str());
		return -1;
	}
	
	std::string contents = readFromFile(filepath.filename());

	if(contents.empty()){
		printf("Cannot read file %s\n", file.c_str());
		return -1;
	}

	A_Compiler::Tokenizer* tokenizer;
	
	std::stack<std::string> tokens = tokenizer->tokenize(file);

	A_Compiler::ParserTree tree;
	A_Compiler::Node* exp = tree.evaluate(tokens);
	
	
	std::cout << exp << '\n';
	
	/* while(!tokens.empty()){ */
	/* 	std::string token = tokens.top(); */
	/* 	std::cout << token << '\n'; */
	/* 	tokens.pop(); */
	/* } */


	return 0;
}
