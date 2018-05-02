#ifndef CIRCULARLINKEDLIST_H
#define CIRCULARLINKEDLIST_H

#include "ItemType.h"
#include <iostream>

using namespace std;

struct NodeType{
  ItemType info;
  NodeType* next;
};

class CircularLinkedList{

  int length;
  NodeType* head;
  NodeType* current;
  
 public:
  CircularLinkedList();
  ~CircularLinkedList();
  int lengthIs()const;
  void insertItem(ItemType &item);
  void deleteItem(ItemType &item);
  void findItem(NodeType* listData, ItemType item, NodeType*& location, NodeType*& preloc, bool& found); 
  void print();
};


#endif
