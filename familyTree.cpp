#include "familyTree.h"
#include<iostream>
#include<string.h>
#include<stdlib.h>

using namespace std;

familyTree::familyTree()
{
    start = NULL;
}

void familyTree::destroy(node* ptr)
{
    node* temp = ptr;

    if(ptr==NULL)
        return;

    while(ptr!=NULL)
    {
        destroy(ptr->fc);
        temp = ptr;
        ptr = ptr->ns;
        delete temp;
    }

    start = NULL;
}

void familyTree::show(node* ptr)
{
    char g[10];
    strcpy(g,"Female");
    if(ptr->g)
        strcpy(g,"Male");
    cout<<"\n\nName: "<< ptr->name <<endl;
    cout<<"Age: "<< ptr->age <<endl;
    cout<<"Gender: "<<g<<endl;
    cout<<"Spouse: "<<ptr->spouse <<endl;
}

void familyTree::display(node* ptr)
{
    // Traverses the full n-array tree by recursion to display names of all people

    if(ptr==NULL)
        return;

    while(ptr!=NULL)
    {
        cout<< ptr->name <<endl;
        if(ptr->age > 22)
            cout << ptr->spouse <<endl;
        display(ptr->fc);
        ptr = ptr->ns;
    }
}

void familyTree::find()
{

    /*
        Same hight: Sibiling if same parent, else cousin
        Difference of height = 1 - Parent if immediate, else uncule/aunt
        Difference oh height = 2 - Grand parents if same link, elss idk
    */

    char name1[50],name2[50];
    cout<<"Enter names of two persons:\n";
    cin>>name1>>name2;
    node* ptr1 = search(name1);
    node* ptr2 = search(name2);
    node* ptr;
    node* ptrk=ptr1;
    node* ptrk1=ptr2;

    switch(ptr1->x - ptr2->x)
    {

    case 0:
            char s[50];
            strcpy(s,"sister");
            if(ptr1->g)
                strcpy(s,"brother");

            ptr = ptr1;
            while(ptr!=NULL)
            {
                if(ptr==ptr2)
                {
                    cout<<endl<<name1<<" is "<<name2<<"'s "<<s<<endl;
                    return;
                }
                ptr = ptr->ns;
            }
            ptr = ptr2;
            while(ptr!=NULL)
            {
                if(ptr==ptr1)
                {
                    cout<<endl<<name1<<" is "<<name2<<"'s "<<s<<endl;
                    return;
                }
                ptr = ptr->ns;
            }
            cout<<endl<<name1<<" and "<<name2<<" are Cousins";
            break;

    case 1:
            char str3[50];
            strcpy(str3,"daughter");
            if(ptr1->g)
                strcpy(str3,"son");
            ptr2 = ptr2->fc;
            while(ptr2!=NULL)
            {
                if(ptr2==ptr1)
                {
                    cout<<endl<<name1<<" is "<<name2<<"'s "<<str3;
                    return;
                }
                ptr2=ptr2->ns;
            }
            strcpy(str3,"niece");
            if(ptr1->g)
                strcpy(str3,"nephew");
            cout<<endl<<name1<<" is "<<name2<<"'s "<<str3;
            break;
    case -1:
            char str[10];
            
            if(name1 != ptrk->name)
            {
                strcpy(str,"father");
                if(ptrk->g)
                    strcpy(str,"mother");
            }
            else
            {
                strcpy(str,"mother");
                if(ptrk->g)
                    strcpy(str,"father");
            }

            ptr = ptrk->fc;
            while(ptr!=NULL)
            {
                if(ptr==ptrk1)
                {
                    cout<<endl<<name1<<" is "<<name2<<"'s "<<str;
                    return;
                }
                ptr=ptr->ns;
            }
            if(name1 != ptrk->name)
            {
                strcpy(str,"uncle");
                if(ptrk->g)
                    strcpy(str,"aunt");
            }
            else
            {
                strcpy(str,"aunt");
                if(ptrk->g)
                    strcpy(str,"uncle");
            }
            cout<<endl<<name1<<" is "<<name2<<"'s "<<str;
            break;

    case 2:
            char str1[50];
            strcpy(str1,"daughter");
            if(ptr2->g)
                strcpy(str1,"son");
            ptr2 = ptr2->fc->fc;
            while(ptr2!=NULL)
            {
                if(ptr2==ptr1)
                {
                    cout<<endl<<name1<<" is grand "<<str1<<" of "<<name2;
                    return;
                }
                ptr2 = ptr2->ns;
            }
            break;
    case -2:
            char str2[50];
            if(name1 != ptrk->name)
            {
                strcpy(str2,"father");
                if(ptrk->g)
                    strcpy(str2,"mother");
            }
            else
            {
                strcpy(str2,"mother");
                if(ptrk->g)
                    strcpy(str2,"father");
            }

             ptr1 = ptr1->fc->fc;

            while(ptr1!=NULL)
            {
                if(ptr1==ptr2)
                {
                    cout<<endl<<name1<<" is grand "<<str2<<" of "<<name2;
                    return;
                }
                ptr1 = ptr1->ns;
            }

            break;
    default:
            cout<<"Too far relationship";
            break;
    }
}



node* familyTree::search(char s[50])
{
    /*
        Searches for the given name from start to it's sibilings and their children
        Returns the pointer of node where the name is present
    */

    node *ptr = start;

    if(strcmp(ptr->name,s)==0)
        return ptr;
    else if(traverseRight(start,s)!=NULL)
        return traverseRight(start,s);
    else if(traverseDown(start,s)!=NULL)
        return traverseDown(start,s);
    else
    {
        return NULL;
        cout<<"***Not found***8";
    }
}

node* familyTree::traverseDown(node* ptr, char s[50])
{
    // Searches all the children

    ptr = ptr->fc;

    while(ptr!=NULL)
    {
        if(  strcmp(ptr->name,s)==0 || strcmp(ptr->spouse,s)==0 )
            return ptr;
        else if(traverseRight(ptr,s)!=NULL)
            return traverseRight(ptr,s);
        else
            ptr = ptr->fc;
    }
    return NULL;
}

node* familyTree::traverseRight(node* ptr, char s[50])
{

    //  Searches all the sibilings

    ptr = ptr->ns;

    while(ptr!=NULL)
    {
        if(strcmp(ptr->name,s)==0 || strcmp(ptr->spouse, s)==0)
            return ptr;
        else if (traverseDown(ptr,s)!=NULL)
            return traverseDown(ptr,s);
        else
            ptr = ptr->ns;
    }
    return NULL;
}

void familyTree::addNew()
{
    node* temp = new node;
    temp->getData();

    if(start == NULL)
    {
        start = temp;
        temp->x=0;
    }

    else
    {
        cout<<"\nEnter any relation's name: ";
        char name[50];
        cin>>name;
        cout<<"\n1. Child\n2. Sibiling\n\n"<< temp->name <<" is ____ to "<<name<<" : ";
        int opt;
        cin>>opt;
        switch(opt)
        {
            case 1:
                    addChild(search(name),temp);
                    break;
            case 2:
                    addSib(search(name),temp);
                    break;

        }
    }
    cout<<"\nPerson sucessfully added.\n";
}

void familyTree::addSib(node* a,node* b)
{
    // b is added as sibling of a

    while(a->ns!=NULL)
        a=a->ns;
    a->ns = b;

    b->x = a->x;
}

void familyTree::addChild(node* a,node* b)
{

    // b is added as child as a (or) b is added as sibiling to last child of a

    if(a->fc==NULL)
        a->fc = b;
    else
        addSib(a->fc,b);

    b->x = a->x+1;
}

// Edited by Zhang Niansong
// 2017/11/12