#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include "BinTree.h"

enum Gender { female, male, others, unknown };

struct Member {
	string name;
	Gender gender;
	int birth[3];
}

class FamilyTree
{
public:
	//TODO
private:
	BinTree< Member > family;
};

//TODO

#endif // FAMILYTREE_H
