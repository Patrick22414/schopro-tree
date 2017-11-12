#ifndef NODE_H
#define NODE_H

#include<iostream>
#include<string.h>
#include<stdlib.h>

struct node
{
    char name[50];
    char spouse[50];
    short int age,x;    // x - height of node
    bool g;             // g- gender
    node* fc;           // Pointer to first child
    node* ns;           // Pointer to next sibiling

    node();
    void getData();
};

#endif // NODE_H
// Edited by Zhang Niansong
// 2017/11/12
