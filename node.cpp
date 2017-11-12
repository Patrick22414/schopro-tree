#include "node.h"
#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std;

node::node()
{
    fc=ns=NULL;
    g=0;
    strcpy(name,"");
    age=x=0;
}

void node::getData()
{
    char ch;
    cout<<"\nName of the Person: ";
    cin>>name;
    cout<<"Age of "<<name<<": ";
    cin>>age;
    if (age > 22)
    {
       cout<<"Spouse of the Person: ";
       cin>>spouse;
    }
    cout<<name<<" is (m/f): ";
    cin>>ch;
    if(ch=='m')
        g=1;
}
// Edited by Zhang Niansong
// 2017/11/12
