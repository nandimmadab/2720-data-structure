#include "LinkedList.h"

/**
return the address of the node that contains the item.
Otherwise return nullptr.
@param item: this is the item you want to find the node
@return: the address of the item
*/
NodeType* LinkedList::findNode(ItemType &item){
  current = head;
  for(int i = 0; i < length; i++){
    if(current->info.getValue() != item.getValue()){
      getNextNode();
    }else{
      return current;
    }
  }
  return nullptr;
}

/**
current points to it’s next node.
*/
void LinkedList::getNextNode(){
  current = current->next;
}

/**
List is created.
*/
LinkedList::LinkedList(){
  length = 0;
  head = nullptr;
  current = head;
}

/**
all nodes are freed.
*/
LinkedList::~LinkedList(){
  NodeType* temp;
  while(head != nullptr){
    temp = head;
    head = head->next;
    delete temp;
  }
}

/**
return length instance variable.
@return: length
*/
int LinkedList::lengthIs()const{
  return length;
}

/**
found is set to true if the item is found in the list and
item is set to the info instance variable of the node
that is equal to item.
@param item: this is the item you want to retrieve
*/
void LinkedList::retrieveItem(ItemType &item, bool &found){
  if(findNode(item) != nullptr){
    found = true;
    item.initialize(findNode(item)->info.getValue());
  }else{
    found = false;
  }
}

/**
item is inserted into the list in sorted order.
@param item: this is the item you want to insert
*/
void LinkedList::insertItem(ItemType &item){
  NodeType * nNode = new NodeType();
  NodeType * pNode = nullptr;
  nNode->info.initialize(item.getValue());
  if(head == nullptr){						// when head == nullptr
    head = nNode;
    length++;
  }else if(item.compareTo(head->info) == LESS){			// insert before the head
    nNode->next = head;
    head = nNode;
    length++;
  }else{
    current = head;
    for(int i = 0; i < length; i++){
      if(item.compareTo(current->info) == LESS){		// insert before the current 
	nNode->next = current;
	pNode->next = nNode;
	length++;
	break;
      }else if(i == (length - 1)){				// insert in the end
	current->next = nNode;
	length++;
	break;
      }else{							// get next node
	pNode = current;
	getNextNode();
      }
    }
  }
}

/**
the node that contains item is removed from the list.
@param item: this is the item you want to delete
*/
void LinkedList::deleteItem(ItemType &item){
  NodeType * preLocation = head;
  NodeType * location = head;
  if(head == nullptr){
    return;
  }
  if(head->info.compareTo(item) == EQUAL){			// delete head
    head = head->next;
    length --;
  }else{
    location = head->next;
    for(int i = 0; i < length ; i++){
      if(location->info.compareTo(item) == EQUAL){		// delete current
	preLocation->next = location->next;
	length --;
	break;
      }else{							// get next node
	preLocation = preLocation->next;
	location = location->next;
      }
    }
  }
  delete location;
}
/**
currrent pointer is set to nullptr.
*/
void LinkedList::resetList(){
  current = nullptr;
}

/**
item equals the info member of the next node pointed
to by the current pointer. Current now points to the
next node.
@param item: this is the item, and you want to find the next one
*/
void LinkedList:: getNextItem(ItemType &item){
  if(current == nullptr){
    current = head;
  }else{
    if(current->next != nullptr){
      getNextNode();
    }else{
      current = head;
    }
  }
  item = current->info;
}

/**
ist contains no items. Length is equal to 0. All node
pointer memory freed.
*/
void LinkedList::makeEmpty(){
  NodeType* temp;
  while(head != nullptr){
    temp = head;
    head = head->next;
    delete temp;
  }
  length = 0;
}

/**
items are printed to standard-out based on the
implementation in ItemType.
*/
void LinkedList::print(){
  cout << "List:"; 
  current = head;
  for(int i = 0; i < length; i++){
    if(i != (length-1)){
      cout << current->info.getValue() << ",";
      getNextNode();
    }else{
      cout << current->info.getValue() << endl;
    }
  }
}
