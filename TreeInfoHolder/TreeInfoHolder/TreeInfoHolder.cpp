//dont have enough time to refactor, finish project

#include <iostream>
#include <string>
#include <list>
#include <fstream>

using namespace std;

class BaseHolder
{

};

class IntHolder : public BaseHolder
{
public:
	int value;
	IntHolder(int input)
	{
		value = input;
	}
};

class CharArrayHolder : public BaseHolder
{
public:
	char* value;
	CharArrayHolder(char* input)
	{
		value = input;
	}
};

class DoubleHolder : public BaseHolder
{
public:
	double value;
	DoubleHolder(double input)
	{
		value = input;
	}
};

class TreeNode
{
public:
	TreeNode* child;
	BaseHolder value;

	TreeNode()
	{
		child = {};
		value = IntHolder(0);
	}

	TreeNode(BaseHolder inputValue)
	{
		child = {};
		value = inputValue;
	}
};

class Tree
{
public:
	TreeNode root;

	Tree(BaseHolder inputValue)
	{
		root = TreeNode(inputValue);
	}

	void AddTo(TreeNode parentElement, BaseHolder addedElementValue)
	{
		int lenghtOfChild = sizeof(parentElement.child);
		TreeNode* newChild = new TreeNode[lenghtOfChild + 1];
		for (int i =0;i< lenghtOfChild;i++)
		{
			newChild[i] = parentElement.child[i];
		}
		newChild[lenghtOfChild] = TreeNode(addedElementValue);
		delete[]parentElement.child;
		parentElement.child = newChild;
		delete[]newChild;
		return;
	}
};


Tree CreateAndFillTree()
{
	Tree output = (IntHolder(11));
	output.AddTo(output.root, CharArrayHolder(strdup("anyText")));
	output.AddTo(output.root.child[0], CharArrayHolder(strdup("afterAnyText")));
	output.AddTo(output.root.child[0], DoubleHolder(3.14));
	output.AddTo(output.root.child[0].child[1], IntHolder(15926535));
	output.AddTo(output.root, IntHolder(2));
	output.AddTo(output.root.child[1], DoubleHolder(312.441));
	output.AddTo(output.root.child[1].child[0], CharArrayHolder(strdup("anotherText")));
	return output;
}

bool WriteTreeToFile(Tree tree, string fileWay)
{
	ofstream file;
	file.open(fileWay);
	if (!file.is_open())
		return false;

	file << tree.root.value.
}

int main()
{
    
}