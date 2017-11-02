#ifndef BINTREENODE_H
#define BINTREENODE_H

template< typename Node_T >
class BinTreeNode
{
public:
	BinTreeNode();
	BinTreeNode(const Node_T& xdata);
	BinTreeNode(const BinTreeNode& copy);
	template< typename Tree_T > friend class BinTree;
private:
	Node_T data;
	BinTreeNode< Node_T >* parent;
	BinTreeNode< Node_T >* lchild;
	BinTreeNode< Node_T >* rchild;
};

template< typename Node_T >
BinTreeNode::BinTreeNode() {
	parent = NULL;
	lchild = NULL;
	rchild = NULL;
}

template< typename Node_T >
BinTreeNode::BinTreeNode(const Node_T& xdata) {
	data = xdata;
	parent = NULL;
	lchild = NULL;
	rchild = NULL;
}

template< typename Node_T >
BinTreeNode::BinTreeNode(const BinTreeNode& copy) {
	data = copy.data;
	parent = copy.parent;
	lchild = copy.lchild;
	rchild = copy.rchild;
}
#endif // BINTREENODE_H
