#ifndef ITEMTYPE_H
#define ITEMTYPE_H

#include<iostream>

using namespace std;

typedef enum {GREATER,LESS,EQUAL} RelationType;

class ItemType{
 
  int value;
  
public:
  
  ItemType();
  RelationType compareTo(ItemType &item);
  void print();
  void initialize(int number);
  int getValue() const;
  
};

#endif
