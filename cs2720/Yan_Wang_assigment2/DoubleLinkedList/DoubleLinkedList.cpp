#include "DoubleLinkedList.h"

/**
return the address of the node that contains the item.
Otherwise return nullptr.
@param item: this is the item you want to find the node
@return: the address of the item
*/
NodeType* DoubleLinkedList::findNode(ItemType &item){
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
void DoubleLinkedList::getNextNode(){
  current = current->next;
}

/**
List is created.
*/
DoubleLinkedList::DoubleLinkedList(){
  length = 0;
  head = nullptr;
  current = head;
}

/**
all nodes are freed.
*/
DoubleLinkedList::~DoubleLinkedList(){
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
int DoubleLinkedList::lengthIs()const{
  return length;
}

/**
found is set to true if the item is found in the list and
item is set to the info instance variable of the node
that is equal to item.
@param item: this is the item you want to retrieve
*/
void DoubleLinkedList::retrieveItem(ItemType &item, bool &found){
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
void DoubleLinkedList::insertItem(ItemType &item){
  if(findNode(item) != nullptr){
    return;
  }
  NodeType * nNode = new NodeType();
  NodeType * pNode = nullptr;
  nNode->info.initialize(item.getValue());
  if(head == nullptr){						// when head == nullptr
    head = nNode;
  }else if(item.compareTo(head->info) == LESS){			// insert before the head
    nNode->next = head;
    head->back = nNode;
    head = nNode;
  }else{
    current = head;
    for(int i = 0; i < length; i++){
      if(item.compareTo(current->info) == LESS){		// insert before the current 
	nNode->next = current;
	nNode->back = pNode;
	pNode->next = nNode;
	current->back = nNode;
	break;
      }else if(i == (length - 1)){				// insert in the end
	current->next = nNode;
	nNode->back = current;
	break;
      }else{							// get next node
	pNode = current;
	getNextNode();
      }
    }
  }
  length++;
}

/**
the node that contains item is removed from the list.
@param item: this is the item you want to delete
*/
void DoubleLinkedList::deleteItem(ItemType &item){
  NodeType * location;
  if(head == nullptr){
    return;
  }
  if(head->info.compareTo(item) == EQUAL){			// delete head
    if(head->next == nullptr){
      head == nullptr;
    }else{
      location = head;
      head = head->next;
      head->back = nullptr;
      delete location;
    }
    length--;
  }else{
    location = head->next;
    for(int i = 0; i < length ; i++){
      if(location->info.compareTo(item) == EQUAL){		// delete current
	if(location->next != nullptr){
	  location->back->next = location->next;
	  location->next->back = location->back;
	}else{							// delete tail
	  location->back->next = nullptr;
	}
	delete location;
	length--;
	break;
      }else{							// get next node
	location = location->next;
      }
    }
  }
}
/**
currrent pointer is set to nullptr.
*/
void DoubleLinkedList::resetList(){
  current = nullptr;
}

/**
items are printed to standard-out based on the
implementation in ItemType.
*/
void DoubleLinkedList::print(){
  if(head == nullptr){
    cout << "list is empty." << endl;
  }else{
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
}
