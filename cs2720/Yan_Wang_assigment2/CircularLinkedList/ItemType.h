#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include<iostream>

using namespace std;

class ItemType{
 
  int value;
  
public:
  
  ItemType();
  void print();
  void initialize(int number);
  int getValue() const;
  
};

#endif
