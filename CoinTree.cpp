#include "stdafx.h"
#include "CoinTree.h"


CoinTree::CoinTree(const CoinTree & treeToCopy)
{
}

CoinTree::CoinTree()
{
	root_ = NULL;
}

CoinTree::~CoinTree()
{
}

void CoinTree::copyTree(CoinTreeNode*& copiedTreeRoot, CoinTreeNode* otherTreeRoot)
{
	if (otherTreeRoot == NULL) {
		copiedTreeRoot = NULL;
	}
	else {
		copiedTreeRoot = new CoinTreeNode();
		copyTree(copiedTreeRoot->leftSubtree_, otherTreeRoot->leftSubtree_);
	}
}

void CoinTree::inorder(CoinTreeNode * p)
{
	//if there is a left subtree, traverse left
	if (p->leftSubtree_) {
		inorder(p->leftSubtree_);
	}
	//vist the node
	cout << p->element_ << " ";
}

void CoinTree::inorderTraversal()
{
	if (root_) inorder(root_);
}

bool CoinTree::insert(Coin * insertItem)
{
	CoinTreeNode* newItem = new CoinTreeNode(insertItem, NULL);
	CoinTreeNode* current = this->root_;
	CoinTreeNode* trailing = NULL;

	//checks if tree is empty, assigns new item to root
	if (this->root_ == NULL) {
		this->root_ = newItem;
		return true;
	}
	else {
		//while there is still tree to traverse
		while (current != NULL) {

			//if the search item is smaller, search the left subtree
			else if (current->element_ > insertItem) {
				trailing = current;
				current = current->leftSubtree_;
			}

			//if the search item is larger, search the right subtree
			else if (current->element_ < insertItem) {
				trailing = current;
				current = current->rightSubtree_;
				// otherwise, you must have found it
			}
		}
		if (insertItem < trailing->element_) {
			trailing->leftSubtree_ = newItem;
			return true;
		}
		//greater than or equal to
		if (insertItem >= trailing->element_) {
			trailing->rightSubtree_ = newItem;
			return true;
		}

		return false;
	}
}

Coin * CoinTree::removeLowestValue()
{
	CoinTreeNode* current = this->root_;
	CoinTreeNode* trailing = NULL;
	CoinTreeNode* trailingPrev = NULL;
	if (root_ == NULL) {
		return NULL;
	}
	while (current) {
		trailingPrev = trailing;
		trailing = current;
		current = current->leftSubtree_;
	}
	Coin* temp;
	if (trailing == root_) {
		temp = root_;
		root_ == NULL;
		if (root_->rightSubtree_) {
			root_ = root_->rightSubtree_;
		}
		return temp;
	}
	temp = trailing;
	trailingPrev->leftSubtree_ = NULL;
	delete trailing;
	return temp;
	
}

bool CoinTree::search(const Coin * searchItem)
{
	//create a temporary variable named current to traverse the tree
	CoinTreeNode* current = this->root_;

	//while there is still tree to traverse
	while (current) {
		//if the search item is smaller, search the left subtree
		if (current->element_ > searchItem) {
			current = current->leftSubtree_;
			//if the search item is larger, search the right subtree
		}
		else {
			return true;
		}
	}
	//the end of the tree was reached with out finding the node
	return false;
}

//called by user, calls sumValues
double CoinTree::sumTraversal()
{
	double sum = 0;
	if (root_) {
		sumValues(root_, sum);
	}
	return sum;
}

void CoinTree::sumValues(CoinTreeNode* p, double& sum)
{
	if (p->leftSubtree_) {
		sum += p->leftSubtree_->element_->getValue();
		sumValues(p->leftSubtree_, sum);
	}
}

CoinTree::CoinTreeNode::CoinTreeNode()
{
	leftSubtree_ = NULL;
}

CoinTree::CoinTreeNode::CoinTreeNode(Coin * element, CoinTreeNode* leftSubtree)
{
	element_ = element;
	leftSubtree_ = leftSubtree;
}
