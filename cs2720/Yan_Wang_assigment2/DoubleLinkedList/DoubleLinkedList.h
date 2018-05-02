#ifndef DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_H

#include "ItemType.h"
#include <iostream>

using namespace std;

struct NodeType{
  ItemType info;
  NodeType* next;
  NodeType* back;
};

class DoubleLinkedList{

  int length;
  NodeType* head;
  NodeType* current;
  NodeType* findNode(ItemType &item);
  void getNextNode(); 
  
 public:
  DoubleLinkedList();
  ~DoubleLinkedList();
  int lengthIs()const;
  void retrieveItem(ItemType &item, bool &found);
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  void resetList();
  void print();
};


#endif
