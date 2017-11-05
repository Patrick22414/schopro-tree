#ifndef BINTREE_H
#define BINTREE_H

#include "BinTreeNode.h"

enum ErrBinTree { BT_SUCCESS, BT_FAIL, BT_OCCUPIED };

template< typename Tree_T >
class BinTree
{
public:
	BinTree();
	BinTree(const Tree_T& rootdata);

	bool isempty();
	int size();
	int depth();

	void preorder(void (*visit)(Tree_T& data));
	void inorder(void (*visit)(Tree_T& data));
	void postorder(void (*visit)(Tree_T& data));
	void bylayer(void (*visit)(Tree_T& data));
	BinTreeNode< Tree_T >* find(Tree_T xdata);
	ErrBinTree addLeft(BinTreeNode< Tree_T >* parentptr, const Tree_T& xdata);
	ErrBinTree addRight(BinTreeNode< Tree_T >* parentptr, const Tree_T& xdata);
	ErrBinTree remove(BinTreeNode< Tree_T >* nodeptr); // remove the whole subtree below this node
	ErrBinTree replace(BinTreeNode< Tree_T >* nodeptr, const Tree_T& xdata);

	BinTreeNode* findParent(); // neither am I sure about what this method does, yet...
	void display(); // print the whole tree to console in ASCII
	//TODO

private:
	// private recursive methods for preorder, inorder and postorder traversal
	void travRecurse_preo(void (*visit)(Tree_T& data), BinTreeNode< Tree_T >* subroot) {
		if (subroot != NULL) {
			(*visit)(subroot->data);
			travRecurse_preo(visit, subroot->lchild);
			travRecurse_preo(visit, subroot->rchild);
		}
	}
	void travRecurse_ino(void (*visit)(Tree_T& data), BinTreeNode< Tree_T >* subroot) {
		if (subroot != NULL) {
			travRecurse_ino(visit, subroot->lchild);
			(*visit)(subroot->data);
			travRecurse_ino(visit, subroot->rchild);
		}
	}
	void travRecurse_posto(void (*visit)(Tree_T& data), BinTreeNode< Tree_T >* subroot) {
		if (subroot != NULL) {
			travRecurse_posto(visit, subroot->lchild);
			travRecurse_posto(visit, subroot->rchild);
			(*visit)(subroot->data);
		}
	}

	int count; // number of elements in the binary tree
	int level; // number of levels in the binary tree
	BinTreeNode< Tree_T >* root;
};

template< typename Tree_T >
BinTree< Tree_T >::BinTree() {
	root = NULL;
}

template< typename Tree_T >
BinTree< Tree_T >::BinTree(const Tree_T& rootdata) {
	root = new BinTreeNode< Tree_T >(rootdata);
}

template< typename Tree_T >
void BinTree< Tree_T >::preorder(void (*visit)(Tree_T& data)) {
	travRecurse_preo(visit, root);
}

template< typename Tree_T >
void BinTree< Tree_T >::inorder(void (*visit)(Tree_T& data)) {
	travRecurse_ino(visit, root);
}

template< typename Tree_T >
void BinTree< Tree_T >::postorder(void (*visit)(Tree_T& data)) {
	travRecurse_posto(visit, root);
}
#endif // BINTREE_H
