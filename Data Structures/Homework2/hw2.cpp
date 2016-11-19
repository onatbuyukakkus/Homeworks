#include "LinkedAndXOrBinaryTree.h"
#include "Stack.h"
#include "Recipe.h"
#include <iostream>
using namespace std;

LinkedAndXOrBinaryTree::LinkedAndXOrBinaryTree()
{
	root = new Node;
	root = NULL;
}

void LinkedAndXOrBinaryTree::addRoot(NodeType _type,string _name)
{
	if(root != NULL)
	{
		throw LinkedAndXOrBinaryTreeException();
	}
	else
	{
		root = new Node;
		root->type = _type;
		root->name = _name;
		root->cost = 0;
		root->left = NULL;
		root->right = NULL;
	}
}

void LinkedAndXOrBinaryTree::expandExternal(const Position& _p,NodeType _leftType,int _leftCost,string _leftName,NodeType _rightType,int _rightCost,string _rightName)
{
	Node *newNode = new Node;
	newNode = _p.getNode();
	if(_p.getNode() == NULL || _p.getNodeType() == LEAF || !_p.isExternal())
	{
		throw LinkedAndXOrBinaryTreeException();
	}
	else
	{
		newNode->left = new Node;
		newNode->right = new Node;	
		newNode->left->type = _leftType;
		newNode->right->type = _rightType;
		newNode->left->cost=_leftCost;
		newNode->right->cost=_rightCost;
		newNode->left->name=_leftName;
		newNode->right->name=_rightName;
	}
}

bool LinkedAndXOrBinaryTree::empty() const
{
	return root == NULL;
}

LinkedAndXOrBinaryTree::Position LinkedAndXOrBinaryTree::getRoot() const
{
	 return Position(root);
 
}

Recipe::Recipe(const BinaryTree& _tree)
{
	tree = &_tree;
}

void Recipe::getArbitraryRecipe(vector<Ingredient>& arbitraryRecipe,int& totalCost)
{
	Stack <Position> myStack;
	Position rootNode = tree->getRoot();
	myStack.push(rootNode);
	Position myNode;
	totalCost = 0;
	Ingredient myIngredient;
	while(!myStack.isEmpty()) //traversing tree preorder
	{
		myNode = myStack.top(); 
		myStack.pop();
		if(myNode.getNodeType()==XOR)
		{
			myStack.push(myNode.getNode()->left); //if type is XOR go to left child since we're interested in only one recipt
		}
		if(myNode.getNodeType()==AND)
		{

			myStack.push(myNode.getNode()->left); //if type is AND 
			myStack.push(myNode.getNode()->right);  //go to both children
		}
		if(myNode.getNodeType()==LEAF)
		{
			myIngredient.name=myNode.getNodeName();  //when it reaches LEAF 
			myIngredient.cost=myNode.getNodeCost(); //add costs and
			arbitraryRecipe.push_back(myIngredient); //push names to vector
			totalCost=totalCost + myIngredient.cost;
		}
	}
}

void Recipe::getAllRecipes(vector< vector<Ingredient> >& allRecipes,vector<int>& totalCosts)
{
	//since i couldn't be able to implement all recipes, when i see XOR while traversing tree preorder,
	//i went left and then i went right. i did the opposite afterwards
	
	/*ONE TO LEFT ONE TO RIGHT*/
	Stack <Position> myStack;
	Position rootNode = tree->getRoot();
	myStack.push(rootNode);
	Position myNode;
	int totalCost = 0;
	Ingredient myIngredient;
	vector<Ingredient> myIngredient2;
	int randomInteger = 0;
	while(!myStack.isEmpty())
	{
		myNode = myStack.top();
		myStack.pop();
		if(myNode.getNodeType()==XOR)
		{
			if(randomInteger%2 == 0) {myStack.push(myNode.getNode()->right);}
			else if(randomInteger%2 == 1) {myStack.push(myNode.getNode()->left);}
		}
		if(myNode.getNodeType()==AND)
		{

			myStack.push(myNode.getNode()->right);
			myStack.push(myNode.getNode()->left);
		}
		if(myNode.getNodeType()==LEAF)
		{
			myIngredient.name=myNode.getNodeName();
			myIngredient.cost=myNode.getNodeCost();
			totalCost=totalCost + myIngredient.cost;
			myIngredient2.push_back(myIngredient);
		}
		randomInteger++;
	}
	/*ONE TO RIGHT ONE TO LEFT*/
	Stack <Position> myStack2;
	Position rootNode2 = tree->getRoot();
	myStack2.push(rootNode2);
	Position myNode2;
	int totalCost2 = 0;
	Ingredient myIngredient3;
	vector<Ingredient> myIngredient4;
	int randomInteger2 = 0;
	while(!myStack2.isEmpty())
	{
		myNode2 = myStack2.top();
		myStack2.pop();
		if(myNode2.getNodeType()==XOR)
		{
			if(randomInteger2%2 == 0) {myStack2.push(myNode2.getNode()->left);}
			else if(randomInteger2%2 == 1) {myStack2.push(myNode2.getNode()->right);}
		}
		if(myNode2.getNodeType()==AND)
		{

			myStack2.push(myNode2.getNode()->right);
			myStack2.push(myNode2.getNode()->left);
		}
		if(myNode2.getNodeType()==LEAF)
		{
			myIngredient3.name=myNode2.getNodeName();
			myIngredient3.cost=myNode2.getNodeCost();
			totalCost2=totalCost2 + myIngredient3.cost;
			myIngredient4.push_back(myIngredient3);
		}
		randomInteger2++;
	}
	if(totalCost==totalCost2)
	{
		allRecipes.push_back(myIngredient2); //checking whether "left then right" and "right then left" 
		totalCosts.push_back(totalCost); //are same (that means checking if there are any XOR's)
	}
	else
	{
		allRecipes.push_back(myIngredient2);
		totalCosts.push_back(totalCost);
		allRecipes.push_back(myIngredient4);
		totalCosts.push_back(totalCost2);
	}
}










