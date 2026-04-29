#pragma once
#include <iostream>
#include <string>
#include <stack>
using namespace std ;

struct node {
string song ; 
string artist ;
string genre ;
int duration_seconds ;
int play_count ;
node* next ;
node* pre ;
};
