#ifndef BINTREE_H
#define BINTREE_H

#include "BinTreeNode.h"

enum ErrBinTree { BT_SUCCESS, BT_FAIL };

template< typename Tree_T >
class BinTree
{
public:
	BinTree();
	BinTree(const Tree_T& rootdata);

	void preorder(void (*visit)(BinTreeNode< Tree_T >& node));
	void inorder(void (*visit)(BinTreeNode< Tree_T >& node));
	void postorder(void (*visit)(BinTreeNode< Tree_T >& node));
	void bylayer(void (*visit)(BinTreeNode< Tree_T >& node));
	BinTreeNode* find(Tree_T xdata);
	ErrBinTree addLeft(BinTreeNode< Tree_T >* parentptr, const Tree_T& xdata);
	ErrBinTree addRight(BinTreeNode< Tree_T >* parentptr, const Tree_T& xdata);
	ErrBinTree remove(BinTreeNode< Tree_T >* entryptr);
	ErrBinTree replace(BinTreeNode< Tree_T >* entryptr, const Tree_T& xdata);

	BinTreeNode* findParent();
	void display();
	//TODO

private:
	BinTreeNode< Tree_T >* root;
};

//TODO

#endif // BINTREE_H
