#include <cstdlib>// This library is added for the NULL keyword
#include <string>

using namespace std;

class LinkedAndXOrBinaryTreeException// Throw this exception class when invalid tree operation is performed
{
	public:
   		LinkedAndXOrBinaryTreeException() : message( "Invalid Operation for Linked AndXOr Binary Tree !!" ) { }
   		const char *show() const { return message; }
	private:
   		const char *message;
};

enum NodeType { AND, XOR, LEAF };// These are types of the nodes
	
class LinkedAndXOrBinaryTree 
{
	private:
		struct Node// a node of the tree
		{					
      			NodeType type;// type of the node
			int cost;// cost of the node
			string name;// name of the node
      			Node* left;// left child
      			Node* right;// right child
   		};
	public:
   		class Position// position in the tree
		{					
    			private:
      				Node* v;// pointer to the node		
   			public:
				Position(Node* _v = NULL) : v(_v) { }// constructor
				Node* getNode() const { return v; }// get node
      				int getNodeType() const { return v->type; }// get node type
				int getNodeCost() const { return v->cost; }// get node cost
				string getNodeName() const { return v->name; }// get node name
      				Position left() const { return Position(v->left); }// get left child
      				Position right() const { return Position(v->right); }// get right child
     				bool isExternal() const { return v->left == NULL && v->right == NULL; }// an external node?
    		};
	public:
		LinkedAndXOrBinaryTree();// constructor
		void addRoot(NodeType _type,string _name);// add root to empty tree
		void expandExternal(const Position& _p,NodeType _leftType,int _leftCost,string _leftName,NodeType _rightType,int _rightCost,string _rightName);// expand external node
		bool empty() const;// is tree empty?
		Position getRoot() const;// get the root
	private:
		Node* root;// pointer to the root
};
