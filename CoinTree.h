#pragma once
#include "Coin.h"
class CoinTree
{
public:
	CoinTree(const CoinTree& treeToCopy);
	CoinTree();
	~CoinTree();
	class CoinTreeNode {
	public:
		Coin* element_;
		CoinTreeNode* leftSubtree_;
		CoinTreeNode* rightSubtree_;
		CoinTreeNode();
		CoinTreeNode(Coin* coin, CoinTreeNode* leftSubtree);
	};
protected:
	CoinTreeNode* root_;
public:

	void copyTree(CoinTreeNode*& copiedTreeRoot, CoinTreeNode* otherTreeRoot);
	void inorder(CoinTreeNode* p);
	void inorderTraversal();
	bool insert(Coin* insertItem);
	Coin* removeLowestValue();
	bool search(const Coin* searchItem);
	double sumTraversal();
	void sumValues(CoinTreeNode* p, double& sum);
};

