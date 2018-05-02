#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "ItemType.h"
#include <iostream>

using namespace std;

struct NodeType{
  ItemType info;
  NodeType* next;
};

class LinkedList{

  int length;
  NodeType* head;
  NodeType* current;
  NodeType* findNode(ItemType &item);
  void getNextNode(); 
  
 public:
  LinkedList();
  ~LinkedList();
  int lengthIs()const;
  void retrieveItem(ItemType &item, bool &found);
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  void resetList();
  void getNextItem(ItemType &item);
  void makeEmpty();
  void print();
};


#endif
