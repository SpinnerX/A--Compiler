#pragma once
#include <tokenizer/token.h>
#include <types.h>

namespace A_Compiler{
	
	/*
	 *@note Rewriting/Repurposing this Node class. (Will represent tokens as a node for use in the tree structures.
	 * @class Node
	 * 
	 * @note API call example below regarding the node and formatting metadata
	 * Example expression: int x = 10;
	 * Example expression: int x: 10; // This was just a joke, but am actually considering it tbh...
		Node* node = {.id="x", .op=NodeType::OPERATOR_EQ, .value="10"};

	 * @note the idea is that we will use the operator = to read in the value and evaluating if we are reading via from variable name (in example is x) and the value (in example is 10)
	 * @note intializing the node with the properties in this format: {dataType, id, op, and value}
	 *
	 *
	 * @variable left
	 * @note this will act as a way to be adding to left side of the leaf. (same with right node)
	 *
	 * */
	struct Node{
		std::string typeId="Default typeID";
		std::string id="Default";
		DataTypes op = DataTypes::DEFAULT;
		std::string value="Default Value";
		Node* left = nullptr;
		Node* right = nullptr;

		friend std::ostream& operator<<(std::ostream& outs, const Node* node){
			outs << "Node Information\n";
			outs << "Id is " << node->id << '\n';
			outs << "Operator is " << node->operatorToString() << '\n';
			outs << "Value is " << node->value << '\n';
			return outs << "Variable Expression: " << node->typeId << ' ' << node->id << ' ' << node->operatorToString() << ' ' << node->value;
		}

	private:
		// @note For debugging purposes for checking if DataTypes assigned to the nodes are correct.
		std::string operatorToString() const{
			switch (op) {
			case DataTypes::STRING: return "DataTypes::STRING";
			case DataTypes::INTEGER: return "DataTypes::INTEGER";
			case DataTypes::DOUBLE: return "DataTypes::DOUBLE";
			case DataTypes::FLOAT: return "DataTypes::FLOAT";
			case DataTypes::OPERATOR_EQ: return "=";
			default: return "DataTypes::DEFAULT";
			}
			/* case DataTypes::OPERATOR_EQ: return "DataTypes::OPERATOR_EQ"; */
		}
	};
};
