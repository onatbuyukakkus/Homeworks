#include <vector>
#include <string>

using namespace std;

class Recipe
{
	public: 
		struct Ingredient// Ingredients of the recipe
		{
			string name;// name of the ingredient
			int cost;// cost of the ingredient
		};
	private:
    		typedef LinkedAndXOrBinaryTree BinaryTree;// Redefinition of the LinkedBinaryTree type
    		typedef LinkedAndXOrBinaryTree::Position Position;// Redefinition of the Position type
	private:
		const BinaryTree* tree;// Data member for the tree
	public:
		Recipe(const BinaryTree& _tree);// Create Recipe instance with the given tree. Be cautious to const and & keywords
		void getArbitraryRecipe(vector<Ingredient>& arbitraryRecipe,int& totalCost);// Returns an arbitrary receipt
		void getAllRecipes(vector< vector<Ingredient> >& allRecipes,vector<int>& totalCosts);// Returns all receipts
};
