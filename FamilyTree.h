#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include "BinTree.h"

enum Gender { female, male, others, unknown };

struct Member {
	string name;
	Gender gender;
	int birth[3]; // birthday of the member. [1] contains year, month in [2], and day [3].
	//TODO
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
