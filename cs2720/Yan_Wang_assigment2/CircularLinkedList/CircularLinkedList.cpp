#include "CircularLinkedList.h"

/**
List is created.
*/
CircularLinkedList::CircularLinkedList(){
  length = 0;
  head = nullptr;
  current = head;
}

/**
all nodes are freed.
*/
CircularLinkedList::~CircularLinkedList(){
  NodeType* temp;
  if(head != nullptr){ 
    while(head != head->next){
      temp = head->next;
      head->next = temp->next;
      delete temp;
    }
    delete head;
  }
}

/**
return length instance variable.
@return: length
*/
int CircularLinkedList::lengthIs()const{
  return length;
}

/**
item is inserted into the list in sorted order.
@param item: this is the item you want to insert
*/
void CircularLinkedList::insertItem(ItemType &item){
  NodeType* newNode;
  NodeType* preLoc;
  NodeType* location;
  bool found;
  
  newNode = new NodeType();
  newNode->info.initialize(item.getValue());
  if(head != nullptr){
    findItem(head,item,location,preLoc,found);
    if(found){
      delete newNode;
      return;
    }
    newNode->next = preLoc->next;
    preLoc->next = newNode;
    if(head->info.getValue() < item.getValue()){
      head = newNode;
    }
  }else{
    head = newNode;
    newNode->next = newNode;
  }
  length++;
}

/**
the node that contains item is removed from the list.
@param item: this is the item you want to delete
*/
void CircularLinkedList::deleteItem(ItemType &item){
  NodeType* location;
  NodeType* preLoc;
  bool found;
  findItem(head,item, location, preLoc, found);
  if(found == false){
    item.initialize(-99999);
    return;
  }
  if(preLoc == location){
    head = nullptr;
  }else{
    preLoc->next = location->next;
    if(location == head){
      head = preLoc;
    }
  }
  delete location;
  length--;
}

/**
If there is any element someItem whose key matches item’s key, then found =
true else, found = false. If found, location contains the address of someItem and
predLoc contains the address of someItem’s predecessor. Else, location contains
address of item’s logical successor and predLoc contains address of item’s
logical predecessor.
@param listData: this is the list you want to find item
@param item: the item you want to find
@param location: the item address if found
@param preloc: the location before the ltem location if found
@param found: boolean shows if found or not

 */

void CircularLinkedList::findItem(NodeType* listData, ItemType item, NodeType*& location, NodeType*& preloc, bool& found){
  bool moreToSearch = true;
  location = listData->next;
  preloc = listData;
  found = false;
  while(moreToSearch && !found){
    if(item.getValue() < location->info.getValue()){
      moreToSearch = false;
    }else if(item.getValue() == location->info.getValue()){
      found = true;
    }else{
      preloc = location;
      location = location->next;
      moreToSearch = (location != listData->next);
    }
  }
}

/**
items are printed to standard-out based on the
implementation in ItemType.
*/
void CircularLinkedList::print(){
  if(head == nullptr){
    cout << "list is empty" << endl;
  }else{
    cout << "List:";
    current = head->next;
    for(int i = 0; i < length; i++){
      if(i != (length-1)){
	cout << current->info.getValue() << ",";
	current = current->next;
      }else{
	cout << current->info.getValue() << endl;
      }
    }
  }
}
