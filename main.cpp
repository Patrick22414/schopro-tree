#define WINDOWS


/** FAMILY TREE */

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include"node.h"
#include"familyTree.h"

using namespace std;

//void connect(familyTree *T1, familyTree *T2);

int main()
{
    familyTree T;
    int opt,n1,n2;
    char c,name[50];
    while(1)
    {
#ifdef WINDOWS
        system("cls");
#endif // WINDOWS

        cout<<"\n\n\n\t1. Add new person\n\t2. Find relationship b/w two persons\n\t3. Search\n\t4. Destroy\n\t5. Display\n\t6. Exit\n\n\tEnter your choice = ";
        cin>>opt;
        cout<<endl;

        switch(opt)
        {

        default:
                cout<<"Invalid input";
                break;

        case 1:
                T.addNew();
                break;

        case 2:
                T.find();
                break;

        case 3:
                cout<<"Enter name of person to search: ";
                cin>>name;
                T.show(T.search(name));
                break;

        case 4:
                T.destroy(T.start);
                cout<<"Tree "<<" has been destroyed sucessfully";
                break;

        case 5:
                T.display(T.start);
                break;

        case 6:
            return 0;

        }
        cout<<"\n\nPress any key to continue.....";
        cin>>c;
    }
}
// Edited by Zhang Niansong
// 2017/11/12