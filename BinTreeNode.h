#ifndef BINTREENODE_H
#define BINTREENODE_H

template< typename Node_T >
class BinTreeNode
{
public:
	BinTreeNode();
	BinTreeNode(const Node_T& xdata);
	BinTreeNode(const BinTreeNode& copy); // copy constructor
	// BinTree is a friend of BinTreeNode, and thus has full access to its private members.
	template< typename Tree_T > friend class BinTree;
	
private:
	Node_T data;
	BinTreeNode< Node_T >* parent;
	BinTreeNode< Node_T >* lchild;
	BinTreeNode< Node_T >* rchild;
};

template< typename Node_T >
BinTreeNode< Node_T >::BinTreeNode() {
	parent = NULL;
	lchild = NULL;
	rchild = NULL;
}

template< typename Node_T >
BinTreeNode< Node_T >::BinTreeNode(const Node_T& xdata) {
	data = xdata;
	parent = NULL;
	lchild = NULL;
	rchild = NULL;
}

template< typename Node_T >
BinTreeNode< Node_T >::BinTreeNode(const BinTreeNode& copy) {
	data = copy.data;
	parent = copy.parent;
	lchild = copy.lchild;
	rchild = copy.rchild;
}
#endif // BINTREENODE_H
