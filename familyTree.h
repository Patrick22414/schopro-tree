#ifndef FAMILYTREE_H
#define FAMILYTREE_H

#include<iostream>
#include<string.h>
#include<stdlib.h>
#include"node.h"

class familyTree
{

public:

    node* start;

    familyTree();

    node* traverseDown(node*,char[]);   // Search functions
    node* traverseRight(node*,char[]);
    node* search(char[]);

    void addSib(node*,node*);           // Auxilliary functions for adding new members
    void addChild(node*,node*);
    void addNew();                      // Function for adding new members

    void find();                        // Function to find relations
    void show(node*);                   // Function to show details of particular person
    void display(node*);                // Function to display full tree
    void destroy(node*);                // Function to destroy full tree
    void updateX(node*,int);

};


#endif // FAMILYTREE_H
// Edited by Zhang Niansong
// 2017/11/12
