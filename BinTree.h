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
	~BinTree();

	bool isempty() {return count == 0}
	int size() {return count}
	int depth() {return level}

	void preorder(void (*visit)(Tree_T&));
	void inorder(void (*visit)(Tree_T&));
	void postorder(void (*visit)(Tree_T&));
	void bylayer(void (*visit)(Tree_T&));
	BinTreeNode< Tree_T >* find(const Tree_T& xdata);
	ErrBinTree addLeft(BinTreeNode< Tree_T >* parentptr, const Tree_T& xdata);
	ErrBinTree addRight(BinTreeNode< Tree_T >* parentptr, const Tree_T& xdata);
	ErrBinTree remove(BinTreeNode< Tree_T >* nodeptr); // remove the whole subtree below this node
	ErrBinTree replace(BinTreeNode< Tree_T >* nodeptr, const Tree_T& xdata);

	BinTreeNode* findParent(); // neither am I sure about what this method does, yet...
	void display(); // print the whole tree to console in ASCII
	//TODO

private:
	// private recursive methods for preorder, inorder and postorder traversal
	void travRecurse_preo(void (*visit)(Tree_T&), BinTreeNode< Tree_T >* subroot) {
		if (subroot != NULL) {
			(*visit)(subroot->data);
			travRecurse_preo(visit, subroot->lchild);
			travRecurse_preo(visit, subroot->rchild);
		}
	}
	void travRecurse_ino(void (*visit)(Tree_T&), BinTreeNode< Tree_T >* subroot) {
		if (subroot != NULL) {
			travRecurse_ino(visit, subroot->lchild);
			(*visit)(subroot->data);
			travRecurse_ino(visit, subroot->rchild);
		}
	}
	void travRecurse_posto(void (*visit)(Tree_T&), BinTreeNode< Tree_T >* subroot) {
		if (subroot != NULL) {
			travRecurse_posto(visit, subroot->lchild);
			travRecurse_posto(visit, subroot->rchild);
			(*visit)(subroot->data);
		}
	}
	// private recursive method for searching an element
	BinTreeNode< Tree_T >* searchRecurse(const Tree_T& xdata; BinTreeNode< Tree_T >* subroot) {
		/*if (subroot->data == xdata) {
			return subroot;
		}
		if (subroot->lchild != NULL) {
			return searchRecurse(xdata, subroot->lchild);
		}else if (subroot->rchild != NULL) {
			return searchRecurse(xdata, subroot->rchild);
		}*/
		//TODO
	}
	int count; // number of elements in the binary tree
	int level; // number of levels in the binary tree
	BinTreeNode< Tree_T >* root;
};

template< typename Tree_T >
BinTree< Tree_T >::BinTree() {
	count = 0;
	level = 0;
	root = NULL;
}

template< typename Tree_T >
BinTree< Tree_T >::BinTree(const Tree_T& rootdata) {
	count = 1;
	level = 1;
	root = new BinTreeNode< Tree_T >(rootdata);
}

template< typename Tree_T >
void BinTree< Tree_T >::preorder(void (*visit)(Tree_T&)) {
	travRecurse_preo(visit, root);
}

template< typename Tree_T >
void BinTree< Tree_T >::inorder(void (*visit)(Tree_T&)) {
	travRecurse_ino(visit, root);
}

template< typename Tree_T >
void BinTree< Tree_T >::postorder(void (*visit)(Tree_T&)) {
	travRecurse_posto(visit, root);
}

template< typename Tree_T >
void BinTree< Tree_T >::bylayer(void (*visit)(Tree_T&)) {
	std::queue< BinTreeNode< Tree_T >* > q;
	BinTreeNode< Tree_T >* current = root;
	q.push(current);
	while (q.front() != NULL) {
		current = q.front();
		q.push(current->lchild);
		q.push(current->rchild);
		(*visit)(current->data);
		q.pop();
	}
}

template< typename Tree_T >
BinTreeNode< Tree_T >* BinTree< Tree_T >::find(Tree_T xdata) {
	return searchRecurse(xdata, root);
}

template< typename Tree_T >
ErrBinTree BinTree< Tree_T >::addLeft(BinTreeNode< Tree_T >* parentptr, const Tree_T& xdata) {

}

template< typename Tree_T >
ErrBinTree BinTree< Tree_T >::addRight(BinTreeNode< Tree_T >* parentptr, const Tree_T& xdata) {

}

template< typename Tree_T >
ErrBinTree BinTree< Tree_T >::remove(BinTreeNode< Tree_T >* nodeptr) {

}

template< typename Tree_T >
ErrBinTree BinTree< Tree_T >::replace(BinTreeNode< Tree_T >* nodeptr, const Tree_T& xdata) {

}

#endif // BINTREE_H
