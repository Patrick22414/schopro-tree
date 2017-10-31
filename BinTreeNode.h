#ifndef BINTREENODE_H
#define BINTREENODE_H

template< typename Node_T >
class BinTreeNode
{
public:
	BinTreeNode();
	BinTreeNode(const Node_T& xdata);
	template< typename Tree_T > friend class BinTree;
private:
	Node_T data;
	BinTreeNode< Node_T >* parent;
	BinTreeNode< Node_T >* lchild;
	BinTreeNode< Node_T >* rchild;
};

#endif // BINTREENODE_H
