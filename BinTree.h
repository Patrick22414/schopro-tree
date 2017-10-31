#ifndef BINTREE_H
#define BINTREE_H

#include "BinTreeNode.h"

template< typename Tree_T >
class BinTree
{
public:
	BinTree();
	
	
private:
	BinTreeNode< Tree_T >* root;
};

#endif // BINTREE_H
