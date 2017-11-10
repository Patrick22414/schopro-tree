#ifndef FAMILYMEM_H
#define FAMILYMEM_H

#include <iostream>
#include <string>

enum Gender { female, male, other, none };

class FamilyMem // family member
{
public:
	FamilyMem();
	FamilyMem(string xname);
	FamilyMem(string xname, Gender xgender);
	FamilyMem(string xname, int yyyy, int mm, int dd);
	FamilyMem(string xname, Gender xgender, int yyyy, int mm, int dd, string xspouse = "");

	bool operator==(const FamilyMem& another);
	ostream operator<<(ostream& os);

	display(int leadingspaces = 0);
private:
	string name;
	Gender gender;
	int birthday[3];
	string spouse;
};

FamilyMem::FamilyMem() {
	FamilyMem("", none, 0, 0, 0, "");
}

FamilyMem:FamilyMem(string xname) {
	FamilyMem(xname, none, 0, 0, 0, "");
}

FamilyMem::FamilyMem(string xname, Gender xgender) {
	FamilyMem(xname, xgender, 0, 0, 0, ""};
}

FamilyMem::FamilyMem(string xname, int yyyy, int mm, int dd) {
	FamilyMem(xname, none, yyyy, mm, dd, "");
}

FamilyMem::FamilyMem(string xname, Gender xgender, int yyyy, int mm, int dd, string xspouse) {
	name = xname;
	gender = xgender;
	birthday[0] = yyyy;
	birthday[1] = (mm > 0 && mm < 13) ? mm : 0;
	switch (mm) {
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			birthday[2] = (dd > 0 && dd < 32) ? dd : 0;
			break;
		case 4: case 6: case 9: case 11:
			birthday[2] = (dd > 0 && dd < 31) ? dd : 0;
			break;
		case 2:
			if ((yyyy%4 == 0) && (yyyy%100 !=0) || (yyyy%400 == 0)) {
				birthday[2] = (dd > 0 && dd < 30) ? dd : 0;
			}else {
				birthday[2] = (dd > 0 && dd < 29) ? dd : 0;
			}
	}
	spouse = xspouse;
}

bool FamilyMem::operator==(const FamilyMem& another) {
	bool flag = true;
	if (!strcmp(name, "") && !strcmp(another.name, "") && !strcmp(name, another.name)) {
		flag = false;
	}
	if (gender!=none && another.gender!=none && gender!= another.gender) {
		flag = false;
	}
	for (int i=0; i<3; i++) {
		if (birthday[i]!=0 && another.birthday[i]!=0 && birthday[i]!=another.birthday[i]) {
			flag = false;
		}
	}
	if (!strcmp(spouse, "") && !strcmp(another.spouse, "") && !strcmp(spouse, another.spouse)) {
		flag = false;
	}
	return flag;
}

ostream FamilyMem::operator <<(ostream& os) {
}

FamilyMem::display(int leadingspaces) {
}

#endif // FAMILYMEM_H
